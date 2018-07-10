#include "stdafx.h"
#include "barScnen.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"

barScnen::barScnen()
{
}


barScnen::~barScnen()
{
}

HRESULT barScnen::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();

	
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
		if (!_isShopCheck)
		{
			_isShopCheck = true;
			setItem();
		}
		else if (_isShopCheck) _isShopCheck = false;
	}

	if (!_isShopCheck)
	{
		for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
		{
			_im->getPItem()->removeItem(i);
		
		}
		for (int i = 0; i < _im->getPortion()->getVPotion().size(); ++i)
		{
			_im->getPortion()->removePotion(i);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("상태씬");
	}
	
	buyItem();
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
	_im->render();
	fontUI();


}

void barScnen::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "술집씬";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

	if (_isShopCheck)
	{
		for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
		{
			// 샵 아이템 이름 표시
			string str1 = _im->getPItem()->getVItem()[i].name;
			font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
			ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
			SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
			SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + i * 50, str1.c_str(), strlen(str1.c_str()));
			SelectObject(CAMERA->getCameraDC(), ofont);
			DeleteObject(font);

			// 샵 아이템 가격 표시
			char str3[128];
			font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
			ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
			SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
			SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

			sprintf_s(str3, "%d", _im->getPItem()->getVItem()[i].cost);
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 +50, 120 + i * 50, str3, strlen(str3));
			SelectObject(CAMERA->getCameraDC(), ofont);
			DeleteObject(font);
		}

		for (int i = 0; i < _im->getPortion()->getVPotion().size(); ++i)
		{
			// 샵 포션 이름 표시
			string str2 = _im->getPortion()->getVPotion()[i].name;
			font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
			ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
			SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
			SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
				str2.c_str(), strlen(str2.c_str()));
			SelectObject(CAMERA->getCameraDC(), ofont);
			DeleteObject(font);

			// 샵 포션 가격 표시
			char str4[128];
			font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
			ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
			SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
			SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
			sprintf_s(str4, "%d", _im->getPortion()->getVPotion()[i].cost);
			TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 50, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
				str4, strlen(str4));
			SelectObject(CAMERA->getCameraDC(), ofont);
			DeleteObject(font);
		}
	}

	char str6[128];
	sprintf_s(str6, "%d", _im->getPItem()->getVItem().size());
	TextOut(getMemDC(), 500, 50, str6, strlen(str6));

}

void barScnen::setItem()
{
	_im->itemMakeSet("청룡도", WINSIZEX/2-260, 130);
	_im->itemMakeSet("불타는 마검", WINSIZEX / 2 - 260, 180);
	_im->itemMakeSet("명주 귀신살", WINSIZEX / 2 - 260, 230);
	_im->itemMakeSet("호랑이 도복", WINSIZEX / 2 - 260, 280);
	_im->potionMakeSet("약초", WINSIZEX / 2 - 260, 330);
}

void barScnen::buyItem()
{

}
