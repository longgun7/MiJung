#include "stdafx.h"
#include "spearMan.h"


HRESULT spearMan::init(float x, float y)
{
	_img = IMAGEMANAGER->addFrameImage("창병", "image/enemy/창병.bmp", 576, 64, 4, 1, true, RGB(255, 0, 255), true);

	_direction = SPEAR_MAN_STAND;

	_hp = 10;
	_att = 10;
	_def = 10;
	_miss = 10;
	_speed = 5;
	_alphaValue = 255;
	_frameY = 0;

	_x = x;
	_y = y;

	rc = RectMake(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	return S_OK;
}

void spearMan::release()
{
}

void spearMan::update()
{
	/*
	if(플레이어가 스킬을 썻다면)
	{
		if(상대의 스킬 X가 몇 번째 프레임일 때)
		{
			_direction = SPEAR_MAN_HIT
			_hp -= 15;
		}
	}
	*/
	
	
	if (_hp <= 0 && _alphaValue > 6)
	{
		_alphaValue -= 5;
	}

	if (_direction == SPEAR_MAN_HIT)
	{
		_x += 1;
	}

	if (_x == WINSIZEX / 2 + 50)
	{
		_direction = SPEAR_MAN_STAND;
		_x = WINSIZEX / 2;
	}

	motion();
}

void spearMan::render()
{
	_img->alphaFrameRender(getMemDC(), _x, _y, _currentFrameX, _frameY, _alphaValue);
}

void spearMan::motion()
{
	_count++;

	if (_count % 10 == 0)
	{
		if (_direction == SPEAR_MAN_STAND)
		{
			_currentFrameX = 0;
		}
		if (_direction == SPEAR_MAN_ATTACK)
		{
			_currentFrameX++;

			if (_currentFrameX >= 2) _direction = SPEAR_MAN_STAND;
		}
		if (_direction == SPEAR_MAN_HIT)
		{
			_currentFrameX = 3;
		}
	}
}



spearMan::spearMan()
{
}


spearMan::~spearMan()
{
}
