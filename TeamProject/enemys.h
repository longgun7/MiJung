#pragma once
#include "enemy.h"

// â��
// �ش� ���ʹ��� ���� ��� : �������� 1
class spearMan : public enemy
{
private:



public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	spearMan();
	~spearMan();
};

// ��Ǫ
// �ش� ���ʹ��� ���� ��� : �������� 1 
class kungpu : public enemy
{
private:



public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	kungpu();
	~kungpu();
};

// ����
// �ش� ���ʹ��� ���� ��� : �������� 1
class spirit : public enemy
{
private:



public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	spirit();
	~spirit();
};

// ����
// �ش� ���ʹ��� ���� ��� : �������� 2
class bat : public enemy
{
private:

	tagEnemy _bat;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	bat();
	~bat();
};

// ��
// �ش� ���ʹ��� ���� ��� : �������� 2
class snake : public enemy
{
private:

	tagEnemy _snake;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	snake();
	~snake();
};

// �����
// �ش� ���ʹ��� ���� ��� : �������� 2
class wildboar : public enemy
{
private:

	tagEnemy _wildboar;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	wildboar();
	~wildboar();
};

// ���̷���
// �ش� ���ʹ��� ���� ��� : �������� 3
class skeleton : public enemy
{
private:

	tagEnemy _skeleton;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	skeleton();
	~skeleton();
};

// ���̷��� ������
// �ش� ���ʹ��� ���� ��� : �������� 3
class skeletonMage : public enemy
{
private:

	tagEnemy _skeletonMage;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	skeletonMage();
	~skeletonMage();
};

// �巡��
// �ش� ���ʹ��� ���� ��� : �������� 3
class dragon : public enemy
{
private:

	tagEnemy _dragon;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	dragon();
	~dragon();
};

// ����
// �ش� ���ʹ��� ���� ��� : ������
class boss : public enemy
{
private:

	tagEnemy _boss;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// ����, ���, ��Ʈ, ���

	boss();
	~boss();
};

//class middleBoss : public enemy
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