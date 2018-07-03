#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"
#include "player2.h"

HRESULT enemyManager::init()
{
	setSpearMan();

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viSkeleton = _vSkeleton.begin(); _viSkeleton != _vSkeleton.end(); ++_viSkeleton)
	{
		(*_viSkeleton)->update();
	}
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
	for (_viSkeleton = _vSkeleton.begin(); _viSkeleton != _vSkeleton.end(); ++_viSkeleton)
	{
		(*_viSkeleton)->render();
	}
	for (_viSpearMan = _vSpearMan.begin(); _viSpearMan != _vSpearMan.end(); ++_viSpearMan)
	{
		(*_viSpearMan)->render();
	}
}

void enemyManager::setSkeleton()
{
	for (int i = 0; i < MAXSKELETON; i++)
	{
		_skeleton = new skeleton;										// _skeleton 할당
		_skeleton->init();												// _skeleton.init함수 호출

		_skeleton->setSkeleton(RND->getInt(1000), RND->getInt(750));	// 스켈레톤을 x : 0 ~ 1000, y : 0 ~ 750사이에 랜덤하게 뿌린다.

		_vSkeleton.push_back(_skeleton);								// 벡터에 담는다
	}
}

void enemyManager::setSpearMan()
{
	spearMan* _spearMan;
	_spearMan = new spearMan;
	_spearMan->init(WINSIZEX / 2, WINSIZEY / 2);

	_vSpearMan.push_back(_spearMan);
}

void enemyManager::hitDamge()
{
	//_ataho->
}

void enemyManager::hitSpearMan(int index, int damage)
{
	_vSpearMan[index]->setHitMotion(SPEAR_MAN_HIT);
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
