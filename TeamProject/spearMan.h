#pragma once
#include "gameNode.h"

enum SPEAR_MAN_DIRECTION
{
	SPEAR_MAN_STAND,
	SPEAR_MAN_ATTACK,
	SPEAR_MAN_HIT
};

class spearMan : public gameNode
{
private:

	image * _img;
	SPEAR_MAN_DIRECTION _direction;
	RECT rc;

	int _hp;				// 체력
	int _att;				// 공격력
	int _def;				// 방어력
	int _miss;				// 회피율
	int _currentFrameX;		// 현재 프레임 X
	int _frameY;			// 프레임 Y
	int _alphaValue;		// 알파 블렌딩 수치
	int _speed;				// 높은애가 먼저 공격 함
	int _count;				// 프레임 감을 카운트
	
	float _x;				// X좌표
	float _y;				// Y좌표

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	void setHitMotion(SPEAR_MAN_DIRECTION _hit) { _direction = _hit; }

	spearMan();
	~spearMan();
};
