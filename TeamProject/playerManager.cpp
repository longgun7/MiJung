#include "stdafx.h"
#include "playerManager.h"
#include "itemManager.h"

HRESULT playerManager::init()
{
	
	//아타호 init()
	_ataho = new player;
	_ataho->init();
	
	//스마슈 init()
	_smasyu = new player2;
	_smasyu->init(_ataho->getX() , _ataho->getY());

	//인벤토리 init()

	
	//아이템 매니저 전방선언
	_itemManager = new itemManager;
	
	return S_OK;
}

void playerManager::update()
{
	//플레이어
	_ataho->update();
	_smasyu->update();
	_smasyu->fieldKeyManager(_ataho->getX(), _ataho->getY());
	eventMode(); //아타호 떨어질 때 스마슈도 같이 떨어지게 하는 함수
	getItemValue(); //아이템 인벤
	inventory(); //인벤토리
	mounting();//장착하기
	//인벤토리
	
	

}

void playerManager::render()
{
	//플레이어
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
		sprintf_s(str, "이름 : %s", _vA_WeapInven[i].name.c_str());
		TextOut(getMemDC(), 100 +i*100, WINSIZEY / 2-150 + 100, str, strlen(str));
	}
		sprintf_s(str, "아타호 공격력 : %d", _ataho->getAttribute().atk);
		TextOut(getMemDC(), 100 , WINSIZEY / 2 - 150 + 120, str, strlen(str));
		sprintf_s(str, "아타호 방어력 : %d", _ataho->getAttribute().def);
		TextOut(getMemDC(), 100 , WINSIZEY / 2 - 150 + 140, str, strlen(str));
		sprintf_s(str, "아타호 운 : %d", _ataho->getAttribute().luck);
		TextOut(getMemDC(), 100 , WINSIZEY / 2 - 150 + 160, str, strlen(str));
		sprintf_s(str, "아타호 스피드 : %d", _ataho->getAttribute().speed);
		TextOut(getMemDC(), 100, WINSIZEY / 2 - 150 + 180, str, strlen(str));
	
	for (int i = 0; i < _vA_ArmorInven.size(); i++)
	{
		sprintf_s(str, "이름 : %s", _vA_ArmorInven[i].name.c_str());
		TextOut(getMemDC(), 100 + i * 100, WINSIZEY / 2 - 50+100, str, strlen(str));
		sprintf_s(str, "공격력 : %d", _vA_ArmorInven[i].atk);
		TextOut(getMemDC(), 100 + i * 100, WINSIZEY / 2 - 50 + 120, str, strlen(str));
		sprintf_s(str, "방어력 : %d", _vA_ArmorInven[i].def);
		TextOut(getMemDC(), 100 + i * 100, WINSIZEY / 2 - 50 + 140, str, strlen(str));
		sprintf_s(str, "운 : %d", _vA_ArmorInven[i].luck);
		TextOut(getMemDC(), 100 + i * 100, WINSIZEY / 2 - 50 + 160, str, strlen(str));
		sprintf_s(str, "스피드 : %d", _vA_ArmorInven[i].speed);
		TextOut(getMemDC(), 100 + i * 100, WINSIZEY / 2 - 50 + 180, str, strlen(str));
	}
	for (int i = 0; i < _vA_WeapInven.size(); i++)
	{
		Rectangle(getMemDC(), _vA_WeapInven[i].rc.left, _vA_WeapInven[i].rc.top, _vA_WeapInven[i].rc.right, _vA_WeapInven[i].rc.bottom);
	}
}


void playerManager::release()
{
	//플레이어
	_ataho->release();
	_smasyu->release();

	//인벤토리
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
//장착하기
void playerManager::mounting()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vA_WeapInven.size(); i++)
		{
			if (PtInRect(&_vA_WeapInven[i].rc, _ptMouse))
			{	
				_ataho->setStat(-_A_saveBeforWeapon.atk, 0, -_A_saveBeforWeapon.luck, 0, 0);
				_ataho->setStat(_vA_WeapInven[i].atk, _vA_WeapInven[i].def, _vA_WeapInven[i].luck, _vA_WeapInven[i].cri, _vA_WeapInven[i].speed);
				_A_saveBeforWeapon.atk = _vA_WeapInven[i].atk;
				_A_saveBeforWeapon.luck = _vA_WeapInven[i].luck;
			}
		}
	}
}

