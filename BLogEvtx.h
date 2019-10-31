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

#pragma once
#pragma comment(lib, "shlwapi.lib")

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include <Windows.h>
#include <shlwapi.h>
#include <winevt.h>

class BLogEvtx
{
private:
	static const wchar_t* const BACKUP_FOLDER;

public:
	BLogEvtx()
	{
	}
	~BLogEvtx()
	{
	}

	bool isEvtxFilesHere();
	void backupEvtxFiles();
	void removeEvtxFiles();
	std::wstring doHashingEvtxFiles();
	void makeEvtxBackupFolder();
};