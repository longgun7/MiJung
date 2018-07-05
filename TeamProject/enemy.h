#pragma once
#include "gameNode.h"

struct tagEnemy
{
	image* img;
	RECT rc;

	int hp;					// ü��
	int att;				// ���ݷ�
	int def;				// ����
	int miss;				// ȸ����
	int currentFrameX;		// ���� ������ X
	int currentFrameY;		// ������ Y
	int alphaValue;			// ���� ���� ��ġ
	int count;				// ������ ���� ī��Ʈ
	int hitCount;

	float x;				// X��ǥ
	float y;				// Y��ǥ
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

