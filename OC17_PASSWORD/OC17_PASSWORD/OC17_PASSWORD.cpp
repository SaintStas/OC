#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include "string.h"
#include "conio.h"
#include <fstream>

#define STRLEN(x) (sizeof(x)/sizeof(TCHAR)-1)
#define PASSWORD 1
using namespace std;

HANDLE output;
HANDLE input;
COORD cursor;
int x = 10;
int y = 5;
const TCHAR szMsg[] = L"Input password:";
TCHAR szName[1];
DWORD dwCount = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");
	ifstream fout;
	fout.open("m:/OC/text.txt");
	//Проверка успешности открытия файла для чтения
	if (fout.fail()) {
		cout << "\n \t!Ошибка открытия файла паролей\n\n";
		return 1;
	}
	char str[256];
	fout >> str;
	int numpas = atoi(str);
	int numpasall = numpas;
	int a = 0;
	int b = 0;
	while (numpas--){
		system("cls");
		fout >> str;
		int num = strlen(str);
		if(PASSWORD==1) cout <<"PASSWORD: "<< str << endl;
		cout << num << "sin.\n" << "OPEN: " << a << "\nALL: " << numpasall << "\nLOST: " << b << endl;
		char *carr = new char[num + 1];
	
		output = GetStdHandle(STD_OUTPUT_HANDLE);
		input = GetStdHandle(STD_INPUT_HANDLE);
		cursor.X = x;
		cursor.Y = y;
		SetConsoleCursorPosition(output, cursor);
		WriteConsole(output, &szMsg, STRLEN(szMsg), &dwCount, NULL);
		cursor.Y++;
		SetConsoleCursorPosition(output, cursor);
		char ch;
		int i = 0;
		bool priz = true;
		while (i <= num - 1)
		{
			//ReadConsole(input,&szName,STRLEN(szName),&dwCount,NULL);

			ch = _getch();
			carr[i] = ch;
			if (!(ch == str[i]))
			{
				priz = false;
			}


			ch = '*';

			cursor.X++;
			SetConsoleCursorPosition(output, cursor);
			printf("%c", ch);
			i++;

		}
		if (priz){
			cout << "\nPASWORD OK!" << std::endl;
			a++; b++;
		}
		else
		{
			cout << "\nPASWORD NO!" << std::endl;
			b++;
		}

	}
	return 0;
	cout << "\nALL!!!" << std::endl;
	system("pause");
}

