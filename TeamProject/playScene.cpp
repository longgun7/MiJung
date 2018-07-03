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
	SCENEMANAGER->addScene("»óÅÂ¾À", new statusScene);
	SCENEMANAGER->addScene("Å¸¿î¾À", new townScene);
	SCENEMANAGER->addScene("ÇÊµå¾À", new fieldScene);
	SCENEMANAGER->addScene("¹èÆ²¾À", new battleScene);

	SCENEMANAGER->changeScene("Å¸¿î¾À");

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
