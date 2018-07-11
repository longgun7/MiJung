#include "stdafx.h"
#include "playerManager.h"
#include "itemManager.h"
#include "enemyManager.h"

HRESULT playerManager::init()
{
	//아타호 init()
	_ataho = new player;
	_ataho->init();
	_ataho->setEnemyManagerAdressLink(_em);
	
	//스마슈 init()
	_smasyu = new player2;
	_smasyu->init(_ataho->getX() , _ataho->getY());
	_smasyu->setEnemyManagerAdressLink(_em);

	//인벤토리 init()
	_gold.money = 10000;
	_gold.moneyFrame = 0;
	
	_HPpoIndex = 0; //포션 인덱스
	_MPpoIndex = 0;
	//아이템 매니저 전방선언
	//_im = new itemManager;
	//_im->init();
	//_em = new enemyManager;

	
	return S_OK;
}

void playerManager::update()
{
	//플레이어
	_ataho->update();	
	_smasyu->update();
	
	_smasyu->fieldKeyManager(_ataho->getX(), _ataho->getY(), _ataho->getAngle());
	eventMode(); //아타호 떨어질 때 스마슈도 같이 떨어지게 하는 함수
	inventory(); //인벤토리
	setEnemyDead(); //돈 드랍
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
		TextOut(getMemDC(), 250 +i*100, WINSIZEY / 2-150 + 100, str, strlen(str));
	}
		sprintf_s(str, "아타호 돈 : %d", _gold.money);
		TextOut(getMemDC(), 250, WINSIZEY / 2 - 150 + 120, str, strlen(str));
		sprintf_s(str, "아타호 방어력 : %d", _ataho->getAttribute().def);
		TextOut(getMemDC(), 250, WINSIZEY / 2 - 150 + 140, str, strlen(str));
		sprintf_s(str, "아타호 운 : %d", _ataho->getAttribute().luck);
		TextOut(getMemDC(), 250, WINSIZEY / 2 - 150 + 160, str, strlen(str));
		sprintf_s(str, "아타호 스피드 : %d", _ataho->getAttribute().speed);
		TextOut(getMemDC(), 250, WINSIZEY / 2 - 150 + 180, str, strlen(str));
	
		for (int i = 0; i < _em->getVEnmey().size(); i++)
		{
			char str2[1000];
			sprintf_s(str2, "적 체력 : %d", _em->getVEnmey()[i]->getTagEnmey().hp);
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
	//아타호 무기
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
				if (_vA_WeapInven[i].name == "명주 귀신살")
				{
					_ataho->setSwordMounting(true);
				}
				else
				{
					_ataho->setSwordMounting(false);
				}
			}
			
		}

		//아타호 갑옷
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
		
		//스마슈 무기
		for (int i = 0; i < _vS_WeapInven.size(); i++)
		{
			if (PtInRect(&_vS_WeapInven[i].rc, _ptMouse))
			{
				_smasyu->setStat(-_S_saveBeforWeapon.atk, 0, -_S_saveBeforWeapon.luck, -_S_saveBeforWeapon.cri, 0);
				_smasyu->setStat(_vS_WeapInven[i].atk, _vS_WeapInven[i].def, _vS_WeapInven[i].luck, _vS_WeapInven[i].cri, _vS_WeapInven[i].speed);
				_S_saveBeforWeapon.atk = _vS_WeapInven[i].atk;
				_S_saveBeforWeapon.luck = _vS_WeapInven[i].luck;
				_S_saveBeforWeapon.cri = _vS_WeapInven[i].cri;
				if (_vS_WeapInven[i].name == "마인아수라")
				{
					_smasyu->setMounting(true);
				}
				else
				{
					_smasyu->setMounting(false);

				}
			}
		}
		//스마슈 갑옷
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
		//포션
		for (int i = 0; i < _vPoInven.size(); i++)
		{
			if (PtInRect(&_vPoInven[i].rc, _ptMouse))
			{
				//아타호일 때
				_ataho->setPortion(_vPoInven[i].hp, _vPoInven[i].mp);				
				//스마슈일 때
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

//받아서 푸쉬할 아이템 종류
void playerManager::getItemValue(string itemName)
{
	int frameX = INIDATA->loadDataInterger("item", itemName.c_str(), "frameX");
	int frameY = INIDATA->loadDataInterger("item", itemName.c_str(), "frameY");
	
	tagInventory inventory;
	inventory.name = INIDATA->loadDataString("item", itemName.c_str(), "이름");
	inventory.atk = INIDATA->loadDataInterger("item", itemName.c_str(), "공격력");
	inventory.luck = INIDATA->loadDataInterger("item", itemName.c_str(), "운");
	inventory.cri = INIDATA->loadDataInterger("item", itemName.c_str(), "크리티컬 확률");
	inventory.def = INIDATA->loadDataInterger("item", itemName.c_str(), "방어력");
	inventory.speed = INIDATA->loadDataInterger("item", itemName.c_str(), "스피드");
	inventory.hp = INIDATA->loadDataInterger("item", itemName.c_str(), "HP회복");
	inventory.mp = INIDATA->loadDataInterger("item", itemName.c_str(), "MP회복");

	//아타호 무기
	if (frameY == 0)
	{
		if (frameX < 6)
		{
			_vA_WeapInven.push_back(inventory);
		}

		//아타호 방어구
		if (frameX >= 6)
		{
			
			_vA_ArmorInven.push_back(inventory);
		}
	}

	//스마슈 무기
	else if (frameY == 2)
	{
		if (frameX < 6)
		{
			_vS_WeapInven.push_back(inventory);
		}

		//스마슈 방어구
		if (frameX >= 6)
		{
			_vS_ArmorInven.push_back(inventory);
		}
	}

	//포션
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
	//아타호 무기
	for (int i = 0; i < _vA_WeapInven.size(); i++)
	{
		_vA_WeapInven[i].rc = RectMakeCenter(600+ i * 50, 100, 50, 50);
	}
	//아타호 방어구
	for (int i = 0; i < _vA_ArmorInven.size(); i++)
	{
		_vA_ArmorInven[i].rc = RectMakeCenter(600 + i * 50, 150, 50, 50);
	}
	//스마슈 무기
	for (int i = 0; i <_vS_WeapInven.size(); i++)
	{
		_vS_WeapInven[i].rc = RectMakeCenter(600 + i * 50, 250, 50, 50);
	}
	//스마슈 방어구
	for (int i = 0; i <_vS_ArmorInven.size(); i++)
	{
		_vS_ArmorInven[i].rc = RectMakeCenter(600 + i * 50, 300, 50, 50);
	}
	//포션
	for  (int i = 0; i < _vPoInven.size();  i++)
	{
		_vPoInven[i].rc = RectMakeCenter(600 + i*50, 350, 50, 50);
	}
}

void playerManager::setEnemyDead()
{
	
	for (int i = 0; i < _em->getVEnmey().size(); i++)
	{
		
		//에너미 사망
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
