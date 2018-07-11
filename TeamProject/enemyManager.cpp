#include "stdafx.h"
#include "enemyManager.h"
#include "playerManager.h"

HRESULT enemyManager::init()
{
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

	if (KEYMANAGER->isOnceKeyDown('A'))					// A키를 누르면
	{
		randEnemy();									// randEnemy 함수를 호출한다
	}

	if (KEYMANAGER->isToggleKey('F'))					// Z키를 누르면
	{
		hitPlayer();									// hitPlayer 함수를 호출한다
	}

	if (KEYMANAGER->isOnceKeyDown('V'))
	{
		while (_vEnemy.size() > 0)										// V키를 누르면
		{
			removeEnemy(0);								// 벡터 사이즈만큼 removeEnemy 함수를 호출한다
		}
		
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
		sprintf_s(str, "%d:%d", _vEnemy[i]->getTagEnmey().currentFrameX, _vEnemy[i]->getTagEnmey().maxAttackFrameX);
		TextOut(getMemDC(), 100 * i + WINSIZEX/2 + 50*i, 100, str, strlen(str));
	}
	char str[128];
	sprintf_s(str, "%d", _hitIndex);
	TextOut(getMemDC(), WINSIZEX / 2 + 50, 50, str, strlen(str));
}

void enemyManager::setEnemy(float x, float y)
{
	switch (_enemyIndex)				// 조건은 _enemyIndex
	{

	case 1:								// _enemyIndex의 값이 1일 떄
		spearMan* enemy1;				// spearMan을 enemy1란 이름으로 사용한다
		enemy1 = new spearMan;			// enemy1을 spearMan로 할당한다
		enemy1->init(x, y);				// x, y좌표를 넣어준다

		_vEnemy.push_back(enemy1);		// 벡터에 enemy1을 담는다

	break;

	case 2:								// _enemyIndex의 값이 2일 때			
		kungpu* enemy2;					// kungpu을 enemy2란 이름으로 사용한다
		enemy2 = new kungpu;			// enemy2을 kungpu로 할당한다
		enemy2->init(x, y);				// x, y좌표를 넣어준다

		_vEnemy.push_back(enemy2);		// 벡터에 enemy2을 담는다

	break;

	case 3:								// _enemyIndex의 값이 3일 때
		spirit * enemy3;				// spirit을 enemy3란 이름으로 사용한다
		enemy3 = new spirit;			// enemy3을 spirit로 할당한다
		enemy3->init(x, y);				// x, y좌표를 넣어준다

		_vEnemy.push_back(enemy3);		// 벡터에 ebemy3을 담는다

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

	case 10:
		boss * enemy10;
		enemy10 = new boss;
		enemy10->init(x, y);

		_vEnemy.push_back(enemy10);

		break;
	}
}

void enemyManager::hitEnemy(int index, int damge)
{
	_vEnemy[index]->setHp(damge);
}

void enemyManager::hitPlayer()
{
	if (_vEnemy[_hitIndex]->getTagEnmey().isAttack == true && _vEnemy[_hitIndex]->getTagEnmey().currentFrameX == 0)
	{
		_pm->getPlayer()->setPlayerDamage(_vEnemy[_hitIndex]->getTagEnmey().att);
		_vEnemy[_hitIndex]->setEnemyDirection(ATTACK);
	}

	if (_vEnemy[_hitIndex]->getTagEnmey().currentFrameX >= _vEnemy[_hitIndex]->getTagEnmey().maxAttackFrameX && _vEnemy[_hitIndex]->getTagEnmey().direction == STAND)
	{
		_hitIndex++;
		if (_hitIndex >= _vEnemy.size())
		{
			_hitIndex = 0;
		}	
	}

	

	

	
}

void enemyManager::randEnemy()
{
	_randNum = RND->getFromIntTo(1, 5);

	for (int i = 0; i < _randNum; i++)
	{
		_enemyIndex = RND->getFromIntTo(1, 11);

		if (_randNum == 1)
		{
			setEnemy(WINSIZEX / 2 + 300, PLAYMAPSIZEY / 2);
		}
		if (_randNum == 2)
		{
			setEnemy((WINSIZEX / 2 + 200) + (i * 30), (PLAYMAPSIZEY / 3) * (i + 1));
		}
		if (_randNum == 3)
		{
			setEnemy((WINSIZEX / 2 + 200) + (i * 30), (PLAYMAPSIZEY / 4) * (i + 1));
		}
		if (_randNum == 4)
		{
			if (i == 0 || i == 3)
			{
				setEnemy(WINSIZEX / 2 + 200, (PLAYMAPSIZEY / 5) * (i + 1));
			}
			if (i == 1 || i == 2)
			{
				setEnemy((WINSIZEX / 2 + 200) - 30, (PLAYMAPSIZEY / 5) * (i + 1));
			}
		}
	}
}

void enemyManager::removeEnemy(int arrNum)
{
	_vEnemy.erase(_vEnemy.begin() + arrNum);
}

void enemyManager::setMotion(DIRECTION direction)
{
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
