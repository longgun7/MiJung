#include "stdafx.h"
#include "eventMode.h"


HRESULT eventMode::init()
{
	IMAGEMANAGER->addImage("카페베네", "image/player/카페베네.bmp", 367, 137, true, RGB(255, 0, 255),true);
	SOUNDMANAGER->addSound("낙사", "falling.mp3", true, false);

	_pm = SCENEMANAGER->getPlayerManagerLink();
	_pm->getPlayer()->setEventMode(EVENTMODE);
	_pm->getPlayer2()->setEventMode(S_EVENTMODE);
	_soundFrame = 0;

	return S_OK;
}

void eventMode::update()
{

	if (_pm->getPlayer()->getSceneMode() == EVENTMODE)
	{
		if (_pm->getPlayer()->getIsJumping() == true)
		{
			_pm->getPlayer2()->setIsJumping(true);
			++_soundFrame;
			
		}
		if (_soundFrame == 2)
		{
			SOUNDMANAGER->play("낙사", 1.0f);
		}
		if (_soundFrame >= 1 && _alphaNum <= 252)
		{
			_alphaNum += 3;
		}

		
		if (_pm->getPlayer()->getSlopeNum() <= 2 || _pm->getPlayer()->getSlopeNum() >= 6)
		{
			_pm->getPlayer2()->setMove(S_AFRAID);
		}
		//아래키 누르면 움직인다

		if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _pm->getPlayer()->getMove() != RIGHT4 && _pm->getPlayer()->getMove() != LEFT4
			&& _pm->getPlayer()->getMove() != WOODRIGHT4
			&& _pm->getPlayer()->getMove() != WOODLEFT4)
		{
			_pm->getPlayer()->setIsMotionLive(true);
			_pm->getPlayer()->setY(_pm->getPlayer()->getY() + 3);
			_pm->getPlayer2()->setIsMotionLive(true);
			_pm->getPlayer2()->setY(_pm->getPlayer2()->getY() + 3);
		}
	}
	if (KEYMANAGER->isOnceKeyDown('U'))
	{
		init();
		SOUNDMANAGER->stop("낙사");
	}
}


void eventMode::render()
{
	char str[128];
	sprintf_s(str, " 기울기 : %d", _pm->getPlayer()->getSlopeNum());
	TextOut(getMemDC(), WINSIZEX / 2, 50, str, strlen(str));


	if (_soundFrame >= 2)
	{
		IMAGEMANAGER->alphaRender("카페베네", CAMERA->getCameraDC(), WINSIZEX / 3, WINSIZEY - 200,_alphaNum);
	}
}

void eventMode::release()
{
	
}

eventMode::eventMode()
{
}


eventMode::~eventMode()
{
}
