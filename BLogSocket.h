/*
<>
</>

<Initialize>
<I>
	
</I>

<Function>
</F>
	<컴퓨터 IP 받기> std::wstring getMyComputerIP();

	사용중인 컴퓨터 IP를 받는다.
	받은 결과물을 return

	</컴퓨터 IP 받기>

</F>


*/


#pragma once

#include <iostream>
#include <string>



class BLogSocket
{
private:
	static const int WORKING_BUFFER_SIZE;

public:
	BLogSocket()
	{
	}
	~BLogSocket()
	{
	}

	void getMyComputerIP(char* ipNum);
};

