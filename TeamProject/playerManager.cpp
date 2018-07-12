#include "stdafx.h"
#include "playerManager.h"
#include "itemManager.h"
#include "enemyManager.h"

HRESULT playerManager::init()
{
	//��Ÿȣ init()
	_ataho = new player;
	_ataho->init();
	_ataho->setEnemyManagerAdressLink(_em);
	
	//������ init()
	_smasyu = new player2;
	_smasyu->init(_ataho->getX() , _ataho->getY());
	_smasyu->setEnemyManagerAdressLink(_em);

	//�κ��丮 init()
	_gold.money = 10000;
	_gold.moneyFrame = 0;
	
	_HPpoIndex = 0; //���� �ε���
	_MPpoIndex = 0;
	//������ �Ŵ��� ���漱��
	//_im = new itemManager;
	//_im->init();
	//_em = new enemyManager;
	getItemValue("��");
	getItemValue("�ǹ��� ����");
	getItemValue("û�浵");
	getItemValue("���� ����");
	
	_ataho->setStat(_vA_WeapInven[0].atk, _vA_WeapInven[0].def, _vA_WeapInven[0].luck, _vA_WeapInven[0].cri, _vA_WeapInven[0].speed);
	_A_saveBeforWeapon.atk = _vA_WeapInven[0].atk;
	_A_saveBeforWeapon.luck = _vA_WeapInven[0].luck;
	_A_saveBeforWeapon.cri = _vA_WeapInven[0].cri;

	_ataho->setStat(_vA_ArmorInven[0].atk, _vA_ArmorInven[0].def, _vA_ArmorInven[0].luck, _vA_ArmorInven[0].cri, _vA_ArmorInven[0].speed);
	_A_saveBeforArmor.def = _vA_ArmorInven[0].def;
	_A_saveBeforArmor.speed = _vA_ArmorInven[0].speed;
	
	_smasyu->setStat(_vS_WeapInven[0].atk, _vS_WeapInven[0].def, _vS_WeapInven[0].luck, _vS_WeapInven[0].cri, _vS_WeapInven[0].speed);
	_S_saveBeforWeapon.atk = _vS_WeapInven[0].atk;
	_S_saveBeforWeapon.luck = _vS_WeapInven[0].luck;
	_S_saveBeforWeapon.cri = _vS_WeapInven[0].cri;

	_smasyu->setStat(_vS_ArmorInven[0].atk, _vS_ArmorInven[0].def, _vS_ArmorInven[0].luck, _vS_ArmorInven[0].cri, _vS_ArmorInven[0].speed);
	_S_saveBeforArmor.def = _vS_ArmorInven[0].def;
	_S_saveBeforArmor.speed = _vS_ArmorInven[0].speed;
	

	return S_OK;
}

void playerManager::update()
{
	//�÷��̾�
	_ataho->update();	
	_smasyu->update();
	
	_smasyu->fieldKeyManager(_ataho->getX(), _ataho->getY(), _ataho->getAngle());
	eventMode(); //��Ÿȣ ������ �� �������� ���� �������� �ϴ� �Լ�
	inventory(); //�κ��丮
	setEnemyDead(); //�� ���
	
	//�κ��丮

}

