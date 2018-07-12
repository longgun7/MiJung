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

	IMAGEMANAGER->addFrameImage("¼¥UI¹öÆ°", "image/ui/UI¹öÆ°.bmp", 450, 75, 18, 3, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("¼¥¿ÞÂÊ", "image/ui/UI¹öÆ°.bmp", 450, 75, 18, 3, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("¼¥¿À¸¥ÂÊ", "image/ui/UI¹öÆ°.bmp", 450, 75, 18, 3, false, RGB(0, 0, 0));

	IMAGEMANAGER->findImage("¼¥UI¹öÆ°")->setFrameX(7);
	IMAGEMANAGER->findImage("¼¥¿ÞÂÊ")->setFrameX(8);
	IMAGEMANAGER->findImage("¼¥¿À¸¥ÂÊ")->setFrameX(9);

	_buyNum	  = 0;
	_totalNum = 0;
	_purchase = true;
	_index = 0;

	return S_OK;
}

void shop::release(void)
{
}

void shop::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_buyNum--;
		if (_buyNum < 0) _buyNum = 10;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		++_buyNum;
		if (_buyNum > _maxNum || _totalNum > 10) _buyNum = 0;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_index--;
		if (_index < 0) _index = _im->getPortion()->getVPotion().size() + _im->getPItem()->getVItem().size() - 1;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_index++;
		if (_index > _im->getPortion()->getVPotion().size() + _im->getPItem()->getVItem().size() - 1) _index = 0;
	}

	if (_buyNum == 0)  IMAGEMANAGER->findImage("¼¥¿ÞÂÊ")->setFrameY(5);
	else IMAGEMANAGER->findImage("¼¥¿ÞÂÊ")->setFrameY(0);

	if (_buyNum == 10) IMAGEMANAGER->findImage("¼¥¿À¸¥ÂÊ")->setFrameY(5);
	else IMAGEMANAGER->findImage("¼¥¿À¸¥ÂÊ")->setFrameY(0);

	buyItem();

}

void shop::render(void)
{
	_im->render();
	IMAGEMANAGER->findImage("¼¥UI¹öÆ°")->frameRender(CAMERA->getCameraDC(), 190, 115 + (_index * 50));
	IMAGEMANAGER->findImage("¼¥¿ÞÂÊ")->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2 + 135, WINSIZEY / 2 - 110);
	IMAGEMANAGER->findImage("¼¥¿À¸¥ÂÊ")->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2 + 295, WINSIZEY / 2 - 110);
}

