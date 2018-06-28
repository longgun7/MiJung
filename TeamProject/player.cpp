#include "stdafx.h"
#include "player.h"


HRESULT player::init()
{
	
	//��Ÿȣ �̹���
	IMAGEMANAGER->addFrameImage("��Ÿȣ����", "image/player/��Ÿȣ ����.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ����", "image/player/��Ÿȣ ����.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ������", "image/player/��Ÿȣ ������.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�޸��", "image/player/��Ÿȣ �޸��.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����̵�", "image/player/��Ÿȣ �����̵�.bmp", 180, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�Ʒ��̵�", "image/player/��Ÿȣ �Ʒ��̵�.bmp", 190, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�������̵�", "image/player/��Ÿȣ �������̵�.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����̵�", "image/player/��Ÿȣ �����̵�.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����������", "image/player/��Ÿȣ �����������.bmp", 220, 80, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ��ȣ������", "image/player/��Ÿȣ ��ȣ������.bmp", 244, 85, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ��ȣ����", "image/player/��Ÿȣ ��ȣ����.bmp", 1912, 110, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ��ȣ�����", "image/player/��Ÿȣ ��ȣ�����.bmp", 3520, 172, 20, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣȣ�ݱ�", "image/player/��Ÿȣ ȣ�ݱ�.bmp", 1100, 90, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ�����̵�", "image/player/��Ÿȣ �����̵�.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ÿȣ����", "image/player/��Ÿȣ ����.bmp", 502, 85, 8, 1, true, RGB(255, 0, 255));

	_image = IMAGEMANAGER->findImage("��Ÿȣ����");
	
	_x = WINSIZEX / 2;
	_y = WINSIZEY/2;
	_imageFrame	= 0;
	_frame		= 0;
	_moveSpeed  = 5;

	return S_OK;
}

void player::update()
{
	image();		 //�̹���
	keyManager();	 //Ű
	move();			 //������
	imageFrame();	 //�̹���������


}

void player::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	//image
	_image->frameRender(getMemDC(), _rc.left, _rc.top);
}

void player::release()
{
}

void player::keyManager()
{
	//��Ʈ ����
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	//�����̴� ���
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_move = LEFTMOVE;

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_move = RIGHTMOVE;

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_move = UPMOVE;

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_move = DOWNMOVE;

	}

	//���ڼ�
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_move = FRONT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_move = LEFT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_move = RIGHT;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_move = BACK;

	}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_image = IMAGEMANAGER->findImage("��Ÿȣ�����������");

	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_image = IMAGEMANAGER->findImage("��Ÿȣ����");
		
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_image = IMAGEMANAGER->findImage("��Ÿȣ��ȣ������");
	}
	if (KEYMANAGER->isStayKeyDown('F'))
	{
		_image = IMAGEMANAGER->findImage("��Ÿȣ��ȣ����");

	}
	if (KEYMANAGER->isStayKeyDown('G'))
	{
		_image = IMAGEMANAGER->findImage("��Ÿȣ��ȣ�����");

	}
	if (KEYMANAGER->isStayKeyDown('H'))
	{
		_image = IMAGEMANAGER->findImage("��Ÿȣȣ�ݱ�");

	}



}

void player::image()
{
	switch (_move)
	{
	case LEFT:
		_image = IMAGEMANAGER->findImage("��Ÿȣ����");
		break;
	case RIGHT:
		_image = IMAGEMANAGER->findImage("��Ÿȣ������");
		break;
	case FRONT:
		_image = IMAGEMANAGER->findImage("��Ÿȣ����");
		break;
	case BACK:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�޸��");
		break;
	case LEFTMOVE:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�����̵�");
		break;
	case RIGHTMOVE:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�������̵�");
		break;
	case DOWNMOVE:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�Ʒ��̵�");
		break;
	case UPMOVE:
		_image = IMAGEMANAGER->findImage("��Ÿȣ�����̵�");
		break;
	default:
		break;
	}
}

void player::imageFrame()
{
	
	++_frame;
	
	
	if (_frame % 10 == 0)
	{
		++_imageFrame;

		_image->setFrameX(_imageFrame);
		
		if (_imageFrame >= _image->getMaxFrameX())
		{
			_imageFrame = -1;
			if (_image == IMAGEMANAGER->findImage("��Ÿȣ����"))
			{
				_imageFrame = 1;
			}
		}
		_frame = 0;
	}

}



void player::move()
{
	switch (_move)
	{
	case LEFT:
		break;
	case RIGHT:
		break;
	case FRONT:
		break;
	case BACK:
		break;
	case LEFTMOVE:
		_x -= _moveSpeed;
		break;
	case RIGHTMOVE:
		_x += _moveSpeed;
		break;
	case DOWNMOVE:
		_y += _moveSpeed;
		break;
	case UPMOVE:
		_y -= _moveSpeed;
		break;
	default:
		break;
	}
}




player::player()
{
}


player::~player()
{
}
