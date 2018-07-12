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
		SCENEMANAGER->changeScene("������");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("���¾�");
	}

	npcCollision();

	// �÷��̾ ��� Ÿ�Ͽ� �ִ��� �ε��� ��ȣ ����
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	sceneChange();

}

void townScene::render(void)
{
	_map->render();

	_npc->render();

	// ������Ʈ ����
	_map->objRender();
	
	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);
	
	if (_isTemp) TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, 400, "��ȭ��ȭ", strlen("��������"));

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
			_npc->addNPC((vObjTile[i].first.x+1) * TILESIZE, (vObjTile[i].first.y-1) * TILESIZE, NORMAL, frameIdX, frameIdY);
			frameIdX++;
			if (frameIdX > 5) frameIdX = 0, frameIdY = 1;
		}
	}

}

void townScene::npcCollision()
{
	vector<pair<POINT, tagTile>> vObjTile = _map->getVObjectTile();	
	RECT rc;
	for (int i = 0; i < vObjTile.size(); ++i)
	{
		if (vObjTile[i].second.obj == OBJ_NPC)
		{
			if (IntersectRect(&rc, &vObjTile[i].second.rc, &_pm->getPlayer()->getZorderRC()))
			{
				// ���ó�� �Ͻÿ�
				_isTemp = true;
			}
			//else _isTemp = false;
		}
	}
}

void townScene::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "Ÿ���";
	font = CreateFont(20, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);

	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
	
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);
}

void townScene::sceneChange(void)
{
	//�÷��̾ ��� ��ġ�� �ִ��Ŀ� ���� ��Ż �̵� �� �� �̵�
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:
		_pm->getPlayer()->setX(400); _pm->getPlayer()->setY(700);
		_pm->getPlayer()->setX(400); _pm->getPlayer()->setY(700);
		SCENEMANAGER->changeScene("������");
		break;
	case OBJ_DOWNPORTAL:	break;
	case OBJ_LEFTPORTAL:	break;
	case OBJ_RIGHTPORTAL:
		SOUNDMANAGER->stop("TownTheMa");
		_pm->getPlayer()->setX(100); _pm->getPlayer()->setY(100);
		_pm->getPlayer()->setX(100); _pm->getPlayer()->setY(100);
		SCENEMANAGER->changeScene("�ʵ��1");
		break;
	}
}
