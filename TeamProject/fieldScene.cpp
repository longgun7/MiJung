#include "stdafx.h"
#include "fieldScene.h"


fieldScene::fieldScene()
{
}


fieldScene::~fieldScene()
{
}

HRESULT fieldScene::init(void)
{
	IMAGEMANAGER->addImage("�׵θ�", "image/ui/�����׵θ�.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�⺻status", "image/ui/�⺻status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));
	return S_OK;
}

void fieldScene::release(void)
{
}

void fieldScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("���¾�");
	}
	
}

void fieldScene::render(void)
{
	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);
	IMAGEMANAGER->findImage("�⺻status")->render(CAMERA->getCameraDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(CAMERA->getCameraDC(), 650, 550);
	IMAGEMANAGER->findImage("HP")->frameRender(CAMERA->getCameraDC(), 200, 562);
	IMAGEMANAGER->findImage("MP")->frameRender(CAMERA->getCameraDC(), 350, 562);
	IMAGEMANAGER->findImage("EXP")->frameRender(CAMERA->getCameraDC(), 500, 562);
	fontUI();
}

void fieldScene::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "�ʵ��";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
