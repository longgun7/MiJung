#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"
#include "player2.h"

HRESULT enemyManager::init()
{
	_randNum = 4;

	for (int i = 0; i < _randNum; i++)
	{
		spearMan* spearMans;
		spearMans = new spearMan;

		if (_randNum == 1)
		{
			spearMans->init(WINSIZEX / 2 + 300, PLAYMAPSIZEY / 2);
		}
		if (_randNum == 2)
		{
			spearMans->init((WINSIZEX / 2 + 200) + (i * 50), (PLAYMAPSIZEY / 3) * (i + 1));
		}
		if (_randNum == 3)
		{
			spearMans->init((WINSIZEX / 2 + 200) + (i * 50), (PLAYMAPSIZEY / 4) * (i + 1));
		}
		if (_randNum == 4)
		{
			if (i == 0 || i == 3)
			{
				spearMans->init(WINSIZEX / 2 + 200, (PLAYMAPSIZEY / 5) * (i + 1));
			}
			if (i == 1 || i == 2)
			{
				spearMans->init((WINSIZEX / 2 + 200) - 50, (PLAYMAPSIZEY / 5) * (i + 1));
			}
		}

		_vSpearMan.push_back(spearMans);
	}

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

	for (_viSpearMan = _vSpearMan.begin(); _viSpearMan != _vSpearMan.end(); ++_viSpearMan)
	{
		(*_viSpearMan)->update();
	}

	/*
	if(스테이지3으로 가는 씬이 나오면 && stage == 3)
	{
		setSkeleton();
	}
	*/
}

void enemyManager::render()
{
	//for (_viFildSkeleton = _vFildSkeleton.begin(); _viFildSkeleton != _vFildSkeleton.end(); ++_viFildSkeleton)
	//{
	//	(*_viFildSkeleton)->render();
	//}

	for (_viSpearMan = _vSpearMan.begin(); _viSpearMan != _vSpearMan.end(); ++_viSpearMan)
	{
		(*_viSpearMan)->render();
	}
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
