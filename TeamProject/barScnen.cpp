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

	IMAGEMANAGER->addImage("����â", "image/ui/����â.bmp", 450, 360, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â������", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â���Լ�", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("����â����", "image/ui/����â2.bmp", 200, 120, false, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("ĳ�����̹���1", "image/ui/ĳ�����̹���.bmp", 1000, 250, 8, 2, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("��ȭâ1", "image/ui/��ȭâ.bmp", 600, 125, false, RGB(0, 0, 0));
	_isShopCheck = false;
	_isHotelCheck = false;
	_isTalkCheck = false;

	_sl = new saveLoad;
	_sl->init();
	
	_map->init(BAR);

	_npc = new npc;
	_npc->init();
	npcTileSetting();

	if (_start == 0)
	{
		_isTalkCheck = true;
		SCENEMANAGER->setIsInHouseTalk(true);
		talkSave();
		talkLoad();
	}

	return S_OK;
}

void barScnen::release(void)
{
}

void barScnen::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());

	_count++;
	if (_count % 8 == 0)
	{
		_talkIndex++;
		if (_maxTalkIndex <= (_talkIndex * 2))
		{
			_talkIndex = (_maxTalkIndex / 2);
		}
	}

	if (_talkIndex == (_maxTalkIndex / 2))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_index++;
			_who++;
			_count = 0;
			_talkIndex = 0;
			_maxTalkIndex = 0;
			if (_index == 21)
			{
				_start = 1;
				_isTalkCheck = false;
				SCENEMANAGER->setIsInHouseTalk(false);
			}
		}
	}

	else if (_talkIndex < (_maxTalkIndex / 2));
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_talkIndex = (_maxTalkIndex / 2);
		}
	}

	//���� üũ
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
		SCENEMANAGER->changeScene("���¾�");
	}

	npcCollision();

	// �÷��̾ ��� Ÿ�Ͽ� �ִ��� �ε��� ��ȣ ����
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	sceneChange();
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0)) _sl->save(1);

}

void barScnen::render(void)
{
	_map->render();

	_npc->render();
	
	// ������Ʈ ����
	_map->objRender();
	if ((_start == 0) && (SCENEMANAGER->getIsInHouseTalk()))
	{
		if (_who <= 10)
		{
			if (_who % 2 == 0)
			{
				IMAGEMANAGER->findImage("ĳ�����̹���1")->frameRender(CAMERA->getCameraDC(), 137, 400, 0, 0);
			}
			else if (_who % 2 == 1)
			{
				IMAGEMANAGER->findImage("ĳ�����̹���1")->frameRender(CAMERA->getCameraDC(), 137, 400, 1, 0);
			}
		}
		else
		{
			if (_who % 2 == 0)
			{
				IMAGEMANAGER->findImage("ĳ�����̹���1")->frameRender(CAMERA->getCameraDC(), 137, 400, 1, 0);
			}
			else if (_who % 2 == 1)
			{
				IMAGEMANAGER->findImage("ĳ�����̹���1")->frameRender(CAMERA->getCameraDC(), 137, 400, 0, 0);
			}

		}
		IMAGEMANAGER->findImage("��ȭâ1")->render(CAMERA->getCameraDC(), 272, 400);
		SetTextColor(getMemDC(), RGB(255, 255, 255));

		for (int i = 0; i < 21; ++i)
		{
			if (_index == i)
			{
				_maxTalkIndex = strlen(vStr[i].c_str());

				if ((_talkIndex * 2) < 70)
				{
					TextOut(CAMERA->getCameraDC(), 300, 430, vStr[i].c_str(), (_talkIndex * 2));
				}
				else if ((_talkIndex * 2) >= 70 && (_talkIndex * 2) < 140)
				{
					string text = "";
				
					text = vStr[i].substr(0, 70);
					TextOut(CAMERA->getCameraDC(), 300, 430, text.c_str(), text.size());
				
					text = vStr[i].substr(70, 140);
					TextOut(CAMERA->getCameraDC(), 300, 450, text.c_str(), (_talkIndex * 2) - 70);
				}
				else
				{
					string text = "";
				
					text = vStr[i].substr(0, 70);
					TextOut(CAMERA->getCameraDC(), 300, 430, text.c_str(), text.size());
				
					text = vStr[i].substr(70, 140);
					TextOut(CAMERA->getCameraDC(), 300, 450, text.c_str(), text.size() - 70);
				
					text = vStr[i].substr(140, _maxTalkIndex);
					TextOut(CAMERA->getCameraDC(), 300, 470, text.c_str(), (_talkIndex * 2) - 140);
				}
			}
		}
	}

	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);
	
	if(_isShopCheck)
	{	
		IMAGEMANAGER->findImage("����â")->render(CAMERA->getCameraDC(), 175, 95);
		IMAGEMANAGER->findImage("����â������")->render(CAMERA->getCameraDC(), 625, 95);
		IMAGEMANAGER->findImage("����â���Լ�")->render(CAMERA->getCameraDC(), 625, 215);
		IMAGEMANAGER->findImage("����â����")->render(CAMERA->getCameraDC(), 625, 335);
		_shop->fontUI();
		_shop->render();
	}
	for (int i = 0; i < 5; ++i)
	{
		char str[128];
		sprintf_s(str, "�÷��̾�����%d", i);
		if (INIDATA->loadDataInterger(str, "���̺�", "���̺꿩��") == 1)
		{

		}
	}
	fontUI();

}

void barScnen::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "������";

	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX - 320, WINSIZEY - 160, str, strlen(str));
	SelectObject(CAMERA->getCameraDC(), ofont);
	DeleteObject(font);

}

void barScnen::sceneChange(void)
{
	//�÷��̾ ��� ��ġ�� �ִ��Ŀ� ���� ��Ż �̵� �� �� �̵�
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL: break;

	case OBJ_DOWNPORTAL:
		_pm->getPlayer()->setX(550); _pm->getPlayer()->setY(250);
		_pm->getPlayer2()->setX(550); _pm->getPlayer2()->setY(250);
		SCENEMANAGER->changeScene("Ÿ���");
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
		if ((vObjTile[i].second.obj == OBJ_NPC && IntersectRect(&rc, &vObjTile[i].second.rc, &_pm->getPlayer()->getZorderRC()) &&
			 vObjTile[i].second.obj == OBJ_SHOP && vObjTile[i].second.obj == OBJ_MOTEL))
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
void barScnen::talkSave()
{
	vStr.push_back(str);
	vStr.push_back(str1);
	vStr.push_back(str2);
	vStr.push_back(str3);
	vStr.push_back(str4);
	vStr.push_back(str5);
	vStr.push_back(str6);
	vStr.push_back(str7);
	vStr.push_back(str8);
	vStr.push_back(str9);
	vStr.push_back(str10);
	vStr.push_back(str11);
	vStr.push_back(str12);
	vStr.push_back(str13);
	vStr.push_back(str14);
	vStr.push_back(str15);
	vStr.push_back(str16);
	vStr.push_back(str17);
	vStr.push_back(str18);
	vStr.push_back(str19);
	vStr.push_back(str20);

	TXTDATA->txtSave("���.txt", vStr);
}

void barScnen::talkLoad()
{
	vStr = TXTDATA->txtLoad("���.txt");
}