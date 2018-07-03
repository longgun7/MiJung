#pragma once
#include "gameNode.h"

enum DIRECTION	// 상태
{
	SKELETON_RIGHT_MOVE,	// 오른쪽 이동
	SKELETON_LEFT_MOVE,	// 왼쪽 이동
	SKELETON_UP_MOVE,	// 위로 이동
	SKELETON_DOWN_MOVE,	// 아래로 이동
	SKELETON_STAND		// 가만히
};



class skeleton : public gameNode
{
private:

	image * _img;			// 스켈레톤 이미지
	DIRECTION _direction;	// 스켈레톤 상태
	RECT _rc;				// 스켈레톤 렉트

	float _x;				// 스켈레톤 x좌표
	float _y;				// 스켈레톤 y좌표
	float _speed;			// 스켈레톤 스피드

	int _count;				// 프레임 감을 카운트
	int _moveCount;			// 일정 시간마다 움직임을 위한 카운트
	int _currentFrameX;		// 현재 프레임 X
	int _currentFrameY;		// 현재 프레임 Y
	int _alphaValue;		// 스켈레톤 투명 불투명 값
	int _moveCount2;		// 일정 시간마다 스켈레톤의 움직임을 바꿈
	bool _setSkeleton;		// 스켈레톤 배치 

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setSkeleton(float x, float y);		// 스켈레톤 배치
	void move();							// 스켈레톤 이동, 모션

	skeleton();
	~skeleton();
};

