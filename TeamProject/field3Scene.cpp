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

	return S_OK;
}

void field3Scene::release(void)
{
}

void field3Scene::update(void)
{
	CAMERA->setPosition(_pm->getPlayer()->getX(), _pm->getPlayer()->getY());

	// �÷��̾ ��� Ÿ�Ͽ� �ִ��� �ε��� ��ȣ ����
	_map->setTilePos(_pm->getPlayer()->getZorderRC(), OBJ_PLAYER1);
	_map->setTilePos(_pm->getPlayer2()->getZorderRC(), OBJ_PLAYER2);
	// �� Ÿ�� �ε�����ȣ �߰��ؾ���

	sceneChange();

}

void field3Scene::render(void)
{
	//_map->render();
	// ������Ʈ ����
	//_map->objRender();
	
	IMAGEMANAGER->findImage("�׵θ�")->render(CAMERA->getCameraDC(), 0, 0);

	fontUI();

}

void field3Scene::fontUI(void)
{
	HFONT font, ofont;
	char str[] = "�ʵ��";


	font = CreateFont(25, 0, 0, 0, FW_HEAVY, 0, 0, 0, 0, 0, 0, 0, 0, "������");
	ofont = (HFONT)SelectObject(CAMERA->getCameraDC(), font);
	SetTextColor(CAMERA->getCameraDC(), RGB(255, 255, 255));
	SetBkMode(CAMERA->getCameraDC(), TRANSPARENT);
	TextOut(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2 - 100, str, strlen(str));
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
