/*
<>
</>

<Initialize>
<I>

</I>

<Function>
</F>
	<��ǻ�� IP �ޱ�> void getMyComputerIP(char* ipNum);

	������� ��ǻ�� IP�� �޴´�.
	�Ķ���ͷ� ���� char*�� ����

	</��ǻ�� IP �ޱ�>

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

void BLogSocket::getMyComputerIP(char* ipNum) // https://dojang.io/mod/page/view.php?id=550 �����ؼ� �Լ� �ٲٱ�
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