#include "stdafx.h"
#include "main.h"
#pragma comment(lib,"comctl32")
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wp)) {
		case BUTTON_ID1:
			MessageBox(hwnd, L"AA", L"bB", MB_OK);
		}
		return 0;
	}
	return DefWindowProcW(hwnd, msg, wp, lp);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hwnd;
	MSG msg;
	WNDCLASS wc;
	InitCommonControls();

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("MainWindow_MFApp");
	if (!RegisterClass(&wc)) return -1;
	hwnd = CreateWindow(TEXT("MainWindow_MFApp"), TEXT("Title Bar?"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1)), hInstance, NULL);
	CreateWindow(L"BUTTON", L"Button1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, 0, 100, 50, hwnd, (HMENU)BUTTON_ID1, hInstance, nullptr);
	if (hwnd == NULL) return -1;
	while (GetMessage(&msg, NULL, 0, 0))DispatchMessage(&msg);
	return msg.wParam;
}
