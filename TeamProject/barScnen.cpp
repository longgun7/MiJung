#include "stdafx.h"
#include "barScnen.h"


barScnen::barScnen()
{
}


barScnen::~barScnen()
{
}

HRESULT barScnen::init(void)
{
	IMAGEMANAGER->addImage("�׵θ�", "image/ui/�����׵θ�.bmp", 1000, 550, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�⺻status", "image/ui/�⺻status.bmp", 650, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("infoStatus", "image/ui/infoStatus.bmp", 350, 200, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("����â", "image/ui/����â.bmp", 450, 360, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â������", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â���Լ�", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â����", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));

	_isShopCheck = false;
	_isHotelCheck = false;

	return S_OK;
}

void barScnen::release(void)
{
}

void barScnen::update(void)
{
	//���� üũ
	if(KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isShopCheck) _isShopCheck = true;
		else if (_isShopCheck) _isShopCheck = false;
	}
	
}

void barScnen::render(void)
{
	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);
	IMAGEMANAGER->findImage("�⺻status")->render(CAMERA->getCameraDC(), 0, 550);
	IMAGEMANAGER->findImage("infoStatus")->render(CAMERA->getCameraDC(), 650, 550);
	IMAGEMANAGER->findImage("HP")->frameRender(CAMERA->getCameraDC(), 200, 562);
	IMAGEMANAGER->findImage("MP")->frameRender(CAMERA->getCameraDC(), 350, 562);
	IMAGEMANAGER->findImage("EXP")->frameRender(CAMERA->getCameraDC(), 500, 562);
	if(_isShopCheck)
	{
		IMAGEMANAGER->findImage("����â")->render(CAMERA->getCameraDC(), 175, 95);
		IMAGEMANAGER->findImage("����â������")->render(CAMERA->getCameraDC(), 625, 95);
		IMAGEMANAGER->findImage("����â���Լ�")->render(CAMERA->getCameraDC(), 625, 215);
		IMAGEMANAGER->findImage("����â����")->render(CAMERA->getCameraDC(), 625, 335);
	}
	
	fontUI();
}

void barScnen::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "������";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(0, 0, 1));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}
