/*
������ ������ �ʿ��� �Լ��� �����		... ������Ʈ -> �Ӽ� -> ��Ŀ -> �Ŵ��佺Ʈ ���� -> UAC ���� ���� -> administrator

<Initialize>
<I>

</I>

<Function>
</F>
	<Evtx ���� ã��> bool isEvtxFilesHere();

		if) %systemroot%System32\winevt\Logs �ȿ� �ִ� '��� ����'�� ã�´�.		... %systemroot%�� Windows�� ��ġ�Ǿ��ִ� ���丮. ������ C:\\Windows\�� �ǹ���.
		/ ��� ���� ------------------
		application.evtx		... ���ø����̼� �α�
		system.evtx				... �ý��� �α�
		setup.evtx				... ��ġ �α�
		security.evtx			... ���� �α�
		forwarded Events Log(���޵� �̺�Ʈ �α�) ����		...��� ����
		----------------------------/
		true)
			return true

		flase)
			return false


	</Evtx ���� ã��>

	<Evtx ���� ���> void backupEvtxFiles();

		BACKUP_FOLDER ���� �����Ѵ�.					... ������ �����Ǿ� ������ �����Ѵ�.
		�� '��� ����'���� BACKUP_FOLDER �� �����Ѵ�.
		���� �� ���� (YYYYMMDD '��� ����'.evtx)		... ex)20190117_Application.evtx

	</Evtx ���� ����>

	<Evtx ���� ����> void removeEvtxFiles();

		%systemroot%System32\winevt\Logs �ȿ� �ִ� '��� ����' ����

	</Evtx ���� ����>

	<Evtx ���� �ؽ�> std::wstring doHashingEvtxFiles();

		%systemroot%System32\winevt\Logs �ȿ� �ִ� '��� ����'�� ��� md5�� �ؽ�
		���� ������� return

	</Evtx ���� �ؽ�>

	<Evtx ���� ����> void makeEvtxBackupFolder();

		BACKUP_FOLDER ���� �����Ѵ�.

	</Evtx ���� ����>

</F>
*/

#include "BLogEvtx.h"

const wchar_t* const BLogEvtx::BACKUP_FOLDER = L"C:/Windows/BackupLog_BlockChain";

bool BLogEvtx::isEvtxFilesHere()
{
	HANDLE hEventLog;
	hEventLog = OpenEventLogW(NULL, L"Application");

	if (hEventLog == NULL) {
		std::cout << "�α׸� ã�� �� �����ϴ�." << GetLastError() << std::endl;
		return false;
	}

	CloseEventLog(hEventLog);
	return true;
}

void BLogEvtx::backupEvtxFiles()
{
	HANDLE hEventLog;
	time_t m_time;
	struct tm ptime;
	std::wstring wstrBuffer;
	const wchar_t* wcpBuffer;

	m_time = time(0);
	localtime_s(&ptime, &m_time);

	wstrBuffer = BACKUP_FOLDER;
	wstrBuffer += L"/";
	wstrBuffer += std::to_wstring(ptime.tm_year + 1900);
	wstrBuffer += std::to_wstring(ptime.tm_mon + 1);
	wstrBuffer += std::to_wstring(ptime.tm_mday);
	wstrBuffer += L"_Application.evtx";

	wcpBuffer = wstrBuffer.c_str();

	hEventLog = OpenEventLogW(NULL, L"Application");

	if (!BackupEventLogW(hEventLog, wcpBuffer)) {
		std::cout << "Application �α� ���� ����� �����߽��ϴ�." << std::endl;
		CloseEventLog(hEventLog);
		return;
	}

	std::cout << "Application �α� ���� ����� �����߽��ϴ�." << std::endl;
	CloseEventLog(hEventLog);
	return;
}

void BLogEvtx::removeEvtxFiles()
{
	HANDLE hEventLog;
	hEventLog = OpenEventLogW(NULL, L"Application");

	if (!ClearEventLogW(hEventLog, NULL)) {
		std::cout << "Application �α� ������ �����߽��ϴ�." << GetLastError() << std::endl;
		return;
	}

	std::cout << "Application �α� ������ �����߽��ϴ�.";
	

	CloseEventLog(hEventLog);
	return;
}

std::wstring BLogEvtx::doHashingEvtxFiles()
{	
	return L"asdf";
}

void BLogEvtx::makeEvtxBackupFolder()
{
	if (_wmkdir(BACKUP_FOLDER) == 0) {
		std::cout << "��� ������ �����Ǿ����ϴ�." << std::endl;
		return;
	}
	
	// system("mkdir \"C:/Windows/System32/winevt/Logs/tt\"");

	std::cout << "��� ���� ������ �����߽��ϴ�." << std::endl;
	return;
}
