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
	IMAGEMANAGER->addImage("ī�亣��", "image/player/ī�亣��.bmp", 367, 137, true, RGB(255, 0, 255), true);
	SOUNDMANAGER->addSound("����", "soundEffect/falling.mp3", true, false);
	talk();
	_talkIndex = 0;
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_map = SCENEMANAGER->getPlayMapLink();
	_map->init(EVENT);

	if (!SOUNDMANAGER->isPauseSound("eventTheMa"))
	{
		SOUNDMANAGER->play("eventTheMa");
	}
	else
	{
		SOUNDMANAGER->resume("eventTheMa");
	}
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
		POINT index2 = _map->getTileIndex(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
		if (_map->getTiles()[index2.y * TILEX + index2.x].obj == OBJ_ROPEEND)
		{
			_pm->getPlayer()->setEventMode(FIELDMODE);
			_pm->getPlayer2()->setEventMode(S_FIELDMODE);
		}
		if (_pm->getPlayer()->getIsJumping() == true)
		{
			_pm->getPlayer2()->setIsJumping(true);
			++_soundFrame;

		}
		if (_soundFrame == 1)
		{
			SOUNDMANAGER->pause("eventTheMa");
			SOUNDMANAGER->play("����", 0.5f);
		}
		if (_soundFrame >= 1 && _alphaNum <= 252)
		{
			_alphaNum += 3;
		}


		if (_pm->getPlayer()->getSlopeNum() <= 2 || _pm->getPlayer()->getSlopeNum() >= 6)
		{
			_pm->getPlayer2()->setMove(S_AFRAID);
		}
		//�Ʒ�Ű ������ �����δ�

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
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		init();
		SOUNDMANAGER->stop("����");
		SOUNDMANAGER->resume("eventTheMa");
	}

	// �÷��̾ ��� Ÿ�Ͽ� �ִ��� �ε��� ��ȣ ����
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);

	sceneChange();
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN) && _talkIndex < 5)
	{
		++_talkIndex;
	}
}

void eventScene::render(void)
{
	//_map->render();

	char str[128];
	sprintf_s(str, " ���� : %d", _pm->getPlayer()->getSlopeNum());
	TextOut(getMemDC(), WINSIZEX / 2, 50, str, strlen(str));

	if (_pm->getPlayer()->getX() > WINSIZEX + 150)
	{
		if (_talkIndex == 4)
		{
			IMAGEMANAGER->findImage("ĳ�����̹���1")->frameRender(CAMERA->getCameraDC(), 137, 400, 1, 0);
		}
		else
		{
			IMAGEMANAGER->findImage("ĳ�����̹���1")->frameRender(CAMERA->getCameraDC(), 137, 400, 0, 0);
		}
		IMAGEMANAGER->findImage("��ȭâ1")->render(CAMERA->getCameraDC(), 272, 400);
		TextOut(CAMERA->getCameraDC(), 300, 450 , _vTalk[_talkIndex].c_str(), strlen(_vTalk[_talkIndex].c_str() ));

	}

	if (_soundFrame >= 2)
	{
		IMAGEMANAGER->alphaRender("ī�亣��", getMemDC(), CAMERA->getPosition().x + WINSIZEX / 3, CAMERA->getPosition().y + (550 / 3) * 2, _alphaNum);
	}

	// ������Ʈ ����
	//_map->objRender();


}

void eventScene::talk()
{
	_vTalk.push_back(talk1);
	_vTalk.push_back(talk2);
	_vTalk.push_back(talk3);
	_vTalk.push_back(talk4);
	_vTalk.push_back(talk5);
	_vTalk.push_back(talk6);
	
}

void eventScene::sceneChange(void)
{
	//�÷��̾ ��� ��ġ�� �ִ��Ŀ� ���� ��Ż �̵� �� �� �̵�
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:
		SOUNDMANAGER->stop("eventTheMa");
		_pm->getPlayer()->setX(360); _pm->getPlayer()->setY(2750);
		_pm->getPlayer2()->setX(360); _pm->getPlayer2()->setY(2750);
		SCENEMANAGER->changeScene("�ʵ��2");

		break;

	case OBJ_DOWNPORTAL:
		SOUNDMANAGER->stop("eventTheMa");
		_pm->getPlayer()->setX(100); _pm->getPlayer()->setY(100);
		_pm->getPlayer2()->setX(100); _pm->getPlayer2()->setY(100);
		SCENEMANAGER->changeScene("�ʵ��3");

		break;

	}

}
