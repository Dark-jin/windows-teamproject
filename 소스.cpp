#include <windows.h>
#include <stdio.h>
#include <time.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("사각형 맞추기 GAME");


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);


	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}
static int arr1[4]; // { 900,350,1000,450 }
static int arr2[4]; // { 450,350,550,450 }
static int arr3[4]; // { 900,100,1000,200 }
static int arr4[4]; // { 100,300,200,400 }
static int arr5[4]; // { 500,150,600,250 }

void reset() //다시 시작할시 변수 초기화
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 2; i++) {
		arr1[i] = ((rand() % 100) * 10); arr2[i] = ((rand() % 100) * 10);
		arr3[i] = ((rand() % 100) * 10); arr4[i] = ((rand() % 100) * 10);
		arr5[i] = ((rand() % 100) * 10);
	}
	for (int i = 2; i < 4; i++) {
		arr1[i] = arr1[i - 2] + 100; arr2[i] = arr2[i - 2] + 100;
		arr4[i] = arr4[i - 2] + 100; arr3[i] = arr3[i - 2] + 100;
		arr5[i] = arr5[i - 2] + 100;
	}
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH MyBrush, OldBrush;
	HPEN MyPen, OldPen;
	TCHAR s[20];
	static RECT rect;
	// 첫번째 사각형 좌표
	static int x = 20;
	static int y = 120;
	static int a = 100;
	static int b = 200;
	int i = 0;

	// 여러 사각형 좌표
	
	/*static RECT arRect[] = {
	{900,350,1000,450},{450,350,550,450},{900,100,1000,200},
	{100,300,200,400},{500,150,600,250},
	};*/

	switch (iMessage) {
	case WM_CREATE:
		GetClientRect(hWnd, &rect);
		hWndMain = hWnd;

		srand((unsigned int)time(NULL));
		for (int i = 0; i < 2; i++) {
			arr1[i] = ((rand() % 100) * 10); arr2[i] = ((rand() % 100) * 10);
			arr3[i] = ((rand() % 100) * 10); arr4[i] = ((rand() % 100) * 10);
			arr5[i] = ((rand() % 100) * 10);
		}
		for (int i = 2; i < 4; i++) {
			arr1[i] = arr1[i - 2] + 100; arr2[i] = arr2[i - 2] + 100;
			arr4[i] = arr4[i - 2] + 100; arr3[i] = arr3[i - 2] + 100;
			arr5[i] = arr5[i - 2] + 100;
		}
		return 0;
	case WM_KEYDOWN: // 방향키 받기
		switch (wParam) {
		case VK_ESCAPE:
			MessageBox(hWnd, TEXT("종료 하시겠습니까?"), TEXT("알림"), WM_CLOSE);
			PostQuitMessage(0);
			break;
		case VK_F2:
			if (MessageBox(hWnd, TEXT("다시 시작 하시겠습니까?"), TEXT("알림"), MB_OKCANCEL) == IDOK)
			{
				reset();
			}
			else
			{
				PostQuitMessage(0);
			}
			break;
		case VK_LEFT:
			x -= 10;
			y -= 10;
			break;
		case VK_RIGHT:
			x += 10;
			y += 10;
			break;
		case VK_UP:
			a -= 10;
			b -= 10;
			break;
		case VK_DOWN:
			a += 10;
			b += 10;
			break;
		case VK_RETURN: // CLEAR
			if (x == arr1[0] && y == arr1[2] && a == arr1[1] && b == arr1[3])
			{
				MessageBox(hWnd, TEXT("사각형이 도킹을 완료했습니다!"), TEXT("알림"), MB_OK);
			}
			else if (x == arr2[0] && y == arr2[2] && a == arr2[1] && b == arr2[3])
			{
				MessageBox(hWnd, TEXT("사각형이 도킹을 완료했습니다!"), TEXT("알림"), MB_OK);
			}
			else if (x == arr3[0] && y == arr3[2] && a == arr3[1] && b == arr3[3])
			{
				MessageBox(hWnd, TEXT("사각형이 도킹을 완료했습니다!"), TEXT("알림"), MB_OK);
			}
			else if (x == arr4[0] && y == arr4[2] && a == arr4[1] && b == arr4[3])
			{
				MessageBox(hWnd, TEXT("사각형이 도킹을 완료했습니다!"), TEXT("알림"), MB_OK);
			}
			else if (x == arr5[0] && y == arr5[2] && a == arr5[1] && b == arr5[3])
			{
				MessageBox(hWnd, TEXT("사각형이 도킹을 완료했습니다!"), TEXT("알림"), MB_OK);
			}
			else
			{
				MessageBox(hWnd, TEXT("사각형이 도킹에 실패했습니다!"), TEXT("알림"), MB_OK);
			}
			return 0;
		}
		InvalidateRect(hWnd, NULL, TRUE); // 이거 FALSE로 바꾸면 계속 그려짐
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		MyBrush = CreateSolidBrush(RGB(255, 0, 255)); // 안에 특성
		OldBrush = (HBRUSH)SelectObject(hdc, MyBrush); // 브러쉬
		MyPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0)); // 선 특성
		OldPen = (HPEN)SelectObject(hdc, MyPen); // 선

		Rectangle(hdc, x, a, y, b); // 첫번째 사각형

		SelectObject(hdc, GetStockObject(NULL_BRUSH)); // 안에 색 안 채우고 선만
		Rectangle(hdc, arr1[0], arr1[1], arr1[2], arr1[3]);
		Rectangle(hdc, arr2[0], arr2[1], arr2[2], arr2[3]);
		Rectangle(hdc, arr3[0], arr3[1], arr3[2], arr3[3]);
		Rectangle(hdc, arr4[0], arr4[1], arr4[2], arr4[3]);
		Rectangle(hdc, arr5[0], arr5[1], arr5[2], arr5[3]);

		//Rectangle(hdc,900,100,1000,200); // 두번째 사각형

		wsprintf(s, TEXT("%d %d %d %d"), x, a, y, b); // 위치 출력
		TextOut(hdc, 10, 10, s, lstrlen(s)); // 위치 출력
		EndPaint(hWnd, &ps);

		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}