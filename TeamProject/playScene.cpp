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
	SCENEMANAGER->addScene("���¾�", new statusScene);
	return S_OK;
}

void playScene::release(void)
{
}

void playScene::update(void)
{
	if(KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("���¾�");
	}
}


void playScene::render(void)
{
	TextOut(getMemDC(), 300, 300, "playScene", strlen("playScene"));
}
