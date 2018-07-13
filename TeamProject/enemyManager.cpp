#include "stdafx.h"
#include "enemyManager.h"
#include "playerManager.h"

HRESULT enemyManager::init()
{
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("데미지", "image/enemy/데미지.bmp", 70, 15, 10, 1, true, RGB(255, 0, 255), false);

	_ge = new gameEffect;
	_ge->init();

	_randAttack = 0;
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

	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		randEnemy();
	}
	if (KEYMANAGER->isToggleKey('F'))
	{
		hitPlayer();
	}

	if (KEYMANAGER->isOnceKeyDown('V'))
	{
		while (_vEnemy.size() > 0)
		{
			removeEnemy(0);
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
		
		int width = (_vEnemy[i]->getTagEnmey().rc.right - _vEnemy[i]->getTagEnmey().rc.left) / 2;									// width에 i번째 에너미의 X 중점값을 넣는다
		int height = (_vEnemy[i]->getTagEnmey().rc.bottom - _vEnemy[i]->getTagEnmey().rc.top) / 2;									// height에 i번째 에너미의 y 중점값을 넣는다

		_img->setX(_vEnemy[i]->getTagEnmey().rc.left + width);																		// 이미지의 setX는 가로크기
		_img->setY(_vEnemy[i]->getTagEnmey().rc.top + height);																		// 이미지의 setY는 세로크기

		if (_vEnemy[i]->getTagEnmey().direction == HIT)																				// 몬스터의 상태가 HIT면
		{
			int damage = _vEnemy[i]->getTagEnmey().damage;																			// damge에 i번째 에너미의 데미지를 넣어준다
			for (int i = 0; i <= 4; ++i)																							// i는 0 i가 4보다 같거나 작으면 ++i를 해준다
			{
				int f = pow(10,i);																									// 
				if (damage / f == 0) break;																							// 
				_img->frameRender(CAMERA->getCameraDC(), _img->getX() - (8 * i), _img->getY() + height, (damage / f) % 10, 0);		// 
			}
		}
		
		if (_vEnemy[i]->getTagEnmey().isDead == false && _vEnemy[i]->getTagEnmey().fadeCount >= 4)									// i번째 에너미가 죽고, i번째 에너미의 faceCount가 4와 같거나 크면
		{
			_ge->addMoney(_vEnemy[i]->getTagEnmey().rc.left + width, _vEnemy[i]->getTagEnmey().rc.top + height);					// gameEffect에 있는 addMoney함수를 호출한다

			_vEnemy[i]->setIsDead(true);																							// i번재 에너미의 isDead를 true로 바꿔준다
		}
		if (_vEnemy[i]->getTagEnmey().fadeCount >= 4 && _vEnemy[i]->getTagEnmey().fadeCount <= 150)									// 
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

		_vEnemy.push_back(enemy3);		// 벡터에 enemy3을 담는다

	break;

	case 4:								// _enemyIndex의 값이 4일 때
		bat * enemy4;					// bat을 enemy4란 이름으로 사용한다
		enemy4 = new bat;				// enemy4를 bat로 할당한다
		enemy4->init(x, y);				// x,y 좌표를 넣어준다
										
		_vEnemy.push_back(enemy4);		// 벡터에 enemy4를 담는다

	break;

	case 5:								// _enemyIndex의 값이 5일 때
		snake * enemy5;					// snake를 enemy5란 이름으로 사용한다
		enemy5 = new snake;				// enemy5를 snake로 할당한다
		enemy5->init(x, y);				// x, y 좌표를 넣어준다
										
		_vEnemy.push_back(enemy5);		// 벡터에 enemy5를 담는다

	break;

	case 6:								// _enemyIndex의 값이 6일 때
		wildboar * enemy6;				// wildboar을 enemy6이란 이름으로 사용한다
		enemy6 = new wildboar;			// enemy6을 wildboar로 할당한다
		enemy6->init(x, y);				// x, y 좌표를 넣어준다
										
		_vEnemy.push_back(enemy6);		// 벡터에 enemy6를 담는다

	break;

	case 7:								// _enemyIndex의 값이 7일 때
		skeleton * enemy7;				// skeleton를 enemy7이란 이름으로 사용한다
		enemy7 = new skeleton;			// enemy7을 skeleton으로 할당한다
		enemy7->init(x, y);				// x, y 좌표를 넣어준다
										
		_vEnemy.push_back(enemy7);		// 벡터에 enemy7을 담는다

	break;

	case 8:								// _enemyIndex의 값이 8일 떄
		skeletonMage * enemy8;			// skeletonMage를 enemy8이란 이름으로 사용한다
		enemy8 = new skeletonMage;		// enemy8을 skeletonMage로 할당한다
		enemy8->init(x, y);				// x, y 좌표를 넣어준다
										
		_vEnemy.push_back(enemy8);		// 벡터에 enemy8을 담는다

	break;

	case 9:								// _enemyIndex의 값이 9일 때
		dragon * enemy9;				// dargon을 enemy9란 이름으로 사용한다
		enemy9 = new dragon;			// enemy9를 dragon으로 할당한다
		enemy9->init(x, y);				// x, y 좌표를 넣어준다
										
		_vEnemy.push_back(enemy9);		// 벡터에 enemy9를 담는다

	break;

	case 10:							// _enemyIndex의 값이 10일 때
		boss * enemy10;					// boss를 enemy10이란 이름으로 사용한다
		enemy10 = new boss;				// enemy10을 boss로 할당한다
		enemy10->init(x, y);			// x, y 좌표를 넣어준다
										
		_vEnemy.push_back(enemy10);		// 벡터에 enemy10을 담는다

		break;
	}
}

