#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init(void)
{
	gameNode::init(true);

	musicInit();

	SCENEMANAGER->addScene("스타트씬", new startScene);
	SCENEMANAGER->addScene("엔드씬", new endScene);
	SCENEMANAGER->addScene("맵툴씬", new mapToolScene);
	SCENEMANAGER->changeScene("스타트씬");
	_psm = new playSceneManager;
	_psm->init();
	
	_startScene = new startScene;
	_startScene->init();
	return S_OK;
}

void playGround::release(void)
{
	gameNode::release();
	_psm->release();
	
}

void playGround::update(void)
{
	
	gameNode::update();
	SCENEMANAGER->update();
	if (!_startScene->getIsPlay())
	{
		_startScene->update();
		if (!SOUNDMANAGER->isPlaySound("MainTheMa"))
		{
			SOUNDMANAGER->play("MainTheMa", 0.5f);
		}
	}
	if (_startScene->getIsPlay())
	{
		SOUNDMANAGER->stop("MainTheMa");
		_psm->update();
	}
	
	
	
}

void playGround::render(void)
{

	//흰색도화지 한 장 깔아둔다
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH oldbrush = (HBRUSH)SelectObject(CAMERA->getCameraDC(), brush);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, PATCOPY);
	SelectObject(CAMERA->getCameraDC(), oldbrush);
	DeleteObject(brush);

	//============== 이 위로는 건드리지 말자 ==============

	
	if (_startScene->getIsPlay())
	{
		_psm->render();
	}
	SCENEMANAGER->render();
	
	TIMEMANAGER->render(CAMERA->getCameraDC());

	//================이 밑으로도 건드리지 말자 =============
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(getMemDC());
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getPosition().x, CAMERA->getPosition().y, WINSIZEX, WINSIZEY);


}

void playGround::musicInit()
{
	SOUNDMANAGER->addSound("MainTheMa", "soundOST/MainTheMa.mp3", true, true);
	SOUNDMANAGER->addSound("TownTheMa", "soundOST/TownTheMa.mp3", true, true);
	SOUNDMANAGER->addSound("BattleTheMa1", "soundOST/BattleTheMa1.mp3", true, true);
	SOUNDMANAGER->addSound("BattleTheMa2", "soundOST/BattleTheMa2.mp3", true, true);
	SOUNDMANAGER->addSound("FiledTheMa", "soundOST/FiledTheMa.mp3", true, true);
	SOUNDMANAGER->addSound("eventTheMa", "soundOST/eventTheMa.mp3", true, true);
	// 호격권
	SOUNDMANAGER->addSound("TigerSound", "soundEffect/TigerSound.mp3", true, false);
	// 비기 광파참
	SOUNDMANAGER->addSound("EnergyCharge", "soundEffect/EnergyCharge.wav", true, false);
	SOUNDMANAGER->addSound("EnergyGo", "soundEffect/EnergyGo.mp3", true, false);
	// 베기 3개 소리
	SOUNDMANAGER->addSound("Cut1", "soundEffect/Cut1.mp3", true, false);
	SOUNDMANAGER->addSound("Cut2", "soundEffect/Cut2.mp3", true, false);
	SOUNDMANAGER->addSound("Cut3", "soundEffect/Cut3.mp3", true, false);
	SOUNDMANAGER->addSound("Cut4", "soundEffect/Cut4.mp3", true, false);
	// 분신술
	SOUNDMANAGER->addSound("Clone1", "soundEffect/Clone1.mp3", true, false);
	// 용오름
	SOUNDMANAGER->addSound("DragronUp", "soundEffect/DragronUp.mp3", true, false);
	// 화둔
	SOUNDMANAGER->addSound("Flour", "soundEffect/Flour.mp3", true, false);
	// 다리후리기
	SOUNDMANAGER->addSound("Overturn", "soundEffect/Overturn.mp3", true, false);
	// 노익장 대폭발
	SOUNDMANAGER->addSound("Volcano", "soundEffect/Volcano.mp3", true, false);
	// 맞는 소리
	SOUNDMANAGER->addSound("Hit", "soundEffect/Hit.mp3", true, false);
}



