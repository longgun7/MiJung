#include "stdafx.h"
#include "enemys.h"

// 창병
// 해당 에너미의 출현 장소 : 스테이지 1
HRESULT spearMan::init(float x, float y) 
{
	// 이미지 ~ 능력치 기본 설정 
	_enemy.img = IMAGEMANAGER->addFrameImage("창병", "image/enemy/창병.bmp", 576, 64, 4, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.hp = 10;
	_enemy.att = 10;
	_enemy.def = 10;
	_enemy.miss = 10;

	_enemy.count = 0;
	_enemy.deadCount = 0;
	_enemy.hitCount = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;

	_enemy.direction = STAND;

	_enemy.x = x;	// 함수의 매개변수를 통해 받아옴
	_enemy.y = y;	// 함수의 매개변수를 통해 받아옴

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

	return S_OK;
}

void spearMan::release()
{
}

void spearMan::update()
{
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_enemy.direction = ATTACK;
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_enemy.direction = HIT;
	}
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		_enemy.direction = DEAD;
	}

	motion();
}

void spearMan::render()
{
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void spearMan::motion()
{
	++_enemy.count;

	if (_enemy.count == 18)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX++;

			if (_enemy.currentFrameX == 2)
			{
				_enemy.direction = STAND;
			}
		}
		if (_enemy.direction == HIT)
		{
			_enemy.hitCount++;

			_enemy.currentFrameX = 3;

			if (_enemy.hitCount == 5)
			{
				_enemy.direction = STAND;

				_enemy.hitCount = 0;
			}
		}

		_enemy.count = 0;
	}

	if (_enemy.direction == DEAD)
	{
		_enemy.currentFrameX = 3;
	
		if (_enemy.fadeCount >= 6)
		{
			_enemy.alphaValue -= 5;

			if (_enemy.alphaValue <= 0)
			{
				_enemy.alphaValue = 0;
			}
		}
		else
		{
			_enemy.deadCount++;
		}
		if (_enemy.deadCount == 10)
		{
			if (_enemy.alphaValue == 255)
			{
				_enemy.alphaValue = 0;
		
				_enemy.fadeCount += 1;
			}
			else if(_enemy.alphaValue == 0)
			{
				_enemy.alphaValue = 255;
		
				_enemy.fadeCount += 1;
			}
		
			_enemy.deadCount = 0;
		}
	}
}

spearMan::spearMan()
{
}


spearMan::~spearMan()
{
}

// 쿵푸
// 해당 에너미의 출현 장소 : 스테이지 1
HRESULT kungpu::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("쿵푸", "image/enemy/쿵푸.bmp", 1215, 153, 9, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.hp = 10;
	_enemy.att = 10;
	_enemy.def = 10;
	_enemy.miss = 10;

	_enemy.count = 0;
	_enemy.deadCount = 0;
	_enemy.fadeCount = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.hitCount = 0;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());
	
	return S_OK;
}

void kungpu::release()
{
}

void kungpu::update()
{
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_enemy.direction = ATTACK;

		_enemy.randAttack = RND->getInt(3);

		if (_enemy.randAttack == 1)
		{
			_enemy.currentFrameX = 4;
		}
		if (_enemy.randAttack == 2)
		{
			_enemy.currentFrameX = 7;
		}
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_enemy.direction = HIT;
	}
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		_enemy.direction = DEAD;
	}

	motion();
}

