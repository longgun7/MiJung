#include "stdafx.h"
#include "townScene.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"


townScene::townScene()
{
}


townScene::~townScene()
{
}

HRESULT townScene::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_em = SCENEMANAGER->getEnemyManagerLink();
	_im = SCENEMANAGER->getItemManagerLink();
	_map = SCENEMANAGER->getPlayMapLink();

	_map->init(TOWN);
	SOUNDMANAGER->play("TownTheMa", 0.5f);

	_npc = new npc;
	_npc->init();
	npcTileSetting();

	return S_OK;
}

void townScene::release(void)
{
}

void townScene::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());

	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		SCENEMANAGER->changeScene("필드씬3");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("상태씬");
	}

	npcCollision();

	// 플레이어가 어느 타일에 있는지 인덱스 번호 세팅
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	sceneChange();
	_npc->update();
}

void townScene::render(void)
{
	//_map->render();

	_npc->render();

	// 오브젝트 렌더
	//_map->objRender();
	
	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);
	
	if (_isTemp) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, 400, "대화대화", strlen("ㅇㅇㅇㅇ"));

	fontUI();
}

void townScene::npcTileSetting()
{
	vector<pair<POINT, tagTile>> vObjTile;
	vObjTile = _map->getVObjectTile();

	int frameIdX = 0, frameIdY = 0;
	for (int i = 0; i < vObjTile.size(); ++i)
	{
		if (vObjTile[i].second.obj == OBJ_NPC)
		{
			_npc->addNPC((vObjTile[i].first.x+1) * TILESIZE, (vObjTile[i].first.y-1) * TILESIZE, NORMAL, frameIdX, frameIdY, vObjTile[i].first.x, vObjTile[i].first.y);
			frameIdX++;
			if (frameIdX > 5) frameIdX = 0, frameIdY = 1;
		}
	}

}

void townScene::npcCollision()
{
	vector<pair<POINT, tagTile>> vObjTile = _map->getVObjectTile();	
	vector<tagNPC> vNpc = _npc->getVTagNPC();

	for (int i = 0; i < vObjTile.size(); ++i)
	{
		RECT rc;
		if (!_npc->getIsTalk() && vObjTile[i].second.obj == OBJ_NPC && IntersectRect(&rc, &vObjTile[i].second.rc, &_pm->getPlayer()->getZorderRC()))
		{
			for (int j = 0; j < vNpc.size(); ++j)
			{
				if(vObjTile[i].first.x == vNpc[j].tileX &&
					vObjTile[i].first.y == vNpc[j].tileY)
					_npc->talkNPC(vNpc[j].frameX, vNpc[j].frameY);
				_npc->setIsTalk(true);
			}
		}
	}
}

void townScene::fontUI(void)
{
	HFONT font, ofont;
	font = CreateFont(20, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}

void townScene::sceneChange(void)
{
	//플레이어가 어느 위치에 있느냐에 따라 포탈 이동 및 씬 이동
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:
		_pm->getPlayer()->setX(400); _pm->getPlayer()->setY(700);
		_pm->getPlayer()->setX(400); _pm->getPlayer()->setY(700);
		SCENEMANAGER->changeScene("술집씬");
		break;
	case OBJ_DOWNPORTAL:	break;
	case OBJ_LEFTPORTAL:	break;
	case OBJ_RIGHTPORTAL:
		SOUNDMANAGER->stop("TownTheMa");
		_pm->getPlayer()->setX(2700); _pm->getPlayer()->setY(1300);
		SCENEMANAGER->changeScene("필드씬1");
		break;
	}
}
