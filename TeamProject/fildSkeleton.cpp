#include "stdafx.h"
#include "fildSkeleton.h"


HRESULT fildSkeleton::init()
{
	 _img = IMAGEMANAGER->addFrameImage("���̷���", "image/enemy/���̷���.bmp", 270, 360, 5, 5, true, RGB(255, 0, 255), true);	// ���̷��� �̹���

	 _alphaValue = 255;							// ���� ������ ���İ� 255�� ������, 0�� ����� ���� ����
	 _direction = SKELETON_STAND;				// �⺻ ���´� ������ �ִ� ����
	 _moveCount2 = 0;							// ���� �ð����� �������� �ٲٱ� ���� ī��Ʈ 0���� �ʱ�ȭ
	 _speed = 1.0f;								// �̵��ӵ��� 1.0f
	 _currentFrameX = _currentFrameY = 0;		// ������ �̹��� Y�� ������ ���� �ε����� 0���� �ʱ�ȭ
	 _count = 0;								// ������ ���� ī��Ʈ
	 _moveCount = 4;							// ������ �ٲٱ� ���� ī��Ʈ 0~3���� �̵� 4�� ������ �ִ� ����
	 _setSkeleton = false;						// ���̷����� ��ġ ����

	return S_OK;
}

void fildSkeleton::release()
{
}

void fildSkeleton::update()
{
	if (KEYMANAGER->isOnceKeyDown('Y'))	// Y��ư�� ������
	{
		_alphaValue -= 30;				// ���� ������ ���İ��� 30 �پ�� >> ������ ������
	}
	if (KEYMANAGER->isOnceKeyDown('T'))	// T��ư�� ������
	{
		_alphaValue += 30;				// ���� ������ ���İ��� 30 ������ >> ������ ������, �������� ������
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

	move();		// move�Լ� ȣ��
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
	_x = x;			// enemyManager.init���� x�� �ҷ���
	_y = y;			// enemyManager.init���� y�� �ҷ���
}

void fildSkeleton::move()
{
	_moveCount2++;														// _moveCount2�� ��� ++ ����

	if (_moveCount2 % 200 == 0)											// _moveCount ������ 200�� 0�� �� 
	{
		_moveCount = RND->getInt(4);									// _movecount�� 0~3������ �������� �ο��Ѵ�

		_moveCount2 = 0;												// _moveCount2�� �ٽ� 0���� �ʱ�ȭ
	}

	if (_moveCount == 0 && _x > 0)										// _moveCount�� 0�̰� �� �������� ������ �ʰ� �ϱ� ���� ����ó��
	{
		_direction = SKELETON_LEFT_MOVE;											// ���¸� ���� �̵�
		_currentFrameY = 3;												// ���� ������ Y�� 3

		_x -= _speed;													// x��ǥ�� speed��ŭ ���ش�
	}
	if (_moveCount == 1 && _x + _img->getFrameWidth() < WINSIZEX)		// _moveCount�� 1�̰� �� ���������� ������ �ʰ�[ �ϱ� ���� ����ó��
	{
		_direction = SKELETON_RIGHT_MOVE;										// ���´� ������ �̵�
		_currentFrameY = 2;												// ���� ������ Y�� 2

		_x += _speed;													// x��ǥ�� speed��ŭ �����ش�
	}
	if (_moveCount == 2 && _y > 0)										// _moveCount�� 2�̰� �� ���� ������ �ʰ� �ϱ� ���� ����ó��
	{
		_direction = SKELETON_UP_MOVE;											// ���´� ���� �̵�
		_currentFrameY = 1;												// ���� ������ Y�� 1

		_y -= _speed;													// y��ǥ�� speed��ŭ ���ش�
	}
	if (_moveCount == 3 && _y + _img->getFrameHeight() < WINSIZEY)		// _moveCount�� 3�̰� �� �Ʒ��� ������ �ʰ� �ϱ� ���� ����ó��
	{
		_direction = SKELETON_DOWN_MOVE;											// ���´� �Ʒ��� �̵�
		_currentFrameY = 0;												// ���� ������ Y�� 0

		_y += _speed;													// y��ǥ�� speed��ŭ �����ش�
	}
	if (_direction == SKELETON_STAND)											// ���°� ������ �ִ� ���¶��
	{
		_currentFrameY = 4;												// ���� ������ Y�� 4
	}

	_rc = RectMake(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());	// ���̷����� ��ǥ�� ������ �̹��� ũ�⿡ ���缭 ��Ʈ�� �׸�

	_count++;	// _count�� ++���ش�

	if (_count % 10 == 0)												// _count ������ 10�� 0�̶��
	{															
		if (_direction == SKELETON_STAND)										// ���°� ������ �ִ� ���¶��
		{														
			_currentFrameX++;											// _currentFrameX�� ++���ش�

			if (_currentFrameX > 1) _currentFrameX = 0;					// _currentFrameX�� 1���� ũ�� _currentFrameX�� 0���� �ʱ�ȭ�Ѵ�								
		}														
		else															// if ������ �ƴ϶��
		{														
			if (_currentFrameX >= _img->getMaxFrameX()) _currentFrameX = 0;		// _currentFrameX�� _img�� getMaxFrameX���� ũ�ų� ���� ��� _currentFrameX�� 0���� �ʱ�ȭ�Ѵ�
																
			_currentFrameX++;											// _currentFrameX�� ++���ش�
		}														
																
		_count = 0;														// _count�� 0���� �ʱ�ȭ�Ѵ�
	}

}

fildSkeleton::fildSkeleton()
{
}


fildSkeleton::~fildSkeleton()
{
}
