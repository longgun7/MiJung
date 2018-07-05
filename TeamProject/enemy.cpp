#include "stdafx.h"
#include "enemy.h"


HRESULT enemy::init(float x, float y)
{
	_enemy.currentFrameX = 0;
	_enemy.count = 0;
	_enemy.x = x;
	_enemy.y = y;
	_enemy.alphaValue = 255;
	_enemy.rc = RectMakeCenter(_enemy.x, _enemy.y, _enemy.img->getFrameWidth(), _enemy.img->getFrameHeight());

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
}

void enemy::render()
{
}

enemy::enemy()
{
}


enemy::~enemy()
{
}
