// OC15-klient.cpp: определяет точку входа для консольного приложения.
//
 
#include "stdafx.h"
#include <Windows.h>
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");
	HANDLE hPipe;
	DWORD dwWritten;
	char buffer[1024];
	DWORD dwRead;
	char sms[6][100] = { "Привет.\n", "Я бетман.\n", "Мне нужна помощь.\n", "7*8\n", "Спасибо!\n", "...\n" };
	int i = 0;

	//fConnected = ConnectNamedPipe(hNamedPipe, NULL);

	hPipe = CreateFile(TEXT("\\\\.\\pipe\\pipe"),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);
	if (hPipe != INVALID_HANDLE_VALUE)
	{
		WriteFile(hPipe,
			sms[i],
			12,   // = length of string + terminating '\0' !!!
			&dwWritten,
			NULL);
		i++;
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE && i<7)
			{
				/* add terminating zero */
				buffer[dwRead] = '\0';

				/* do something with data in buffer */
				printf("%s", buffer);
				Sleep(1000);
				WriteFile(hPipe,
					sms[i],
					50,   // = length of string + terminating '\0' !!!
					&dwWritten,
					NULL);
				i++;
			
			}

		CloseHandle(hPipe);
	}
	gets_s(sms[0]);
	return (0);
}
