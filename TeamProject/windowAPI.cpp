#include "stdafx.h"
#include "playGround.h"

//API : Application Programming Interface

//================== 전역 변수 ======================

HINSTANCE	_hInstance;	//윈도우 고유번호
HWND		_hWnd;		//윈도우 핸들
LPCTSTR _lpszClass = TEXT("Alpha");

POINT _ptMouse;
POINT _ptBGMouse;

playGround _pg;

BOOL _leftButtonDown;	//왼쪽클릭했는지 여부에 대한 불 값

//============== 함수 프로토 타입 =====================
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int cmdShow)
{
	MSG message;		//메세지 (윈도우)
	WNDCLASS wndClass;	//윈도우 구조체

	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);
	
	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	ShowWindow(_hWnd, cmdShow);

	//메세지 처리 루프문
	if (FAILED(_pg.init()))
	{

		return 0;	//꺼버려라
	}
	//GetMessage : 메시지가 발생해야 그제서야 처리한다
	//PeekMessage : 메세지 여부와 상관없이 메시지 처리를 계속 하고있다
	
	/*
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);	//키보드 입력하는 순간에 입력키 전달 메시지
		DispatchMessage(&message);	//실제로 윈도우로 메시지를 전송해주는 역할
	}
	*/
	
	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			TIMEMANAGER->update(60.0f);
			_pg.update();
			_pg.render();
		}
	}
	
	//KillTimer - 메세지 루프 다돌고 해제염
	_pg.release();

	UnregisterClass(WINNAME, hInstance);

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _pg.MainProc(hWnd, iMessage, wParam, lParam);
}

//클라이언트 영역 재조정 함수
void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;

	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	AdjustWindowRect(&winRect, WINSTYLE, false);

	//실질적으로 윈도우 크기 조절을 한다
	SetWindowPos(_hWnd, NULL, x, y, 
		(winRect.right - winRect.left),
		(winRect.bottom - winRect.top), 
		SWP_NOZORDER | SWP_NOMOVE);
}
