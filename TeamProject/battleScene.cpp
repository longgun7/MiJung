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

	return S_OK;
}

void battleScene::release(void)
{
}

void battleScene::update(void)
{
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("�׵θ�")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("�⺻status")->render(getMemDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(getMemDC(), 650, 550);
}
