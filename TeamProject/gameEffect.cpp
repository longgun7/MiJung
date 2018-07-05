#include "stdafx.h"
#include "gameEffect.h"


gameEffect::gameEffect()
{
}


gameEffect::~gameEffect()
{
}

HRESULT gameEffect::init()
{
	EFFECTMANAGER->addEffect("HitLUDiagonal", "image/effect/HitLUDiagonal.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitLDDiagonal", "image/effect/HitLDDiagonal.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("CutEffect", "image/effect/CutEffect.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitRDDiagonal", "image/effect/HitRDDiagonal.bmp", 144, 48, 48, 48, 1.0f, 0.2f, 1);

	EFFECTMANAGER->addEffect("HitLUDiagonal2", "image/effect/HitLUDiagonal2.bmp", 128, 48, 32, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitLDDiagonal2", "image/effect/HitLDDiagonal2.bmp", 128, 48, 32, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitRUDiagonal2", "image/effect/HitRUDiagonal2.bmp", 128, 48, 32, 48, 1.0f, 0.2f, 1);
	EFFECTMANAGER->addEffect("HitRDDiagonal2", "image/effect/HitRDDiagonal2.bmp", 128, 48, 32, 48, 1.0f, 0.2f, 1);

	EFFECTMANAGER->addEffect("LCloud", "image/effect/LCloud.bmp", 160, 32, 32, 32, 1.0f, 0.5f, 3);
	EFFECTMANAGER->addEffect("RCloud", "image/effect/RCloud.bmp", 160, 32, 32, 32, 1.0f, 0.5f, 3);

	EFFECTMANAGER->addEffect("LSpeed", "image/effect/LSpeed.bmp", 256, 48, 64, 48, 1.0f, 0.5f, 3);
	EFFECTMANAGER->addEffect("RSpeed", "image/effect/RSpeed.bmp", 256, 48, 64, 48, 1.0f, 0.5f, 3);
	return S_OK;
}

void gameEffect::realse()
{
}

void gameEffect::update()
{
	EFFECTMANAGER->update();
}

void gameEffect::render()
{
	EFFECTMANAGER->render();
}

// 왼쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitLUDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitLUDiagonal", x, y);
}

// 왼쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitLDDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitLDDiagonal", x, y);
}

// 오른쪽 위로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitRUDiagonal(float x, float y)
{
	EFFECTMANAGER->play("CutEffect", x, y);
}

// 오른쪽 아래로 튀기는 큰 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitRDDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitRDDiagonal", x, y);
}

// 왼쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitLUDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitLUDiagonal2", x, y);
}

// 왼쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitLDDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitLDDiagonal2", x, y);
}

// 오른쪽 위로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitRUDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitRUDiagonal2", x, y);
}

// 오른쪽 아래로 튀기는 작은 타격 이미지 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::hitRDDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitRDDiagonal2", x, y);
}

// 왼쪽 이동 중 구름 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::summonLCloud(float x, float y)
{
	EFFECTMANAGER->play("LCloud", x, y);
}

// 오른쪽 이동 중 구름 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::summonRCloud(float x, float y)
{
	EFFECTMANAGER->play("RCloud", x, y);
}

// 왼쪽 이동 중 급한 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::summonLSpeed(float x, float y)
{
	EFFECTMANAGER->play("LSpeed", x, y);
}

// 오른쪽 이동 중 급한 이미지 생성 x(그릴 중점 좌표), y(그릴 중점 좌표)
void gameEffect::summonRSpeed(float x, float y)
{
	EFFECTMANAGER->play("RSpeed", x, y);
}
