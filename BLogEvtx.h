/*
관리자 권한이 필요한 함수를 사용함		... 프로젝트 -> 속성 -> 링커 -> 매니페스트 파일 -> UAC 실행 수준 -> administrator

<Initialize>
<I>

</I>

<Function>
</F>
	<Evtx 파일 찾기> bool isEvtxFilesHere();

		if) %systemroot%System32\winevt\Logs 안에 있는 '대상 파일'을 찾는다.		... %systemroot%는 Windows가 설치되어있는 디렉토리. 보통은 C:\\Windows\를 의미함.
		/ 대상 파일 ------------------
		application.evtx		... 어플리케이션 로그
		system.evtx				... 시스템 로그
		setup.evtx				... 설치 로그
		security.evtx			... 보안 로그
		forwarded Events Log(전달된 이벤트 로그) 파일		...사용 보류
		----------------------------/
		true)
			return true

		flase)
			return false


	</Evtx 파일 찾기>

	<Evtx 파일 백업> void backupEvtxFiles();

		BACKUP_FOLDER 폴더 생성한다.					... 폴더가 생성되어 있으면 생략한다.
		각 '대상 파일'들을 BACKUP_FOLDER 에 복사한다.
		파일 명 설정 (YYYYMMDD '대상 파일'.evtx)		... ex)20190117_Application.evtx

	</Evtx 파일 복사>

	<Evtx 파일 삭제> void removeEvtxFiles();

		%systemroot%System32\winevt\Logs 안에 있는 '대상 파일' 삭제

	</Evtx 파일 삭제>

	<Evtx 파일 해싱> std::wstring doHashingEvtxFiles();

		%systemroot%System32\winevt\Logs 안에 있는 '대상 파일'을 모두 md5로 해싱
		나온 결과물을 return

	</Evtx 파일 해싱>

	<Evtx 폴더 생성> void makeEvtxBackupFolder();

		BACKUP_FOLDER 폴더 생성한다.

	</Evtx 폴더 생성>

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