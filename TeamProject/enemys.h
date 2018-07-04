#pragma once
#include "gameNode.h"

enum DIRECTION
{
	STAND,
	ATTACK,
	HIT,
	SKILL,
	SKILL2,
};

struct tagEnemy
{
	image* img;
	DIRECTION direction;
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

// â��
// �ش� ���ʹ��� ���� ��� : �������� 1
class spearMan : public gameNode
{
private:

	tagEnemy _spearMan;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();
	void setDirection(DIRECTION _direction) { _spearMan.direction = _direction; }
	spearMan();
	~spearMan();
};

// ��Ǫ
// �ش� ���ʹ��� ���� ��� : �������� 1 
class kungpu : public gameNode
{
private:

	tagEnemy _kungpu;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	kungpu();
	~kungpu();
};

// ����
// �ش� ���ʹ��� ���� ��� : �������� 1
class spirit : public gameNode
{
private:

	tagEnemy _spirit;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	spirit();
	~spirit();
};

// ����
// �ش� ���ʹ��� ���� ��� : �������� 2
class bat : public gameNode
{
private:

	tagEnemy _bat;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	bat();
	~bat();
};

// ��
// �ش� ���ʹ��� ���� ��� : �������� 2
class snake : public gameNode
{
private:

	tagEnemy _snake;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	snake();
	~snake();
};

// �����
// �ش� ���ʹ��� ���� ��� : �������� 2
class wildboar : public gameNode
{
private:

	tagEnemy _wildboar;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	wildboar();
	~wildboar();
};

// ���̷���
// �ش� ���ʹ��� ���� ��� : �������� 3
class skeleton : public gameNode
{
private:

	tagEnemy _skeleton;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	skeleton();
	~skeleton();
};

// ���̷��� ������
// �ش� ���ʹ��� ���� ��� : �������� 3
class skeletonMage : public gameNode
{
private:

	tagEnemy _skeletonMage;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	skeletonMage();
	~skeletonMage();
};

// �巡��
// �ش� ���ʹ��� ���� ��� : �������� 3
class dragon : public gameNode
{
private:

	tagEnemy _dragon;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	dragon();
	~dragon();
};

// ����
// �ش� ���ʹ��� ���� ��� : ������
class boss : public gameNode
{
private:

	tagEnemy _boss;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

	boss();
	~boss();
};

//class middleBoss : public gameNode
//{
//private:
//
//	tagEnemy _middleBoss;
//
//public:
//
//	virtual HRESULT init(float x, float y);
//	virtual void release();
//	virtual void update();
//	virtual void render();
//
//	void motion();
//
//	middleBoss();
//	~middleBoss();
//};