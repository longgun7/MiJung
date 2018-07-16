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
	IMAGEMANAGER->addImage("�����������", "image/player/�����������.bmp", 55, 65, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����������", "image/ui/����������.bmp", 1000, 750, false, RGB(0, 0, 0));
	talkSave();
	talkLoad();
	_npc = new npc;
	_start = 0;
	_bossTalk = false;
	_bossAppear = false;
	_end = false;
	return S_OK;
}

void field3Scene::release(void)
{
}

void field3Scene::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());


	RECT testRC;
	testRC = RectMake(2600, 950, 300, 300);
	RECT RC;
	if (IntersectRect(&RC, &testRC, &_pm->getPlayer()->getZorderRC()))
	{
		_start = 1;
		if (_start == 1)
		{
			_bossTalk = true;
		}
	}


	// �÷��̾ ��� Ÿ�Ͽ� �ִ��� �ε��� ��ȣ ����
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	// �� Ÿ�� �ε�����ȣ �߰��ؾ���

	_npc->update();
	if (_bossTalk)
	{
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
				if (_index == 10)
				{
					_start = 2;
					_bossTalk = false;
					_bossAppear = true;
					_em->setStart(true);
				}
				if (_index == 17)
				{
					_start = 4;
					_bossTalk = false;
					_end = true;
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
	}

	if (_start == 2)
	{
		if(_bossAppear)
		{
			//_em->randEnemy();
			SCENEMANAGER->setPlayerScenePosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());
			_bossAppear = false;
			SOUNDMANAGER->stop("FiledTheMa");
			SCENEMANAGER->changeScene("��Ʋ��");
		}
		else if (_em->getVEnmey().size() <= 0)
		{
			_start = 3;
		}
	}

	if (_start == 3)
	{
		_bossTalk = true;
	}

	if (_end)
	{
		SOUNDMANAGER->stop("FiledTheMa");
		SCENEMANAGER->changeScene("�����");
		SOUNDMANAGER->play("EndingTheMa", 0.5f);
	}

	sceneChange();


}

void field3Scene::render(void)
{
	//_map->render();
	// ������Ʈ ����
	//_map->objRender();

	// ���� ��ġ 
	IMAGEMANAGER->findImage("NPC1")->frameRender(getMemDC(), 2700, 950, 2, 2);
	IMAGEMANAGER->findImage("�����������")->render(getMemDC(), 2750, 1000);
	
	//_map->objRender();
	
	if (_bossTalk)
	{
		if (_who == 1 || _who == 3 || _who == 7 || _who == 9 || _who == 11 || _who == 15)
		{
			IMAGEMANAGER->findImage("ĳ�����̹���1")->frameRender(CAMERA->getCameraDC(), 137, 400, 0, 0);
		}
		else if (_who == 4 || _who == 8 || _who == 13)
		{
			IMAGEMANAGER->findImage("ĳ�����̹���1")->frameRender(CAMERA->getCameraDC(), 137, 400, 1, 0);
		}

		IMAGEMANAGER->findImage("��ȭâ1")->render(CAMERA->getCameraDC(), 272, 400);
		SetTextColor(getMemDC(), RGB(255, 255, 255));

		for (int i = 0; i < 21; ++i)
		{
			if (_index == i)
			{
				_maxTalkIndex = strlen(vStrBoss[i].c_str());

				if ((_talkIndex * 2) < 70)
				{
					TextOut(CAMERA->getCameraDC(), 300, 430, vStrBoss[i].c_str(), (_talkIndex * 2));
				}
				else if ((_talkIndex * 2) >= 70 && (_talkIndex * 2) < 140)
				{
					string text = "";

					text = vStrBoss[i].substr(0, 70);
					TextOut(CAMERA->getCameraDC(), 300, 430, text.c_str(), text.size());

					text = vStrBoss[i].substr(70, 140);
					TextOut(CAMERA->getCameraDC(), 300, 450, text.c_str(), (_talkIndex * 2) - 70);
				}
				else
				{
					string text = "";

					text = vStrBoss[i].substr(0, 70);
					TextOut(CAMERA->getCameraDC(), 300, 430, text.c_str(), text.size());

					text = vStrBoss[i].substr(70, 140);
					TextOut(CAMERA->getCameraDC(), 300, 450, text.c_str(), text.size() - 70);

					text = vStrBoss[i].substr(140, _maxTalkIndex);
					TextOut(CAMERA->getCameraDC(), 300, 470, text.c_str(), (_talkIndex * 2) - 140);
				}
			}
		}
	}

	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);

	fontUI();

}

void field3Scene::fontUI(void)
{
	HFONT font, ofont;
	


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
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
	//�÷��̾ ��� ��ġ�� �ִ��Ŀ� ���� ��Ż �̵� �� �� �̵�
	int idX = _pm->getPlayer()->getZorderRC().right / TILESIZE - 1;
	int idY = _pm->getPlayer()->getZorderRC().top / TILESIZE;
	switch (_map->getTiles()[idY * TILEX + idX].obj)
	{
	case OBJ_UPPORTAL:
		_pm->getPlayer()->setX(550); _pm->getPlayer()->setY(1950);
		_pm->getPlayer2()->setX(550); _pm->getPlayer2()->setY(1950);
		SCENEMANAGER->changeScene("�̺�Ʈ��");		
	break;
	case OBJ_DOWNPORTAL: break;
	case OBJ_LEFTPORTAL: break;
	case OBJ_RIGHTPORTAL:break;

	}
}

void field3Scene::talkSave()
{
	vStrBoss.push_back(strBoss1);
	vStrBoss.push_back(strBoss2);
	vStrBoss.push_back(strBoss3);
	vStrBoss.push_back(strBoss4);
	vStrBoss.push_back(strBoss5);
	vStrBoss.push_back(strBoss6);
	vStrBoss.push_back(strBoss7);
	vStrBoss.push_back(strBoss8);
	vStrBoss.push_back(strBoss9);
	vStrBoss.push_back(strBoss10);
	vStrBoss.push_back(strBoss11);
	vStrBoss.push_back(strBoss12);
	vStrBoss.push_back(strBoss13);
	vStrBoss.push_back(strBoss14);
	vStrBoss.push_back(strBoss15);
	vStrBoss.push_back(strBoss16);
	vStrBoss.push_back(strBoss17);

	TXTDATA->txtSave("Boss���.txt", vStrBoss);
}

void field3Scene::talkLoad()
{
	vStrBoss = TXTDATA->txtLoad("Boss���.txt");
}
