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

	IMAGEMANAGER->addFrameImage("샵UI버튼", "image/ui/UI버튼.bmp", 450, 75, 18, 3, false, RGB(0, 0, 0));
	IMAGEMANAGER->findImage("샵UI버튼")->setFrameX(7);
	IMAGEMANAGER->findImage("샵UI버튼")->setFrameY(0);
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
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _buyNum > 0)
	{
		_buyNum--;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _totalNum < 10 && _buyNum < 10)
	{
		++_buyNum;
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

	buyItem();
}

void shop::render(void)
{
	_im->render();
	IMAGEMANAGER->findImage("샵UI버튼")->frameRender(CAMERA->getCameraDC(), 190, 115 + (_index * 50));
}

void shop::fontUI()
{
	HFONT font, ofont;

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	char str5[] = "소지수";
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 160,WINSIZEY/6,str5, strlen(str5));
	char str6[] = "구입수";
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 160, WINSIZEY / 2 - 140, str6, strlen(str6));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

	char str2[128];
	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
	{
		// 샵 아이템 이름 표시
		string str1 = _im->getPItem()->getVItem()[i].name;
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + i * 50, str1.c_str(), strlen(str1.c_str()));
		// 샵 아이템 가격 표시
		sprintf_s(str2, "%d", _im->getPItem()->getVItem()[i].cost);
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 50, 120 + i * 50, str2, strlen(str2));

		if (_index == i)
		{
			sprintf_s(str2, "%dG", _im->getPItem()->getVItem()[i].cost*_buyNum);
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 280, WINSIZEY / 3 + 40, str2, strlen(str2));
		}
		else _totalNum = 0;
	}

	for (int i = 0; i < _im->getPortion()->getVPotion().size(); ++i)
	{
		// 샵 포션 이름 표시
		string str1 = _im->getPortion()->getVPotion()[i].name;
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
			str1.c_str(), strlen(str1.c_str()));
		// 샵 포션 가격 표시
		sprintf_s(str2, "%d", _im->getPortion()->getVPotion()[i].cost);
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 50, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
			str2, strlen(str2));

		if (_index == i + _im->getPItem()->getVItem().size())
		{
	
			if (_im->getPortion()->getVPotion()[i].name == "약초")
			{

				sprintf_s(str2, "%d", _pm->getHpPoIndex());
				_totalNum = _pm->getHpPoIndex() + _buyNum;

			}

			if (_im->getPortion()->getVPotion()[i].name == "마법의 물약")
			{
				sprintf_s(str2, "%d", _pm->getMpPoIndex());
				_totalNum = _pm->getMpPoIndex() + _buyNum;
			}

			TextOut(CAMERA->getCameraDC(), WINSIZEX - 240, WINSIZEY / 6 + 40, str2, strlen(str2));
			sprintf_s(str2, "%dG", _im->getPortion()->getVPotion()[i].cost*_buyNum);
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 280, WINSIZEY / 3 + 40, str2, strlen(str2));

			if (_totalNum > 10) _buyNum--;
		}
		else _totalNum = 0;
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
	_im->itemMakeSet("마인아수라", WINSIZEX / 2 - 260, 130);
	_im->itemMakeSet("불타는 마검", WINSIZEX / 2 - 260, 180);
	_im->itemMakeSet("명주 귀신살", WINSIZEX / 2 - 260, 230);
	_im->itemMakeSet("호랑이 도복", WINSIZEX / 2 - 260, 280);
	_im->potionMakeSet("약초", WINSIZEX / 2 - 260, 330);
	_im->potionMakeSet("마법의 물약", WINSIZEX / 2 - 260, 380);

}

void shop::buyItem()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		IMAGEMANAGER->findImage("샵UI버튼")->setFrameY(1);
		for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
		{
			if (_index == i)
			{
				if (_im->getPItem()->getVItem()[i].frameY == 0)
				{
					if (_im->getPItem()->getVItem()[i].frameX < 6)
					{
						for (int j = 0; j < _pm->getVA_WeapInven().size(); ++j)
						{
							if (_pm->getVA_WeapInven()[j].name == _im->getPItem()->getVItem()[i].name) _purchase = false;
						}
					}

					if (_im->getPItem()->getVItem()[i].frameX >= 6)
					{
						for (int j = 0; j < _pm->getVA_ArmorInven().size(); ++j)
						{
							if (_pm->getVA_ArmorInven()[j].name == _im->getPItem()->getVItem()[i].name) _purchase = false;
						}
					}
				}

				if (_im->getPItem()->getVItem()[i].frameY == 2)
				{
					if (_im->getPItem()->getVItem()[i].frameX < 6)
					{
						for (int j = 0; j < _pm->getVS_WeapInven().size(); ++j)
						{
							if (_pm->getVS_WeapInven()[j].name == _im->getPItem()->getVItem()[i].name) _purchase = false;
						}
					}

					if (_im->getPItem()->getVItem()[i].frameX >= 6)
					{
						for (int j = 0; j < _pm->getVS_ArmorInven().size(); ++j)
						{
							if (_pm->getVS_ArmorInven()[j].name == _im->getPItem()->getVItem()[i].name) _purchase = false;
						}
					}
				}
				
				if (_purchase == false) break;

				if (_buyNum >= 1)
				{
					if (_pm->getTagMoney().money < _im->getPItem()->getVItem()[i].cost) break;
					_pm->getItemValue(_im->getPItem()->getVItem()[i].name);
					_pm->setMoney(_im->getPItem()->getVItem()[i].cost);
					_buyNum--;
					_purchase = true;
				}
				
				
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
	if (KEYMANAGER->isOnceKeyUp(VK_RETURN)) IMAGEMANAGER->findImage("샵UI버튼")->setFrameY(0);
}
