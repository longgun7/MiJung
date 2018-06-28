#include "stdafx.h"
#include "skeleton.h"


HRESULT skeleton::init()
{
	_tagSkeleton._image = IMAGEMANAGER->addFrameImage("���̷���", "image/���̷���.bmp", 0, 0, 270, 360, 5, 5, true, RGB(255, 0, 255)); // ���̷��� �̹��� �߰�
	_tagSkeleton.deadImage = IMAGEMANAGER->addImage("���彺�̷���", "image/�ذ��ü.bmp", 74, 55, true, RGB(255, 0, 255));	// ���̷��� �״� �̹���

	_tagSkeleton.speed = 50.0f;	// �̵� �ӵ� 50.0

	_tagSkeleton.isAlive == true;

	_tagSkeleton.direction = SKELETON_RIGHT_MOVE;	// �⺻ �𷺼��� ���������� �̵�

	int leftMove[] = { 15, 16, 17, 18, 19 };	// �������� �̵�
	KEYANIMANAGER->addArrayFrameAnimation("skeletonLeftMove", "skeleton", leftMove, 5, 10, false);

	int topMove[] = { 5, 6, 7, 8, 9 };	// ���� �̵�
	KEYANIMANAGER->addArrayFrameAnimation("skeletonTopMove", "skeleton", topMove, 5, 10, false);

	int rightMove[] = { 10, 11, 12, 13, 14 };	// ���������� �̵�
	KEYANIMANAGER->addArrayFrameAnimation("skeletonRightMove", "skeleton", rightMove, 5, 10, false);

	int bottomMove[] = { 0, 1, 2, 3, 4 };	// �Ʒ��� �̵�
	KEYANIMANAGER->addArrayFrameAnimation("skeletonBottomMove", "skeleton", bottomMove, 5, 10, false);

	int stand[] = { 20, 21 };	// ������ �ִ� ����
	KEYANIMANAGER->addArrayFrameAnimation("skeletonStand", "skeleton", stand, 2, 10, true);

	return S_OK;
}

void skeleton::release()
{
}

void skeleton::update()
{
	move();

	KEYANIMANAGER->update();
}

void skeleton::render()
{
	_tagSkeleton._image->aniRender(getMemDC(), _tagSkeleton.x, _tagSkeleton.y, _skeletonMotion);
}

void skeleton::setSkeleton()
{
	for (int i = 0; i < 10; i++)
	{
		tagSkeleton _tagSkeleton;
		ZeroMemory(&_tagSkeleton, sizeof(_tagSkeleton));
		_tagSkeleton._image->init("image/���̷���.bmp", 270, 360, true, RGB(255, 0, 255));
		_tagSkeleton.deadImage->init("image/���彺�̷���.bmp", 74, 55, true, RGB(255, 0, 255));
		_tagSkeleton.direction = SKELETON_RIGHT_MOVE;
		_tagSkeleton.isAlive = true;
		_tagSkeleton.speed = 50.0f;
		_tagSkeleton.x = i * 100;
		_tagSkeleton.y = WINSIZEY / 2;

		_vEnemy.push_back(_tagSkeleton);
	}
}

void skeleton::move()
{
	_moveCount = RND->getInt(4);

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_tagSkeleton.direction = SKELETON_TOP_MOVE;
		_skeletonMotion = KEYANIMANAGER->findAnimation("skeletonTopMove");
		_skeletonMotion->start();
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_tagSkeleton.direction = SKELETON_BOTTOM_MOVE;
		_skeletonMotion = KEYANIMANAGER->findAnimation("skeletonBottomMove");
		_skeletonMotion->start();
	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_tagSkeleton.direction = SKELETON_LEFT_MOVE;
		_skeletonMotion = KEYANIMANAGER->findAnimation("skeletonLeftMove");
		_skeletonMotion->start();
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_tagSkeleton.direction = SKELETON_RIGHT_MOVE;
		_skeletonMotion = KEYANIMANAGER->findAnimation("skeletonRightMove");
		_skeletonMotion->start();
	}
}

void skeleton::checkCoolide()
{
}

skeleton::skeleton()
{
}


skeleton::~skeleton()
{
}
