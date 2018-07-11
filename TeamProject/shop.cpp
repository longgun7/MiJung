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
	buyItem();
}

void shop::render(void)
{
	_im->render();
}

void shop::fontUI()
{
	HFONT font, ofont;

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	char str5[] = "������";
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 160,WINSIZEY/6,str5, strlen(str5));
	char str6[] = "���Լ�";
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 160, WINSIZEY / 2 - 140, str6, strlen(str6));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

	char str2[128];
	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
	{
		// �� ������ �̸� ǥ��
		string str1 = _im->getPItem()->getVItem()[i].name;
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + i * 50, str1.c_str(), strlen(str1.c_str()));
		// �� ������ ���� ǥ��
		sprintf_s(str2, "%d", _im->getPItem()->getVItem()[i].cost);
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 50, 120 + i * 50, str2, strlen(str2));

		if (PtInRect(&_im->getPItem()->getVItem()[i].rc, _ptMouse))
		{
			sprintf_s(str2, "%dG", _im->getPItem()->getVItem()[i].cost*_buyNum);
			TextOut(CAMERA->getCameraDC(), WINSIZEX - 280, WINSIZEY / 3 + 40, str2, strlen(str2));
		}
		else _totalNum = 0;
	}

	for (int i = 0; i < _im->getPortion()->getVPotion().size(); ++i)
	{
		// �� ���� �̸� ǥ��
		string str1 = _im->getPortion()->getVPotion()[i].name;
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
			str1.c_str(), strlen(str1.c_str()));
		// �� ���� ���� ǥ��
		sprintf_s(str2, "%d", _im->getPortion()->getVPotion()[i].cost);
		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 + 50, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
			str2, strlen(str2));

		if (PtInRect(&_im->getPortion()->getVPotion()[i].rc, _ptMouse))
		{
	
			if (_im->getPortion()->getVPotion()[i].name == "����")
			{

				sprintf_s(str2, "%d", _pm->getHpPoIndex());
				_totalNum = _pm->getHpPoIndex() + _buyNum;

			}

			if (_im->getPortion()->getVPotion()[i].name == "������ ����")
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
	_im->itemMakeSet("���ξƼ���", WINSIZEX / 2 - 260, 130);
	_im->itemMakeSet("��Ÿ�� ����", WINSIZEX / 2 - 260, 180);
	_im->itemMakeSet("���� �ͽŻ�", WINSIZEX / 2 - 260, 230);
	_im->itemMakeSet("ȣ���� ����", WINSIZEX / 2 - 260, 280);
	_im->potionMakeSet("����", WINSIZEX / 2 - 260, 330);
	_im->potionMakeSet("������ ����", WINSIZEX / 2 - 260, 380);
}

void shop::buyItem()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
		{
			if (PtInRect(&_im->getPItem()->getVItem()[i].rc, _ptMouse))
			{
				while (_buyNum > 0)
				{
					if (_pm->getTagMoney().money < _im->getPItem()->getVItem()[i].cost) break;
					_pm->getItemValue(_im->getPItem()->getVItem()[i].name);
					_pm->setMoney(_im->getPItem()->getVItem()[i].cost);
					_buyNum--;
				}
			}
		}

		for (int i = 0; i < _im->getPortion()->getVPotion().size(); ++i)
		{
			if (PtInRect(&_im->getPortion()->getVPotion()[i].rc, _ptMouse))
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
}
