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
	return S_OK;
	IMAGEMANAGER->addImage("¿£µå¾À", "image/ui/³ëÀ»¿£µù¾À.bmp", 1000, 750, false, RGB(0, 0, 0));
}

void endScene::release(void)
{
}

void endScene::update(void)
{
}

void endScene::render(void)
{
	IMAGEMANAGER->findImage("¿£µå¾À")->frameRender(CAMERA->getCameraDC(), 0, 0);
}
