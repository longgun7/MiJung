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

	SCENEMANAGER->addScene("��ŸƮ��", new startScene);
	SCENEMANAGER->addScene("�����", new endScene);
	SCENEMANAGER->addScene("������", new mapToolScene);
	SCENEMANAGER->changeScene("��ŸƮ��");
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
	if(SCENEMANAGER->getCurrentSceneName() != "��ŸƮ��" && SCENEMANAGER->getCurrentSceneName() != "������" )
	{
		SOUNDMANAGER->stop("MainTheMa");
		_psm->update();
	}
	
}

void playGround::render(void)
{

	//�����ȭ�� �� �� ��Ƶд�
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH oldbrush = (HBRUSH)SelectObject(CAMERA->getCameraDC(), brush);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, PATCOPY);
	SelectObject(CAMERA->getCameraDC(), oldbrush);
	DeleteObject(brush);

	//============== �� ���δ� �ǵ帮�� ���� ==============

	SCENEMANAGER->render();

	if (SCENEMANAGER->getCurrentSceneName() != "��ŸƮ��" && SCENEMANAGER->getCurrentSceneName() != "������")
	{
		_psm->render();
	}
	
	TIMEMANAGER->render(CAMERA->getCameraDC());

	//================�� �����ε� �ǵ帮�� ���� =============
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
	// ȣ�ݱ�
	SOUNDMANAGER->addSound("TigerSound", "soundEffect/TigerSound.mp3", true, false);
	// ��� ������
	SOUNDMANAGER->addSound("EnergyCharge", "soundEffect/EnergyCharge.wav", true, false);
	SOUNDMANAGER->addSound("EnergyGo", "soundEffect/EnergyGo.mp3", true, false);
	// ���� 3�� �Ҹ�
	SOUNDMANAGER->addSound("Cut1", "soundEffect/Cut1.mp3", true, false);
	SOUNDMANAGER->addSound("Cut2", "soundEffect/Cut2.mp3", true, false);
	SOUNDMANAGER->addSound("Cut3", "soundEffect/Cut3.mp3", true, false);
	SOUNDMANAGER->addSound("Cut4", "soundEffect/Cut4.mp3", true, false);
	// �нż�
	SOUNDMANAGER->addSound("Clone1", "soundEffect/Clone1.mp3", true, false);
	// �����
	SOUNDMANAGER->addSound("DragronUp", "soundEffect/DragronUp.mp3", true, false);
	// ȭ��
	SOUNDMANAGER->addSound("Flour", "soundEffect/Flour.mp3", true, false);
	// �ٸ��ĸ���
	SOUNDMANAGER->addSound("Overturn", "soundEffect/Overturn.mp3", true, false);
	// ������ ������
	SOUNDMANAGER->addSound("Volcano", "soundEffect/Volcano.mp3", true, false);
	// �´� �Ҹ�
	SOUNDMANAGER->addSound("Hit", "soundEffect/Hit.mp3", true, false);
}



