#pragma once
#include "gameNode.h"

#define Count 5

enum DIRECTION
{
	STAND,	// ������ �ִ� ����
	ATTACK,	// ����
	HIT,	// �´� ����
	DEAD,	// ����
	DEAD_END // ���� �� �����ִ� ����
};

struct tagEnemy	// ���ʹ� ����ü
{
	image* img;	// �̹���

	RECT rc;	// ��Ʈ
	
	DIRECTION direction;		// ����

	string name;			// �� �̸�

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
	int damage;					// ������ ����� ���� ����
	int skillCount;				// ���� ��ų Ÿ�̹��� ���߱� ���� ��ų ī��Ʈ

	bool isGoldSet;				// ���� ���´���
	bool isAttack;				// �����ߴ���
	bool isRandAttack;			// � ������ ���� ������ �ߴ���
	bool isDead;				// �׾�����
	bool isSkill;				// ��ų�� �����

	float x;					// X��ǥ
	float y;					// Y��ǥ
};

class enemy : public gameNode
{
protected:

	tagEnemy _enemy;							// tagEnemy�� _enemy�� �̸����� ���

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void setHp(int damage);																	// ���ʹ̰� �������� �Դ� �Լ�

	void setisGoldSet(bool gold) { _enemy.isGoldSet = gold; }								// ���� ���´��� �Ⱥ��´��� ������ �� �ְ� ���ִ� ������
	void setEnemyDirection(DIRECTION direction) { _enemy.direction = direction; }			// ���ʹ��� ���¸� ������ �� �ְ� ���ִ� ������
	tagEnemy getTagEnmey() { return _enemy; }												// �ٸ������� ���ʹ� ����ü�� ����� �� �ְ� ��ȯ
	void setIsDead(bool dead) { _enemy.isDead = dead; }										// ���� �׾����� ��Ҵ��� ������ �� �ְ� ���ִ� ������
	void setIsAttack(bool attack) { _enemy.isAttack = attack; }								// ���� ������ �ߴ��� �������ִ� ������
	image* getImage() { return _enemy.img; }												// ���ʹ� �̹����� ������ ���� ���ʹ� �̹��� ������

	enemy();
	~enemy();
};

