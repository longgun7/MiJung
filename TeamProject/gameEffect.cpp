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

// ���� ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitLUDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitLUDiagonal", x, y);
}

// ���� �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitLDDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitLDDiagonal", x, y);
}

// ������ ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitRUDiagonal(float x, float y)
{
	EFFECTMANAGER->play("CutEffect", x, y);
}

// ������ �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitRDDiagonal(float x, float y)
{
	EFFECTMANAGER->play("HitRDDiagonal", x, y);
}

// ���� ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitLUDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitLUDiagonal2", x, y);
}

// ���� �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitLDDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitLDDiagonal2", x, y);
}

// ������ ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitRUDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitRUDiagonal2", x, y);
}

// ������ �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::hitRDDiagonal2(float x, float y)
{
	EFFECTMANAGER->play("HitRDDiagonal2", x, y);
}

// ���� �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::summonLCloud(float x, float y)
{
	EFFECTMANAGER->play("LCloud", x, y);
}

// ������ �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::summonRCloud(float x, float y)
{
	EFFECTMANAGER->play("RCloud", x, y);
}

// ���� �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::summonLSpeed(float x, float y)
{
	EFFECTMANAGER->play("LSpeed", x, y);
}

// ������ �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
void gameEffect::summonRSpeed(float x, float y)
{
	EFFECTMANAGER->play("RSpeed", x, y);
}
