#pragma once
#include "gameNode.h"

enum DIRECTION
{
	STAND,
	ATTACK,
	HIT,
	DEAD
};

struct tagEnemy
{
	image* img;

	RECT rc;
	
	DIRECTION direction;

	int hp;
	int att;
	int def;
	int miss;
	int currentFrameX;
	int currentFrameY;
	int alphaValue;
	int count;
	int hitCount;
	int deadCount;
	int fadeCount;
	int randAttack;

	float x;
	float y;
};

class enemy : public gameNode
{
protected:

	tagEnemy _enemy;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	enemy();
	~enemy();
};

