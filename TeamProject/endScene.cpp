#include "stdafx.h"
#include "endScene.h"


endScene::endScene()
{
}


endScene::~endScene()
{
}

HRESULT endScene::init(void)
{
	IMAGEMANAGER->addImage("�����", "image/ui/����������.bmp", 1000, 750, false, RGB(0, 0, 0));

	return S_OK;
}

void endScene::release(void)
{
}

void endScene::update(void)
{
}

void endScene::render(void)
{
	IMAGEMANAGER->findImage("�����")->render(CAMERA->getCameraDC(), 0, 0);
}
