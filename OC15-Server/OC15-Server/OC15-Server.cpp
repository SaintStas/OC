// OC15-Server.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <string.h>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");
	HANDLE hPipe;
	char buffer[1024];
	int i=0;
	DWORD dwRead;
	char sms[6][100] = { "Привет. Ты кто?\n", "Вау!\n", "Какая?\n", "Это 48.\n", "Это все?\n", "Аууууу...\n"};


	//                        \\ИмяСервера\pipe\ИмяКанала
	hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\pipe"),
		PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,   // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
		PIPE_WAIT,
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	DWORD dwWritten;
	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, NULL) != FALSE)   // wait for someone to connect to the pipe
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE && i<6)
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
		}

		DisconnectNamedPipe(hPipe);
	}

	return 0;
}
