#pragma once
#include "gameNode.h"

enum DIRECTION
{
	STAND,	// 가만히 있는 상태
	ATTACK,	// 공격
	HIT,	// 맞는 상태
	DEAD	// 죽음
};

struct tagEnemy	// 에너미 구조체
{
	image* img;	// 이미지

	RECT rc;	// 렉트
	
	DIRECTION direction;	// 상태

	int hp;					// 체력
	int att;				// 공격력
	int def;				// 방어력
	int miss;				// 회피율
	int exp;				// 경험치
	int currentFrameX;		// 현재 X프레임
	int currentFrameY;		// 현재 Y프레임
	int alphaValue;			// 투명 불투명 수치
	int count;				// 프레임 감을 카운트
	int hitCount;			// 맞는 프레임 지속시간을 정해주는 카운트
	int deadCount;			// 죽을 때 깜빡거리면서 사라지게 하기 위한 카운트
	int fadeCount;			// 서서히 투명화 되면서 사라지게 해주는 카운트
	int randAttack;			// 어떤 공격을 할지 랜덤값
	int dropGold;			// 드랍 골드
	bool isGoldSet;         // 돈을 보냈는지
	float x;				// X좌표
	float y;				// Y좌표
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

