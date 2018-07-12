#include "stdafx.h"
#include "enemyManager.h"
#include "playerManager.h"

HRESULT enemyManager::init()
{
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("������", "image/enemy/������.bmp", 70, 15, 10, 1, true, RGB(255, 0, 255), false);

	_ge = new gameEffect;
	_ge->init();

	_x = _y = 0;
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
	if (KEYMANAGER->isOnceKeyDown('W'))					// AŰ�� ������
	{
		_ge->addMoney(WINSIZEX/2 + 200, WINSIZEY/2);									// randEnemy �Լ��� ȣ���Ѵ�
	}
	
	if (KEYMANAGER->isToggleKey('F'))					// ZŰ�� ������
	{
		hitPlayer();									// hitPlayer �Լ��� ȣ���Ѵ�
	}

	if (KEYMANAGER->isOnceKeyDown('V'))
	{
		while (_vEnemy.size() > 0)										// VŰ�� ������
		{
			removeEnemy(0);								// ���� �����ŭ removeEnemy �Լ��� ȣ���Ѵ�
		}
		
	}
	_ge->update();
}


void enemyManager::render()
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}

	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		
		int width = (_vEnemy[i]->getTagEnmey().rc.right - _vEnemy[i]->getTagEnmey().rc.left) / 2;
		int height = (_vEnemy[i]->getTagEnmey().rc.bottom - _vEnemy[i]->getTagEnmey().rc.top) / 2;
		_img->setX(_vEnemy[i]->getTagEnmey().rc.left + width);
		_img->setY(_vEnemy[i]->getTagEnmey().rc.top + height);

		if (_vEnemy[i]->getTagEnmey().direction == HIT)
		{
			int damage = _vEnemy[i]->getTagEnmey().damage;
			for (int i = 0; i <= 4; ++i)
			{
				int f = pow(10,i);
				if (damage / f == 0) break;
				_img->frameRender(CAMERA->getCameraDC(), _img->getX() - (8 * i), _img->getY() + height, (damage / f) % 10, 0);
			}
		}

		if (_vEnemy[i]->getTagEnmey().isDead == false && _vEnemy[i]->getTagEnmey().fadeCount >= 4)
		{

			_ge->addMoney(_vEnemy[i]->getTagEnmey().rc.left + width, _vEnemy[i]->getTagEnmey().rc.top + height);

			_vEnemy[i]->setIsDead(true);
		}

		if (_vEnemy[i]->getTagEnmey().fadeCount >= 4 && _vEnemy[i]->getTagEnmey().fadeCount <= 150)
		{
			int cost = _vEnemy[i]->getTagEnmey().dropGold;

			for (int i = 0; i < 5; ++i)
			{
				int f = pow(10, i);
				if (cost / f == 0) break;
				_img->frameRender(CAMERA->getCameraDC(), _img->getX() - (8 * i), _img->getY(), (cost / f) % 10, 0);
			}
		}
		
	}
	_ge->render();
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
	// ����ó���߰�(�ΰ�), ���ʹ̰� �Ѹ����� ������ �� �Լ��� ������� �ʴ´�.
	if (_vEnemy.size() <= 0) return;

	if (_vEnemy[_hitIndex]->getTagEnmey().currentFrameX == 0 && _hitCount == 0)
	{
		_vEnemy[_hitIndex]->setEnemyDirection(ATTACK);
	}

	if (_vEnemy[_hitIndex]->getTagEnmey().isAttack == true)
	{
		_pm->getPlayer()->setPlayerDamage(_vEnemy[_hitIndex]->getTagEnmey().att);
		_hitTume = true;
		_vEnemy[_hitIndex]->setIsAttack(false);
		
	}
	if (_hitTume) ++_hitCount;

	if (_hitCount >= 90)
	{
		_hitIndex++;
		_hitTume = false;
		_hitCount = 0;
	}
	
	if (_hitIndex >= _vEnemy.size()) _hitIndex = 0;

	
}

void enemyManager::randEnemy()
{
	_randNum = RND->getFromIntTo(1, 5);

	for (int i = 0; i < _randNum; i++)
	{
		_enemyIndex = RND->getFromIntTo(1,2);

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

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
