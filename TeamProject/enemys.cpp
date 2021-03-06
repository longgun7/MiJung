#include "stdafx.h"
#include "enemys.h"

// 창병
// 해당 에너미의 출현 장소 : 스테이지 1
HRESULT spearMan::init(float x, float y) 
{
	// 기본 정보 세팅

	_enemy.img = IMAGEMANAGER->addFrameImage("창병", "image/enemy/창병.bmp", 576, 64, 4, 1, true, RGB(255, 0, 255), true);

	_enemy.name = "창병";
	
	_enemy.alphaValue = 255;

	_enemy.hp = 40;
	_enemy.totalHp = 40;
	_enemy.att = 20;
	_enemy.def = 3;
	_enemy.miss = 10;
	_enemy.exp = 20;
	_enemy.isAttack = false;
	_enemy.isDead = false;

	_enemy.dropGold = RND->getFromIntTo(100, 200);
	 
	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 2;

	_enemy.direction = STAND;
	
	_enemy.x = x;
	_enemy.y = y;
	 
	_enemy.hitCount = 0;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

	return S_OK;
}

void spearMan::release()
{
}

void spearMan::update()
{
	motion();
}

void spearMan::render()
{
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void spearMan::motion()
{
	if(!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX++;

			if (_enemy.currentFrameX > 1)
			{
				_enemy.isAttack = true;
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
			_enemy.fadeCount += 1;
			_enemy.alphaValue -= 5;

			if (_enemy.alphaValue < 0)
			{
				//_enemy.fadeCount = 80;				
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

	_enemy.name = "쿵푸";

	_enemy.hp = 40;
	_enemy.totalHp = 40;
	_enemy.att = 20;
	_enemy.def = 3;
	_enemy.miss = 10;
	_enemy.exp = 20;

	_enemy.isAttack = false;
	_enemy.isRandAttack = false;
	_enemy.dropGold = RND->getFromIntTo(100, 200);

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 0;

	_enemy.direction = STAND;

	_enemy.x = x;
	_enemy.y = y;
	_enemy.hitCount = 0;

	_enemy.hitCount = 0;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

	return S_OK;
}

void kungpu::release()
{
}

void kungpu::update()
{
	motion();
}

void kungpu::render()
{
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void kungpu::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.direction == STAND)
	{
		_enemy.randAttack = RND->getFromIntTo(1, 3);
		_enemy.isRandAttack = false;
	}

	if (_enemy.direction == ATTACK)
	{
		if (_enemy.isRandAttack == false)
		{
			if (_enemy.randAttack == 1)
			{
				_enemy.currentFrameX = 1;
				_enemy.maxAttackFrameX = 3;
			}

			if (_enemy.randAttack == 2)
			{
				_enemy.currentFrameX = 4;
				_enemy.maxAttackFrameX = 5;
			}
			_enemy.isRandAttack = true;
		}
	}

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX++;

			if (_enemy.currentFrameX >= _enemy.maxAttackFrameX)
			{
				_enemy.isAttack = true;
				_enemy.direction = STAND;
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
			_enemy.fadeCount += 1;

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

	_enemy.name = "정령";

	_enemy.hp = 40;
	_enemy.totalHp = 40;
	_enemy.att = 17;
	_enemy.def = 3;
	_enemy.miss = 10;
	_enemy.exp = 20;

	_enemy.isAttack = false;
	_enemy.isRandAttack = false;

	_enemy.dropGold = RND->getFromIntTo(100, 200);

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 7;

	_enemy.direction = STAND;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY,_enemy.alphaValue);
}

void spirit::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX++;

			if (_enemy.currentFrameX > 1)
			{
				_enemy.currentFrameX = 0;
			}
		}
		else if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX++;
			_enemy.isAttack = true;

			if (_enemy.currentFrameX > 6)
			{
				_enemy.direction = STAND;
			}
		}
		else if (_enemy.direction == HIT)
		{
			_enemy.hitCount++;

			_enemy.currentFrameX = 2;

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
			_enemy.fadeCount += 1;
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

	if (_enemy.direction == STAND)
	{
		_enemy.isRandAttack = false;
	}

	if (_enemy.direction == ATTACK)
	{
		if (_enemy.isRandAttack == false)
		{
			_enemy.currentFrameX = 3;
			_enemy.isRandAttack = true;

		}
	}
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
	_enemy.img = IMAGEMANAGER->addFrameImage("박쥐", "image/enemy/박쥐.bmp", 420, 100, 4, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.name = "박쥐";

	_enemy.hp = 100;
	_enemy.totalHp = 100;
	_enemy.att = 27;
	_enemy.def = 10;
	_enemy.miss = 10;
	_enemy.exp = 50;

	_enemy.isAttack = false;
	_enemy.isRandAttack = false;

	_enemy.dropGold = RND->getFromIntTo(400, 800);

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 2;

	_enemy.direction = STAND;
	
	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void bat::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX++;

			if (_enemy.currentFrameX > 1)
			{
				_enemy.currentFrameX = 0;
			}
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX = 2;

			if (_enemy.currentFrameX == 2)
			{
				_enemy.isAttack = true;
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
			_enemy.fadeCount += 1;

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
	_enemy.img = IMAGEMANAGER->addFrameImage("뱀", "image/enemy/뱀.bmp", 1085, 103, 5, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.name = "뱀";

	_enemy.hp = 100;
	_enemy.totalHp = 100;
	_enemy.att = 27;
	_enemy.def = 10;
	_enemy.miss = 10;
	_enemy.exp = 50;

	_enemy.isAttack = false;

	_enemy.dropGold = RND->getFromIntTo(400, 800);

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 1;

	_enemy.direction = STAND;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void snake::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX = 1;

			if (_enemy.currentFrameX == 1)
			{
				_enemy.isAttack = true;
				_enemy.direction = STAND;
			}
		}

		if (_enemy.direction == HIT)
		{
			_enemy.currentFrameX = 2;

			_enemy.hitCount++;

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
		_enemy.currentFrameX = 4;

		if (_enemy.fadeCount >= 6)
		{
			_enemy.fadeCount += 1;
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
	_enemy.img = IMAGEMANAGER->addFrameImage("멧돼지", "image/enemy/멧돼지.bmp", 690, 104, 5, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.name = "맷돼지";

	_enemy.hp = 100;
	_enemy.totalHp = 100;
	_enemy.att = 27;
	_enemy.def = 10;
	_enemy.miss = 10;
	_enemy.exp = 50;

	_enemy.isAttack = false;

	_enemy.dropGold = RND->getFromIntTo(400, 800);

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 2;

	_enemy.direction = STAND;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void wildboar::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX = 2;
	
			if (_enemy.currentFrameX == 2)
			{
				_enemy.isAttack = true;
				_enemy.direction = STAND;
			}
		}

		if (_enemy.direction == HIT)
		{
			_enemy.currentFrameX = 1;

			_enemy.hitCount++;

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
		_enemy.currentFrameX = 1;
		

		if (_enemy.fadeCount >= 6)
		{
			_enemy.alphaValue -= 5;
			_enemy.fadeCount += 1;

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
	_enemy.img = IMAGEMANAGER->addFrameImage("스켈레톤", "image/enemy/스켈레톤.bmp", 261, 64, 3, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.name = "스켈레톤";

	_enemy.hp = 300;
	_enemy.totalHp = 300;
	_enemy.att = 35;
	_enemy.def = 20;
	_enemy.miss = 10;
	_enemy.exp = 70;

	_enemy.isAttack = false;

	_enemy.dropGold = RND->getFromIntTo(1000, 1200);

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 1;

	_enemy.direction = STAND;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void skeleton::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX = 1;

			if (_enemy.currentFrameX == 1)
			{
				_enemy.isAttack = true;
				_enemy.direction = STAND;
			}
		}

		if (_enemy.direction == HIT)
		{
			_enemy.currentFrameX = 2;

			_enemy.hitCount++;

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
		_enemy.currentFrameX = 2;
		
		if (_enemy.fadeCount >= 6)
		{
			_enemy.alphaValue -= 5;
			_enemy.fadeCount += 1;

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

skeleton::skeleton()
{
}

skeleton::~skeleton()
{
}

// 위치
// 해당 에너미의 출현 장소 : 스테이지 3
HRESULT skeletonMage::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("위치", "image/enemy/위치.bmp", 612, 80, 4, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.name = "위치";

	_enemy.hp = 300;
	_enemy.totalHp = 300;
	_enemy.att = 35;
	_enemy.def = 20;
	_enemy.miss = 10;
	_enemy.exp = 70;

	_enemy.isAttack = false;

	_enemy.dropGold = RND->getFromIntTo(1000, 1200);

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 0;

	_enemy.direction = STAND;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void skeletonMage::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}

		if (_enemy.direction == ATTACK)
		{

			if (_enemy.currentFrameX == _enemy.maxAttackFrameX)
			{
				_enemy.isAttack = true;
				_enemy.direction = STAND;
			}

		}

		if (_enemy.direction == HIT)
		{
			_enemy.currentFrameX = 3;

			_enemy.hitCount++;

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
			_enemy.fadeCount += 1;
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


	if (_enemy.direction == STAND)
	{
		_enemy.isRandAttack = false;
	}

	if (_enemy.direction == ATTACK)
	{
		if (_enemy.isRandAttack == false)
		{
			_enemy.randAttack = RND->getFromIntTo(1, 3);

			if (_enemy.randAttack == 1)
			{
				_enemy.currentFrameX = 1;
				_enemy.maxAttackFrameX = 1;
				
			}

			if (_enemy.randAttack == 2)
			{
				_enemy.currentFrameX = 2;
				_enemy.maxAttackFrameX = 2;
			}

			_enemy.isRandAttack = true;
		}
	}
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
	_enemy.img = IMAGEMANAGER->addFrameImage("드래곤", "image/enemy/드래곤.bmp", 1974, 200, 6, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.name = "드래곤";

	_enemy.hp = 300;
	_enemy.totalHp = 300;
	_enemy.att = 35;
	_enemy.def = 20;
	_enemy.miss = 10;
	_enemy.exp = 70;

	_enemy.isAttack = false;

	_enemy.dropGold = RND->getFromIntTo(1000, 1200);

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 0;

	_enemy.direction = STAND;

	_enemy.x = x;	
	_enemy.y = y;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void dragon::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX = 5;

			if (_enemy.currentFrameX == 5)
			{
				_enemy.direction = STAND;
				_enemy.isAttack = true;
			}
		}

		if (_enemy.direction == HIT)
		{
			_enemy.currentFrameX = 4;

			_enemy.hitCount++;

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
		_enemy.currentFrameX = 4;

		if (_enemy.fadeCount >= 6)
		{
			_enemy.fadeCount += 1;
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
	_bs = new BossSkill1;
	_bs->init();

	_bs2 = new BossSkill2;
	_bs2->init();

	_enemy.img = IMAGEMANAGER->addFrameImage("보스", "image/enemy/보스.bmp", 1200, 792, 8, 6, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.name = "보스";

	_enemy.hp = 750;
	_enemy.totalHp = 750;
	_enemy.att = 40;
	_enemy.def = 30;
	_enemy.miss = 10;
	_enemy.exp = 0;
	_enemy.skillCount = 0;

	_enemy.isAttack = false;
	_enemy.isSkill = false;

	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	_enemy.maxAttackFrameX = 0;

	_enemy.direction = STAND;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	motion();
	_bs->update();
	_bs2->update();
}

void boss::render()
{
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
	_bs->render();
	_bs2->render();
}

void boss::motion()
{
	if (!(_enemy.direction == DEAD)) ++_enemy.count;

	if (_enemy.direction == STAND)
	{
		_enemy.isRandAttack = true;
	}

	if (_enemy.direction == ATTACK)
	{
		if (_enemy.isRandAttack == true)
		{
			_enemy.randAttack = RND->getFromIntTo(1, 6);

			if (_enemy.randAttack == 1)
			{
				_enemy.currentFrameY = 1;
				_enemy.maxAttackFrameX = 3;
			}

			if (_enemy.randAttack == 2)
			{
				_enemy.currentFrameY = 2;
				_enemy.maxAttackFrameX = 7;
			}

			if (_enemy.randAttack == 3)
			{
				_enemy.currentFrameY = 3;
				_enemy.maxAttackFrameX = 5;
			}

			if (_enemy.randAttack == 4)
			{
				_enemy.currentFrameY = 4;
				_enemy.maxAttackFrameX = 3;
			}

			if (_enemy.randAttack == 5)
			{
				_enemy.currentFrameY = 5;
				_enemy.maxAttackFrameX = 2;
			}

			_enemy.isRandAttack = false;
		}
	}

	if (_enemy.count == Count)
	{
		if (_enemy.direction == STAND)
		{
			_enemy.currentFrameX = 0;
			_enemy.currentFrameY = 0;
		}

		if (_enemy.direction == ATTACK)
		{
			_enemy.currentFrameX++;

			if (_enemy.randAttack == 1 && _enemy.currentFrameX == 1)
			{
				_bs->addAreaSkill(_enemy.x, _enemy.y);
			}
			else if ((_enemy.randAttack == 2 || _enemy.randAttack == 3) && _enemy.currentFrameX % 2 == 0 && _enemy.currentFrameX != 0 && _enemy.currentFrameX != 1)
			{
				_enemy.isAttack = true;
			}
			else if (_enemy.randAttack == 4 && _enemy.currentFrameX == 2)
			{
				_enemy.isSkill = true;
			}
			else if (_enemy.randAttack == 5 && _enemy.currentFrameX == 1)
			{
				_enemy.isAttack = true;
			}
			if (_enemy.currentFrameX >= _enemy.maxAttackFrameX)
			{
				if(_enemy.randAttack == 1)_enemy.isAttack = true;

				_enemy.skillCount = 0;
				_enemy.direction = STAND;
			}
		}

		if (_enemy.direction == HIT)
		{
			_enemy.currentFrameX = 1;

			_enemy.hitCount++;

			if (_enemy.hitCount == 5)
			{
				_enemy.direction = STAND;

				_enemy.hitCount = 0;
			}
		}

		_enemy.count = 0;
	}

	if (_enemy.isSkill == true && _enemy.randAttack == 4)
	{
		_enemy.skillCount++;

		if (_enemy.skillCount == 5)
		{
			_bs2->addAreaSkill();

			_enemy.skillCount = 0;
		}
	}

	if (_enemy.direction == DEAD)
	{
		_enemy.currentFrameX = 1;
		_enemy.currentFrameY = 0;

		if (_enemy.fadeCount >= 6)
		{
			_enemy.fadeCount += 1;
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
