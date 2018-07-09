#include "stdafx.h"
#include "cameraManager.h"


cameraManager::cameraManager() {}
cameraManager::~cameraManager() {}

HRESULT cameraManager::init()
{
	// 카메라 버퍼 사이즈 지정
	_cameraBuffer = IMAGEMANAGER->addImage("카메라", WINSIZEX, WINSIZEY);
	_cameraX = _cameraY = 0;

	return S_OK;
}

void cameraManager::release()
{

}

void cameraManager::update()
{
	//cursor();	
}

void cameraManager::render(HDC hdc)
{
	GdiTransparentBlt(
		hdc,							//복사될 DC
		_cameraX,						//복사될 좌표 X(left)
		_cameraY,						//복사될 좌표 Y(top)
		_cameraBuffer->getWidth(),		//복사될 가로크기
		_cameraBuffer->getHeight(),		//복사될 세로크기
		_cameraBuffer->getMemDC(),		//복사할 DC
		0, 0,							//복사할 x,y
		WINSIZEX,						//복사할 가로, 세로크기
		WINSIZEY,
		RGB(255, 0, 255));					//복사할때 제외할 칼라
}

void cameraManager::setPosition(float x, float y, BOOL isMouse)
{
	// 마우스로 화면 이동하기
	if (isMouse)
	{
		if (x < WINSIZEX / 10) // 왼쪽
		{
			_cameraX -= CAMERASPEED;
			if (_cameraX < 0) _cameraX = 0;
		}
		if (x > WINSIZEX - WINSIZEX / 10) // 오른쪽
		{
			_cameraX += CAMERASPEED;
			if (_cameraX + WINSIZEX > BACKGROUNDX) _cameraX = BACKGROUNDX - WINSIZEX;
		}
		if (y < WINSIZEY / 10) // 위
		{
			_cameraY -= CAMERASPEED;
			if (_cameraY < 0) _cameraY = 0;
		}
		if (y > WINSIZEY - WINSIZEY / 10)  // 아래
		{
			_cameraY += CAMERASPEED;
			if (_cameraY + WINSIZEY > BACKGROUNDY) _cameraY = BACKGROUNDY - WINSIZEY;
		}
	}
	// 플레이어기준 카메라 좌표 세팅
	else
	{
		if (x > WINSIZEX / 3 && x < _maxCameraX - WINSIZEX / 3)
		{
			if (x < _cameraX + WINSIZEX / 3) _cameraX = x - (WINSIZEX / 3);
			else if (x > _cameraX + WINSIZEX - WINSIZEX / 3) _cameraX = x - (WINSIZEX - WINSIZEX / 3);
		}

		if (y > WINSIZEY / 3 && y < _maxCameraY - 550 / 3)
		{
			if (y < _cameraY + 550 / 3) _cameraY = y - (550 / 3);
			else if (y > _cameraY + 550 - 550 / 3) _cameraY = y - (550 - 550 / 3);
		}
	}
}

void cameraManager::cursor()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		(_isCursor == true) ? _isCursor = false : _isCursor = true;
	}

	RECT rc;
	POINT p1, p2;

	GetClientRect(_hWnd, &rc);    // 클라이언트 크기

	p1.x = rc.left;
	p1.y = rc.top;
	p2.x = rc.right;
	p2.y = rc.bottom;

	// 클라이언트 크기를 스크린 크기로 변환
	ClientToScreen(_hWnd, &p1);
	ClientToScreen(_hWnd, &p2);

	rc.left = p1.x;
	rc.top = p1.y;
	rc.right = p2.x;
	rc.bottom = p2.y;

	//해당 좌표를 기준으로 커서를 고정
	(_isCursor == true) ? ClipCursor(&rc) : ClipCursor(NULL);
}
