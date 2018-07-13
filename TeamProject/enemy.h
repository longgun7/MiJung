#pragma once
#include "gameNode.h"

#define Count 18
#define dCount 6
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
	
	DIRECTION direction;		// 상태

	string name;			// 적 이름

	int hp;						// 현재 체력	
	int totalHp;				// 체력
	int att;					// 공격력
	int def;					// 방어력
	int miss;					// 회피율
	int exp;					// 경험치
	int currentFrameX;			// 현재 X프레임
	int currentFrameY;			// 현재 Y프레임
	int alphaValue;				// 투명 불투명 수치
	int count;					// 프레임 감을 카운트
	int hitCount;				// 맞는 프레임 지속시간을 정해주는 카운트
	int deadCount;				// 죽을 때 깜빡거리면서 사라지게 하기 위한 카운트
	int fadeCount;				// 서서히 투명화 되면서 사라지게 해주는 카운트
	int randAttack;				// 어떤 공격을 할지 랜덤값
	int dropGold;				// 드랍 골드
	int maxAttackFrameX;		// 최대 공격 프레임
	int damage;					// 데미지 출력을 위한 변수
	int skillCount;				// 보스 스킬 타이밍을 맞추기 위한 스킬 카운트

	bool isGoldSet;				// 돈을 보냈는지
	bool isAttack;				// 공격했는지
	bool isRandAttack;			// 어떤 공격을 할지 선택을 했는지
	bool isDead;				// 죽었는지
	bool isSkill;				// 스킬을 썼는지

	float x;					// X좌표
	float y;					// Y좌표
};

class enemy : public gameNode
{
protected:

	tagEnemy _enemy;							// tagEnemy를 _enemy란 이름으로 사용

public:

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	void setHp(int damage);																	// 에너미가 데미지를 입는 함수

	void setisGoldSet(bool gold) { _enemy.isGoldSet = gold; }								// 플레이어가 골드를 받아갈 수 있게 해주는 설정자
	void setEnemyDirection(DIRECTION direction) { _enemy.direction = direction; }			// 플레이어가 에너미의 상태를 설정할 수 있게 해주는 설정자
	tagEnemy getTagEnmey() { return _enemy; }												// 다른곳에서 에너미 구조체를 사용할 수 있게 반환
	void setIsDead(bool dead) { _enemy.isDead = dead; }
	void setIsAttack(bool attack) { _enemy.isAttack = attack; }
	image* getImage() { return _enemy.img; }
	enemy();
	~enemy();
};

