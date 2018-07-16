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
	IMAGEMANAGER->addImage("노을엔딩씬", "image/ui/노을엔딩씬.bmp", 1000, 750, false, RGB(0, 0, 0));
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


	// 플레이어가 어느 타일에 있는지 인덱스 번호 세팅
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	// 적 타일 인덱스번호 추가해야함

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
			SCENEMANAGER->changeScene("배틀씬");
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
		SCENEMANAGER->changeScene("엔드씬");
		SOUNDMANAGER->play("EndingTheMa", 0.5f);
	}

	sceneChange();


}

void field3Scene::render(void)
{
	//_map->render();
	// 오브젝트 렌더
	//_map->objRender();

	// 보스 위치 
	IMAGEMANAGER->findImage("NPC1")->frameRender(getMemDC(), 2700, 950, 2, 2);
	IMAGEMANAGER->findImage("린샹앉은모습")->render(getMemDC(), 2750, 1000);
	
	//_map->objRender();
	
	if (_bossTalk)
	{
		if (_who == 1 || _who == 3 || _who == 7 || _who == 9 || _who == 11 || _who == 15)
		{
			IMAGEMANAGER->findImage("캐릭터이미지1")->frameRender(CAMERA->getCameraDC(), 137, 400, 0, 0);
		}
		else if (_who == 4 || _who == 8 || _who == 13)
		{
			IMAGEMANAGER->findImage("캐릭터이미지1")->frameRender(CAMERA->getCameraDC(), 137, 400, 1, 0);
		}

		IMAGEMANAGER->findImage("대화창1")->render(CAMERA->getCameraDC(), 272, 400);
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

	TXTDATA->txtSave("Boss대사.txt", vStrBoss);
}

void field3Scene::talkLoad()
{
	vStrBoss = TXTDATA->txtLoad("Boss대사.txt");
}
