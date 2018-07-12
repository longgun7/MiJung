#include "stdafx.h"
#include "enemyManager.h"
#include "playerManager.h"

HRESULT enemyManager::init()
{
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("������", "image/enemy/������.bmp", 70, 15, 10, 1, true, RGB(255, 0, 255), false);

	_ge = new gameEffect;
	_ge->init();

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
	if (KEYMANAGER->isToggleKey('F'))					// ZŰ�� ������
	{
		hitPlayer();									// hitPlayer �Լ��� ȣ���Ѵ�
	}
	if (KEYMANAGER->isOnceKeyDown('V'))						// VŰ�� ������
	{
		while (_vEnemy.size() > 0)
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

	for (int i = 0; i < _vEnemy.size(); ++i)	// i�� 0 i�� ���� ������� ������� ++i�� ���ش�
	{
		
		int damage = _vEnemy[i]->getTagEnmey().damage;												// dagme�� i��° ������ �������� �־��ش�															
		int width = (_vEnemy[i]->getTagEnmey().rc.right - _vEnemy[i]->getTagEnmey().rc.left) / 2;	// width�� i��° ���ʹ��� x ������ �ִ´�
		int height = (_vEnemy[i]->getTagEnmey().rc.bottom - _vEnemy[i]->getTagEnmey().rc.top) / 2;	// height�� i��° ���ʹ��� y ������ �ִ´�
		_img->setX(_vEnemy[i]->getTagEnmey().rc.left + width);										// img�� setX�� i��° ���ʹ��� x ������ �ִ´�
		_img->setY(_vEnemy[i]->getTagEnmey().rc.top + height);										// img�� setY�� i��° ���ʹ��� y ������ �ִ´�

		if (_vEnemy[i]->getTagEnmey().direction == HIT)																										// 
		{
			_img->frameRender(CAMERA->getCameraDC(), _img->getX() + width / 2, _img->getY() + height - 10, (damage % 10), 0);								// 

			if (damage > 10) _img->frameRender(CAMERA->getCameraDC(), _img->getX() + width / 2 + 8, _img->getY() + height - 10, (damage / 10) % 10, 0);		// 
		}

		if (_vEnemy[i]->getTagEnmey().isDead == false && _vEnemy[i]->getTagEnmey().fadeCount >= 4)															// 
		{
			_ge->addMoney(_vEnemy[i]->getTagEnmey().rc.left + width, _vEnemy[i]->getTagEnmey().rc.top + height);											// 

			_vEnemy[i]->setIsDead(true);																													// 
		}

		if (_vEnemy[i]->getTagEnmey().fadeCount >= 4 && _vEnemy[i]->getTagEnmey().fadeCount <= 150)															// 
		{
			int cost = _vEnemy[i]->getTagEnmey().dropGold;

			_img->frameRender(CAMERA->getCameraDC(), _img->getX()+10, _img->getY(), (cost % 10), 0);
			if (cost >=10) _img->frameRender(CAMERA->getCameraDC(), _img->getX() + 2, _img->getY(), (cost / 10) % 10, 0);
			if (cost >= 100) _img->frameRender(CAMERA->getCameraDC(), _img->getX() - 6, _img->getY(), (cost / 100) % 10, 0);
			if (cost >= 1000) _img->frameRender(CAMERA->getCameraDC(), _img->getX() - 14, _img->getY(), (cost / 1000) % 10, 0);
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

		_vEnemy.push_back(enemy3);		// ���Ϳ� enemy3�� ��´�

	break;

	case 4:								// _enemyIndex�� ���� 4�� ��
		bat * enemy4;					// bat�� enemy4�� �̸����� ����Ѵ�
		enemy4 = new bat;				// enemy4�� bat�� �Ҵ��Ѵ�
		enemy4->init(x, y);				// x,y ��ǥ�� �־��ش�
										
		_vEnemy.push_back(enemy4);		// ���Ϳ� enemy4�� ��´�

	break;

	case 5:								// _enemyIndex�� ���� 5�� ��
		snake * enemy5;					// snake�� enemy5�� �̸����� ����Ѵ�
		enemy5 = new snake;				// enemy5�� snake�� �Ҵ��Ѵ�
		enemy5->init(x, y);				// x, y ��ǥ�� �־��ش�
										
		_vEnemy.push_back(enemy5);		// ���Ϳ� enemy5�� ��´�

	break;

	case 6:								// _enemyIndex�� ���� 6�� ��
		wildboar * enemy6;				// wildboar�� enemy6�̶� �̸����� ����Ѵ�
		enemy6 = new wildboar;			// enemy6�� wildboar�� �Ҵ��Ѵ�
		enemy6->init(x, y);				// x, y ��ǥ�� �־��ش�
										
		_vEnemy.push_back(enemy6);		// ���Ϳ� enemy6�� ��´�

	break;

	case 7:								// _enemyIndex�� ���� 7�� ��
		skeleton * enemy7;				// skeleton�� enemy7�̶� �̸����� ����Ѵ�
		enemy7 = new skeleton;			// enemy7�� skeleton���� �Ҵ��Ѵ�
		enemy7->init(x, y);				// x, y ��ǥ�� �־��ش�
										
		_vEnemy.push_back(enemy7);		// ���Ϳ� enemy7�� ��´�

	break;

	case 8:								// _enemyIndex�� ���� 8�� ��
		skeletonMage * enemy8;			// skeletonMage�� enemy8�̶� �̸����� ����Ѵ�
		enemy8 = new skeletonMage;		// enemy8�� skeletonMage�� �Ҵ��Ѵ�
		enemy8->init(x, y);				// x, y ��ǥ�� �־��ش�
										
		_vEnemy.push_back(enemy8);		// ���Ϳ� enemy8�� ��´�

	break;

	case 9:								// _enemyIndex�� ���� 9�� ��
		dragon * enemy9;				// dargon�� enemy9�� �̸����� ����Ѵ�
		enemy9 = new dragon;			// enemy9�� dragon���� �Ҵ��Ѵ�
		enemy9->init(x, y);				// x, y ��ǥ�� �־��ش�
										
		_vEnemy.push_back(enemy9);		// ���Ϳ� enemy9�� ��´�

	break;

	case 10:							// _enemyIndex�� ���� 10�� ��
		boss * enemy10;					// boss�� enemy10�̶� �̸����� ����Ѵ�
		enemy10 = new boss;				// enemy10�� boss�� �Ҵ��Ѵ�
		enemy10->init(x, y);			// x, y ��ǥ�� �־��ش�
										
		_vEnemy.push_back(enemy10);		// ���Ϳ� enemy10�� ��´�

		break;
	}
}

void enemyManager::hitEnemy(int index, int damge)
{
	_vEnemy[index]->setHp(damge);						// �ε����� damge�� �޾Ƽ� ���° ���ʹ����� �־��ְ�, setHp�� �ʿ��� �Ű����� ���� �־��ش�
}

void enemyManager::hitPlayer()
{
	// ����ó���߰�(�ΰ�), ���ʹ̰� �Ѹ����� ������ �� �Լ��� ������� �ʴ´�.
	if (_vEnemy.size() <= 0) return;													// ������ ����� 0���� ���ų� ������ ���ư���

	if (_vEnemy[_hitIndex]->getTagEnmey().currentFrameX == 0 && _hitCount == 0)			// _hitIndex��°�� ���ʹ��� ���� ������ X�� 0�̰�, _hitCount�� 0�� ��
	{
		_vEnemy[_hitIndex]->setEnemyDirection(ATTACK);									// _hitIndex��°�� ���ʹ� �𷺼��� ATTACK�� �ٲ��ش�
	}

	if (_vEnemy[_hitIndex]->getTagEnmey().isAttack == true)								// _hitIndex��°�� ���ʹ��� isAttack�� true�� ��
	{
		_pm->getPlayer()->setPlayerDamage(_vEnemy[_hitIndex]->getTagEnmey().att);		// �÷��̾� �Ŵ����� getPlayer�� �����Ͽ� setPlayerDamge�� �ִ� �Ű������� ���� _hitIndex��°�� ���ʹ��� ���������� �ִ´�
		_hitTume = true;																// _hitTume�� true�� �����
		_vEnemy[_hitIndex]->setIsAttack(false);											// _hitCount��° ���ʹ��� isAttack�� false�� �����
		
	}

	if (_hitTume) ++_hitCount;							// _hitTume�� true�� ��, ++_hitCount�� ���ش�

	if (_hitCount >= 90)								// _hitCount�� 90�ϰ� ���ų� ũ��
	{
		_hitIndex++;									// _hitIndex++ ���ش�
		_hitTume = false;								// _hitTume�� false�� �־��ش�
		_hitCount = 0;									// _hitCount�� 0���� �ʱ�ȭ�Ѵ�
	}
	
	if (_hitIndex >= _vEnemy.size()) _hitIndex = 0;		// _hitIndex�� ���ʹ� ������ ������� ���ų� Ŀ�� ��� _hitIndex�� 0���� �ʱ�ȭ�Ѵ�
}

// ���ʹ̵��� ��� ��������, ��ǥ ����
void enemyManager::randEnemy()
{
	_randNum = RND->getFromIntTo(1, 5);					// _randNum�� 1 ~ 4������ ������ ���� �ִ´�

	for (int i = 0; i < _randNum; i++)														// i�� 0 i�� _randNum���� ������ i�� ++ ���ش�
	{
		_enemyIndex = RND->getFromIntTo(1, 11);												// _enemyIndex�� 1 ~ 10������ ������ ���� �޴´�
																							
		if (_randNum == 1)																	// _randNum�� 1�� ��
		{																					
			setEnemy(WINSIZEX / 2 + 300, PLAYMAPSIZEY / 2);									// setEnemy(float x, float y) �Ű������� ���� �־��ش�
		}																					
		if (_randNum == 2)																	// _randNum�� 2�� ��
		{																					
			setEnemy((WINSIZEX / 2 + 200) + (i * 30), (PLAYMAPSIZEY / 3) * (i + 1));		// setEnemy(float x, float y) �Ű������� ���� �־��ش�
		}																					
		if (_randNum == 3)																	// _randNum�� 3�� ��
		{																					
			setEnemy((WINSIZEX / 2 + 200) + (i * 30), (PLAYMAPSIZEY / 4) * (i + 1));		// setEnemy(float x, float y) �Ű������� ���� �־��ش�
		}																					
		if (_randNum == 4)																	// _randNum�� 4�� ��
		{																					
			if (i == 0 || i == 3)															// i�� ���� 0�̰ų� 3�� ��
			{																				
				setEnemy(WINSIZEX / 2 + 200, (PLAYMAPSIZEY / 5) * (i + 1));					// setEnemy(float x, float y) �Ű������� ���� �־��ش�
			}																				
			if (i == 1 || i == 2)															// i�� ���� 1�̰ų� 2�� ��
			{																				
				setEnemy((WINSIZEX / 2 + 200) - 30, (PLAYMAPSIZEY / 5) * (i + 1));			// setEnemy(float x, float y) �Ű������� ���� �־��ش�
			}
		}
	}
}

void enemyManager::removeEnemy(int arrNum)
{
	_vEnemy.erase(_vEnemy.begin() + arrNum);	// arrNum�� ° ���͸� �����ش�
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
