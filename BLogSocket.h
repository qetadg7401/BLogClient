/*
<>
</>

<Initialize>
<I>
	
</I>

<Function>
</F>
	<��ǻ�� IP �ޱ�> std::wstring getMyComputerIP();

	������� ��ǻ�� IP�� �޴´�.
	���� ������� return

	</��ǻ�� IP �ޱ�>

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

