#include "stdafx.h"
#include "enemys.h"

// â��
// �ش� ���ʹ��� ���� ��� : �������� 1
HRESULT spearMan::init(float x, float y) 
{
	_enemy.img = IMAGEMANAGER->addFrameImage("â��", "image/enemy/â��.bmp", 576, 64, 4, 1, true, RGB(255, 0, 255), true);
	
	_enemy.alphaValue = 255;

	_enemy.hp = 10;
	_enemy.att = 20;
	_enemy.def = 10;
	_enemy.miss = 10;
	 
	_enemy.count = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;
	
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
	if (_enemy.hp <= 0)
	{
		if (_enemy.alphaValue >= 5)
		{
			_enemy.alphaValue -= 5;
		}
	}
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

// ��Ǫ
// �ش� ���ʹ��� ���� ��� : �������� 1
HRESULT kungpu::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("��Ǫ", "image/enemy/��Ǫ.bmp", 1215, 153, 9, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.hp = 10;
	_enemy.att = 5;
	_enemy.def = 10;
	_enemy.miss = 10;
	_enemy.hp = 10;
	_enemy.att = 10;
	_enemy.def = 10;
	_enemy.miss = 10;

	_enemy.count = 0;
	_enemy.deadCount = 0;
	_enemy.fadeCount = 0;
	_enemy.currentFrameX = 0;
	_enemy.currentFrameY = 0;

	_kungpu.direction = STAND;

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

// ����
// �ش� ���ʹ��� ���� ��� : �������� 1
HRESULT spirit::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("����", "image/enemy/����.bmp", 1494, 88, 9, 1, true, RGB(255, 0, 255), true);

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight(),_enemy.alphaValue);
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

// ����
// �ش� ���ʹ��� ���� ��� : �������� 2
HRESULT bat::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("����", "image/enemy/����.bmp", 420, 100, 4, 1, true, RGB(255, 0, 255), true);

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.x, _enemy.y, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
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

// ��
// �ش� ���ʹ��� ���� ��� : �������� 2
HRESULT snake::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("��", "image/enemy/��.bmp", 1085, 103, 5, 1, true, RGB(255, 0, 255), true);

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

void snake::release()
{
}

void snake::update()
{
	motion();
}

void snake::render()
{
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.x, _enemy.y, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
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

// �����
// �ش� ���ʹ��� ���� ��� : �������� 2
HRESULT wildboar::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("�����", "image/enemy/�����.bmp", 690, 104, 5, 1, true, RGB(255, 0, 255), true);

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

void wildboar::release()
{
}

void wildboar::update()
{
	motion();
}

void wildboar::render()
{
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.x, _enemy.y, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
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

// ���̷���
// �ش� ���ʹ��� ���� ��� : �������� 3
HRESULT skeleton::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("���̷���", "image/enemy/�ذ� ����.bmp", 261, 64, 3, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.hp = 10;
	_enemy.att = 10;
	_enemy.def = 10;
	_enemy.miss = 10;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMake(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.x, _enemy.y, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
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

// ���̷��� ������
// �ش� ���ʹ��� ���� ��� : �������� 3
HRESULT skeletonMage::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("���̷��渶����", "image/enemy/�ذ񸶹���.bmp", 612, 80, 4, 1, true, RGB(255, 0, 255), true);

	_enemy.alphaValue = 255;

	_enemy.hp = 10;
	_enemy.att = 10;
	_enemy.def = 10;
	_enemy.miss = 10;

	_enemy.x = x;
	_enemy.y = y;

	_enemy.rc = RectMake(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.x, _enemy.y, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
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

// �巡��
// �ش� ���ʹ��� ���� ��� : �������� 3
HRESULT dragon::init(float x, float y)
{
	_enemy.img = IMAGEMANAGER->addFrameImage("�巡��", "image/enemy/�巡��.bmp", 1974, 200, 6, 1, true, RGB(255, 0, 255), true);

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
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.x, _enemy.y, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
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

// ����
// �ش� ���ʹ��� ���� ��� : �������� 3
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

// �߰�����
// �ش� ���ʹ��� ���� ��� : �������� ??
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