void kungpu::render()
{
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void kungpu::motion()
{
	_enemy.count++;

	if (_enemy.count == 18)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}
		if (_enemy.direction == ATTACK)
		{
			switch (_enemy.randAttack)
			{
			case 0:

				_enemy.currentFrameX++;

				if (_enemy.currentFrameX == 3)
				{
					_enemy.direction = STAND;
				}

				break;

			case 1:

				_enemy.currentFrameX++;

				if (_enemy.currentFrameX == 6)
				{
					_enemy.direction = STAND;
				}

				break;

			case 2:

				if (_enemy.currentFrameX == 7)
				{
					_enemy.direction = STAND;
				}
			}
		}

		if (_enemy.direction == HIT)
		{
			_enemy.hitCount++;

			_enemy.currentFrameX = 8;

			if (_enemy.hitCount == 5)
			{
				_enemy.direction = STAND;

				_enemy.hitCount = 0;
			}
		}


		_enemy.count = 0;
	}

	if (_enemy.direction == DEAD)
	{
		_enemy.currentFrameX = 8;

		if (_enemy.fadeCount >= 6)
		{
			_enemy.alphaValue -= 5;

			if (_enemy.alphaValue <= 0)
			{
				_enemy.alphaValue = 0;
			}
		}
		else
		{
			_enemy.deadCount++;
		}
		if (_enemy.deadCount == 10)
		{
			if (_enemy.alphaValue == 255)
			{
				_enemy.alphaValue = 0;

				_enemy.fadeCount += 1;
			}
			else if (_enemy.alphaValue == 0)
			{
				_enemy.alphaValue = 255;

				_enemy.fadeCount += 1;
			}

			_enemy.deadCount = 0;
		}
	}
}

kungpu::kungpu()
{
}

kungpu::~kungpu()
{
}

