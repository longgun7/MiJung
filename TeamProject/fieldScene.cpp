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
	IMAGEMANAGER->addImage("�׵θ�", "image/ui/�����׵θ�.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�⺻status", "image/ui/�⺻status.bmp", 650, 200, true, RGB(255, 0, 255));
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
		SCENEMANAGER->changeScene("���¾�");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("��Ʋ��");
	}
}

void fieldScene::render(void)
{
	IMAGEMANAGER->findImage("�׵θ�")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�⺻status")->render(getMemDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(getMemDC(), 650, 550);
}
