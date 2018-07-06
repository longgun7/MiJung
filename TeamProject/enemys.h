#pragma once
#include "enemy.h"


// â��
// �ش� ���ʹ��� ���� ��� : �������� 1
class spearMan : public enemy
{

public:
	// ���ʹ�
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