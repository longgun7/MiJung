#pragma once
#include "enemy.h"


// 창병
// 해당 에너미의 출현 장소 : 스테이지 1
class spearMan : public enemy
{

public:
	// 에너미
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