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
	IMAGEMANAGER->addImage("테두리", "image/ui/게임테두리.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("기본status", "image/ui/기본status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스킬선택창", "image/ui/스킬선택창.bmp", 350, 175, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("스킬선택창2", "image/ui/스킬선택창2.bmp", 350, 375, false, RGB(0, 0, 0));

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
		SCENEMANAGER->changeScene("필드씬");
	}
	if(KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isTurn)_isTurn = true;
		else if (_isTurn) _isTurn = false;
	}

	
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("테두리")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("기본status")->render(getMemDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(getMemDC(), 650, 550);

	if (_isTurn)
	{
		IMAGEMANAGER->findImage("스킬선택창")->render(getMemDC(), 320, 0);
		IMAGEMANAGER->findImage("스킬선택창2")->render(getMemDC(), 320, 175);
	}
	
}
