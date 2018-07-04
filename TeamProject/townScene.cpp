#include "stdafx.h"
#include "townScene.h"


townScene::townScene()
{
}


townScene::~townScene()
{
}

HRESULT townScene::init(void)
{
	IMAGEMANAGER->addImage("테두리", "image/ui/게임테두리.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("기본status", "image/ui/기본status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));
	

	return S_OK;
}

void townScene::release(void)
{
}

void townScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("상태씬");
	}
	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		SCENEMANAGER->changeScene("술집씬");
	}
}

void townScene::render(void)
{
	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);
	IMAGEMANAGER->findImage("기본status")->render(CAMERA->getCameraDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(CAMERA->getCameraDC(), 650, 550);
	IMAGEMANAGER->findImage("HP")->frameRender(CAMERA->getCameraDC(), 200, 562);
	IMAGEMANAGER->findImage("MP")->frameRender(CAMERA->getCameraDC(), 350, 562);
	IMAGEMANAGER->findImage("EXP")->frameRender(CAMERA->getCameraDC(), 500, 562);

	fontUI();
}

void townScene::fontUI(void)
{
	HFONT font, ofont;

	char charName[] = "아타호";
	char charName1[] = "스마슈";
	char str[] = "타운씬";
	char str1[] = "번돈";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 -100, str, strlen(str));
	TextOut(CAMERA->getCameraDC(), 25, WINSIZEY -150,charName, strlen(charName));
	TextOut(CAMERA->getCameraDC(), 25, WINSIZEY - 100, charName1, strlen(charName1));
	TextOut(CAMERA->getCameraDC(), WINSIZEX/2+175, WINSIZEY - 75, str1, strlen(str1));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