// 정령
// 해당 에너미의 출현 장소 : 스테이지 1
HRESULT spirit::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("정령", "image/enemy/정령.bmp", 1494, 88, 9, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.hp = 10;
	_enemy.att = 10;
	_enemy.def = 10;
	_enemy.miss = 10;

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMake(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

	return S_OK;
}

void spirit::release()
{
}

void spirit::update()
{
	motion();
}

void spirit::render()
{
}

void spirit::motion()
{
}

spirit::spirit()
{
}

spirit::~spirit()
{
}

// 박쥐
// 해당 에너미의 출현 장소 : 스테이지 2
HRESULT bat::init(float x, float y)
{
	_bat.img = IMAGEMANAGER->addFrameImage("박쥐", "image/enemy/박쥐.bmp", 276, 65, 4, 1, true, RGB(255, 0, 255), true);

	_bat.alphaValue = 255;

	_bat.hp = 10;
	_bat.att = 10;
	_bat.def = 10;
	_bat.miss = 10;

	_bat.count = 0;
	_bat.currentFrameX = 0;
	_bat.currentFrameY = 0;
	
	_bat.x = x;
	_bat.y = y;

	_bat.rc = RectMake(_bat.x, _bat.y, _bat.img->getFrameWidth(), _bat.img->getFrameHeight());

	return S_OK;
}

void bat::release()
{
}

void bat::update()
{
	motion();
}

void bat::render()
{
}

void bat::motion()
{
}

bat::bat()
{
}

bat::~bat()
{
}

// 뱀
// 해당 에너미의 출현 장소 : 스테이지 2
HRESULT snake::init(float x, float y)
{
	_snake.img = IMAGEMANAGER->addFrameImage("뱀", "image/enemy/뱀.bmp", 1085, 103, 5, 1, true, RGB(255, 0, 255), true);

	_snake.alphaValue = 255;

	_snake.hp = 10;
	_snake.att = 10;
	_snake.def = 10;
	_snake.miss = 10;

	_snake.count = 0;
	_snake.currentFrameX = 0;
	_snake.currentFrameY = 0;

	_snake.x = x;
	_snake.y = y;

	_snake.rc = RectMake(_snake.x, _snake.y, _snake.img->getFrameWidth(), _snake.img->getFrameHeight());

	return S_OK;
}

void snake::release()
{
}

void snake::update()
{
	motion();
}

void snake::render()
{
}

void snake::motion()
{
}

snake::snake()
{
}

snake::~snake()
{
}

// 멧돼지
// 해당 에너미의 출현 장소 : 스테이지 2
HRESULT wildboar::init(float x, float y)
{
	_wildboar.img = IMAGEMANAGER->addFrameImage("멧돼지", "image/enemy/멧돼지.bmp", 690, 104, 5, 1, true, RGB(255, 0, 255), true);

	_wildboar.alphaValue = 255;

	_wildboar.hp = 10;
	_wildboar.att = 10;
	_wildboar.def = 10;
	_wildboar.miss = 10;

	_wildboar.count = 0;
	_wildboar.currentFrameX = 0;
	_wildboar.currentFrameY = 0;

	_wildboar.x = x;
	_wildboar.y = y;

	_wildboar.rc = RectMake(_wildboar.x, _wildboar.y, _wildboar.img->getFrameWidth(), _wildboar.img->getFrameHeight());

	return S_OK;
}

void wildboar::release()
{
}

void wildboar::update()
{
	motion();
}

void wildboar::render()
{
}

void wildboar::motion()
{
}

wildboar::wildboar()
{
}

wildboar::~wildboar()
{
}

// 스켈레톤
// 해당 에너미의 출현 장소 : 스테이지 3
HRESULT skeleton::init(float x, float y)
{
	_skeleton.img = IMAGEMANAGER->addFrameImage("해골 공격", "image/enemy/해골 공격.bmp", 261, 64, 3, 1, true, RGB(255, 0, 255), true);

	_skeleton.alphaValue = 255;

	_skeleton.hp = 10;
	_skeleton.att = 10;
	_skeleton.def = 10;
	_skeleton.miss = 10;

	_skeleton.x = x;
	_skeleton.y = y;

	_skeleton.rc = RectMake(_skeleton.x, _skeleton.y, _skeleton.img->getFrameWidth(), _skeleton.img->getFrameHeight());

	return S_OK;
}

void skeleton::release()
{
}

void skeleton::update()
{
	motion();
}

void skeleton::render()
{
}

void skeleton::motion()
{
}

skeleton::skeleton()
{
}

skeleton::~skeleton()
{
}

// 스켈레톤 메이지
// 해당 에너미의 출현 장소 : 스테이지 3
HRESULT skeletonMage::init(float x, float y)
{
	_skeletonMage.img = IMAGEMANAGER->addFrameImage("스켈레톤마법사", "image/enemy/스켈레톤마법사.bmp", 612, 80, 4, 1, true, RGB(255, 0, 255));

	_skeletonMage.alphaValue = 255;

	_skeletonMage.hp = 10;
	_skeletonMage.att = 10;
	_skeletonMage.def = 10;
	_skeletonMage.miss = 10;

	_skeletonMage.x = x;
	_skeletonMage.y = y;

	_skeletonMage.rc = RectMake(_skeletonMage.x, _skeletonMage.y, _skeletonMage.img->getFrameWidth(), _skeletonMage.img->getFrameHeight());

	return S_OK;
}

void skeletonMage::release()
{
}

void skeletonMage::update()
{
	motion();
}

void skeletonMage::render()
{
}

void skeletonMage::motion()
{
}

skeletonMage::skeletonMage()
{
}

skeletonMage::~skeletonMage()
{
}

// 드래곤
// 해당 에너미의 출현 장소 : 스테이지 3
HRESULT dragon::init(float x, float y)
{
	_dragon.img = IMAGEMANAGER->addFrameImage("드래곤", "image/enemy/드래곤.bmp", 1974, 200, 6, 1, true, RGB(255, 0, 255), true);

	_dragon.alphaValue = 255;

	_dragon.hp = 10;
	_dragon.att = 10;
	_dragon.def = 10;
	_dragon.miss = 10;

	_dragon.count = 0;
	_dragon.currentFrameX = 0;
	_dragon.currentFrameY = 0;

	_dragon.x = x;	
	_dragon.y = y;

	return S_OK;
}

void dragon::release()
{
}

void dragon::update()
{
	motion();
}

void dragon::render()
{
}

void dragon::motion()
{
}

dragon::dragon()
{
}

dragon::~dragon()
{
}

// 보스
// 해당 에너미의 출현 장소 : 스테이지 3
HRESULT boss::init(float x, float y)
{
	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	motion();
}

void boss::render()
{
}

void boss::motion()
{
}

boss::boss()
{
}

boss::~boss()
{
}

// 중간보스
// 해당 에너미의 출현 장소 : 스테이지 ??
//HRESULT middleBoss::init(float x, float y)
//{
//	return S_OK;
//}
//
//void middleBoss::release()
//{
//}
//
//void middleBoss::update()
//{
//}
//
//void middleBoss::render()
//{
//}
//
//void middleBoss::motion()
//{
//}
//
//middleBoss::middleBoss()
//{
//}
//
//middleBoss::~middleBoss()
//{
//}
