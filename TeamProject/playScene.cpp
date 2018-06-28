#include "stdafx.h"
#include "playScene.h"


playScene::playScene()
{
}


playScene::~playScene()
{
}

HRESULT playScene::init(void)
{
	SCENEMANAGER->addScene("╩Себ╬ю", new statusScene);
	return S_OK;
}

void playScene::release(void)
{
}

void playScene::update(void)
{
	if(KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("╩Себ╬ю");
	}
}


void playScene::render(void)
{
	TextOut(getMemDC(), 300, 300, "playScene", strlen("playScene"));
}
