#include "stdafx.h"
#include "battleScene.h"


battleScene::battleScene()
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init(void)
{
	IMAGEMANAGER->addImage("�׵θ�", "image/ui/�����׵θ�.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�⺻status", "image/ui/�⺻status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ų����â", "image/ui/��ų����â.bmp", 350, 175, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("��ų����â2", "image/ui/��ų����â2.bmp", 350, 375, false, RGB(0, 0, 0));

	_isTurn = false;

	return S_OK;
}

void battleScene::release(void)
{
}

void battleScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("�ʵ��");
	}
	if(KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isTurn)_isTurn = true;
		else if (_isTurn) _isTurn = false;
	}

	
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("�׵θ�")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�⺻status")->render(getMemDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(getMemDC(), 650, 550);

	if (_isTurn)
	{
		IMAGEMANAGER->findImage("��ų����â")->render(getMemDC(), 320, 0);
		IMAGEMANAGER->findImage("��ų����â2")->render(getMemDC(), 320, 175);
	}
	
}
