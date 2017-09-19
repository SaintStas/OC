// OC13_mail-klient1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <windows.h>
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "I'm klient two: " << std::endl;

	HANDLE hslot;

	LPTSTR slotname = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateFile(slotname, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);




	if (hslot == INVALID_HANDLE_VALUE)
	{

		std::cout << "SLOT WRITING FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;

	}

	std::cout << "I'm opening mail." << std::endl;
	int nData;
	while (3){
		char msg[220] = { "klient 2: " };
		char msgp[200];
		gets_s(msgp);
		strcat_s(msg, msgp);
		DWORD dwBytesWrite;
		if (!WriteFile(hslot, &msg, 200, &dwBytesWrite, NULL))
		{
			std::cout << "WRITE FAILED" << std::endl;
			CloseHandle(hslot);
			std::cout << "PRESS KEY TO FINICH" << std::endl;
			std::cin.get();
			return 0;
		}

		std::cout << "I'm sending: " << msgp << std::endl;
	}
	std::cout << "PRESS KEY TO FINICH" << std::endl;
	CloseHandle(hslot);
	std::cin.get();
	return 0;


	return 0;
}


