#include "stdafx.h"
#include "playerManager.h"
#include "itemManager.h"

HRESULT playerManager::init()
{
	
	//��Ÿȣ init()
	_ataho = new player;
	_ataho->init();
	
	//������ init()	
	_smasyu = new player2;
	_smasyu->init(_ataho->getX() , _ataho->getY());

	//�κ��丮 init()


	//������ �Ŵ��� ���漱��
	_itemManager = new itemManager;
	
	return S_OK;
}

void playerManager::update()
{
	//�÷��̾�
	_ataho->update();
	_smasyu->update();
	_smasyu->angleManager(_ataho->getX(), _ataho->getY());
	eventMode(); //��Ÿȣ ������ �� �������� ���� �������� �ϴ� �Լ�
	getItemValue(); //������ �κ�
	
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

void playerManager::getItemValue()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _itemManager->getWeapon()->getVItem().size(); ++i)
		{
			if (PtInRect(&_itemManager->getWeapon()->getVItem()[i].rc, _ptMouse))
			{
				tagInventory inventory;
				ZeroMemory(&inventory, sizeof(inventory));
				
				inventory.name = _itemManager->getWeapon()->getName(i);
				inventory._atk = _itemManager->getWeapon()->getVItem()[i].atk;
				inventory._def = _itemManager->getWeapon()->getVItem()[i].def;
				inventory._luck = _itemManager->getWeapon()->getVItem()[i].luck;
				inventory._cri = _itemManager->getWeapon()->getVItem()[i].critical;
				inventory._speed = _itemManager->getWeapon()->getVItem()[i].speed;
				
				_vItemInven.push_back(inventory);
			}
		}
	}
	
	

}

playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}
