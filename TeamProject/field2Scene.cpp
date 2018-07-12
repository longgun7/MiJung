#include "stdafx.h"
#include "field2Scene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"


field2Scene::field2Scene()
{
}


field2Scene::~field2Scene()
{
}

HRESULT field2Scene::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();
	_map = SCENEMANAGER->getPlayMapLink();

	_map->init(FIELD2);
	_pm->getPlayer()->setSceneMode(FIELDMODE, DOWN);
	_pm->getPlayer2()->setSceneMode(S_FIELDMODE, S_DOWN);

	return S_OK;
}

void field2Scene::release(void)
{
}

void field2Scene::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());

	// 플레이어가 어느 타일에 있는지 인덱스 번호 세팅
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);

	sceneChange();

}

void field2Scene::render(void)
{
	_map->render();
	// 오브젝트 렌더
	_map->objRender();

	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);

	fontUI();

}

void field2Scene::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "필드씬";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}

void field2Scene::sceneChange(void)
{
	//플레이어가 어느 위치에 있느냐에 따라 포탈 이동 및 씬 이동
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:
		_pm->getPlayer()->setX(1235);	_pm->getPlayer()->setY(2000);
		_pm->getPlayer2()->setX(1235);	_pm->getPlayer2()->setY(2000);
		SCENEMANAGER->changeScene("필드씬1");
	break;

	case OBJ_DOWNPORTAL:		
		SOUNDMANAGER->stop("FiledTheMa");
		_pm->getPlayer()->setX(150); _pm->getPlayer()->setY(70);
		_pm->getPlayer2()->setX(150); _pm->getPlayer2()->setY(70);
		SCENEMANAGER->changeScene("이벤트씬");		
	break;
	case OBJ_LEFTPORTAL:		break;
	case OBJ_RIGHTPORTAL:		break;

	}
}