void playerManager::render()
{
	//�÷��̾�
	if (_ataho->getY() > _smasyu->getY())
	{
		_smasyu->render();
		_ataho->render();
	}
	else
	{
		_ataho->render();
		_smasyu->render();
	}

	char str[1000];
	
	for (int i = 0; i < _vA_WeapInven.size(); ++i)
	{
		sprintf_s(str, "�̸� : %s", _vA_WeapInven[i].name.c_str());
		TextOut(getMemDC(), 250 +i*100, WINSIZEY / 2-150 + 100, str, strlen(str));
	}
		sprintf_s(str, "��Ÿȣ �� : %d", _gold.money);
		TextOut(getMemDC(), 250, WINSIZEY / 2 - 150 + 120, str, strlen(str));
		sprintf_s(str, "��Ÿȣ ���� : %d", _ataho->getAttribute().def);
		TextOut(getMemDC(), 250, WINSIZEY / 2 - 150 + 140, str, strlen(str));
		sprintf_s(str, "��Ÿȣ �� : %d", _ataho->getAttribute().luck);
		TextOut(getMemDC(), 250, WINSIZEY / 2 - 150 + 160, str, strlen(str));
		sprintf_s(str, "��Ÿȣ ���ǵ� : %d", _ataho->getAttribute().speed);
		TextOut(getMemDC(), 250, WINSIZEY / 2 - 150 + 180, str, strlen(str));
	
		for (int i = 0; i < _em->getVEnmey().size(); i++)
		{
			char str2[1000];
			sprintf_s(str2, "�� ü�� : %d", _em->getVEnmey()[i]->getTagEnmey().hp);
			TextOut(getMemDC(),  WINSIZEX - 200,100 + i*20 , str2, strlen(str2));
			
		}

	
	for (int i = 0; i < _vPoInven.size(); i++)
	{
		if (_vPoInven[i].hp != 0)
		{
			Rectangle(getMemDC(), _vPoInven[i].rc.left, _vPoInven[i].rc.top, _vPoInven[i].rc.right, _vPoInven[i].rc.bottom);
			char str[100];
			sprintf_s(str, "%d", _HPpoIndex);
			TextOut(getMemDC(), _vPoInven[i].rc.left, _vPoInven[i].rc.top, str, strlen(str));
		}
		if (_vPoInven[i].mp != 0)
		{
			Rectangle(getMemDC(), _vPoInven[i].rc.left, _vPoInven[i].rc.top, _vPoInven[i].rc.right, _vPoInven[i].rc.bottom);
			char str2[100];
			sprintf_s(str2, "%d", _MPpoIndex);
			TextOut(getMemDC(), _vPoInven[i].rc.left, _vPoInven[i].rc.top, str2, strlen(str2));
		}
	}
}


void playerManager::release()
{
	//�÷��̾�
	_ataho->release();
	_smasyu->release();

	//�κ��丮
}

void playerManager::eventMode()
{
	if (_ataho->getSceneMode() == EVENTMODE)
	{
		
		if (_ataho->getIsJumping() == true)
		{
			_smasyu->setIsJumping(true);
		}

		if (_ataho->getSlopeNum() <= 2 || _ataho->getSlopeNum() >= 6)
		{
			_smasyu->setSkillMove(S_AFRAID);
		}
	}
}
//�����ϱ�
void playerManager::mounting(int frameX, int setIndex, int invenTypeIndex, int invenIndex)
{                   //��Ÿȣ���� ���������� , ���ǰ������۹�ȣ , ������ �������ȣ, ����� ������ ��ȣ 
	//��Ÿȣ ����
	if (frameX == 0 && setIndex == 2)
	{
		if (invenTypeIndex == 0)
		{
			_ataho->setStat(-_A_saveBeforWeapon.atk, 0, -_A_saveBeforWeapon.luck, -_A_saveBeforWeapon.cri, 0);
			_ataho->setStat(_vA_WeapInven[invenIndex].atk, _vA_WeapInven[invenIndex].def, _vA_WeapInven[invenIndex].luck, _vA_WeapInven[invenIndex].cri, _vA_WeapInven[invenIndex].speed);
			_A_saveBeforWeapon.atk = _vA_WeapInven[invenIndex].atk;
			_A_saveBeforWeapon.luck = _vA_WeapInven[invenIndex].luck;
			_A_saveBeforWeapon.cri = _vA_WeapInven[invenIndex].cri;
			if (_vA_WeapInven[invenIndex].name == "���� �ͽŻ�")
			{
				_ataho->setSwordMounting(true);
			}
			else
			{
				_ataho->setSwordMounting(false);
			}
		}
	
		if (invenTypeIndex == 1)
		{
			//��Ÿȣ ����
			_ataho->setStat(-_A_saveBeforArmor.atk, -_A_saveBeforArmor.def, -_A_saveBeforArmor.luck, -_A_saveBeforArmor.cri, -_A_saveBeforArmor.speed);
			_ataho->setStat(_vA_ArmorInven[invenIndex].atk, _vA_ArmorInven[invenIndex].def, _vA_ArmorInven[invenIndex].luck, _vA_ArmorInven[invenIndex].cri, _vA_ArmorInven[invenIndex].speed);
			_A_saveBeforArmor.def = _vA_ArmorInven[invenIndex].def;
			_A_saveBeforArmor.speed = _vA_ArmorInven[invenIndex].speed;
		}
	}



	if (frameX == 1 && setIndex == 2)
	{
		//������ ����
		if (invenTypeIndex == 0)
		{

			_smasyu->setStat(-_S_saveBeforWeapon.atk, 0, -_S_saveBeforWeapon.luck, -_S_saveBeforWeapon.cri, 0);
			_smasyu->setStat(_vS_WeapInven[invenIndex].atk, _vS_WeapInven[invenIndex].def, _vS_WeapInven[invenIndex].luck, _vS_WeapInven[invenIndex].cri, _vS_WeapInven[invenIndex].speed);
			_S_saveBeforWeapon.atk = _vS_WeapInven[invenIndex].atk;
			_S_saveBeforWeapon.luck = _vS_WeapInven[invenIndex].luck;
			_S_saveBeforWeapon.cri = _vS_WeapInven[invenIndex].cri;
			if (_vS_WeapInven[invenIndex].name == "���ξƼ���")
			{
				_smasyu->setMounting(true);
			}
			else
			{
				_smasyu->setMounting(false);

			}
		}
		if (invenTypeIndex == 1)
		{
			//������ ����

			_smasyu->setStat(-_S_saveBeforArmor.atk, -_S_saveBeforArmor.def, -_S_saveBeforArmor.luck, -_S_saveBeforArmor.cri, -_S_saveBeforArmor.speed);
			_smasyu->setStat(_vS_ArmorInven[invenIndex].atk, _vS_ArmorInven[invenIndex].def, _vS_ArmorInven[invenIndex].luck, _vS_ArmorInven[invenIndex].cri, _vS_ArmorInven[invenIndex].speed);
			_S_saveBeforArmor.def = _vS_ArmorInven[invenIndex].def;
			_S_saveBeforArmor.speed = _vS_ArmorInven[invenIndex].speed;
		}
	}


	if (setIndex == 1)
	{
		//��Ÿȣ�� ��
		_ataho->setPortion(_vPoInven[invenIndex].hp, _vPoInven[invenIndex].mp);
		//�������� ��
		_smasyu->setPortion(_vPoInven[invenIndex].hp, _vPoInven[invenIndex].mp);

		if (_vPoInven[invenIndex].hp != 0)
		{
			_HPpoIndex -= 1;
		}
		if (_vPoInven[invenIndex].mp != 0)
		{
			_MPpoIndex -= 1;
		}
		if (_MPpoIndex == 0 && _vPoInven[invenIndex].mp != 0 && _vPoInven.size() > 0)
		{
			_vPoInven.erase(_vPoInven.begin() + invenIndex);
		}
		else if (_HPpoIndex == 0 && _vPoInven[invenIndex].hp != 0 && _vPoInven.size() > 0)
		{
			_vPoInven.erase(_vPoInven.begin() + invenIndex);
		}
	}
}

