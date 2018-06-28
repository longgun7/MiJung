#pragma once
#include "enemy.h"

enum SKELETONDIRECTION
{
	SKELETON_LEFT_MOVE,	// 왼쪽으로 이동
	SKELETON_TOP_MOVE,	// 위로 이동
	SKELETON_RIGHT_MOVE,	// 오른쪽으로 이동
	SKELETON_BOTTOM_MOVE,	// 아래로 이동
	SKELETON_STAND,	// 가만히 서 있음
	SKELETON_ATTACK,	// 공격 모션
	SKELETON_HIT,	// 맞는 모션
	SKELETON_DEAD	// 죽는 모션
};

struct tagSkeleton	// 스켈레톤 구조체
{
	float x;	// 스켈레톤 x좌표
	float y;	// 스켈레톤 y 좌표
	float speed;	// 스켈레톤 스피드

	bool tileAttribute;	// 스켈레톤이 서 있는 타일의 속성
	bool isAlive;	// 해골이 살아있는지

	image* _image;	// 해골 이미지
	image* deadImage;	// 해골 죽은 이미지

	SKELETONDIRECTION direction;	// 해골 상태
};

class skeleton : public enemy
{
private:

	vector<tagSkeleton> _vEnemy;
	vector<tagSkeleton>::iterator _viEnemy;

	tagSkeleton _tagSkeleton;

	animation* _skeletonMotion;

	int _moveCount;	// 일정 시간마다 방향을 바꾸기 위한 움직임 카운트

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void setSkeleton();	// 스켈레톤 배치
	virtual void move();	// 스켈레톤 움직임
	virtual void checkCoolide();	// 스켈레톤과 플레이어 충돌처리



	skeleton();
	~skeleton();
};