void enemyManager::hitEnemy(int index, int damge)
{
	_vEnemy[index]->setHp(damge);						// 인덱스와 damge를 받아서 몇번째 에너미인지 넣어주고, setHp에 필요한 매개변수 값을 넣어준다
}

void enemyManager::hitPlayer()
{
	
	// 예외처리추가(민경), 에너미가 한마리도 없을때 이 함수는 실행되지 않는다.
	if (_vEnemy.size() <= 0) return;													// 벡터의 사이즈가 0보다 같거나 작으면 돌아가라

	if (_vEnemy[_hitIndex]->getTagEnmey().currentFrameX == 0 && _hitCount == 0)			// _hitIndex번째의 에너미의 현재 프레임 X가 0이고, _hitCount가 0일 떄
	{
		_vEnemy[_hitIndex]->setEnemyDirection(ATTACK);	// _hitIndex번째의 에너미 디렉션을 ATTACK로 바꿔준다
		_randAttack = RND->getInt(2);
	}
	
	if (_vEnemy[_hitIndex]->getTagEnmey().isAttack == true)								// _hitIndex번째의 에너미의 isAttack가 true일 때
	{
		
		if (_pm->getPlayer()->getAttribute().currentHp == 0 && _pm->getPlayer2()->getAttribute().currentHp > 0) _randAttack = 1;
		if (_pm->getPlayer2()->getAttribute().currentHp == 0 && _pm->getPlayer()->getAttribute().currentHp > 0) _randAttack = 0;
		
		
		if (_randAttack == 0)
		{
			_pm->getPlayer()->setPlayerDamage(_vEnemy[_hitIndex]->getTagEnmey().att);
			_hitTume = true;
			_vEnemy[_hitIndex]->setIsAttack(false);
		}
		
		if (_randAttack == 1)
		{
			_pm->getPlayer2()->setPlayerDamage(_vEnemy[_hitIndex]->getTagEnmey().att);
			_hitTume = true;
			_vEnemy[_hitIndex]->setIsAttack(false);
		}
			
												// _hitTume를 true로 만든다
	}

	if (_hitTume) ++_hitCount;							// _hitTume가 true일 때, ++_hitCount를 해준다

	if (_hitCount >= 90)								// _hitCount가 90하고 같거나 크면
	{
		_hitIndex++;									// _hitIndex++ 해준다
		_hitTume = false;								// _hitTume에 false를 넣어준다
		_hitCount = 0;									// _hitCount를 0으로 초기화한다
	}
	
	if (_hitIndex >= _vEnemy.size()) _hitIndex = 0;		// _hitIndex가 에너미 벡터의 사이즈보다 같거나 커질 경우 _hitIndex를 0으로 초기화한다

}

// 에너미들이 몇마리 나오는지, 좌표 설정
void enemyManager::randEnemy()
{
	_randNum = RND->getFromIntTo(1, 5);					// _randNum에 1 ~ 4까지의 랜덤한 값을 넣는다

	for (int i = 0; i < _randNum; i++)														// i는 0 i가 _randNum보다 작으면 i를 ++ 해준다
	{
		_enemyIndex = RND->getFromIntTo(1, 10);												// _enemyIndex에 1 ~ 10까지의 랜덤한 값을 받는다
																							
		if (_randNum == 1)																	// _randNum이 1일 때
		{																					
			setEnemy(WINSIZEX / 2 + 300, PLAYMAPSIZEY / 2);									// setEnemy(float x, float y) 매개변수에 값을 넣어준다
		}	

		if (_randNum == 2)																	// _randNum이 2일 때
		{																					
			setEnemy((WINSIZEX / 2 + 200) + (i * 30), (PLAYMAPSIZEY / 3) * (i + 1));		// setEnemy(float x, float y) 매개변수에 값을 넣어준다
		}	

		if (_randNum == 3)																	// _randNum이 3일 때
		{																					
			setEnemy((WINSIZEX / 2 + 200) + (i * 30), (PLAYMAPSIZEY / 4) * (i + 1));		// setEnemy(float x, float y) 매개변수에 값을 넣어준다
		}	

		if (_randNum == 4)																	// _randNum이 4일 때
		{																					
			if (i == 0 || i == 3)															// i의 값이 0이거나 3일 때
			{																				
				setEnemy(WINSIZEX / 2 + 200, (PLAYMAPSIZEY / 5) * (i + 1));					// setEnemy(float x, float y) 매개변수에 값을 넣어준다
			}						

			if (i == 1 || i == 2)															// i의 값이 1이거나 2일 때
			{																				
				setEnemy((WINSIZEX / 2 + 200) - 30, (PLAYMAPSIZEY / 5) * (i + 1));			// setEnemy(float x, float y) 매개변수에 값을 넣어준다
			}
		}
	}
}

void enemyManager::removeEnemy(int arrNum)
{
	_vEnemy.erase(_vEnemy.begin() + arrNum);	// arrNum번 째 벡터를 지워준다
}

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}
