#include "stdafx.h"
#include "player2.h"

HRESULT player2::init(float x , float y)
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
	IMAGEMANAGER->addFrameImage("스마슈베고날아가기", "image/player/스마슈 베고 날아가기2.bmp", 2675, 120, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈난도질", "image/player/스마슈 난도질2.bmp", 6570, 140, 45, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈절사어면", "image/player/스마슈 절사어면.bmp", 1615, 100, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈분신", "image/player/스마슈 분신.bmp", 99, 85, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈방어", "image/player/스마슈 방어.bmp", 56, 75, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈쓰러짐", "image/player/스마슈 쓰러짐.bmp", 90, 61, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈피격", "image/player/스마슈 피격.bmp", 70, 69, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("스마슈전투상태", "image/player/스마슈 전투상태.bmp", 55, 80, 1, 1, true, RGB(255, 0, 255));


	//초기 스마슈모습
	_img = IMAGEMANAGER->findImage("스마슈정면");

	//스마슈 정보
	_x = x - 60;
	_y = y;
	_angle = 0;
	_imageFrame = 0;
	_frame = 0;
	_skillFrame = 0;
	_moveSpeed = 5;
	_isMotionLive = false;
	return S_OK;
}

void player2::update()
{
	image();		 //이미지
	
	if (_isMotionLive)
	{
		imageFrame();	 //이미지프레임
	}
	move();
}

void player2::render()
{
	//RECT
	//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	
	//image
	_img->frameRender(getMemDC(), _rc.left, _rc.top);


	char str[125];

	sprintf_s(str, "스킬 프레임 : %d", _skillFrame);
	TextOut(getMemDC(), 100, 100, str, strlen(str));
	
	char str2[123];
	sprintf_s(str2, "이미지프레임 : %d", _imageFrame);
	TextOut(getMemDC(), 100, 150, str2, strlen(str2));
}

void player2::release()
{
}

void player2::angleManager(float x , float y)
{
	//아타호의 위치에 따라 앵글이 바뀐다.
	_angle = getAngle(_x, _y, x, y);
	
	//렉트 갱신
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	
	//아타호와 스마슈와의 거리
	if (getDistance(x, y, _x, _y) > 60)
	{
		_x += cosf(_angle)*_moveSpeed;
		_y += -sinf(_angle)*_moveSpeed;

		//움직이는 모션
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
		
	}

	//정자세
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
	
	//스킬
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_move = S_SOLOSKILL1;
		_isMotionLive = true;
		_skillFrame = 0;
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_move = S_SOLOSKILL2;
		_isMotionLive = true;
		_skillFrame = 0;
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_move = S_SOLOSKILL3;
		_isMotionLive = true;
		_skillFrame = 0;
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_move = S_AREASKILL1;
		_isMotionLive = true;
		_skillFrame = 0;
	}
	if (KEYMANAGER->isOnceKeyDown('G'))
	{
		_move = S_AREASKILL2;
		_isMotionLive = true;
		_skillFrame = 0;
	}
	if (KEYMANAGER->isOnceKeyDown('H'))
	{
		_move = S_AREASKILL3;
		_isMotionLive = true;
		_skillFrame = 0;
	}

}

void player2::image()
{
	//이미지
	switch (_move)
	{
	case S_RIGHT:
		_img = IMAGEMANAGER->findImage("스마슈오른쪽");
		break;
	case S_LEFT:
		_img = IMAGEMANAGER->findImage("스마슈왼쪽");
		break;
	case S_FRONT:
		_img = IMAGEMANAGER->findImage("스마슈정면");
		break;
	case S_BACK:
		_img = IMAGEMANAGER->findImage("스마슈뒷모습");
		break;
	case S_LEFTMOVE:
		_img = IMAGEMANAGER->findImage("스마슈왼쪽이동");
		break;
	case S_RIGHTMOVE:
		_img = IMAGEMANAGER->findImage("스마슈오른쪽이동");
		break;
	case S_DOWNMOVE:
		_img = IMAGEMANAGER->findImage("스마슈아래이동");
		break;
	case S_UPMOVE:
		_img = IMAGEMANAGER->findImage("스마슈위로이동");
		break;
	case S_SOLOSKILL1:
		_img = IMAGEMANAGER->findImage("스마슈대타격");
		break;
	case S_SOLOSKILL2:
		_img = IMAGEMANAGER->findImage("스마슈절사어면");
		break;
	case S_SOLOSKILL3:
		_img = IMAGEMANAGER->findImage("스마슈베고날아가기");
		break;
	case S_AREASKILL1:
		_img = IMAGEMANAGER->findImage("스마슈용오름");
		break;
	case S_AREASKILL2:
		_img = IMAGEMANAGER->findImage("스마슈난도질");
		break;
	case S_AREASKILL3:
		_img = IMAGEMANAGER->findImage("스마슈분신");
		break;
	default:
		break;
	}
}

void player2::imageFrame()
{
	//이미지프레임
	++_frame;

	if (_frame % 7 == 0)
	{
		
		++_imageFrame;

		_img->setFrameX(_imageFrame);
		
		if (_imageFrame >= _img->getMaxFrameX())
		{
			_imageFrame = -1;
		}
		_frame = 0;
	}

}



void player2::move()
{
	
	//스킬 이동

	//대타격
	if (_img == IMAGEMANAGER->findImage("스마슈대타격"))
	{
		if (_x < WINSIZEX - 100)
		{
			_imageFrame = 1;
			_img->setFrameX(1);
			_x += 10;
		}

		if (_x > WINSIZEX - 100)
		{
			if (_img->getFrameX() >= _img->getMaxFrameX())
			{
				_move = S_RIGHT;
			}
		}
	}
	//절사어면
	if (_img == IMAGEMANAGER->findImage("스마슈절사어면"))
	{
		if (_img->getFrameX() >= 2 && _x < WINSIZEX - 100)
		{
			_imageFrame = 3;
			_x += 10;
			_img->setFrameX(2);
		}
		if (_x > WINSIZEX - 100)
		{
			_img->setFrameX(_imageFrame);
			++_skillFrame;
			if (_skillFrame >= 50)
			{
				_move = S_RIGHT;
			}
		}
	}
	//베고 날아가기
	if(_img == IMAGEMANAGER->findImage("스마슈베고날아가기"))
	{
		if (_img->getFrameX() < 23)
		{
			_x = WINSIZEX - 200;
		}
		if (_img->getFrameX() >= 23 && _x < WINSIZEX )
		{
			_x += 20;
			_img->setFrameX(23);
			_imageFrame = 23;
		}
		if (_x >= WINSIZEX )
		{	
			_img->setFrameX(0);
			_imageFrame = 0;
			_move = S_RIGHT;
			
		}
	}
	//난도질
	if (_img == IMAGEMANAGER->findImage("스마슈난도질"))
	{	
		++_skillFrame;
		if (_img->getFrameX() >= 44 && _skillFrame >= 200)
		{
			_imageFrame = 44;
		}
		if (_skillFrame >= 400)
		{	
			_imageFrame = 0;
			_move = S_RIGHT;	
		}
	}
	//분신
	if (_img == IMAGEMANAGER->findImage("스마슈분신"))
	{
		++_skillFrame;

		if (_skillFrame < 50)
		{
			_img->setFrameX(0);
		}
		if (_skillFrame > 50 && _skillFrame < 150)
		{
			_img->setFrameX(1);
		}
		if (_skillFrame > 150)
		{
			_skillFrame = 0;
			_imageFrame = 0;
			_move = S_AREASKILL2;
		}
	}
}




player2::player2()
{
}


player2::~player2()
{
}
