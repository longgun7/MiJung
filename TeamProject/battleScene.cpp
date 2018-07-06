#include "stdafx.h"
#include "battleScene.h"


battleScene::battleScene()
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init(void)
{
	
	IMAGEMANAGER->addImage("스킬선택창", "image/ui/스킬선택창.bmp", 350, 175, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("스킬선택창2", "image/ui/스킬선택창2.bmp", 350, 375, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("기본기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("개인기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("단체기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("도구아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("모드아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("특수기아이콘", "image/ui/아이콘.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->findImage("기본기아이콘")->setFrameX(5);
	IMAGEMANAGER->findImage("개인기아이콘")->setFrameX(6);
	IMAGEMANAGER->findImage("단체기아이콘")->setFrameX(7);
	IMAGEMANAGER->findImage("도구아이콘")->setFrameX(1);
	IMAGEMANAGER->findImage("모드아이콘")->setFrameX(8);
	IMAGEMANAGER->findImage("특수기아이콘")->setFrameX(9);

	IMAGEMANAGER->addFrameImage("SKILLBUTTON", "image/ui/UI버튼.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->findImage("SKILLBUTTON")->setFrameX(6);

	_isTurn = false;
	_choiceIndex = 0;

	_choiceX=357;
	_choiceY=125;
	return S_OK;
}

void battleScene::release(void)
{
}

void battleScene::update(void)
{
	
	if(KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isTurn)_isTurn = true;
		else if (_isTurn) _isTurn = false;
	}

	if(_isTurn)
	{
		if(KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_choiceIndex--;
			if (_choiceIndex < 0) _choiceIndex = 5;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_choiceIndex++;
			if (_choiceIndex > 5) _choiceIndex = 0;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{

		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{

		}
		if(KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			
		}
		
		for(int i=0;i<6;i++)
		{
			if(_choiceIndex == i)
			{
				_choiceX = 357 + i * 50;
			}
		}

	}
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);
	
	if (_isTurn)
	{
		IMAGEMANAGER->findImage("스킬선택창")->render(CAMERA->getCameraDC(), 320, 0);
		IMAGEMANAGER->findImage("스킬선택창2")->render(CAMERA->getCameraDC(), 320, 175);
		IMAGEMANAGER->findImage("기본기아이콘")->frameRender(CAMERA->getCameraDC(), 345, 75);
		IMAGEMANAGER->findImage("개인기아이콘")->frameRender(CAMERA->getCameraDC(), 395, 75);
		IMAGEMANAGER->findImage("단체기아이콘")->frameRender(CAMERA->getCameraDC(), 445, 75);
		IMAGEMANAGER->findImage("도구아이콘")->frameRender(CAMERA->getCameraDC(), 495, 75);
		IMAGEMANAGER->findImage("모드아이콘")->frameRender(CAMERA->getCameraDC(), 545, 75);
		IMAGEMANAGER->findImage("특수기아이콘")->frameRender(CAMERA->getCameraDC(), 595, 75);

		IMAGEMANAGER->findImage("SKILLBUTTON")->frameRender(CAMERA->getCameraDC(), _choiceX, _choiceY);
	}
	fontUI();
}

void battleScene::fontUI(void)
{
	HFONT font, ofont;
	char charName[] = "아타호";
	char charName2[] = "스마슈";

	char str[] = "배틀씬";
	char str1[] = "기본기";
	char str2[] = "개인기";
	char str3[] = "단체기";
	char str4[] = "도구";
	char str5[] = "모드";
	char str6[] = "특수기";

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	if(_isTurn)
	{
		TextOut(CAMERA->getCameraDC(), 345, 25, charName, strlen(charName));
		if (_choiceIndex == 0) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str1, strlen(str1));
		if (_choiceIndex == 1) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str2, strlen(str2));
		if (_choiceIndex == 2) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str3, strlen(str3));
		if (_choiceIndex == 3) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 37, 190, str4, strlen(str4));
		if (_choiceIndex == 4) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 37, 190, str5, strlen(str5));
		if (_choiceIndex == 5) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 50, 190, str6, strlen(str6));
	}

	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
