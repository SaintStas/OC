// OC16_Heap.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	//������� ����
	hHeap = HeapCreate(HEAP_NO_SERIALIZE, h_size, h_size);
	if (!hHeap)
	{
		std::cout << "������ 1!" << std::endl;
		return GetLastError();

	}
	int num;
	cout << "���� ����?!" << endl << "�� ���� ";
	cin >> num; cout << "�� ����." << endl;
	num++;

	//������������ ������ ���� ��� ������
	arr = (int*)HeapAlloc(hHeap, NULL, num*sizeof(int));
	if (!arr)
	{
		std::cout << "������ 2!" << std::endl;
		return GetLastError();

	}

	for (int i = 0; i < num; i++)
		arr[i] = i;
	// �������
	std::cout << "� ��� ���� �������� �� " << num - 1 << " �����." << endl;
	cout << "\t��� ���� � ����:\n";
	for (int i = 1; i < num; i++)
	{
		cout << i << " ������� ��� " << arr[i] << endl;
	}
	// ������� ��� ����
	cout << "������� ��� �������.";
	arr = (int*)HeapReAlloc(hHeap, NULL, arr, ++num * sizeof(int));
	arr[num - 1] = num - 1;

	std::cout << "� ��� ���� �������� �� " << num - 1 << " �����." << endl;
	cout << num - 1 << " ������� ��� " << arr[num - 1] << endl;

	//�������� 1
	cout << "��� �� ��������� ��� " << num - 1;
	arr = (int*)HeapReAlloc(hHeap, NULL, arr, --num * sizeof(int));
	cout << ". � � ������.\n\t��� ���� � ����:\n";
	for (int i = 1; i < num; i++)
	{
		cout << i << " ������� ��� " << arr[i] << endl;
	}
	// ������� �� ������ ����� �����
	cout << "������� ������ 0 ����� 1";
	arr = (int*)HeapReAlloc(hHeap, NULL, arr, num++ * sizeof(int));
	for (int i = num-1; i>0; i--)
		arr[i] = arr[i - 1];

	arr[0] =  0;
		cout << "\n\t��� ���� � ����:\n";
		for (int i = 1; i<num; i++)
		{
			cout << i << " ������� ��� " << arr[i] << endl;
		}
		//�������� c ������� ����� 
		cout << "��� �� ��������� ���� 0";
		for (int i = 0; i<num; i++)
			arr[i] = arr[i+1];

		arr = (int*)HeapReAlloc(hHeap, NULL, arr, --num * sizeof(int));
		cout << ". � ��� ������.\n\t��� ���� � ����:\n";
		for (int i = 1; i < num; i++)
		{
			cout << i << " ������� ��� " << arr[i] << endl;
		}



		//���������� ����
		if (HeapDestroy(hHeap) != 0)
			cout << "� ���� ����!!" << endl;

		system("pause");



}
