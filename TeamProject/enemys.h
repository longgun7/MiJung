#pragma once
#include "enemy.h"


// â��
// �ش� ���ʹ��� ���� ��� : �������� 1
class spearMan : public enemy
{

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();
	spearMan();
	~spearMan();
};

// ��Ǫ
// �ش� ���ʹ��� ���� ��� : �������� 1 
class kungpu : public enemy
{
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
class spirit : public enemy
{
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
class bat : public enemy
{
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
class snake : public enemy
{
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
class wildboar : public enemy
{
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
class skeleton : public enemy
{

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
class skeletonMage : public enemy
{

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
class dragon : public enemy
{

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
class boss : public enemy
{

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();

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