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

	for (int i = 0; i < 4; ++i)
	{
		_weapon->makeItem(i, 0, 100 + 100 * i, 100);	
		_weapon->makeItem(i, 2, 500 + 100 * i, 100);
	}

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	_weapon->update();
}

void itemManager::render()
{
	_weapon->render();
	for (int i = 0; i < 8; ++i)
	{
		char str[128];
		sprintf_s(str, "%d", _weapon->getVItem()[i].atk);
		TextOut(getMemDC(), 100 + 100 * i, 150, str, strlen(str));
	}
	
}
