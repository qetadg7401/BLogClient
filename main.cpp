/*
/00������ Ȯ���Ѵ�.(true)/
			%systemroot%System32\winevt\Logs\BLogs ���� �����Ѵ�.		... ������ �����Ǿ� ������ �����Ѵ�.
			@<Evtx���� �ؽ�> �� ���� ���� ������� @<Socket ���>@<Socket ����> �� �����Ѵ�.		... %systemroot%System32\winevt\Logs\BLogs�� Evtx ������ ������ �����Ѵ�.
			'��� ����' ���縦 ���� ������ ������ ȹ���Ѵ�.
			�� '��� ����'���� ������ ������ ������ �����Ѵ�.
			���� �� ����(YYYYMMDD '��� ����'.evtx)		... ex)20190117 application.evtx
			@<Evtx���� ����> �� �����Ѵ�.

		/00������ Ȯ���Ѵ�.(false)/
			00�ð� �� ������ ���
*/

#pragma once

#include "BLogEvtx.h"
#include "BLogSocket.h"

int main()
{
	BLogEvtx BLog;
	//BLog.isEvtxFilesHere();
	//BLog.makeEvtxBackupFolder();
	//BLog.backupEvtxFiles();
	//BLog.removeEvtxFiles();

	BLogSocket socket;
	char* temp = new char[BUFSIZ];

	socket.getMyComputerIP(temp);

	std::cout << temp << " : " << strlen(temp) << std::endl;

	delete[] temp;
	getchar();

	return 0;
}