// OC16_Heap.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");
	HANDLE hHeap;
	int *arr = NULL;
	int h_size = 10048;
	int a_size = 10048;
	//создаем кучу
	hHeap = HeapCreate(HEAP_NO_SERIALIZE, h_size, h_size);
	if (!hHeap)
	{
		std::cout << "ОШИБКА 1!" << std::endl;
		return GetLastError();

	}
	int num;
	cout << "Скок цыфр?!" << endl << "Ну цифр ";
	cin >> num; cout << "Ну ладн." << endl;
	num++;

	//распределяем память кучи под массив
	arr = (int*)HeapAlloc(hHeap, NULL, num*sizeof(int));
	if (!arr)
	{
		std::cout << "ОШИБКА 2!" << std::endl;
		return GetLastError();

	}

	for (int i = 0; i < num; i++)
		arr[i] = i;
	// выводим
	std::cout << "У нас есть масивчик из " << num - 1 << " цифер." << endl;
	cout << "\tЧто есть в куче:\n";
	for (int i = 1; i < num; i++)
	{
		cout << i << " элемент это " << arr[i] << endl;
	}
	// Добавим еще один
	cout << "Добавим еще элемент.";
	arr = (int*)HeapReAlloc(hHeap, NULL, arr, ++num * sizeof(int));
	arr[num - 1] = num - 1;

	std::cout << "У нас есть масивчик из " << num - 1 << " цифер." << endl;
	cout << num - 1 << " элемент это " << arr[num - 1] << endl;

	//удаление 1
	cout << "Мне не нравиться эта " << num - 1;
	arr = (int*)HeapReAlloc(hHeap, NULL, arr, --num * sizeof(int));
	cout << ". Я её удалил.\n\tЧто есть в куче:\n";
	for (int i = 1; i < num; i++)
	{
		cout << i << " элемент это " << arr[i] << endl;
	}
	// Вставка на другое место числа
	cout << "Добавим элемнт 0 перед 1";
	arr = (int*)HeapReAlloc(hHeap, NULL, arr, num++ * sizeof(int));
	for (int i = num-1; i>0; i--)
		arr[i] = arr[i - 1];

	arr[0] =  0;
		cout << "\n\tЧто есть в куче:\n";
		for (int i = 1; i<num; i++)
		{
			cout << i << " элемент это " << arr[i] << endl;
		}
		//удаление c другого конца 
		cout << "Мне не нравиться этот 0";
		for (int i = 0; i<num; i++)
			arr[i] = arr[i+1];

		arr = (int*)HeapReAlloc(hHeap, NULL, arr, --num * sizeof(int));
		cout << ". Я его удалил.\n\tЧто есть в куче:\n";
		for (int i = 1; i < num; i++)
		{
			cout << i << " элемент это " << arr[i] << endl;
		}



		//разрушение кучи
		if (HeapDestroy(hHeap) != 0)
			cout << "Я убил кучу!!" << endl;

		system("pause");



}
