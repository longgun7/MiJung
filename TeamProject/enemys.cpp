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
		
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
	
	}
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		_enemy.hp -= 20;
	}

	motion();
}

void spearMan::render()
{
	_enemy.img->alphaFrameRender(getMemDC(), _enemy.rc.left, _enemy.rc.top, _enemy.currentFrameX, _enemy.currentFrameY, _enemy.alphaValue);
}

void spearMan::motion()
{
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

	_enemy.count = 0;
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
	if (_enemy.hp <= 0)
	{
		

		if (_enemy.alphaValue >= 5)
		{
			_enemy.alphaValue -= 5;
		}
	}
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		

		_enemy.currentFrameX = 4;
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_enemy.currentFrameX =2;
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_enemy.currentFrameX = 3;
	}
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		_enemy.hp -= 20;
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
