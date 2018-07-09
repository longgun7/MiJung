#include "stdafx.h"
#include "cameraManager.h"


cameraManager::cameraManager() {}
cameraManager::~cameraManager() {}

HRESULT cameraManager::init()
{
	// ī�޶� ���� ������ ����
	_cameraBuffer = IMAGEMANAGER->addImage("ī�޶�", WINSIZEX, WINSIZEY);
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
		hdc,							//����� DC
		_cameraX,						//����� ��ǥ X(left)
		_cameraY,						//����� ��ǥ Y(top)
		_cameraBuffer->getWidth(),		//����� ����ũ��
		_cameraBuffer->getHeight(),		//����� ����ũ��
		_cameraBuffer->getMemDC(),		//������ DC
		0, 0,							//������ x,y
		WINSIZEX,						//������ ����, ����ũ��
		WINSIZEY,
		RGB(255, 0, 255));					//�����Ҷ� ������ Į��
}

void cameraManager::setPosition(float x, float y, BOOL isMouse)
{
	// ���콺�� ȭ�� �̵��ϱ�
	if (isMouse)
	{
		if (x < WINSIZEX / 10) // ����
		{
			_cameraX -= CAMERASPEED;
			if (_cameraX < 0) _cameraX = 0;
		}
		if (x > WINSIZEX - WINSIZEX / 10) // ������
		{
			_cameraX += CAMERASPEED;
			if (_cameraX + WINSIZEX > BACKGROUNDX) _cameraX = BACKGROUNDX - WINSIZEX;
		}
		if (y < WINSIZEY / 10) // ��
		{
			_cameraY -= CAMERASPEED;
			if (_cameraY < 0) _cameraY = 0;
		}
		if (y > WINSIZEY - WINSIZEY / 10)  // �Ʒ�
		{
			_cameraY += CAMERASPEED;
			if (_cameraY + WINSIZEY > BACKGROUNDY) _cameraY = BACKGROUNDY - WINSIZEY;
		}
	}
	// �÷��̾���� ī�޶� ��ǥ ����
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

	GetClientRect(_hWnd, &rc);    // Ŭ���̾�Ʈ ũ��

	p1.x = rc.left;
	p1.y = rc.top;
	p2.x = rc.right;
	p2.y = rc.bottom;

	// Ŭ���̾�Ʈ ũ�⸦ ��ũ�� ũ��� ��ȯ
	ClientToScreen(_hWnd, &p1);
	ClientToScreen(_hWnd, &p2);

	rc.left = p1.x;
	rc.top = p1.y;
	rc.right = p2.x;
	rc.bottom = p2.y;

	//�ش� ��ǥ�� �������� Ŀ���� ����
	(_isCursor == true) ? ClipCursor(&rc) : ClipCursor(NULL);
}
