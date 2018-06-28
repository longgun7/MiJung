#include "stdafx.h"
#include "player2.h"

HRESULT player2::init()
{

	//������ �̹���
	IMAGEMANAGER->addFrameImage("����������", "image/player/������ ����.bmp", 50, 78, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "image/player/������ ����.bmp", 40, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������������", "image/player/������ ������.bmp", 45, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������޸��", "image/player/������ �޸��.bmp", 45, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����������̵�", "image/player/������ �����̵�.bmp", 190, 84, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������Ʒ��̵�", "image/player/������ �Ʒ��̵�.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������������̵�", "image/player/������ �������̵�.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����������̵�", "image/player/������ �����̵�.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	
	//������ ��ų
	IMAGEMANAGER->addFrameImage("��������Ÿ��", "image/player/������ ��Ÿ��.bmp", 402, 85, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����������", "image/player/������ �����.bmp", 2000, 87, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����������ư���", "image/player/������ ���� ���ư���.bmp", 2000, 120, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������������", "image/player/������ ������.bmp", 5240, 140, 36, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������������", "image/player/������ ������.bmp", 1615, 100, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������н�", "image/player/������ �н�.bmp", 99, 85, 2, 1, true, RGB(255, 0, 255));

	//�ʱ� ���������
	_image = IMAGEMANAGER->findImage("����������");

	//������ ����
	_x = WINSIZEX / 3;
	_y = WINSIZEY / 3;
	_imageFrame = 0;
	_frame = 0;
	_skillFrame = 0;
	_moveSpeed = 5;
	_isMotionLive = false;
	return S_OK;
}

void player2::update()
{
	image();		 //�̹���
	keyManager();	 //Ű
	if (_isMotionLive)
	{
		imageFrame();	 //�̹���������
	}
	move();			 //������
}

void player2::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	
	//image
	_image->frameRender(getMemDC(), _rc.left, _rc.top);
}

void player2::release()
{
}

void player2::keyManager()
{
	//��Ʈ ����
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	//�����̴� ���
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_move = S_LEFTMOVE;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_move = S_RIGHTMOVE;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_move = S_UPMOVE;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_move = S_DOWNMOVE;
		_isMotionLive = true;
	}

	//���ڼ�
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_move = S_FRONT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_move = S_LEFT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_move = S_RIGHT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_move = S_BACK;

	}

	//��ų
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_move = S_SOLOSKILL1;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_move = S_SOLOSKILL2;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_move = S_SOLOSKILL3;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_move = S_AREASKILL1;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isOnceKeyDown('G'))
	{
		_move = S_AREASKILL2;
		_isMotionLive = true;
	}
	if (KEYMANAGER->isOnceKeyDown('H'))
	{
		_move = S_AREASKILL3;
		_isMotionLive = true;
	}

}

void player2::image()
{
	//�̹���
	switch (_move)
	{
	case S_LEFT:
		_image = IMAGEMANAGER->findImage("����������");
		break;
	case S_RIGHT:
		_image = IMAGEMANAGER->findImage("������������");
		break;
	case S_FRONT:
		_image = IMAGEMANAGER->findImage("����������");
		break;
	case S_BACK:
		_image = IMAGEMANAGER->findImage("�������޸��");
		break;
	case S_LEFTMOVE:
		_image = IMAGEMANAGER->findImage("�����������̵�");
		break;
	case S_RIGHTMOVE:
		_image = IMAGEMANAGER->findImage("�������������̵�");
		break;
	case S_DOWNMOVE:
		_image = IMAGEMANAGER->findImage("�������Ʒ��̵�");
		break;
	case S_UPMOVE:
		_image = IMAGEMANAGER->findImage("�����������̵�");
		break;
	case S_SOLOSKILL1:
		_image = IMAGEMANAGER->findImage("��������Ÿ��");
		break;
	case S_SOLOSKILL2:
		_image = IMAGEMANAGER->findImage("������������");
		break;
	case S_SOLOSKILL3:
		_image = IMAGEMANAGER->findImage("�����������ư���");
		break;
	case S_AREASKILL1:
		_image = IMAGEMANAGER->findImage("�����������");
		break;
	case S_AREASKILL2:
		_image = IMAGEMANAGER->findImage("������������");
		break;
	case S_AREASKILL3:
		_image = IMAGEMANAGER->findImage("�������н�");
		break;
	default:
		break;
	}
}

void player2::imageFrame()
{
	//�̹���������
	++_frame;

	if (_frame % 7 == 0)
	{

		++_imageFrame;

		_image->setFrameX(_imageFrame);

		if (_imageFrame >= _image->getMaxFrameX())
		{
			_imageFrame = -1;
		}
		_frame = 0;
	}
	

}



void player2::move()
{
	//�̵�
	switch (_move)
	{
	case S_LEFT:
		break;
	case S_RIGHT:
		break;
	case S_FRONT:
		break;
	case S_BACK:
		break;
	case S_LEFTMOVE:
		_x -= _moveSpeed;
		break;
	case S_RIGHTMOVE:
		_x += _moveSpeed;
		break;
	case S_DOWNMOVE:
		_y += _moveSpeed;
		break;
	case S_UPMOVE:
		_y -= _moveSpeed;
		break;
	default:
		break;
	}

	//��ų �̵�

	//��Ÿ��
	if (_image == IMAGEMANAGER->findImage("��������Ÿ��") && _x < WINSIZEX -100)
	{	
		_imageFrame = 1;
		_image->setFrameX(1);
		_x += 10;
	}
	if (_image == IMAGEMANAGER->findImage("��������Ÿ��") && _x > WINSIZEX - 100)
	{
		if (_image->getFrameX() >= _image->getMaxFrameX())
		{
			_move = S_RIGHT;
		}
	}
}




player2::player2()
{
}


player2::~player2()
{
}
