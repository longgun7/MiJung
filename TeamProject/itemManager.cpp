#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	_weapon = new item;
	_weapon->init(8);

	_potion = new item;
	_potion->init(1);
	for (int i = 0; i < 8; ++i)
	{
		_weapon->makeItem(i, 0, 100 + 100 * i, 100);
	}

	_potion->makepotion(0, 3, 100, 200);

	

	

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	_weapon->update();
	_potion->update();
}

void itemManager::render()
{
	_weapon->render();
	_potion->render();

	for (int i = 0; i < 8; ++i)
	{
		char str[128];
		sprintf_s(str, "%d", _weapon->getVItem()[i].atk);
		TextOut(getMemDC(), 100 + 100 * i, 150, str, strlen(str));
	}

	char str[128];
	sprintf_s(str, "%d", _potion->getVPotion()[0].mp);
	TextOut(getMemDC(), 100, 250, str, strlen(str));
	
}
