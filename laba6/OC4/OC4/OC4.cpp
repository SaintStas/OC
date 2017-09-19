#include "stdafx.h"
#include <windows.h>

#pragma comment(lib,"MSImg32.lib")

#include "OC4.h"
HWND hWnd2;
HWND hWnd3;
#define MAX_LOADSTRING 100
int colmn = 1; int prkey = NULL;
int colnm = 1;
COLORREF C2 = RGB(100, 100, 100);
LPDRAWITEMSTRUCT lpdraws = NULL;
// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	myF(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: разместите код здесь.
	MSG msg;
	HACCEL hAccelTable;

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_OC4, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OC4));

	// Цикл основного сообщения:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OC4));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(7);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_OC4);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


void DrawButton1(DRAWITEMSTRUCT* dis, HWND hWnd)
{
	if (dis->itemState & ODS_SELECTED)
	{
		TRIVERTEX   tx[2];
		tx[0].x = 0;
		tx[0].y = 0;
		tx[0].Red = 0;
		tx[0].Green = 0x0AAAA;
		tx[0].Blue = 0x0FFFF;
		tx[1].x = 100;    // Ширина кнопки.
		tx[1].y = 20;   // Высота кнопки. 
		tx[1].Red = 0x0CCCC;
		tx[1].Green = 0;
		tx[1].Blue = 0;

		GRADIENT_RECT       gRect;
		gRect.UpperLeft = 1;
		gRect.LowerRight = 0;
		GradientFill(dis->hDC, tx, 2, &gRect, 1, GRADIENT_FILL_RECT_H);
	}
	else
	{
		TRIVERTEX   tx[2];
		tx[0].x = 0;
		tx[0].y = 0;
		tx[0].Red = 0x0AAAA;
		tx[0].Green = 0x07777;
		tx[0].Blue = 0;
		tx[1].x = 100;    // Ширина кнопки.
		tx[1].y = 20;   // Высота кнопки.
		tx[1].Red = 0x0DDDD;
		tx[1].Green = 0;
		tx[1].Blue = 0;

		GRADIENT_RECT       gRect;
		gRect.UpperLeft = 1;
		gRect.LowerRight = 0;
		GradientFill(dis->hDC, tx, 2, &gRect, 1, GRADIENT_FILL_RECT_H);
	}

	RECT rect;
	GetClientRect(hWnd, &rect);
	SetBkMode(dis->hDC, TRANSPARENT);

	TCHAR Buffer[256];
	GetWindowText(hWnd, Buffer, 256);
	DrawText(dis->hDC, Buffer, lstrlen(Buffer), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void DrawButton2(DRAWITEMSTRUCT* dis, HWND hWnd)
{
	RECT rect;
	GetClientRect(hWnd, &rect);

	if (dis->itemState & ODS_SELECTED)
	{
		TRIVERTEX   tx[2];
		tx[0].x = 0;
		tx[0].y = 0;
		tx[0].Red = 0x02378;
		tx[0].Green = 0;
		tx[0].Blue = 0x0FFFF;
		tx[1].x = 100;    // Ширина кнопки.
		tx[1].y = 20;   // Высота кнопки.
		tx[1].Red = 0;
		tx[1].Green = 0;
		tx[1].Blue = 0x0CCCC;

		GRADIENT_RECT       gRect;
		gRect.UpperLeft = 0;
		gRect.LowerRight = 1;
		GradientFill(dis->hDC, tx, 2, &gRect, 1, GRADIENT_FILL_RECT_H);
	}
	else
	{
		TRIVERTEX   tx[2];
		tx[0].x = 0;
		tx[0].y = 0;
		tx[0].Red = 0;
		tx[0].Green = 0x0BBCC;
		tx[0].Blue = 0;
		tx[1].x = 100;    // Ширина кнопки.
		tx[1].y = 20;   // Высота кнопки.
		tx[1].Red = 0;
		tx[1].Green = 0;
		tx[1].Blue = 0x0DDDD;

		GRADIENT_RECT       gRect;
		gRect.UpperLeft = 0;
		gRect.LowerRight = 1;
		GradientFill(dis->hDC, tx, 2, &gRect, 1, GRADIENT_FILL_RECT_H);
	}
	SetBkMode(dis->hDC, TRANSPARENT);

	TCHAR Buffer[256];
	GetWindowText(hWnd, Buffer, 256);
	DrawText(dis->hDC, Buffer, lstrlen(Buffer), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND	- обработка меню приложения
//  WM_PAINT	-Закрасить главное окно
//  WM_DESTROY	 - ввести сообщение о выходе и вернуться.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	int wmId, wmEvent;
	PAINTSTRUCT ps;
	RECT r; //объявляем экзмепляр структуры RECT - координаты прямоугольника.
	HDC hdc;
	TCHAR str[] = TEXT("ПОМИДОР");

	LOGFONT lf;
	HFONT hFont;
	HBRUSH hBrush;
	HPEN hPen;
	RECT *rp;
	switch (message)
	{
	case WM_CREATE:
		hWnd2 = CreateWindowEx(NULL,
			L"BUTTON",
			L"НАЖМИ",
			BS_OWNERDRAW | WS_TABSTOP | WS_VISIBLE |
			WS_CHILD ,
			500,
			200,
			100,
			24,
			hWnd,
			HMENU(IDC_MyButton),
			hInst,
			NULL);
		ShowWindow(hWnd2, 1);
		hWnd3 = CreateWindowEx(NULL,
			L"BUTTON",
			L"ВЫХОД",
			BS_OWNERDRAW | WS_TABSTOP | WS_VISIBLE |
			WS_CHILD | BS_DEFPUSHBUTTON,
			150,
			200,
			100,
			24,
			hWnd,
			HMENU(IDC_MyButton2),
			hInst,
			NULL);
		ShowWindow(hWnd3, 1);
		break;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		if (LOWORD(wParam) == IDC_MyButton &&
			HIWORD(wParam) == BN_CLICKED)
		{

			hdc = GetDC(hWnd);
			DialogBox(hInst, (LPCTSTR)IDD_DIALOG1, hWnd, (DLGPROC)myF);
		}
		if (LOWORD(wParam) == IDC_MyButton2 &&
			HIWORD(wParam) == BN_CLICKED)
		{

			PostQuitMessage(0);
		}
		return 0;
		break;

		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_RBUTTONDOWN:
		hdc = GetDC(hWnd);
		DialogBox(hInst, (LPCTSTR)IDD_DIALOG1, hWnd, (DLGPROC)myF);
		break;

	case WM_CTLCOLORBTN:
	{
		SetBkColor((HDC)wParam, RGB(255, 0, 255));
		
		return (LRESULT)CreateSolidBrush(RGB(255, 255, 0));
	}
		break;
	

	
	case WM_DRAWITEM:
	{
		DRAWITEMSTRUCT* dis = (DRAWITEMSTRUCT*)lParam;

		switch (dis->CtlID)
		{
		case IDC_MyButton:
			DrawButton2(dis, hWnd2);
			break;

		case IDC_MyButton2:
			DrawButton1(dis, hWnd3);
			break;
		}
	}
	return TRUE;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);



	case WM_KEYUP:
		if (wParam == VK_SHIFT)
			prkey = 0;
			break;
	case WM_KEYDOWN:
		if (wParam == VK_SHIFT)
			prkey = 1;
		break;
	case WM_CHAR:
		if (WM_CHAR)
			if (wParam == 32 && prkey == 1){
				hdc = GetDC(hWnd);
					
				COLORREF C1= RGB(255, 0, 0);
				SetTextColor(hdc, C1);
				SetBkMode(hdc, TRANSPARENT);
				InvalidateRect(NULL, 0, 0);
                              
				TextOut(hdc, colmn++, colnm++, str, 7);
				ReleaseDC(hWnd, hdc);
			}break;

	}
	return 0;
}



// оброботчик для вызова окна
LRESULT CALLBACK myF(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	HBRUSH hBrush;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_PAINT:
	/*	hdc = BeginPaint(hDlg, &ps);
		hBrush = CreateSolidBrush(RGB(0, 255, 0));
		FillRect(ps.hdc, &ps.rcPaint, hBrush);
		EndPaint(hDlg, &ps);
		DeleteObject(hBrush);*/

		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)

		{
			int z = MessageBoxEx(NULL, TEXT("HELLO!"), TEXT("HELLLLOOOOOOOOOO!!!!!"), MB_ICONWARNING, 0x0409);
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL)

		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}