#include "stdafx.h"
#include "player.h"


HRESULT player::init()
{
	
	//아타호 이미지
	IMAGEMANAGER->addFrameImage("아타호정면", "image/player/아타호 정면.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호왼쪽", "image/player/아타호 왼쪽.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호오른쪽", "image/player/아타호 오른쪽.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호뒷모습", "image/player/아타호 뒷모습.bmp", 50, 80, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호위로이동", "image/player/아타호 위로이동.bmp", 180, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호아래이동", "image/player/아타호 아래이동.bmp", 190, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호오른쪽이동", "image/player/아타호 오른쪽이동.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호왼쪽이동", "image/player/아타호 왼쪽이동.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("아타호노익장대폭발", "image/player/아타호 노익장대폭발.bmp", 220, 80, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호맹호광파참", "image/player/아타호 맹호광파참.bmp", 244, 85, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호맹호난무", "image/player/아타호 맹호난무.bmp", 1912, 110, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호맹호스페셜", "image/player/아타호 맹호스페셜.bmp", 3520, 172, 20, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호호격권", "image/player/아타호 호격권.bmp", 1100, 90, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호왼쪽이동", "image/player/아타호 왼쪽이동.bmp", 200, 80, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아타호만취", "image/player/아타호 만취.bmp", 502, 85, 8, 1, true, RGB(255, 0, 255));

	_image = IMAGEMANAGER->findImage("아타호정면");
	
	_x = WINSIZEX / 2;
	_y = WINSIZEY/2;
	_imageFrame	= 0;
	_frame		= 0;
	_moveSpeed  = 5;

	return S_OK;
}

void player::update()
{
	image();		 //이미지
	keyManager();	 //키
	move();			 //움직임
	imageFrame();	 //이미지프레임


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
	//렉트 갱신
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	//움직이는 모션
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

	//정자세
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
		_image = IMAGEMANAGER->findImage("아타호노익장대폭발");

	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_image = IMAGEMANAGER->findImage("아타호만취");
		
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_image = IMAGEMANAGER->findImage("아타호맹호광파참");
	}
	if (KEYMANAGER->isStayKeyDown('F'))
	{
		_image = IMAGEMANAGER->findImage("아타호맹호난무");

	}
	if (KEYMANAGER->isStayKeyDown('G'))
	{
		_image = IMAGEMANAGER->findImage("아타호맹호스페셜");

	}
	if (KEYMANAGER->isStayKeyDown('H'))
	{
		_image = IMAGEMANAGER->findImage("아타호호격권");

	}



}

void player::image()
{
	switch (_move)
	{
	case LEFT:
		_image = IMAGEMANAGER->findImage("아타호왼쪽");
		break;
	case RIGHT:
		_image = IMAGEMANAGER->findImage("아타호오른쪽");
		break;
	case FRONT:
		_image = IMAGEMANAGER->findImage("아타호정면");
		break;
	case BACK:
		_image = IMAGEMANAGER->findImage("아타호뒷모습");
		break;
	case LEFTMOVE:
		_image = IMAGEMANAGER->findImage("아타호왼쪽이동");
		break;
	case RIGHTMOVE:
		_image = IMAGEMANAGER->findImage("아타호오른쪽이동");
		break;
	case DOWNMOVE:
		_image = IMAGEMANAGER->findImage("아타호아래이동");
		break;
	case UPMOVE:
		_image = IMAGEMANAGER->findImage("아타호위로이동");
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
			if (_image == IMAGEMANAGER->findImage("아타호만취"))
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
