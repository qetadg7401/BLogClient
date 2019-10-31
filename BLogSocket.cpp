/*
<>
</>

<Initialize>
<I>

</I>

<Function>
</F>
	<컴퓨터 IP 받기> void getMyComputerIP(char* ipNum);

	사용중인 컴퓨터 IP를 받는다.
	파라미터로 받은 char*에 저장

	</컴퓨터 IP 받기>

</F>


*/
#pragma once
#include "BLogSocket.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>


#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")


const int WORKING_BUFFER_SIZE = 16 * 1024;

/*char* convertIPAddr2Char(MIB_IPADDRROW addr)
{
	char* addr_str = new char;

	inet_ntop(AF_INET, (void*)& addr.dwAddr, addr_str, BUFSIZ);

	return addr_str;
}*/

void BLogSocket::getMyComputerIP(char* ipNum) // https://dojang.io/mod/page/view.php?id=550 참조해서 함수 바꾸기
{
	DWORD rv;
	DWORD size = 0;
	PMIB_IPADDRTABLE ipaddrtable;
	int bufLen;

	size = 0;

	rv = GetIpAddrTable(NULL, &size, 0);
	if (rv != ERROR_INSUFFICIENT_BUFFER) {
		fprintf(stderr, "GetIpAddrTable() failed...");;

		return;
	}

	ipaddrtable = (PMIB_IPADDRTABLE)malloc(size);

	rv = GetIpAddrTable(ipaddrtable, &size, 0);
	if (rv != NO_ERROR) {
		fprintf(stderr, "GetIpAddrTable() failed...");
		
		free(ipaddrtable);

		return;
	}

	if (ipaddrtable == nullptr) {
		free(ipaddrtable);

		return;
	}

	bufLen = ipaddrtable->dwNumEntries;
	char pBuffer[BUFSIZ] = { 0, };

	for (int i = 0; i < bufLen; ++i) {
		inet_ntop(AF_INET, &ipaddrtable->table[i], pBuffer, BUFSIZ);
		printf("%s", pBuffer);
	}	

	/*bufLen = strlen(pBuffer);
	for (int i = 0; i < bufLen; i++) {
		ipNum[i] = myIPAddress[i];
		std::cout << ipNum[i] << " : " << myIPAddress[i] << std::endl;
		ipNum[i + 1] = '\0';
	}*/
	
	*ipNum = pBuffer[0];

	free(ipaddrtable);

	return;
}