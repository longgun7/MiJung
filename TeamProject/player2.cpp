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


	_image = IMAGEMANAGER->findImage("����������");

	_x = WINSIZEX / 3;
	_y = WINSIZEY / 3;
	_imageFrame = 0;
	_frame = 0;
	_moveSpeed = 5;

	return S_OK;
}

void player2::update()
{
	image();		 //�̹���
	keyManager();	 //Ű
	move();			 //������
	imageFrame();	 //�̹���������


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
		_move = SLEFTMOVE;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_move = SRIGHTMOVE;

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_move = SUPMOVE;

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_move = SDOWNMOVE;

	}

	//���ڼ�
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_move = SFRONT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_move = SLEFT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_move = SRIGHT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_move = SBACK;

	}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_image = IMAGEMANAGER->findImage("��������Ÿ��");

	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_image = IMAGEMANAGER->findImage("������������");

	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_image = IMAGEMANAGER->findImage("�����������ư���");

	}
	if (KEYMANAGER->isStayKeyDown('F'))
	{
		_image = IMAGEMANAGER->findImage("�����������");

	}
	if (KEYMANAGER->isStayKeyDown('G'))
	{
		_image = IMAGEMANAGER->findImage("������������");

	}
	if (KEYMANAGER->isStayKeyDown('H'))
	{
		_image = IMAGEMANAGER->findImage("�������н�");
	}

}

void player2::image()
{
	switch (_move)
	{
	case SLEFT:
		_image = IMAGEMANAGER->findImage("����������");
		break;
	case SRIGHT:
		_image = IMAGEMANAGER->findImage("������������");
		break;
	case SFRONT:
		_image = IMAGEMANAGER->findImage("����������");
		break;
	case SBACK:
		_image = IMAGEMANAGER->findImage("�������޸��");
		break;
	case SLEFTMOVE:
		_image = IMAGEMANAGER->findImage("�����������̵�");
		break;
	case SRIGHTMOVE:
		_image = IMAGEMANAGER->findImage("�������������̵�");
		break;
	case SDOWNMOVE:
		_image = IMAGEMANAGER->findImage("�������Ʒ��̵�");
		break;
	case SUPMOVE:
		_image = IMAGEMANAGER->findImage("�����������̵�");
		break;
	default:
		break;
	}
}

void player2::imageFrame()
{

	++_frame;

	if (_frame % 5 == 0)
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
	switch (_move)
	{
	case SLEFT:
		break;
	case SRIGHT:
		break;
	case SFRONT:
		break;
	case SBACK:
		break;
	case SLEFTMOVE:
		_x -= _moveSpeed;
		break;
	case SRIGHTMOVE:
		_x += _moveSpeed;
		break;
	case SDOWNMOVE:
		_y += _moveSpeed;
		break;
	case SUPMOVE:
		_y -= _moveSpeed;
		break;
	default:
		break;
	}
}




player2::player2()
{
}


player2::~player2()
{
}
