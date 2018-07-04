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

	int hp;					// 체력
	int att;				// 공격력
	int def;				// 방어력
	int miss;				// 회피율
	int currentFrameX;		// 현재 프레임 X
	int currentFrameY;		// 프레임 Y
	int alphaValue;			// 알파 블렌딩 수치
	int count;				// 프레임 감을 카운트
	int hitCount;

	float x;				// X좌표
	float y;				// Y좌표
};

// 창병
// 해당 에너미의 출현 장소 : 스테이지 1
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

// 쿵푸
// 해당 에너미의 출현 장소 : 스테이지 1 
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

// 정령
// 해당 에너미의 출현 장소 : 스테이지 1
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

// 박쥐
// 해당 에너미의 출현 장소 : 스테이지 2
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

// 뱀
// 해당 에너미의 출현 장소 : 스테이지 2
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

// 멧돼지
// 해당 에너미의 출현 장소 : 스테이지 2
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

// 스켈레톤
// 해당 에너미의 출현 장소 : 스테이지 3
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

// 스켈레톤 메이지
// 해당 에너미의 출현 장소 : 스테이지 3
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

// 드래곤
// 해당 에너미의 출현 장소 : 스테이지 3
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

// 보스
// 해당 에너미의 출현 장소 : 보스룸
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