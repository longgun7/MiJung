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

	int _hp;				// ü��
	int _att;				// ���ݷ�
	int _def;				// ����
	int _miss;				// ȸ����
	int _currentFrameX;		// ���� ������ X
	int _frameY;			// ������ Y
	int _alphaValue;		// ���� ���� ��ġ
	int _speed;				// �����ְ� ���� ���� ��
	int _count;				// ������ ���� ī��Ʈ
	
	float _x;				// X��ǥ
	float _y;				// Y��ǥ

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