void shop::fontUI()
{
	HFONT font, ofont;

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "»õ±¼¸²");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	char str5[] = "¼ÒÁö¼ö";
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 160,WINSIZEY/6,str5, strlen(str5));
	char str6[] = "±¸ÀÔ¼ö";
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 160, WINSIZEY / 2 - 140, str6, strlen(str6));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

	char str2[128];
	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "»õ±¼¸²");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
	{
		// ¼¥ ¾ÆÀÌÅÛ ÀÌ¸§ Ç¥½Ã
		string str1 = _im->getPItem()->getVItem()[i].name;
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + i * 50, str1.c_str(), strlen(str1.c_str()));
		// ¼¥ ¾ÆÀÌÅÛ °¡°Ý Ç¥½Ã
		sprintf_s(str2, "%d", _im->getPItem()->getVItem()[i].cost);
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 50, 120 + i * 50, str2, strlen(str2));

		if (_index == i)
		{
			_maxNum = 1;
			sprintf_s(str2, "%dG", _im->getPItem()->getVItem()[i].cost*_buyNum);
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 280, WINSIZEY / 3 + 40, str2, strlen(str2));

			if (_purchase == true)
			{
				for (int j = 0; j < _pm->getVA_WeapInven().size(); ++j)
				{
					if (_pm->getVA_WeapInven()[j].name == _im->getPItem()->getVItem()[i].name) _purchase = false;
				}
			}

			if (_purchase == true)
			{
				for (int j = 0; j < _pm->getVA_ArmorInven().size(); ++j)
				{
					if (_pm->getVA_ArmorInven()[j].name == _im->getPItem()->getVItem()[i].name) _purchase = false;
				}
			}

			if (_purchase == true)
			{

				for (int j = 0; j < _pm->getVS_WeapInven().size(); ++j)
				{
					if (_pm->getVS_WeapInven()[j].name == _im->getPItem()->getVItem()[i].name) _purchase = false;
				}
			}

			if (_purchase == true)
			{

				for (int j = 0; j < _pm->getVS_ArmorInven().size(); ++j)
				{
					if (_pm->getVS_ArmorInven()[j].name == _im->getPItem()->getVItem()[i].name) _purchase = false;
				}
			}

			if (_purchase == false) _buyNum = 0;

			_purchase = true;
		}
	}

	for (int i = 0; i < _im->getPortion()->getVPotion().size(); ++i)
	{
		// ¼¥ Æ÷¼Ç ÀÌ¸§ Ç¥½Ã
		string str1 = _im->getPortion()->getVPotion()[i].name;
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
			str1.c_str(), strlen(str1.c_str()));
		// ¼¥ Æ÷¼Ç °¡°Ý Ç¥½Ã
		sprintf_s(str2, "%d", _im->getPortion()->getVPotion()[i].cost);
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 50, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
			str2, strlen(str2));

		if (_index == i + _im->getPItem()->getVItem().size())
		{
			_maxNum = 10;
			if (_im->getPortion()->getVPotion()[i].name == "¾àÃÊ")
			{

				sprintf_s(str2, "%d", _pm->getHpPoIndex());
				_totalNum = _pm->getHpPoIndex() + _buyNum;

			}

			if (_im->getPortion()->getVPotion()[i].name == "¸¶¹ýÀÇ ¹°¾à")
			{
				sprintf_s(str2, "%d", _pm->getMpPoIndex());
				_totalNum = _pm->getMpPoIndex() + _buyNum;
			}

			TextOut(CAMERA->getCameraDC(), WINSIZEX - 240, WINSIZEY / 6 + 40, str2, strlen(str2));
			sprintf_s(str2, "%dG", _im->getPortion()->getVPotion()[i].cost*_buyNum);
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 280, WINSIZEY / 3 + 40, str2, strlen(str2));
		}
		
	}

	if (_totalNum > 10) _buyNum--;

	sprintf_s(str2, "%d", _buyNum);
	TextOut(CAMERA->getCameraDC(), WINSIZEX - 240, WINSIZEY / 3 + 10, str2, strlen(str2));
	sprintf_s(str2, "%d", _index);
	TextOut(CAMERA->getCameraDC(), WINSIZEX - 240, 10, str2, strlen(str2));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

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
	_im->itemMakeSet("¸¶ÀÎ¾Æ¼ö¶ó", WINSIZEX / 2 - 260, 130);
	_im->itemMakeSet("ºÒÅ¸´Â ¸¶°Ë", WINSIZEX / 2 - 260, 180);
	_im->itemMakeSet("¸íÁÖ ±Í½Å»ì", WINSIZEX / 2 - 260, 230);
	_im->itemMakeSet("È£¶ûÀÌ µµº¹", WINSIZEX / 2 - 260, 280);
	_im->potionMakeSet("¾àÃÊ", WINSIZEX / 2 - 260, 330);
	_im->potionMakeSet("¸¶¹ýÀÇ ¹°¾à", WINSIZEX / 2 - 260, 380);

}

void shop::buyItem()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		
		IMAGEMANAGER->findImage("¼¥UI¹öÆ°")->setFrameY(1);
		for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
		{
			if (_index == i)
			{
				if (_buyNum == 0) break;

				if (_pm->getTagMoney().money < _im->getPItem()->getVItem()[i].cost) break;
				_pm->getItemValue(_im->getPItem()->getVItem()[i].name);
				_pm->setMoney(_im->getPItem()->getVItem()[i].cost);
				_buyNum--;
			}
		}

		for (int i = 0; i < _im->getPortion()->getVPotion().size(); ++i)
		{
			if (_index == i + _im->getPItem()->getVItem().size())
			{
				while (_buyNum > 0)
				{
					if (_pm->getTagMoney().money < _im->getPortion()->getVPotion()[i].cost) break;
					_pm->getItemValue(_im->getPortion()->getVPotion()[i].name);
					_pm->setMoney(_im->getPortion()->getVPotion()[i].cost);
					_buyNum--;
				}
			}
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RETURN)) IMAGEMANAGER->findImage("¼¥UI¹öÆ°")->setFrameY(0);
}
