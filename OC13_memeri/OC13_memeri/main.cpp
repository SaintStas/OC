#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <ctime>
using namespace std;

HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);



int three()
{
	int i, n;
	cout << "������� ������ �������\n";
	cin >> n;//���� ������� �������

	struct MyStruct
	{
		int a;
		int b;
		float c;
	};
	//MyStruct *abc = (MyStruct*)malloc(n*sizeof(MyStruct)); // c
	MyStruct *abc = new MyStruct[n]; // c++
	cout << "������� ������(a,b)\n";
	for (i = 0; i < n; i++){
		cout << "��������� ����� " << i + 1 << ":\n";
		cin >> abc[i].a;
		cin >> abc[i].b;
		abc[i].c = ((float)abc[i].a / (float)abc[i].b);
	}//���� �������

	cout << "\n massiv\n";
	for (i = 0; i < n; i++)
		cout << "[" << i + 1 << " MyStruct ] is " << abc[i].a << ":" << abc[i].b << "=" << abc[i].c << endl;       //����� �������


	// �������� �������

	delete[] abc;

	cout << "\n�������\n\n";
	system("pause");
	return 1;
}


int two()
{
	int i;
	struct MyStruct
	{
		int a;
		int b;
		float c;
	};

	//MyStruct *abc = (MyStruct*)malloc(sizeof(MyStruct));
	MyStruct *abc = new MyStruct;
	cout << "������� a � b:\n";
		cin >> abc->a; 
		cin >> abc->b;
		abc->c = ((float)abc->a / (float)abc->b);

	cout << "\n ENTER\n";
	cout << "[ MyStruct ] is " << abc->a << ":" << abc->b << "=" << abc->c << endl;       //����� �������


	// �������� �������

	delete abc;

	cout << "\n�������\n\n";
	system("pause");
	return 1;
}

int one()
{
	int i, n;
	cout << "������� ������ �������\n";
	cin >> n;//���� ������� �������

	char **a = new char*[10]; // 10 �����
	for (int i = 0; i < 10; i++)
	{
		a[i] = new char[100]; // ��� ������ ������ �������� ������ � 100 ��������
	}
	cout << "������� (���������) ������, ������� ENTER ����� ������� ��������\n";

	for (i = 0; i<n; i++)

		cin >> a[i];       //���� �������

	cout << "\n massiv\n";
	for (i = 0; i < n; i++)
		cout << "[" << i + 1 << " word ] is " << a[i] << endl;       //����� �������


	// �������� �������
	for (int i = 0; i < 10; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	cout << "\n�������\n\n";
	system("pause");
	return 1;
}

int  main()
{
	int i;
//	_getch();
	system("mode con cols=60 lines=10");
	system("title String");
	setlocale(0, "");
	system("cls");
	SetConsoleTextAttribute(H,6);
	char p[256] = { "1.	������� ������ ��� ���������� ����� (�������� �����������  ���������)\n2.	������� ������ ��� ���������� ���������.\n3.	������� ������ ��� ���������� ������� ��������.\n" };
	cout << p<< "������� �������\n";
	cin >> i;//���� ������� �������
	switch (i)
	{
	case 1:if(one()==1) main();
		break;
	case 2:if (two() == 1) main();
		break;
	case 3: if (three() == 1) main();
		break;
	default: main();
		break;
	}
	

	return 0;
	//������������ ������
}

