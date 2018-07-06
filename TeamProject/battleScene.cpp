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
	
	IMAGEMANAGER->addImage("��ų����â", "image/ui/��ų����â.bmp", 350, 175, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("��ų����â2", "image/ui/��ų����â2.bmp", 350, 375, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("�⺻�������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���α������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ü�������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ư���������", "image/ui/������.bmp", 1000, 200, 20, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->findImage("�⺻�������")->setFrameX(5);
	IMAGEMANAGER->findImage("���α������")->setFrameX(6);
	IMAGEMANAGER->findImage("��ü�������")->setFrameX(7);
	IMAGEMANAGER->findImage("����������")->setFrameX(1);
	IMAGEMANAGER->findImage("��������")->setFrameX(8);
	IMAGEMANAGER->findImage("Ư���������")->setFrameX(9);

	IMAGEMANAGER->addFrameImage("SKILLBUTTON", "image/ui/UI��ư.bmp", 450, 75, 18, 3, true, RGB(255, 0, 255));
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
	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);
	
	if (_isTurn)
	{
		IMAGEMANAGER->findImage("��ų����â")->render(CAMERA->getCameraDC(), 320, 0);
		IMAGEMANAGER->findImage("��ų����â2")->render(CAMERA->getCameraDC(), 320, 175);
		IMAGEMANAGER->findImage("�⺻�������")->frameRender(CAMERA->getCameraDC(), 345, 75);
		IMAGEMANAGER->findImage("���α������")->frameRender(CAMERA->getCameraDC(), 395, 75);
		IMAGEMANAGER->findImage("��ü�������")->frameRender(CAMERA->getCameraDC(), 445, 75);
		IMAGEMANAGER->findImage("����������")->frameRender(CAMERA->getCameraDC(), 495, 75);
		IMAGEMANAGER->findImage("��������")->frameRender(CAMERA->getCameraDC(), 545, 75);
		IMAGEMANAGER->findImage("Ư���������")->frameRender(CAMERA->getCameraDC(), 595, 75);

		IMAGEMANAGER->findImage("SKILLBUTTON")->frameRender(CAMERA->getCameraDC(), _choiceX, _choiceY);
	}
	fontUI();
}

void battleScene::fontUI(void)
{
	HFONT font, ofont;
	char charName[] = "��Ÿȣ";
	char charName2[] = "������";

	char str[] = "��Ʋ��";
	char str1[] = "�⺻��";
	char str2[] = "���α�";
	char str3[] = "��ü��";
	char str4[] = "����";
	char str5[] = "���";
	char str6[] = "Ư����";

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
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
