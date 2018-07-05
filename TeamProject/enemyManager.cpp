#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"
#include "player2.h"

HRESULT enemyManager::init()
{
	_randNum = RND->getFromIntTo(1, 5);
	_enemyIndex = RND->getFromIntTo(1, 4);

	//for (int i = 0; i < _randNum; i++)
	//{
	//	kungpu* kungpus;
	//	kungpus = new kungpu;

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

	//	_vSpearMan.push_back(kungpus);
	//}

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	//for (_viFildSkeleton = _vFildSkeleton.begin(); _viFildSkeleton != _vFildSkeleton.end(); ++_viFildSkeleton)
	//{
	//	(*_viFildSkeleton)->update();
	//}

	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->update();
	}

	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_enemyIndex = 1;
		setEnemy();
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_enemyIndex = 2;
		setEnemy();
	}
}

void enemyManager::render()
{
	//for (_viFildSkeleton = _vFildSkeleton.begin(); _viFildSkeleton != _vFildSkeleton.end(); ++_viFildSkeleton)
	//{
	//	(*_viFildSkeleton)->render();
	//}

	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}
}

void enemyManager::setEnemy()
{
	switch (_enemyIndex)
	{
	case 1:
		spearMan * enemy;
		enemy = new spearMan;
		enemy->init(WINSIZEX / 2 + 200, 200);

		_vEnemy.push_back(enemy);

		break;

	case 2:
		kungpu * enemy1;
		enemy1 = new kungpu;
		enemy1->init(WINSIZEX / 2 + 200, 400);

		_vEnemy.push_back(enemy1);

		break;

	case 3:
		spirit * enemy2;
		enemy2 = new spirit;
		enemy2->init(WINSIZEX / 2 + 200, 400);

		_vEnemy.push_back(enemy2);

		break;
	}
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
