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
	
	DIRECTION direction;		// ����

	int hp;						// ���� ü��	
	int totalHp;				// ü��
	int att;					// ���ݷ�
	int def;					// ����
	int miss;					// ȸ����
	int exp;					// ����ġ
	int currentFrameX;			// ���� X������
	int currentFrameY;			// ���� Y������
	int alphaValue;				// ���� ������ ��ġ
	int count;					// ������ ���� ī��Ʈ
	int hitCount;				// �´� ������ ���ӽð��� �����ִ� ī��Ʈ
	int deadCount;				// ���� �� �����Ÿ��鼭 ������� �ϱ� ���� ī��Ʈ
	int fadeCount;				// ������ ����ȭ �Ǹ鼭 ������� ���ִ� ī��Ʈ
	int randAttack;				// � ������ ���� ������
	int dropGold;				// ��� ���
	int maxAttackFrameX;		// �ִ� ���� ������

	bool isGoldSet;				// ���� ���´���
	bool isAttack;				// �����ߴ���
	bool isRandAttack;			// � ������ ���� ������ �ߴ���

	float x;					// X��ǥ
	float y;					// Y��ǥ
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

	void setisGoldSet(bool gold) { _enemy.isGoldSet = gold; }								// �÷��̾ ��带 �޾ư� �� �ְ� ���ִ� ������
	void setEnemyDirection(DIRECTION direction) { _enemy.direction = direction; }			// �÷��̾ ���ʹ��� ���¸� ������ �� �ְ� ���ִ� ������
	tagEnemy getTagEnmey() { return _enemy; }												// �ٸ������� ���ʹ� ����ü�� ����� �� �ְ� ��ȯ
	enemy();
	~enemy();
};

