#include "stdafx.h"
#include "statusScene.h"


statusScene::statusScene()
{
}


statusScene::~statusScene()
{
}

HRESULT statusScene::init(void)
{
	IMAGEMANAGER->addImage("statusMain", "image/ui/statusMain.bmp", 650, 550, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("statusChoice", "image/ui/statusChoice.bmp", 350, 150, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("statusChoice2", "image/ui/statusChoice2.bmp", 350, 400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("기본status", "image/ui/기본status.bmp", 650, 200, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, false, RGB(0, 0, 0));


	return S_OK;
}

void statusScene::release(void)
{
}

void statusScene::update(void)
{
	if(KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("플레이씬");
	}
}

void statusScene::render(void)
{
	IMAGEMANAGER->findImage("statusMain")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("statusChoice")->render(getMemDC(), 650, 0);
	IMAGEMANAGER->findImage("statusChoice2")->render(getMemDC(), 650, 150);
	IMAGEMANAGER->findImage("기본status")->render(getMemDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(getMemDC(), 650, 550);
}
