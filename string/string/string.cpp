#include "stdafx.h"
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	TCHAR directorySearch[] = TEXT("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Notepad++\\");
	TCHAR filesearch[] = TEXT("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Notepad++\\*.exe");


	// Find the first file in the directory.
	hFind = FindFirstFile(filesearch, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u.\n", GetLastError());
	}
	else
	{
		wcout << "Found: " << FindFileData.cFileName << '\n';

		// List all the other files in the directory.
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			wcout << "Found: " << FindFileData.cFileName << '\n';
		}
		//--------------------------------------------//
		int start = 0;
		char name[50];
		int j;
		for (j = 0; j < 3; j++) {
			cin >> name[j];
		}
		//--------------------------------------------//
		STARTUPINFO cif;
		PROCESS_INFORMATION pi;
		GetStartupInfo(&cif);

		WCHAR *h = FindFileData.cFileName;
		TCHAR s[sizeof(directorySearch) + sizeof(h)];
		TCHAR buf[] = TEXT("");

		int i = 0, o = 0;
		//-----------------------------------------//

		
		for (int l = 0; l < j; l++) {
			if (name[l] == h[l]) {
				start++;
			}
		}
		j = 0;
		if (start >= 2) {

		//----------------------------------------------//

			for (i; i < 13; i++) {
				s[i] = directorySearch[i];
			}
			i--;
			for (i--; i < i + sizeof(h); i++) {
				s[i] = h[o];
				o++;
				if (s[i] == 'e' && s[i - 1] == 'x' && s[i - 2] == 'e' && s[i - 3] == '.') {
					for (int g = i + 1; g < i + sizeof(h); g++) {
						s[g] = buf[0];
					}
					break;
				}
			}
			  

			if (!(CreateProcessW(NULL, s, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi)))
				std::wcout << "Error " << '\n';

			//--------------//
			}
			//--------------//
			
		FindClose(hFind); 
	}
	system("pause");

	return 0;
}