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
	mounting();//�����ϱ�
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

	for (int i = 0; i < _vA_WeapInven.size(); i++)
	{
		Rectangle(getMemDC(), _vA_WeapInven[i].rc.left, _vA_WeapInven[i].rc.top, _vA_WeapInven[i].rc.right, _vA_WeapInven[i].rc.bottom);
	}
	for (int i = 0; i < _vA_ArmorInven.size(); i++)
	{
		Rectangle(getMemDC(), _vA_ArmorInven[i].rc.left, _vA_ArmorInven[i].rc.top, _vA_ArmorInven[i].rc.right, _vA_ArmorInven[i].rc.bottom);
	}
	for (int i = 0; i < _vS_WeapInven.size(); i++)
	{
		Rectangle(getMemDC(), _vS_WeapInven[i].rc.left, _vS_WeapInven[i].rc.top, _vS_WeapInven[i].rc.right, _vS_WeapInven[i].rc.bottom);
	}
	for (int i = 0; i < _vS_ArmorInven.size(); i++)
	{
		Rectangle(getMemDC(), _vS_ArmorInven[i].rc.left, _vS_ArmorInven[i].rc.top, _vS_ArmorInven[i].rc.right, _vS_ArmorInven[i].rc.bottom);
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
	if (_ataho->getSCENEMODE() == EVENTMODE)
	{
		
		if (_ataho->getIsJumping() == true)
		{
			_smasyu->setIsJumping(true);
		}

		if (_ataho->getSlopeNum() <= 2 || _ataho->getSlopeNum() >= 6)
		{
			_smasyu->setMove(S_AFRAID);
		}
	}
}
//�����ϱ�
void playerManager::mounting()
{
	//��Ÿȣ ����
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vA_WeapInven.size(); i++)
		{
			
			if (PtInRect(&_vA_WeapInven[i].rc, _ptMouse) )
			{
				_ataho->setStat(-_A_saveBeforWeapon.atk, 0, -_A_saveBeforWeapon.luck, -_A_saveBeforWeapon.cri, 0);
				_ataho->setStat(_vA_WeapInven[i].atk, _vA_WeapInven[i].def, _vA_WeapInven[i].luck, _vA_WeapInven[i].cri, _vA_WeapInven[i].speed);
				_A_saveBeforWeapon.atk = _vA_WeapInven[i].atk;
				_A_saveBeforWeapon.luck = _vA_WeapInven[i].luck;
				_A_saveBeforWeapon.cri = _vA_WeapInven[i].cri;
				if (_vA_WeapInven[i].name == "���� �ͽŻ�")
				{
					_ataho->setSwordMounting(true);
				}
				else
				{
					_ataho->setSwordMounting(false);
				}
			}
			
		}

		//��Ÿȣ ����
		for (int i = 0; i < _vA_ArmorInven.size(); i++)
		{
			if (PtInRect(&_vA_ArmorInven[i].rc, _ptMouse))
			{
				_ataho->setStat(-_A_saveBeforArmor.atk, -_A_saveBeforArmor.def, -_A_saveBeforArmor.luck, -_A_saveBeforArmor.cri, -_A_saveBeforArmor.speed);
				_ataho->setStat(_vA_ArmorInven[i].atk, _vA_ArmorInven[i].def, _vA_ArmorInven[i].luck, _vA_ArmorInven[i].cri, _vA_ArmorInven[i].speed);
				_A_saveBeforArmor.def = _vA_ArmorInven[i].def;
				_A_saveBeforArmor.speed = _vA_ArmorInven[i].speed;
			}
		}
		
		//������ ����
		for (int i = 0; i < _vS_WeapInven.size(); i++)
		{
			if (PtInRect(&_vS_WeapInven[i].rc, _ptMouse))
			{
				_smasyu->setStat(-_S_saveBeforWeapon.atk, 0, -_S_saveBeforWeapon.luck, -_S_saveBeforWeapon.cri, 0);
				_smasyu->setStat(_vS_WeapInven[i].atk, _vS_WeapInven[i].def, _vS_WeapInven[i].luck, _vS_WeapInven[i].cri, _vS_WeapInven[i].speed);
				_S_saveBeforWeapon.atk = _vS_WeapInven[i].atk;
				_S_saveBeforWeapon.luck = _vS_WeapInven[i].luck;
				_S_saveBeforWeapon.cri = _vS_WeapInven[i].cri;
				if (_vS_WeapInven[i].name == "���ξƼ���")
				{
					_smasyu->setMounting(true);
				}
				else
				{
					_smasyu->setMounting(false);

				}
			}
		}
		//������ ����
		for (int i = 0; i < _vS_ArmorInven.size(); i++)
		{
			if (PtInRect(&_vS_ArmorInven[i].rc, _ptMouse))
			{
				_smasyu->setStat(-_S_saveBeforArmor.atk, -_S_saveBeforArmor.def, -_S_saveBeforArmor.luck, -_S_saveBeforArmor.cri, -_S_saveBeforArmor.speed);
				_smasyu->setStat(_vS_ArmorInven[i].atk, _vS_ArmorInven[i].def, _vS_ArmorInven[i].luck, _vS_ArmorInven[i].cri, _vS_ArmorInven[i].speed);
				_S_saveBeforArmor.def = _vS_ArmorInven[i].def;
				_S_saveBeforArmor.speed = _vS_ArmorInven[i].speed;
			}
		}
		//����
		for (int i = 0; i < _vPoInven.size(); i++)
		{
			if (PtInRect(&_vPoInven[i].rc, _ptMouse))
			{
				//��Ÿȣ�� ��
				_ataho->setPortion(_vPoInven[i].hp, _vPoInven[i].mp);				
				//�������� ��
				_smasyu->setPortion(_vPoInven[i].hp, _vPoInven[i].mp);
				
				if (_vPoInven[i].hp != 0)
				{
					_HPpoIndex -= 1;
				}
				if (_vPoInven[i].mp != 0)
				{
					_MPpoIndex -= 1;
				}
				if (_MPpoIndex == 0 && _vPoInven[i].mp != 0 && _vPoInven.size() > 0 )
				{
					_vPoInven.erase(_vPoInven.begin() + i);
				}
				else if (_HPpoIndex == 0 && _vPoInven[i].hp != 0 && _vPoInven.size() > 0)
				{
					_vPoInven.erase(_vPoInven.begin() + i);
				}
				
			}
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
				_em->getVEnmey()[i]->setEnemyDirection(DEAD);
				_ataho->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_smasyu->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_gold.money += _em->getVEnmey()[i]->getTagEnmey().dropGold;
			}
			if (_ataho->getMove() == FIGHTREADY && _smasyu->getMove() == S_NOCKDOWN)
			{
				_em->getVEnmey()[i]->setEnemyDirection(DEAD);
				_ataho->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_gold.money += _em->getVEnmey()[i]->getTagEnmey().dropGold;
			}
			if (_ataho->getMove() == NOCKDOWN && _smasyu->getMove() == S_FIGHTREADY)
			{
				_em->getVEnmey()[i]->setEnemyDirection(DEAD);
				_smasyu->setExp(_em->getVEnmey()[i]->getTagEnmey().exp);
				_gold.money += _em->getVEnmey()[i]->getTagEnmey().dropGold;
			}
		}
		if (_em->getVEnmey()[i]->getTagEnmey().fadeCount >=6 )
		{
			_em->removeEnemy(i);
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
