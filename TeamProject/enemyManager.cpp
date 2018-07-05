#include "stdafx.h"
#include "enemyManager.h"
#include "playerManager.h"

HRESULT enemyManager::init()
{
	_randNum = RND->getFromIntTo(1, 5);
	_enemyIndex = 0;
	//for (int i = 0; i < _randNum; i++)
	//{
	//	kungpu* kungpus;
	//	kungpus = new kungpu;
	//
	//	if (_randNum == 1)
	//	{
	//		kungpus->init(WINSIZEX / 2 + 300, PLAYMAPSIZEY / 2);
	//	}
	//	if (_randNum == 2)
	//	{
	//		kungpus->init((WINSIZEX / 2 + 200) + (i * 50), (PLAYMAPSIZEY / 3) * (i + 1));
	//	}
	//	if (_randNum == 3)
	//	{
	//		kungpus->init((WINSIZEX / 2 + 200) + (i * 50), (PLAYMAPSIZEY / 4) * (i + 1));
	//	}
	//	if (_randNum == 4)
	//	{
	//		if (i == 0 || i == 3)
	//		{
	//			kungpus->init(WINSIZEX / 2 + 200, (PLAYMAPSIZEY / 5) * (i + 1));
	//		}
	//		if (i == 1 || i == 2)
	//		{
	//			kungpus->init((WINSIZEX / 2 + 200) - 50, (PLAYMAPSIZEY / 5) * (i + 1));
	//		}
	//	}
	//
	//	_vSpearMan.push_back(kungpus);
	//}

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{

	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->update();
	}


	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_enemyIndex = 1;
		setEnmey();
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{

		_enemyIndex = 2;
		setEnmey();
	}
	
}


void enemyManager::render()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}

	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		char str[128];
		sprintf_s(str, "%d", _vEnemy[i]->getTagEnmey().att);
		TextOut(getMemDC(), 100 * i + WINSIZEX/2, 100, str, strlen(str));
	}
}

void enemyManager::setEnmey()
{
	switch (_enemyIndex)
	{

	case 1:
		spearMan* enemy;
		enemy = new spearMan;
		enemy->init(WINSIZEX / 2 + 200, 200);

		_vEnemy.push_back(enemy);
	break;

	case 2:
		kungpu* enemy1;
		enemy1 = new kungpu;
		enemy1->init(WINSIZEX / 2 + 200, 400);

		_vEnemy.push_back(enemy1);
	break;
	case 3:

	break;
	}
	
	
}

void enemyManager::hitEnemy(int index, int damage)
{
	_vEnemy[index]->setHp(damage);
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
