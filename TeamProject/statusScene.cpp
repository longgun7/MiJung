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
	IMAGEMANAGER->addFrameImage("캐릭터이미지", "image/ui/캐릭터이미지.bmp", 1000, 250, 8, 2, false, RGB(0, 0, 0));
	IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(0);

	IMAGEMANAGER->addFrameImage("아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아이템", "image/ui/아이템.bmp", 600, 250, 12, 5, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));

	return S_OK;
}

void statusScene::release(void)
{
}

void statusScene::update(void)
{
	if(KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("타운씬");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("필드씬");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{

		IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(
			IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX() + 1);
		if(IMAGEMANAGER->findImage("캐릭터이미지")->getFrameX()>2) 
		{
			IMAGEMANAGER->findImage("캐릭터이미지")->setFrameX(0);
		}
	}
}

void statusScene::render(void)
{
	IMAGEMANAGER->findImage("statusMain")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("statusChoice")->render(getMemDC(), 650, 0);
	IMAGEMANAGER->findImage("statusChoice2")->render(getMemDC(), 650, 150);
	IMAGEMANAGER->findImage("기본status")->render(getMemDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(getMemDC(), 650, 550);
	IMAGEMANAGER->findImage("캐릭터이미지")->frameRender(getMemDC(), 60, 50);
}