//�޾Ƽ� Ǫ���� ������ ����
void playerManager::getItemValue(string itemName)
{
	int frameX = INIDATA->loadDataInterger("item", itemName.c_str(), "frameX");
	int frameY = INIDATA->loadDataInterger("item", itemName.c_str(), "frameY");
	
	tagInventory inventory;
	inventory.name = INIDATA->loadDataString("item", itemName.c_str(), "�̸�");
	inventory.atk = INIDATA->loadDataInterger("item", itemName.c_str(), "���ݷ�");
	inventory.luck = INIDATA->loadDataInterger("item", itemName.c_str(), "��");
	inventory.cri = INIDATA->loadDataInterger("item", itemName.c_str(), "ũ��Ƽ�� Ȯ��");
	inventory.def = INIDATA->loadDataInterger("item", itemName.c_str(), "����");
	inventory.speed = INIDATA->loadDataInterger("item", itemName.c_str(), "���ǵ�");
	inventory.hp = INIDATA->loadDataInterger("item", itemName.c_str(), "HPȸ��");
	inventory.mp = INIDATA->loadDataInterger("item", itemName.c_str(), "MPȸ��");

	//statusScene�� �� �Ҹ�ǰ �̹���
	if (inventory.name == "����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(0);
		inventory.img->setFrameY(3);
	}
	if (inventory.name == "������ ����") 
	{
		inventory.img = IMAGEMANAGER->addFrameImage("��������",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(3);
		inventory.img->setFrameY(3);
	}
	//statusScene�� �� ��� �̹���
	if (inventory.name == "��")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("��",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(1);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "ȭ��")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("ȭ��",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(4);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "Ư����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("Ư����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(2);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "���� �ͽŻ�")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("���� �ͽŻ�",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(5);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "�ǹ��� ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("�ǹ��� ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(7);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "ȣ���� ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("ȣ���� ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(9);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "������ ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("������ ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(10);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "��ȣ ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("��ȣ ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(11);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "û�浵")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("û�浵",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(1);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "��Ÿ�� ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("��Ÿ�� ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(2);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "������ ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("������ ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(4);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "���ξƼ���")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("���ξƼ���",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(5);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "���� ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("���� ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(7);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "ö�� ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("ö�� ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(9);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "�Ʈ ��Ʈ")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("�Ʈ ��Ʈ",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(10);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "������ ����")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("������ ����",
			"image/ui/������.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(11);
		inventory.img->setFrameY(2);
	}

	//��Ÿȣ ����
	if (frameY == 0)
	{
		if (frameX < 6)
		{
			_vA_WeapInven.push_back(inventory);
		}

		//��Ÿȣ ��
		if (frameX >= 6)
		{
			
			_vA_ArmorInven.push_back(inventory);
		}
	}

	//������ ����
	else if (frameY == 2)
	{
		if (frameX < 6)
		{
			_vS_WeapInven.push_back(inventory);
		}

		//������ ��
		if (frameX >= 6)
		{
			_vS_ArmorInven.push_back(inventory);
		}
	}

	//����
	else if (frameY == 3)
	{

		if (_HPpoIndex == 0 && inventory.hp != 0)
		{
			_vPoInven.push_back(inventory);
		}
		if (_MPpoIndex == 0 && inventory.mp != 0)
		{
			_vPoInven.push_back(inventory);
		}
		if (inventory.hp != 0 && _HPpoIndex < 10)
		{
			_HPpoIndex += 1;
		}
		if (inventory.mp != 0 && _MPpoIndex < 10)
		{
			_MPpoIndex += 1;
		}
	}
}

void playerManager::inventory()
{
	//��Ÿȣ ����
	for (int i = 0; i < _vA_WeapInven.size(); i++)
	{
		_vA_WeapInven[i].rc = RectMakeCenter(600+ i * 50, 100, 50, 50);
	}
	//��Ÿȣ ��
	for (int i = 0; i < _vA_ArmorInven.size(); i++)
	{
		_vA_ArmorInven[i].rc = RectMakeCenter(600 + i * 50, 150, 50, 50);
	}
	//������ ����
	for (int i = 0; i <_vS_WeapInven.size(); i++)
	{
		_vS_WeapInven[i].rc = RectMakeCenter(600 + i * 50, 250, 50, 50);
	}
	//������ ��
	for (int i = 0; i <_vS_ArmorInven.size(); i++)
	{
		_vS_ArmorInven[i].rc = RectMakeCenter(600 + i * 50, 300, 50, 50);
	}
	//����
	for  (int i = 0; i < _vPoInven.size();  i++)
	{
		_vPoInven[i].rc = RectMakeCenter(600 + i*50, 350, 50, 50);
	}
}

void playerManager::setEnemyDead()
{

	for (int i = 0; i < _em->getVEnmey().size(); i++)
	{
		
		//���ʹ� ���
		if ( _em->getVEnmey()[i]->getTagEnmey().direction != DEAD && _em->getVEnmey()[i]->getTagEnmey().hp == 0 )
		{		
			if (_ataho->getMove() == FIGHTREADY && _smasyu->getMove() == S_FIGHTREADY)
			{
				_ataho->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_smasyu->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_gold.money += _em->getVEnmey()[i]->getTagEnmey().dropGold;
				
			}
			else if (_ataho->getMove() == FIGHTREADY && _smasyu->getMove() == S_NOCKDOWN)
			{
				_ataho->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_gold.money += _em->getVEnmey()[i]->getTagEnmey().dropGold;
			}
			else if (_ataho->getMove() == NOCKDOWN && _smasyu->getMove() == S_FIGHTREADY)
			{
				_smasyu->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_gold.money += _em->getVEnmey()[i]->getTagEnmey().dropGold;
			}
			//if (_ataho->getSkillFrame() == 0)_em->getVEnmey()[i]->setEnemyDirection(DEAD);

			if (_smasyu->getSkillFrame() == 0) _em->getVEnmey()[i]->setEnemyDirection(DEAD);
		}
		if (_em->getVEnmey()[i]->getTagEnmey().fadeCount >= 151 )
		{
			_em->removeEnemy(i);
		}
		if (_em->getVEnmey().size() == 0)
		{
			_ataho->setMove(SEREMONI);
			_smasyu->setMove(S_SEREMONI);
		}
	}
}

void playerManager::setMoney(int money)
{
	_gold.money -= money;
}



playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}