//인벤토리 종류
void playerManager::getItemValue()
{
	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		//아타호 무기
		for (int i = 0; i < _itemManager->getA_Weapon()->getVItem().size(); ++i)
		{
			if (PtInRect(&_itemManager->getA_Weapon()->getVItem()[i].rc, _ptMouse))
			{
				tagInventory inventory;
				ZeroMemory(&inventory, sizeof(inventory));

				inventory.name = _itemManager->getA_Weapon()->getName(i);
				inventory.atk = _itemManager->getA_Weapon()->getVItem()[i].atk;
				inventory.def = _itemManager->getA_Weapon()->getVItem()[i].def;
				inventory.luck = _itemManager->getA_Weapon()->getVItem()[i].luck;
				inventory.cri = _itemManager->getA_Weapon()->getVItem()[i].critical;
				inventory.speed = _itemManager->getA_Weapon()->getVItem()[i].speed;

				_invenAttribute = MOUNTING; //무기를 장착했다
				
				if (inventory.luck == 25)
				{
					_ataho->setSwordMounting(true);
				}
				else
				{
					_ataho->setSwordMounting(false);
				}
				_vA_WeapInven.push_back(inventory);
			}
		}
		//아타호 방어구
		for (int i = 0; i < _itemManager->getA_Armor()->getVItem().size(); i++)
		{
			if (PtInRect(&_itemManager->getA_Armor()->getVItem()[i].rc, _ptMouse))
			{
				tagInventory inventory;
				ZeroMemory(&inventory, sizeof(inventory));

				inventory.name = _itemManager->getA_Armor()->getName(i);
				inventory.atk = _itemManager->getA_Armor()->getVItem()[i].atk;
				inventory.def = _itemManager->getA_Armor()->getVItem()[i].def;
				inventory.luck = _itemManager->getA_Armor()->getVItem()[i].luck;
				inventory.cri = _itemManager->getA_Armor()->getVItem()[i].critical;
				inventory.speed = _itemManager->getA_Armor()->getVItem()[i].speed;

				_vA_ArmorInven.push_back(inventory);
			}
		}
		//스마슈 무기
		for (int i = 0; i < _itemManager->getS_Weapon()->getVItem().size(); i++)
		{
			if (PtInRect(&_itemManager->getS_Weapon()->getVItem()[i].rc, _ptMouse))
			{
				tagInventory inventory;
				ZeroMemory(&inventory, sizeof(inventory));

				inventory.name = _itemManager->getS_Weapon()->getName(i);
				inventory.atk = _itemManager->getS_Weapon()->getVItem()[i].atk;
				inventory.def = _itemManager->getS_Weapon()->getVItem()[i].def;
				inventory.luck = _itemManager->getS_Weapon()->getVItem()[i].luck;
				inventory.cri = _itemManager->getS_Weapon()->getVItem()[i].critical;
				inventory.speed = _itemManager->getS_Weapon()->getVItem()[i].speed;

				if (inventory.atk == 50)
				{
					_smasyu->setMounting(true);
				}
				else
				{
					_smasyu->setMounting(false);
				}
				_vS_WeapInven.push_back(inventory);
			}
		}
		//스마슈 방어구
		for (int i = 0; i < _itemManager->getS_Armor()->getVItem().size(); i++)
		{
			if (PtInRect(&_itemManager->getS_Armor()->getVItem()[i].rc, _ptMouse))
			{
				tagInventory inventory;
				ZeroMemory(&inventory, sizeof(inventory));

				inventory.name = _itemManager->getS_Armor()->getName(i);
				inventory.atk = _itemManager->getS_Armor()->getVItem()[i].atk;
				inventory.def = _itemManager->getS_Armor()->getVItem()[i].def;
				inventory.luck = _itemManager->getS_Armor()->getVItem()[i].luck;
				inventory.cri = _itemManager->getS_Armor()->getVItem()[i].critical;
				inventory.speed = _itemManager->getS_Armor()->getVItem()[i].speed;

				_vS_ArmorInven.push_back(inventory);
			}
		}

		//포션
		for (int i = 0; i < _itemManager->getPortion()->getVItem().size(); i++)
		{
			if (PtInRect(&_itemManager->getPortion()->getVItem()[i].rc, _ptMouse))
			{
				tagInventory inventory;
				ZeroMemory(&inventory, sizeof(inventory));

				inventory.name = _itemManager->getPortion()->getName(i);
				inventory.atk = _itemManager->getPortion()->getVItem()[i].atk;
				inventory.def = _itemManager->getPortion()->getVItem()[i].def;
				inventory.luck = _itemManager->getPortion()->getVItem()[i].luck;
				inventory.cri = _itemManager->getPortion()->getVItem()[i].critical;
				inventory.speed = _itemManager->getPortion()->getVItem()[i].speed;

				_vPorInven.push_back(inventory);
			}
		}

	}

}

void playerManager::inventory()
{
	for (int i = 0; i < _vA_WeapInven.size(); i++)
	{
		_vA_WeapInven[i].rc = RectMakeCenter(500+ i * 50, 400, 50, 50);
	}
}

playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}
