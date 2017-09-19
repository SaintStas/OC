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
	cout << "Введите размер массива\n";
	cin >> n;//ввод размера массива

	struct MyStruct
	{
		int a;
		int b;
		float c;
	};
	//MyStruct *abc = (MyStruct*)malloc(n*sizeof(MyStruct)); // c
	MyStruct *abc = new MyStruct[n]; // c++
	cout << "Введите массив(a,b)\n";
	for (i = 0; i < n; i++){
		cout << "Структура номер " << i + 1 << ":\n";
		cin >> abc[i].a;
		cin >> abc[i].b;
		abc[i].c = ((float)abc[i].a / (float)abc[i].b);
	}//ввод массива

	cout << "\n massiv\n";
	for (i = 0; i < n; i++)
		cout << "[" << i + 1 << " MyStruct ] is " << abc[i].a << ":" << abc[i].b << "=" << abc[i].c << endl;       //вывод массива


	// Удаление массива

	delete[] abc;

	cout << "\nУдалено\n\n";
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
	cout << "Введите a и b:\n";
		cin >> abc->a; 
		cin >> abc->b;
		abc->c = ((float)abc->a / (float)abc->b);

	cout << "\n ENTER\n";
	cout << "[ MyStruct ] is " << abc->a << ":" << abc->b << "=" << abc->c << endl;       //вывод массива


	// Удаление массива

	delete abc;

	cout << "\nУдалено\n\n";
	system("pause");
	return 1;
}

int one()
{
	int i, n;
	cout << "Введите размер массива\n";
	cin >> n;//ввод размера массива

	char **a = new char*[10]; // 10 строк
	for (int i = 0; i < 10; i++)
	{
		a[i] = new char[100]; // Под каждую строку выделяем массив в 100 символов
	}
	cout << "Введите (строковый) массив, нажимая ENTER после каждого элемента\n";

	for (i = 0; i<n; i++)

		cin >> a[i];       //ввод массива

	cout << "\n massiv\n";
	for (i = 0; i < n; i++)
		cout << "[" << i + 1 << " word ] is " << a[i] << endl;       //вывод массива


	// Удаление массива
	for (int i = 0; i < 10; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	cout << "\nУдалено\n\n";
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
	char p[256] = { "1.	Создать массив для размещения строк (написать аналогичную  программу)\n2.	Создать массив для размещения структуры.\n3.	Создать массив для размещения массива структур.\n" };
	cout << p<< "Введите задание\n";
	cin >> i;//ввод размера массива
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
	//освобождение памяти
}

