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
	SCENEMANAGER->addScene("Ÿ���", new townScene);
	SCENEMANAGER->addScene("�ʵ��", new fieldScene);
	SCENEMANAGER->addScene("��Ʋ��", new battleScene);

	SCENEMANAGER->changeScene("Ÿ���");

	return S_OK;
}

void playScene::release(void)
{
}

void playScene::update(void)
{
	
}


void playScene::render(void)
{
	
}
