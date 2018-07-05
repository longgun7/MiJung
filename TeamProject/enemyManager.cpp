#include "stdafx.h"
#include "enemyManager.h"
#include "playerManager.h"

HRESULT enemyManager::init()
{
	_randNum = RND->getFromIntTo(1, 5);
	_enemyIndex = RND->getFromIntTo(1, 4);



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
		setEnmey(WINSIZEX/2+200,50);
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{

		_enemyIndex = 2;
		setEnmey(WINSIZEX / 2 + 200, 100);
	}

	if (KEYMANAGER->isOnceKeyDown('V'))
	{

		_enemyIndex = 3;
		setEnmey(WINSIZEX / 2 + 200, 150);
	}

	if (KEYMANAGER->isOnceKeyDown('V'))
	{

		_enemyIndex = 4;
		setEnmey(WINSIZEX / 2 + 200, 200);
	}

	if (KEYMANAGER->isOnceKeyDown('B'))
	{

		_enemyIndex = 5;
		setEnmey(WINSIZEX / 2 + 200, 250);
	}

	if (KEYMANAGER->isOnceKeyDown('N'))
	{

		_enemyIndex = 6;
		setEnmey(WINSIZEX / 2 + 200, 300);
	}

	if (KEYMANAGER->isOnceKeyDown('M'))
	{

		_enemyIndex = 7;
		setEnmey(WINSIZEX / 2 + 200, 350);
	}

	if (KEYMANAGER->isOnceKeyDown('K'))
	{

		_enemyIndex = 8;
		setEnmey(WINSIZEX / 2 + 200, 400);
	}

	if (KEYMANAGER->isOnceKeyDown('L'))
	{

		_enemyIndex = 9;
		setEnmey(WINSIZEX / 2 + 200, 450);
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

void enemyManager::setEnmey(float x, float y)
{
	switch (_enemyIndex)
	{

	case 1:
		spearMan* enemy1;
		enemy1 = new spearMan;
		enemy1->init(x, y);

		_vEnemy.push_back(enemy1);
	break;

	case 2:
		kungpu* enemy2;
		enemy2 = new kungpu;
		enemy2->init(x, y);

		_vEnemy.push_back(enemy2);
	break;
	case 3:
		spirit * enemy3;
		enemy3 = new spirit;
		enemy3->init(x, y);

		_vEnemy.push_back(enemy3);
	break;

	case 4:
		bat * enemy4;
		enemy4 = new bat;
		enemy4->init(x, y);

		_vEnemy.push_back(enemy4);
	break;

	case 5:
		snake * enemy5;
		enemy5 = new snake;
		enemy5->init(x, y);

		_vEnemy.push_back(enemy5);
	break;

	case 6:
		wildboar * enemy6;
		enemy6 = new wildboar;
		enemy6->init(x, y);

		_vEnemy.push_back(enemy6);
	break;

	case 7:
		skeleton * enemy7;
		enemy7 = new skeleton;
		enemy7->init(x, y);

		_vEnemy.push_back(enemy7);
	break;

	case 8:
		skeletonMage * enemy8;
		enemy8 = new skeletonMage;
		enemy8->init(x, y);

		_vEnemy.push_back(enemy8);
	break;

	case 9:
		dragon * enemy9;
		enemy9 = new dragon;
		enemy9->init(x, y);

		_vEnemy.push_back(enemy9);
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
