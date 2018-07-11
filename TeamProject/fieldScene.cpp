#include "stdafx.h"
#include "fieldScene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"

fieldScene::fieldScene()
{
}


fieldScene::~fieldScene()
{
}

HRESULT fieldScene::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();

	return S_OK;
}

void fieldScene::release(void)
{
}

void fieldScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		//SCENEMANAGER->changeScene("»óÅÂ¾À");
	}
	
}

void fieldScene::render(void)
{
	IMAGEMANAGER->findImage("Å×µÎ¸®")->render(CAMERA->getCameraDC(), 0, 0);
	
	fontUI();
}

void fieldScene::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "ÇÊµå¾À";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "»õ±¼¸²");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
