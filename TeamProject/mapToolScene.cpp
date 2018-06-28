#include "stdafx.h"
#include "mapToolScene.h"


mapToolScene::mapToolScene()
{
}


mapToolScene::~mapToolScene()
{
}

HRESULT mapToolScene::init(void)
{
	

	return S_OK;
}

void mapToolScene::release(void)
{
}

void mapToolScene::update(void)
{
	if(KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("½ºÅ¸Æ®¾À");
	}
}

void mapToolScene::render(void)
{
	
}
