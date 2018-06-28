#include "stdafx.h"
#include "startScene.h"


startScene::startScene()
{
}


startScene::~startScene()
{
}

HRESULT startScene::init(void)
{
	IMAGEMANAGER->addImage("background", "image/ui/��ŸƮ��.bmp", 1000, 750, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("startChoice", "image/ui/startUI.bmp", 300, 100, false, RGB(0, 0, 0));
	SCENEMANAGER->addScene("������", new mapToolScene);
	SCENEMANAGER->addScene("�÷��̾�", new playScene);
	return S_OK;
}

void startScene::release(void)
{
}

void startScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("������");
	}
	if(KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("�÷��̾�");
		playScene* _playScene;
		_playScene = new playScene;
		_playScene->init();
	}
}

void startScene::render(void)
{
	IMAGEMANAGER->findImage("background")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("startChoice")->render(getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 60);
}
