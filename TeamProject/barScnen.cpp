#include "stdafx.h"
#include "barScnen.h"
#include "playerManager.h"
#include "enemyManager.h"
#include "itemManager.h"

barScnen::barScnen()
{
}


barScnen::~barScnen()
{
}

HRESULT barScnen::init(void)
{
	_pm = SCENEMANAGER->getPlayerManagerLink();
	_map = SCENEMANAGER->getPlayMapLink();

	IMAGEMANAGER->addImage("상점창", "image/ui/상점창.bmp", 450, 360, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("상점창소지수", "image/ui/상점창2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("상점창구입수", "image/ui/상점창2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("상점창번돈", "image/ui/상점창2.bmp", 200, 120, false, RGB(0, 0, 0));
	
	_isShopCheck = false;
	_isHotelCheck = false;
	_sl = new saveLoad;
	_sl->init();

	
	_map->init(BAR);

	_npc = new npc;
	_npc->init();
	npcTileSetting();

	return S_OK;
}

void barScnen::release(void)
{
}

void barScnen::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());

	//상점 체크
	if(KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isShopCheck)
		{
			SCENEMANAGER->setIsShop(true);
			_isShopCheck = true;
			_shop = new shop;
			_shop->init();
			_shop->setItem();
		}
		else if (_isShopCheck)
		{
			SCENEMANAGER->setIsShop(false);
			_isShopCheck = false;
			_shop->shopRemove();
		}
	}

	if (_isShopCheck) _shop->update();


	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		if(!SCENEMANAGER->getIsShop())
		SCENEMANAGER->changeScene("상태씬");
	}

	npcCollision();

	// 플레이어가 어느 타일에 있는지 인덱스 번호 세팅
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	sceneChange();

}

void barScnen::render(void)
{
	_map->render();

	_npc->render();
	
	// 오브젝트 렌더
	_map->objRender();

	IMAGEMANAGER->findImage("테두리")->render(CAMERA->getCameraDC(), 0, 0);
	
	if(_isShopCheck)
	{	
		IMAGEMANAGER->findImage("상점창")->render(CAMERA->getCameraDC(), 175, 95);
		IMAGEMANAGER->findImage("상점창소지수")->render(CAMERA->getCameraDC(), 625, 95);
		IMAGEMANAGER->findImage("상점창구입수")->render(CAMERA->getCameraDC(), 625, 215);
		IMAGEMANAGER->findImage("상점창번돈")->render(CAMERA->getCameraDC(), 625, 335);
		_shop->fontUI();
		_shop->render();
		
	}
	
	fontUI();

}

void barScnen::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "술집씬";

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "새굴림");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX - 320, WINSIZEY - 160, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

}

void barScnen::sceneChange(void)
{
	//플레이어가 어느 위치에 있느냐에 따라 포탈 이동 및 씬 이동
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL: break;

	case OBJ_DOWNPORTAL:
		_pm->getPlayer()->setX(550); _pm->getPlayer()->setY(250);
		_pm->getPlayer2()->setX(550); _pm->getPlayer2()->setY(250);
		SCENEMANAGER->changeScene("타운씬");
		break;

	case OBJ_LEFTPORTAL:	break;
	case OBJ_RIGHTPORTAL:	break;

	}

}


void barScnen::npcTileSetting()
{
	vector<pair<POINT, tagTile>> vObjTile;
	vObjTile = _map->getVObjectTile();

	int frameIdX = 1, frameIdY = 1;
	for (int i = 0; i < vObjTile.size(); ++i)
	{
		if (vObjTile[i].second.obj == OBJ_NPC)
		{
			_npc->addNPC((vObjTile[i].first.x + 1) * TILESIZE, (vObjTile[i].first.y - 1) * TILESIZE, NORMAL, frameIdX, frameIdY, vObjTile[i].first.x, vObjTile[i].first.y);
			frameIdX++;
			if (frameIdX > 5) frameIdX = 0, frameIdY = 1;
		}
		else if (vObjTile[i].second.obj == OBJ_SHOP)
			_npc->addNPC((vObjTile[i].first.x + 1) * TILESIZE, (vObjTile[i].first.y - 1) * TILESIZE, SHOP, 1, 2, vObjTile[i].first.x, vObjTile[i].first.y);
		else if (vObjTile[i].second.obj == OBJ_MOTEL)
			_npc->addNPC((vObjTile[i].first.x + 1) * TILESIZE, (vObjTile[i].first.y - 1) * TILESIZE, MOTEL, 0, 2, vObjTile[i].first.x, vObjTile[i].first.y);
	}

}

void barScnen::npcCollision()
{
	vector<pair<POINT, tagTile>> vObjTile = _map->getVObjectTile();
	vector<tagNPC> vNpc = _npc->getVTagNPC();

	for (int i = 0; i < vObjTile.size(); ++i)
	{
		RECT rc;
		if ((vObjTile[i].second.obj == OBJ_NPC && IntersectRect(&rc, &vObjTile[i].second.rc, &_pm->getPlayer()->getZorderRC()) ||
			 vObjTile[i].second.obj == OBJ_SHOP || vObjTile[i].second.obj == OBJ_MOTEL))
		{
			for (int j = 0; j < vNpc.size(); ++j)
			{
				if (vObjTile[i].first.x == vNpc[j].tileX &&
					vObjTile[i].first.y == vNpc[j].tileY)
					_npc->talkNPC(vNpc[j].frameX, vNpc[j].frameY);
			}
		}
		
	}
}
