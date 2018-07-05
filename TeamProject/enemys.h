#pragma once
#include "enemy.h"

// 창병
// 해당 에너미의 출현 장소 : 스테이지 1
class spearMan : public enemy
{
private:



public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	spearMan();
	~spearMan();
};

// 쿵푸
// 해당 에너미의 출현 장소 : 스테이지 1 
class kungpu : public enemy
{
private:



public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	kungpu();
	~kungpu();
};

// 정령
// 해당 에너미의 출현 장소 : 스테이지 1
class spirit : public enemy
{
private:



public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	spirit();
	~spirit();
};

// 박쥐
// 해당 에너미의 출현 장소 : 스테이지 2
class bat : public enemy
{
private:

	tagEnemy _bat;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	bat();
	~bat();
};

// 뱀
// 해당 에너미의 출현 장소 : 스테이지 2
class snake : public enemy
{
private:

	tagEnemy _snake;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	snake();
	~snake();
};

// 멧돼지
// 해당 에너미의 출현 장소 : 스테이지 2
class wildboar : public enemy
{
private:

	tagEnemy _wildboar;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	wildboar();
	~wildboar();
};

// 스켈레톤
// 해당 에너미의 출현 장소 : 스테이지 3
class skeleton : public enemy
{
private:

	tagEnemy _skeleton;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	skeleton();
	~skeleton();
};

// 스켈레톤 메이지
// 해당 에너미의 출현 장소 : 스테이지 3
class skeletonMage : public enemy
{
private:

	tagEnemy _skeletonMage;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	skeletonMage();
	~skeletonMage();
};

// 드래곤
// 해당 에너미의 출현 장소 : 스테이지 3
class dragon : public enemy
{
private:

	tagEnemy _dragon;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

	dragon();
	~dragon();
};

// 보스
// 해당 에너미의 출현 장소 : 보스룸
class boss : public enemy
{
private:

	tagEnemy _boss;

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void motion();								// 공격, 방어, 히트, 모션

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