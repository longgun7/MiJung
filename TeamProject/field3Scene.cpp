#include "stdafx.h"
#include "field3Scene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"

field3Scene::field3Scene()
{
}


field3Scene::~field3Scene()
{
}

HRESULT field3Scene::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();
	_map = SCENEMANAGER->getPlayMapLink();

	_map->init(FIELD3);

	_pm->getPlayer()->setSceneMode(FIELDMODE, DOWN);
	_pm->getPlayer2()->setSceneMode(S_FIELDMODE, S_DOWN);

	SOUNDMANAGER->play("FiledTheMa");

	IMAGEMANAGER->addFrameImage("NPC1", "image/maptool/NPC/NPC.bmp", 432, 288, 6, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("린샹앉은모습", "image/player/린샹앉은모습.bmp", 55, 65, true, RGB(255, 0, 255));
	return S_OK;
}

void field3Scene::release(void)
{
}

void field3Scene::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());

	// 플레이어가 어느 타일에 있는지 인덱스 번호 세팅
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	// 적 타일 인덱스번호 추가해야함

	sceneChange();

}

void field3Scene::render(void)
{
	//_map->render();
	// 오브젝트 렌더
	//_map->objRender();

	// 보스 위치 
	IMAGEMANAGER->findImage("NPC1")->frameRender(getMemDC(), 2700, 950, 2, 2);
	IMAGEMANAGER->findImage("린샹앉은모습")->frameRender(getMemDC(), 2700, 1000, 1, 1);
	
	//_map->objRender();
	
	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);

	fontUI();

}

void field3Scene::fontUI(void)
{
	HFONT font, ofont;
	


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}

void field3Scene::fieldSettingEnemy(void)
{
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_map->getTiles()[i * TILEX + j].terrain == TR_MOVE)
			{

			}
		}
	}
}

void field3Scene::sceneChange(void)
{
	//플레이어가 어느 위치에 있느냐에 따라 포탈 이동 및 씬 이동
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:
		_pm->getPlayer()->setX(550); _pm->getPlayer()->setY(1950);
		_pm->getPlayer2()->setX(550); _pm->getPlayer2()->setY(1950);
		SCENEMANAGER->changeScene("이벤트씬");		
	break;
	case OBJ_DOWNPORTAL: break;
	case OBJ_LEFTPORTAL: break;
	case OBJ_RIGHTPORTAL:break;

	}
}
