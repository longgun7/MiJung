#include "stdafx.h"
#include "shop.h"
#include "enemyManager.h"
#include "playerManager.h"
#include "itemManager.h"


shop::shop()
{
}


shop::~shop()
{
}

HRESULT shop::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();
	_buyNum	  = 0;
	_totalNum = 0;

	return S_OK;
}

void shop::release(void)
{
}

void shop::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _buyNum > 0)
	{
		_buyNum--;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _totalNum < 10)
	{
		++_buyNum;
	}
}

void shop::render(void)
{
	_im->render();
}

void shop::fontUI()
{
	HFONT font, ofont;

	char str5[] = "소지수";
	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 160,WINSIZEY/6,str5, strlen(str5));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

	char str6[] = "구입수";
	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 160, WINSIZEY / 2 - 140, str6, strlen(str6));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

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
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 50, 120 + i * 50, str3, strlen(str3));
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

		if(PtInRect(&_im->getPortion()->getVPotion()[i].rc, _ptMouse))
		{
			char str[128];
			if (_im->getPortion()->getVPotion()[i].name == "약초")
			{
				
				sprintf_s(str, "%d", _pm->getPoIndex());
				_totalNum = _pm->getPoIndex() + _buyNum;
				
			}

			if (_im->getPortion()->getVPotion()[i].name == "마법의 물약")
			{
					
			}

			if (_totalNum > 10) _buyNum--;

			font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
			ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
			SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
			SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 240, WINSIZEY / 6 + 40, str, strlen(str));
			SelectObject(CAMERA->getCameraDC(), ofont);
			DeleteObject(font);

			char str1[128];
			font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
			ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
			SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
			SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
			sprintf_s(str1, "%dG",_im->getPortion()->getVPotion()[i].cost*_buyNum);
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 260, WINSIZEY / 3 + 40, str1, strlen(str1));
			sprintf_s(str1, "%d", _buyNum);
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 240, WINSIZEY / 3 + 10, str1, strlen(str1));
			SelectObject(CAMERA->getCameraDC(), ofont);
			DeleteObject(font);
		}
	}
}

void shop::shopRemove()
{
	
	while (_im->getPItem()->getVItem().size() > 0)
	{
		_im->getPItem()->removeItem(0);
	}
	while (_im->getPortion()->getVPotion().size() > 0)
	{
		_im->getPortion()->removePotion(0);
	}
}

void shop::setItem()
{
	_im->itemMakeSet("마인아수라", WINSIZEX / 2 - 260, 130);
	_im->itemMakeSet("불타는 마검", WINSIZEX / 2 - 260, 180);
	_im->itemMakeSet("명주 귀신살", WINSIZEX / 2 - 260, 230);
	_im->itemMakeSet("호랑이 도복", WINSIZEX / 2 - 260, 280);
	_im->potionMakeSet("약초", WINSIZEX / 2 - 260, 330);
	_im->potionMakeSet("마법의 물약", WINSIZEX / 2 - 260, 380);
}
