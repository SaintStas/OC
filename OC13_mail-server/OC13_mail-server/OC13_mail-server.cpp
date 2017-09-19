// OC13_mail-server.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <ctime>



int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hslot;
	LPTSTR slotname = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateMailslot(slotname, 0, MAILSLOT_WAIT_FOREVER, NULL);
	if (hslot == INVALID_HANDLE_VALUE)
	{

		std::cout << "SLOT FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;

	}

	std::cout << "I'm creating a mail." << std::endl;
	while (3){
		char nData[200];
		DWORD dwBytesRead;

		if (!ReadFile(hslot, &nData, sizeof(nData), &dwBytesRead, (LPOVERLAPPED)NULL))
		{
			std::cout << "READING SLOT FAILED" << std::endl;
			CloseHandle(hslot);
			std::cout << "PRESS KEY TO FINICH" << std::endl;
			std::cin.get();
			return 0;
		}

		std::cout << nData << std::endl;
	}
	std::cout << "PRESS KEY TO FINICH" << std::endl;
	CloseHandle(hslot);
	std::cin.get();
	return 0;


	return 0;
}


