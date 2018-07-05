#pragma once
#include "gameNode.h"

class gameEffect : public gameNode
{
private:


public:
	gameEffect();
	~gameEffect();

	HRESULT init();
	void realse();
	void update();
	void render();

	// 왼쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void hitLUDiagonal(float x, float y);
	// 왼쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void hitLDDiagonal(float x, float y);
	// 오른쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void hitRUDiagonal(float x, float y);
	// 오른쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void hitRDDiagonal(float x, float y);

	// 왼쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void hitLUDiagonal2(float x, float y);
	// 왼쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void hitLDDiagonal2(float x, float y);
	// 오른쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void hitRUDiagonal2(float x, float y);
	// 오른쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void hitRDDiagonal2(float x, float y);

	// 왼쪽 이동 중 구름 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void summonLCloud(float x, float y);
	// 오른쪽 이동 중 구름 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void summonRCloud(float x, float y);

	// 왼쪽 이동 중 급한 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void summonLSpeed(float x, float y);
	// 오른쪽 이동 중 급한 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
	void summonRSpeed(float x, float y);
};

