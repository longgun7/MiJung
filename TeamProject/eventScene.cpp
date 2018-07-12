#include "stdafx.h"
#include "eventScene.h"
#include "playerManager.h"

eventScene::eventScene()
{
}


eventScene::~eventScene()
{
}

HRESULT eventScene::init(void)
{
	IMAGEMANAGER->addImage("카페베네", "image/player/카페베네.bmp", 367, 137, true, RGB(255, 0, 255), true);
	SOUNDMANAGER->addSound("낙사", "falling.mp3", true, false);

	_pm = SCENEMANAGER->getPlayerManagerLink();
	_map = SCENEMANAGER->getPlayMapLink();
	_map->init(EVENT);

	//_pm->getPlayer()->setX(150); _pm->getPlayer()->setY(50);
	//_pm->getPlayer2()->setX(150); _pm->getPlayer2()->setY(50);
	//
	//_pm->getPlayer()->setEventMode(FIELDMODE);
	//_pm->getPlayer2()->setEventMode(S_FIELDMODE);

	_soundFrame = 0;
	_isEventMode = false;

	return S_OK;
}

void eventScene::release(void)
{

}

void eventScene::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());
	POINT index = _map->getTileIndex(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	if (!_isEventMode)
	{
		if (_map->getTiles()[index.y * TILEX + index.x].obj == OBJ_ROPE)
		{
			_pm->getPlayer()->setEventMode(EVENTMODE);
			_pm->getPlayer2()->setEventMode(S_EVENTMODE);
			_isEventMode = true;
		}
	}

	if (_pm->getPlayer()->getSceneMode() == EVENTMODE)
	{
		if (_map->getTiles()[index.y * TILEX + index.x].obj == OBJ_ROPE)
		{
			_pm->getPlayer()->setEventMode(FIELDMODE);
			_pm->getPlayer2()->setEventMode(S_FIELDMODE);
		}
		if (_pm->getPlayer()->getIsJumping() == true)
		{
			_pm->getPlayer2()->setIsJumping(true);
			++_soundFrame;

		}
		if (_soundFrame == 2)
		{
			SOUNDMANAGER->play("낙사", 0.5f);
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

	// 플레이어가 어느 타일에 있는지 인덱스 번호 세팅
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);

	sceneChange();
}

void eventScene::render(void)
{
	_map->render();

	char str[128];
	sprintf_s(str, " 기울기 : %d", _pm->getPlayer()->getSlopeNum());
	TextOut(getMemDC(), WINSIZEX / 2, 50, str, strlen(str));


	if (_soundFrame >= 2)
	{
		IMAGEMANAGER->alphaRender("카페베네", getMemDC(), CAMERA->getPosition().x + WINSIZEX / 3, CAMERA->getPosition().y + (550 / 3) * 2, _alphaNum);
	}

	// 오브젝트 렌더
	_map->objRender();


}

void eventScene::sceneChange(void)
{
	//플레이어가 어느 위치에 있느냐에 따라 포탈 이동 및 씬 이동
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:
		//SOUNDMANAGER->stop("FiledTheMa");
		_pm->getPlayer()->setX(360); _pm->getPlayer()->setY(2750);
		_pm->getPlayer2()->setX(360); _pm->getPlayer2()->setY(2750);
		SCENEMANAGER->changeScene("필드씬2");

		break;

	case OBJ_DOWNPORTAL:
		//SOUNDMANAGER->stop("FiledTheMa");
		_pm->getPlayer()->setX(100); _pm->getPlayer()->setY(100);
		_pm->getPlayer2()->setX(100); _pm->getPlayer2()->setY(100);
		SCENEMANAGER->changeScene("필드씬3");

		break;

	}

}
