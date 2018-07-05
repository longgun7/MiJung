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

	// ���� ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void hitLUDiagonal(float x, float y);
	// ���� �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void hitLDDiagonal(float x, float y);
	// ������ ���� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void hitRUDiagonal(float x, float y);
	// ������ �Ʒ��� Ƣ��� ū Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void hitRDDiagonal(float x, float y);

	// ���� ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void hitLUDiagonal2(float x, float y);
	// ���� �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void hitLDDiagonal2(float x, float y);
	// ������ ���� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void hitRUDiagonal2(float x, float y);
	// ������ �Ʒ��� Ƣ��� ���� Ÿ�� �̹��� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void hitRDDiagonal2(float x, float y);

	// ���� �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void summonLCloud(float x, float y);
	// ������ �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void summonRCloud(float x, float y);

	// ���� �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void summonLSpeed(float x, float y);
	// ������ �̵� �� ���� �̹��� ���� x(�׸� ���� ��ǥ), y(�׸� ���� ��ǥ)
	void summonRSpeed(float x, float y);
};

