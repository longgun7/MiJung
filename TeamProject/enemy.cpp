#include "stdafx.h"
#include "enemy.h"



HRESULT enemy::init(float x, float y)
{
	// 기본 설정

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

void enemy::setHp(int damage)
{
	if (damage <= _enemy.def) damage = 0;				// 방어가 데미지보다 높을 때 데미지를 0으로 만든다
	else												// 그게 아니라면
	{
		damage -= _enemy.def;							// 공격력에서 방어력을 뺀다
	}

	_enemy.damage = damage;								// 적의 상태를 HIT상태로 바꾼다
	_enemy.hp -= _enemy.damage;							// 적의 hp에서 공격력을 빼준다


	if (_enemy.hp <= 0)									// 체력이 0 이하가 되면
	{
		_enemy.hp = 0;									// 0으로 초기화 해준다
	}
	_enemy.direction = HIT;
}

enemy::enemy()
{
}


enemy::~enemy()
{
}
