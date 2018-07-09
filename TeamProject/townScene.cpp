#include "stdafx.h"
#include "townScene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"


townScene::townScene()
{
}


townScene::~townScene()
{
}

HRESULT townScene::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();
	
	return S_OK;
}

void townScene::release(void)
{
}

void townScene::update(void)
{
	
	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		SCENEMANAGER->changeScene("¼úÁý¾À");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("»óÅÂ¾À");
	}
}

void townScene::render(void)
{
	IMAGEMANAGER->findImage("Å×µÎ¸®")->render(CAMERA->getCameraDC(), 0, 0);
	

	fontUI();
}

void townScene::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "Å¸¿î¾À";
	font = CreateFont(20, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "»õ±¼¸²");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
