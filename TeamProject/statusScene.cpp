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
	IMAGEMANAGER->addImage("�⺻status", "image/ui/�⺻status.bmp", 650, 200, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("ĳ�����̹���", "image/ui/ĳ�����̹���.bmp", 1000, 250, 8, 2, false, RGB(0, 0, 0));
	IMAGEMANAGER->findImage("ĳ�����̹���")->setFrameX(0);

	IMAGEMANAGER->addFrameImage("������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "image/ui/������.bmp", 600, 250, 12, 5, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));

	return S_OK;
}

void statusScene::release(void)
{
}

void statusScene::update(void)
{
	if(KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("Ÿ���");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("�ʵ��");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{

		IMAGEMANAGER->findImage("ĳ�����̹���")->setFrameX(
			IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX() + 1);
		if(IMAGEMANAGER->findImage("ĳ�����̹���")->getFrameX()>2) 
		{
			IMAGEMANAGER->findImage("ĳ�����̹���")->setFrameX(0);
		}
	}
}

void statusScene::render(void)
{
	IMAGEMANAGER->findImage("statusMain")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("statusChoice")->render(getMemDC(), 650, 0);
	IMAGEMANAGER->findImage("statusChoice2")->render(getMemDC(), 650, 150);
	IMAGEMANAGER->findImage("�⺻status")->render(getMemDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(getMemDC(), 650, 550);
	IMAGEMANAGER->findImage("ĳ�����̹���")->frameRender(getMemDC(), 60, 50);
}
