#pragma once
#include "enemy.h"

enum SKELETONDIRECTION
{
	SKELETON_LEFT_MOVE,	// �������� �̵�
	SKELETON_TOP_MOVE,	// ���� �̵�
	SKELETON_RIGHT_MOVE,	// ���������� �̵�
	SKELETON_BOTTOM_MOVE,	// �Ʒ��� �̵�
	SKELETON_STAND,	// ������ �� ����
	SKELETON_ATTACK,	// ���� ���
	SKELETON_HIT,	// �´� ���
	SKELETON_DEAD	// �״� ���
};

struct tagSkeleton	// ���̷��� ����ü
{
	float x;	// ���̷��� x��ǥ
	float y;	// ���̷��� y ��ǥ
	float speed;	// ���̷��� ���ǵ�

	bool tileAttribute;	// ���̷����� �� �ִ� Ÿ���� �Ӽ�
	bool isAlive;	// �ذ��� ����ִ���

	image* _image;	// �ذ� �̹���
	image* deadImage;	// �ذ� ���� �̹���

	SKELETONDIRECTION direction;	// �ذ� ����
};

class skeleton : public enemy
{
private:

	vector<tagSkeleton> _vEnemy;
	vector<tagSkeleton>::iterator _viEnemy;

	tagSkeleton _tagSkeleton;

	animation* _skeletonMotion;

	int _moveCount;	// ���� �ð����� ������ �ٲٱ� ���� ������ ī��Ʈ

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void setSkeleton();	// ���̷��� ��ġ
	virtual void move();	// ���̷��� ������
	virtual void checkCoolide();	// ���̷���� �÷��̾� �浹ó��



	skeleton();
	~skeleton();
};

