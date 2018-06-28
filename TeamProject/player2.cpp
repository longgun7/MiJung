#include "stdafx.h"
#include "player2.h"

HRESULT player2::init()
{

	//스마슈 이미지
	IMAGEMANAGER->addFrameImage("스마슈정면", "image/player/스마슈 정면.bmp", 50, 78, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈왼쪽", "image/player/스마슈 왼쪽.bmp", 40, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈오른쪽", "image/player/스마슈 오른쪽.bmp", 45, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈뒷모습", "image/player/스마슈 뒷모습.bmp", 45, 85, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈위로이동", "image/player/스마슈 위로이동.bmp", 190, 84, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈아래이동", "image/player/스마슈 아래이동.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈오른쪽이동", "image/player/스마슈 오른쪽이동.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈왼쪽이동", "image/player/스마슈 왼쪽이동.bmp", 180, 85, 4, 1, true, RGB(255, 0, 255));
	
	//스마슈 스킬
	IMAGEMANAGER->addFrameImage("스마슈대타격", "image/player/스마슈 대타격.bmp", 402, 85, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈용오름", "image/player/스마슈 용오름.bmp", 2000, 87, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈베고날아가기", "image/player/스마슈 베고 날아가기.bmp", 2000, 120, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈난도질", "image/player/스마슈 난도질.bmp", 5240, 140, 36, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈절사어면", "image/player/스마슈 절사어면.bmp", 1615, 100, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈분신", "image/player/스마슈 분신.bmp", 99, 85, 2, 1, true, RGB(255, 0, 255));


	_image = IMAGEMANAGER->findImage("스마슈정면");

	_x = WINSIZEX / 3;
	_y = WINSIZEY / 3;
	_imageFrame = 0;
	_frame = 0;
	_moveSpeed = 5;

	return S_OK;
}

void player2::update()
{
	image();		 //이미지
	keyManager();	 //키
	move();			 //움직임
	imageFrame();	 //이미지프레임


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
	//렉트 갱신
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	//움직이는 모션
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

	//정자세
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
		_image = IMAGEMANAGER->findImage("스마슈대타격");

	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_image = IMAGEMANAGER->findImage("스마슈절사어면");

	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_image = IMAGEMANAGER->findImage("스마슈베고날아가기");

	}
	if (KEYMANAGER->isStayKeyDown('F'))
	{
		_image = IMAGEMANAGER->findImage("스마슈용오름");

	}
	if (KEYMANAGER->isStayKeyDown('G'))
	{
		_image = IMAGEMANAGER->findImage("스마슈난도질");

	}
	if (KEYMANAGER->isStayKeyDown('H'))
	{
		_image = IMAGEMANAGER->findImage("스마슈분신");
	}

}

void player2::image()
{
	switch (_move)
	{
	case SLEFT:
		_image = IMAGEMANAGER->findImage("스마슈왼쪽");
		break;
	case SRIGHT:
		_image = IMAGEMANAGER->findImage("스마슈오른쪽");
		break;
	case SFRONT:
		_image = IMAGEMANAGER->findImage("스마슈정면");
		break;
	case SBACK:
		_image = IMAGEMANAGER->findImage("스마슈뒷모습");
		break;
	case SLEFTMOVE:
		_image = IMAGEMANAGER->findImage("스마슈왼쪽이동");
		break;
	case SRIGHTMOVE:
		_image = IMAGEMANAGER->findImage("스마슈오른쪽이동");
		break;
	case SDOWNMOVE:
		_image = IMAGEMANAGER->findImage("스마슈아래이동");
		break;
	case SUPMOVE:
		_image = IMAGEMANAGER->findImage("스마슈위로이동");
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
