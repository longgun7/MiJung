#pragma once
#include "gameNode.h"

enum DIRECTION	// ����
{
	SKELETON_RIGHT_MOVE,	// ������ �̵�
	SKELETON_LEFT_MOVE,	// ���� �̵�
	SKELETON_UP_MOVE,	// ���� �̵�
	SKELETON_DOWN_MOVE,	// �Ʒ��� �̵�
	SKELETON_STAND		// ������
};



class skeleton : public gameNode
{
private:

	image * _img;			// ���̷��� �̹���
	DIRECTION _direction;	// ���̷��� ����
	RECT _rc;				// ���̷��� ��Ʈ

	float _x;				// ���̷��� x��ǥ
	float _y;				// ���̷��� y��ǥ
	float _speed;			// ���̷��� ���ǵ�

	int _count;				// ������ ���� ī��Ʈ
	int _moveCount;			// ���� �ð����� �������� ���� ī��Ʈ
	int _currentFrameX;		// ���� ������ X
	int _currentFrameY;		// ���� ������ Y
	int _alphaValue;		// ���̷��� ���� ������ ��
	int _moveCount2;		// ���� �ð����� ���̷����� �������� �ٲ�
	bool _setSkeleton;		// ���̷��� ��ġ 

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setSkeleton(float x, float y);		// ���̷��� ��ġ
	void move();							// ���̷��� �̵�, ���

	skeleton();
	~skeleton();
};

