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

	if (KEYMANAGER->isOnceKeyDown('A'))					// AŰ�� ������
	{
		randEnemy();									// randEnemy �Լ��� ȣ���Ѵ�
	}

	if (KEYMANAGER->isOnceKeyDown('Z'))					// ZŰ�� ������
	{
		hitPlayer();									// hitPlayer �Լ��� ȣ���Ѵ�
	}

	if (KEYMANAGER->isToggleKey('V'))
	{
		for (int i = 0; i < _vEnemy.size(); ++i)		// VŰ�� ������
		{
			removeEnemy(i);								// ���� �����ŭ removeEnemy �Լ��� ȣ���Ѵ�
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
		sprintf_s(str, "%d", _vEnemy[i]->getTagEnmey().att);
		TextOut(getMemDC(), 100 * i + WINSIZEX/2, 100, str, strlen(str));
	}
}

void enemyManager::setEnemy(float x, float y)
{
	switch (_enemyIndex)				// ������ _enemyIndex
	{

	case 1:								// _enemyIndex�� ���� 1�� ��
		spearMan* enemy1;				// spearMan�� enemy1�� �̸����� ����Ѵ�
		enemy1 = new spearMan;			// enemy1�� spearMan�� �Ҵ��Ѵ�
		enemy1->init(x, y);				// x, y��ǥ�� �־��ش�

		_vEnemy.push_back(enemy1);		// ���Ϳ� enemy1�� ��´�

	break;

	case 2:								// _enemyIndex�� ���� 2�� ��			
		kungpu* enemy2;					// kungpu�� enemy2�� �̸����� ����Ѵ�
		enemy2 = new kungpu;			// enemy2�� kungpu�� �Ҵ��Ѵ�
		enemy2->init(x, y);				// x, y��ǥ�� �־��ش�

		_vEnemy.push_back(enemy2);		// ���Ϳ� enemy2�� ��´�

	break;

	case 3:								// _enemyIndex�� ���� 3�� ��
		spirit * enemy3;				// spirit�� enemy3�� �̸����� ����Ѵ�
		enemy3 = new spirit;			// enemy3�� spirit�� �Ҵ��Ѵ�
		enemy3->init(x, y);				// x, y��ǥ�� �־��ش�

		_vEnemy.push_back(enemy3);		// ���Ϳ� ebemy3�� ��´�

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
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_pm->getPlayer()->setPlayerDamage(_vEnemy[i]->getTagEnmey().att);
		_pm->getPlayer2()->setPlayerDamage(_vEnemy[i]->getTagEnmey().att);
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
