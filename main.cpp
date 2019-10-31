/*
/00시인지 확인한다.(true)/
			%systemroot%System32\winevt\Logs\BLogs 폴더 생성한다.		... 폴더가 생성되어 있으면 생략한다.
			@<Evtx파일 해싱> 을 통해 나온 결과물로 @<Socket 통신>@<Socket 전송> 을 실행한다.		... %systemroot%System32\winevt\Logs\BLogs에 Evtx 파일이 없으면 생략한다.
			'대상 파일' 복사를 위해 관리자 권한을 획득한다.
			각 '대상 파일'들을 위에서 생성한 폴더에 복사한다.
			파일 명 설정(YYYYMMDD '대상 파일'.evtx)		... ex)20190117 application.evtx
			@<Evtx파일 삭제> 을 실행한다.

		/00시인지 확인한다.(false)/
			00시가 될 때까지 대기
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