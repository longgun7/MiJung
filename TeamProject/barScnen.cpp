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
	
	
	IMAGEMANAGER->addImage("상점창", "image/ui/상점창.bmp", 450, 360, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("상점창소지수", "image/ui/상점창2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("상점창구입수", "image/ui/상점창2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("상점창번돈", "image/ui/상점창2.bmp", 200, 120, false, RGB(0, 0, 0));

	_isShopCheck = false;
	_isHotelCheck = false;

	return S_OK;
}

void barScnen::release(void)
{
}

void barScnen::update(void)
{
	//상점 체크
	if(KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isShopCheck) _isShopCheck = true;
		else if (_isShopCheck) _isShopCheck = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("상태씬");
	}
}

void barScnen::render(void)
{
	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);
	
	if(_isShopCheck)
	{
		IMAGEMANAGER->findImage("상점창")->render(CAMERA->getCameraDC(), 175, 95);
		IMAGEMANAGER->findImage("상점창소지수")->render(CAMERA->getCameraDC(), 625, 95);
		IMAGEMANAGER->findImage("상점창구입수")->render(CAMERA->getCameraDC(), 625, 215);
		IMAGEMANAGER->findImage("상점창번돈")->render(CAMERA->getCameraDC(), 625, 335);
	}
	
	fontUI();
}

void barScnen::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "술집씬";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(0, 0, 1));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}

void barScnen::setItem()
{
	
}
