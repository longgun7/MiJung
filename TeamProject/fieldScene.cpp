#include "stdafx.h"
#include "fieldScene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"

fieldScene::fieldScene()
{
}


fieldScene::~fieldScene()
{
}

HRESULT fieldScene::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();
	_map = SCENEMANAGER->getPlayMapLink();

	_map->init(FIELD1);

	_pm->getPlayer()->setSceneMode(FIELDMODE, DOWN);
	_pm->getPlayer2()->setSceneMode(S_FIELDMODE, S_DOWN);

	//if (SCENEMANAGER->getCurrentSceneName() == "필드씬1")
	//{
	//	_pm->getPlayer()->setX(SCENEMANAGER->getPlayerScenePosition().x);
	//	_pm->getPlayer()->setX(SCENEMANAGER->getPlayerScenePosition().y - 10);
	//}
	SOUNDMANAGER->play("FiledTheMa", 0.5f);

	return S_OK;
}

void fieldScene::release(void)
{
}

void fieldScene::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());

	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("상태씬");
	}

	// 플레이어가 어느 타일에 있는지 인덱스 번호 세팅
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	// 적 타일 인덱스번호 추가해야함

	sceneChange();

}

void fieldScene::render(void)
{
	//_map->render();
	// 오브젝트 렌더
	//_map->objRender();

	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);
	
	fontUI();
}

void fieldScene::fontUI(void)
{
	HFONT font, ofont;



	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}

void fieldScene::sceneChange(void)
{
	//플레이어가 어느 위치에 있느냐에 따라 포탈 이동 및 씬 이동
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:		break;
	case OBJ_DOWNPORTAL:
		_pm->getPlayer()->setX(100);	_pm->getPlayer()->setY(100);
		_pm->getPlayer2()->setX(100);	_pm->getPlayer2()->setY(100);

		SCENEMANAGER->changeScene("필드씬2");
		break;
	case OBJ_LEFTPORTAL:
		SOUNDMANAGER->stop("FiledTheMa");
		_pm->getPlayer()->setX(2310); _pm->getPlayer()->setY(1050);
		_pm->getPlayer2()->setX(2310); _pm->getPlayer2()->setY(1050);
		SCENEMANAGER->changeScene("타운씬");
		break;
	case OBJ_RIGHTPORTAL:	break;

	}

	// 몬스터 랜덤 만남
	if ((_pm->getPlayer()->getMove() == LEFTMOVE	||
		 _pm->getPlayer()->getMove() == RIGHTMOVE	||
		 _pm->getPlayer()->getMove() == UPMOVE		||
		 _pm->getPlayer()->getMove() == DOWNMOVE))
	{
		if (_map->getTiles()[idY * TILEX + idX].terrain == TR_MOVE ||
			_map->getTiles()[idY * TILEX + idX].obj < OBJ_UPPORTAL)
		{
			if (RND->getFloat(100) < 0.8f)
			{
				SCENEMANAGER->setPlayerScenePosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());
				SOUNDMANAGER->stop("FiledTheMa");
				SCENEMANAGER->changeScene("배틀씬");
			}
		}
	}

}