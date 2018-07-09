#pragma once
#include "gameNode.h"

enum DIRECTION
{
	STAND,	// ������ �ִ� ����
	ATTACK,	// ����
	HIT,	// �´� ����
	DEAD	// ����
};

struct tagEnemy	// ���ʹ� ����ü
{
	image* img;	// �̹���

	RECT rc;	// ��Ʈ
	
	DIRECTION direction;	// ����

	int hp;					// ü��
	int att;				// ���ݷ�
	int def;				// ����
	int miss;				// ȸ����
	int exp;				// ����ġ
	int currentFrameX;		// ���� X������
	int currentFrameY;		// ���� Y������
	int alphaValue;			// ���� ������ ��ġ
	int count;				// ������ ���� ī��Ʈ
	int hitCount;			// �´� ������ ���ӽð��� �����ִ� ī��Ʈ
	int deadCount;			// ���� �� �����Ÿ��鼭 ������� �ϱ� ���� ī��Ʈ
	int fadeCount;			// ������ ����ȭ �Ǹ鼭 ������� ���ִ� ī��Ʈ
	int randAttack;			// � ������ ���� ������
	int dropGold;			// ��� ���
	bool isGoldSet;         // ���� ���´���
	float x;				// X��ǥ
	float y;				// Y��ǥ
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

	void setHp(int damage);
	void setDirection(DIRECTION direction);

	void setisGoldSet(bool gold) { _enemy.isGoldSet = gold; }
	tagEnemy getTagEnmey() { return _enemy; }
	enemy();
	~enemy();
};

