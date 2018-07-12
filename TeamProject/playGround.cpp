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

	SCENEMANAGER->addScene("½ºÅ¸Æ®¾À", new startScene);
	SCENEMANAGER->addScene("¿£µå¾À", new endScene);
	SCENEMANAGER->addScene("¸ÊÅø¾À", new mapToolScene);
	SCENEMANAGER->changeScene("½ºÅ¸Æ®¾À");
	_psm = new playSceneManager;
	_psm->init();
	
	SOUNDMANAGER->play("MainTheMa", 0.5f);

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
	if(SCENEMANAGER->getCurrentSceneName() != "½ºÅ¸Æ®¾À" && SCENEMANAGER->getCurrentSceneName() != "¸ÊÅø¾À" )
	{
		SOUNDMANAGER->stop("MainTheMa");
		_psm->update();
	}
	
}

void playGround::render(void)
{

	//Èò»öµµÈ­Áö ÇÑ Àå ±ò¾ÆµÐ´Ù
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH oldbrush = (HBRUSH)SelectObject(CAMERA->getCameraDC(), brush);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, PATCOPY);
	SelectObject(CAMERA->getCameraDC(), oldbrush);
	DeleteObject(brush);

	//============== ÀÌ À§·Î´Â °Çµå¸®Áö ¸»ÀÚ ==============

	SCENEMANAGER->render();

	if (SCENEMANAGER->getCurrentSceneName() != "½ºÅ¸Æ®¾À" && SCENEMANAGER->getCurrentSceneName() != "¸ÊÅø¾À")
	{
		_psm->render();
	}
	
	TIMEMANAGER->render(CAMERA->getCameraDC());

	//================ÀÌ ¹ØÀ¸·Îµµ °Çµå¸®Áö ¸»ÀÚ =============
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
	// È£°Ý±Ç
	SOUNDMANAGER->addSound("TigerSound", "soundEffect/TigerSound.mp3", true, false);
	// ºñ±â ±¤ÆÄÂü
	SOUNDMANAGER->addSound("EnergyCharge", "soundEffect/EnergyCharge.wav", true, false);
	SOUNDMANAGER->addSound("EnergyGo", "soundEffect/EnergyGo.mp3", true, false);
	// º£±â 3°³ ¼Ò¸®
	SOUNDMANAGER->addSound("Cut1", "soundEffect/Cut1.mp3", true, false);
	SOUNDMANAGER->addSound("Cut2", "soundEffect/Cut2.mp3", true, false);
	SOUNDMANAGER->addSound("Cut3", "soundEffect/Cut3.mp3", true, false);
	SOUNDMANAGER->addSound("Cut4", "soundEffect/Cut4.mp3", true, false);
	// ºÐ½Å¼ú
	SOUNDMANAGER->addSound("Clone1", "soundEffect/Clone1.mp3", true, false);
	// ¿ë¿À¸§
	SOUNDMANAGER->addSound("DragronUp", "soundEffect/DragronUp.mp3", true, false);
	// È­µÐ
	SOUNDMANAGER->addSound("Flour", "soundEffect/Flour.mp3", true, false);
	// ´Ù¸®ÈÄ¸®±â
	SOUNDMANAGER->addSound("Overturn", "soundEffect/Overturn.mp3", true, false);
	// ³ëÀÍÀå ´ëÆø¹ß
	SOUNDMANAGER->addSound("Volcano", "soundEffect/Volcano.mp3", true, false);
	// ¸Â´Â ¼Ò¸®
	SOUNDMANAGER->addSound("Hit", "soundEffect/Hit.mp3", true, false);
}



