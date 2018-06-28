#include "stdafx.h"
#include "skeleton.h"


HRESULT skeleton::init()
{
	_tagSkeleton._image = IMAGEMANAGER->addFrameImage("스켈레톤", "image/스켈레톤.bmp", 0, 0, 270, 360, 5, 5, true, RGB(255, 0, 255)); // 스켈레톤 이미지 추가
	_tagSkeleton.deadImage = IMAGEMANAGER->addImage("데드스켈레톤", "image/해골시체.bmp", 74, 55, true, RGB(255, 0, 255));	// 스켈레톤 죽는 이미지

	_tagSkeleton.speed = 50.0f;	// 이동 속도 50.0

	_tagSkeleton.isAlive == true;

	_tagSkeleton.direction = SKELETON_RIGHT_MOVE;	// 기본 디렉선은 오른쪽으로 이동

	int leftMove[] = { 15, 16, 17, 18, 19 };	// 왼쪽으로 이동
	KEYANIMANAGER->addArrayFrameAnimation("skeletonLeftMove", "skeleton", leftMove, 5, 10, false);

	int topMove[] = { 5, 6, 7, 8, 9 };	// 위로 이동
	KEYANIMANAGER->addArrayFrameAnimation("skeletonTopMove", "skeleton", topMove, 5, 10, false);

	int rightMove[] = { 10, 11, 12, 13, 14 };	// 오른쪽으로 이동
	KEYANIMANAGER->addArrayFrameAnimation("skeletonRightMove", "skeleton", rightMove, 5, 10, false);

	int bottomMove[] = { 0, 1, 2, 3, 4 };	// 아래로 이동
	KEYANIMANAGER->addArrayFrameAnimation("skeletonBottomMove", "skeleton", bottomMove, 5, 10, false);

	int stand[] = { 20, 21 };	// 가만히 있느 상태
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
		_tagSkeleton._image->init("image/스켈레톤.bmp", 270, 360, true, RGB(255, 0, 255));
		_tagSkeleton.deadImage->init("image/데드스켈레톤.bmp", 74, 55, true, RGB(255, 0, 255));
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
