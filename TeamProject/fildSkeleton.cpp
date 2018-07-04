#include "stdafx.h"
#include "fildSkeleton.h"


HRESULT fildSkeleton::init()
{
	 _img = IMAGEMANAGER->addFrameImage("스켈레톤", "image/enemy/스켈레톤.bmp", 270, 360, 5, 5, true, RGB(255, 0, 255), true);	// 스켈레톤 이미지

	 _alphaValue = 255;							// 알파 블렌딩의 알파값 255면 불투명, 0에 가까울 수록 투명
	 _direction = SKELETON_STAND;				// 기본 상태는 가만히 있는 상태
	 _moveCount2 = 0;							// 일정 시간마다 움직임을 바꾸기 위한 카운트 0으로 초기화
	 _speed = 1.0f;								// 이동속도는 1.0f
	 _currentFrameX = _currentFrameY = 0;		// 프레임 이미지 Y와 프레임 감을 인덱스를 0으로 초기화
	 _count = 0;								// 프레임 감을 카운트
	 _moveCount = 4;							// 방향을 바꾸기 위한 카운트 0~3까지 이동 4는 가만히 있는 상태
	 _setSkeleton = false;						// 스켈레톤은 배치 안함

	return S_OK;
}

void fildSkeleton::release()
{
}

void fildSkeleton::update()
{
	if (KEYMANAGER->isOnceKeyDown('Y'))	// Y버튼을 누르면
	{
		_alphaValue -= 30;				// 알파 블렌딩의 알파값이 30 줄어듬 >> 투명도가 높아짐
	}
	if (KEYMANAGER->isOnceKeyDown('T'))	// T버튼을 누르면
	{
		_alphaValue += 30;				// 알파 블렌딩의 알파값이 30 높아짐 >> 투명도가 낮아짐, 불투명도가 높아짐
	}
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_setSkeleton = true;
	}
	if (_setSkeleton == true)
	{
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			_setSkeleton = false;
		}
	}

	move();		// move함수 호출
}

void fildSkeleton::render()
{
	if (_setSkeleton == true)
	{
		_img->alphaFrameRender(getMemDC(), _x, _y, _currentFrameX, _currentFrameY, _alphaValue);
	}
}

void fildSkeleton::setSkeleton(float x, float y)
{
	_x = x;			// enemyManager.init에서 x를 불러옴
	_y = y;			// enemyManager.init에서 y를 불러옴
}

void fildSkeleton::move()
{
	_moveCount2++;														// _moveCount2를 계속 ++ 해줌

	if (_moveCount2 % 200 == 0)											// _moveCount 나누기 200이 0일 때 
	{
		_moveCount = RND->getInt(4);									// _movecount에 0~3까지의 랜덤값을 부여한다

		_moveCount2 = 0;												// _moveCount2를 다시 0으로 초기화
	}

	if (_moveCount == 0 && _x > 0)										// _moveCount가 0이고 맵 왼쪽으로 나가지 않게 하기 위한 예외처리
	{
		_direction = SKELETON_LEFT_MOVE;											// 상태를 왼쪽 이동
		_currentFrameY = 3;												// 현재 프레임 Y는 3

		_x -= _speed;													// x좌표를 speed만큼 빼준다
	}
	if (_moveCount == 1 && _x + _img->getFrameWidth() < WINSIZEX)		// _moveCount가 1이고 맵 오른쪽으로 나가지 않게[ 하기 위한 예외처리
	{
		_direction = SKELETON_RIGHT_MOVE;										// 상태는 오른쪽 이동
		_currentFrameY = 2;												// 현재 프레임 Y는 2

		_x += _speed;													// x좌표를 speed만큼 더해준다
	}
	if (_moveCount == 2 && _y > 0)										// _moveCount가 2이고 맵 위로 나가지 않게 하기 위한 예외처리
	{
		_direction = SKELETON_UP_MOVE;											// 상태는 위로 이동
		_currentFrameY = 1;												// 현재 프레임 Y는 1

		_y -= _speed;													// y좌표를 speed만큼 빼준다
	}
	if (_moveCount == 3 && _y + _img->getFrameHeight() < WINSIZEY)		// _moveCount가 3이고 맵 아래로 나가지 않게 하기 위한 예외처리
	{
		_direction = SKELETON_DOWN_MOVE;											// 상태는 아래로 이동
		_currentFrameY = 0;												// 현재 프레임 Y는 0

		_y += _speed;													// y좌표를 speed만큼 더해준다
	}
	if (_direction == SKELETON_STAND)											// 상태가 가만히 있는 상태라면
	{
		_currentFrameY = 4;												// 현재 프레임 Y는 4
	}

	_rc = RectMake(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());	// 스켈레톤의 좌표와 프레임 이미지 크기에 맞춰서 렉트를 그림

	_count++;	// _count를 ++해준다

	if (_count % 10 == 0)												// _count 나누기 10이 0이라면
	{															
		if (_direction == SKELETON_STAND)										// 상태가 가만히 있는 상태라면
		{														
			_currentFrameX++;											// _currentFrameX를 ++해준다

			if (_currentFrameX > 1) _currentFrameX = 0;					// _currentFrameX가 1보다 크면 _currentFrameX를 0으로 초기화한다								
		}														
		else															// if 조건이 아니라면
		{														
			if (_currentFrameX >= _img->getMaxFrameX()) _currentFrameX = 0;		// _currentFrameX가 _img의 getMaxFrameX보다 크거나 같을 경우 _currentFrameX를 0으로 초기화한다
																
			_currentFrameX++;											// _currentFrameX를 ++해준다
		}														
																
		_count = 0;														// _count를 0으로 초기화한다
	}

}

fildSkeleton::fildSkeleton()
{
}


fildSkeleton::~fildSkeleton()
{
}
