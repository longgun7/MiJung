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


	return S_OK;
}

void shop::release(void)
{
}

void shop::update(void)
{
}

void shop::render(void)
{
	_im->render();
}

void shop::fontUI()
{
	HFONT font, ofont;

	for (int i = 0; i < _im->getPItem()->getVItem().size(); ++i)
	{
		// �� ������ �̸� ǥ��
		string str1 = _im->getPItem()->getVItem()[i].name;
		font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
		ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
		SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
		SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + i * 50, str1.c_str(), strlen(str1.c_str()));
		SelectObject(CAMERA->getCameraDC(), ofont);
		DeleteObject(font);

		// �� ������ ���� ǥ��
		char str3[128];
		font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
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
		// �� ���� �̸� ǥ��
		string str2 = _im->getPortion()->getVPotion()[i].name;
		font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
		ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
		SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
		SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

		TextOut(CAMERA->getCameraDC(), WINSIZEX / 2 - 200, 120 + (_im->getPItem()->getVItem().size() + i) * 50,
			str2.c_str(), strlen(str2.c_str()));
		SelectObject(CAMERA->getCameraDC(), ofont);
		DeleteObject(font);

		// �� ���� ���� ǥ��
		char str4[128];
		font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
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
