#include "stdafx.h"
#include "fieldScene.h"


fieldScene::fieldScene()
{
}


fieldScene::~fieldScene()
{
}

HRESULT fieldScene::init(void)
{
	IMAGEMANAGER->addImage("테두리", "image/ui/게임테두리.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("기본status", "image/ui/기본status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));
	return S_OK;
}

void fieldScene::release(void)
{
}

void fieldScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		SCENEMANAGER->changeScene("상태씬");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("배틀씬");
	}
}

void fieldScene::render(void)
{
	IMAGEMANAGER->findImage("테두리")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("기본status")->render(getMemDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(getMemDC(), 650, 550);
}
