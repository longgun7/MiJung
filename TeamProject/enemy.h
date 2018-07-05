#pragma once
#include "gameNode.h"

struct tagEnemy
{
	image* img;
	RECT rc;

	int hp;					// 체력
	int att;				// 공격력
	int def;				// 방어력
	int miss;				// 회피율
	int currentFrameX;		// 현재 프레임 X
	int currentFrameY;		// 프레임 Y
	int alphaValue;			// 알파 블렌딩 수치
	int count;				// 프레임 감을 카운트
	int hitCount;

	float x;				// X좌표
	float y;				// Y좌표
};

class enemy : public gameNode
{
protected:
	tagEnemy _enemy;

public:

	virtual HRESULT init(float x , float y);
	virtual void release();
	virtual void update();
	virtual void render();


	tagEnemy getTagEnmey() { return _enemy; }
	void setHp(int damage);
	enemy();
	~enemy();
};

