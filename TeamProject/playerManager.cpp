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
	getItemValue("술");
	getItemValue("권법가 도복");
	getItemValue("청룡도");
	getItemValue("가죽 갑옷");
	
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
	//플레이어
	_ataho->update();	
	_smasyu->update();
	
	_smasyu->fieldKeyManager(_ataho->getX(), _ataho->getY(), _ataho->getAngle());
	eventMode(); //아타호 떨어질 때 스마슈도 같이 떨어지게 하는 함수
	inventory(); //인벤토리
	setEnemyDead(); //돈 드랍
	
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
//장착하기
void playerManager::mounting(int frameX, int setIndex, int invenTypeIndex, int invenIndex)
{                   //아타호인지 스마슈인지 , 포션과아이템번호 , 아이템 무기방어구번호, 무기방어구 각각의 번호 
	//아타호 무기
	if (frameX == 0 && setIndex == 2)
	{
		if (invenTypeIndex == 0)
		{
			_ataho->setStat(-_A_saveBeforWeapon.atk, 0, -_A_saveBeforWeapon.luck, -_A_saveBeforWeapon.cri, 0);
			_ataho->setStat(_vA_WeapInven[invenIndex].atk, _vA_WeapInven[invenIndex].def, _vA_WeapInven[invenIndex].luck, _vA_WeapInven[invenIndex].cri, _vA_WeapInven[invenIndex].speed);
			_A_saveBeforWeapon.atk = _vA_WeapInven[invenIndex].atk;
			_A_saveBeforWeapon.luck = _vA_WeapInven[invenIndex].luck;
			_A_saveBeforWeapon.cri = _vA_WeapInven[invenIndex].cri;
			if (_vA_WeapInven[invenIndex].name == "명주 귀신살")
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
			//아타호 갑옷
			_ataho->setStat(-_A_saveBeforArmor.atk, -_A_saveBeforArmor.def, -_A_saveBeforArmor.luck, -_A_saveBeforArmor.cri, -_A_saveBeforArmor.speed);
			_ataho->setStat(_vA_ArmorInven[invenIndex].atk, _vA_ArmorInven[invenIndex].def, _vA_ArmorInven[invenIndex].luck, _vA_ArmorInven[invenIndex].cri, _vA_ArmorInven[invenIndex].speed);
			_A_saveBeforArmor.def = _vA_ArmorInven[invenIndex].def;
			_A_saveBeforArmor.speed = _vA_ArmorInven[invenIndex].speed;
		}
	}



	if (frameX == 1 && setIndex == 2)
	{
		//스마슈 무기
		if (invenTypeIndex == 0)
		{

			_smasyu->setStat(-_S_saveBeforWeapon.atk, 0, -_S_saveBeforWeapon.luck, -_S_saveBeforWeapon.cri, 0);
			_smasyu->setStat(_vS_WeapInven[invenIndex].atk, _vS_WeapInven[invenIndex].def, _vS_WeapInven[invenIndex].luck, _vS_WeapInven[invenIndex].cri, _vS_WeapInven[invenIndex].speed);
			_S_saveBeforWeapon.atk = _vS_WeapInven[invenIndex].atk;
			_S_saveBeforWeapon.luck = _vS_WeapInven[invenIndex].luck;
			_S_saveBeforWeapon.cri = _vS_WeapInven[invenIndex].cri;
			if (_vS_WeapInven[invenIndex].name == "마인아수라")
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
			//스마슈 갑옷

			_smasyu->setStat(-_S_saveBeforArmor.atk, -_S_saveBeforArmor.def, -_S_saveBeforArmor.luck, -_S_saveBeforArmor.cri, -_S_saveBeforArmor.speed);
			_smasyu->setStat(_vS_ArmorInven[invenIndex].atk, _vS_ArmorInven[invenIndex].def, _vS_ArmorInven[invenIndex].luck, _vS_ArmorInven[invenIndex].cri, _vS_ArmorInven[invenIndex].speed);
			_S_saveBeforArmor.def = _vS_ArmorInven[invenIndex].def;
			_S_saveBeforArmor.speed = _vS_ArmorInven[invenIndex].speed;
		}
	}


	if (setIndex == 1)
	{
		//아타호일 때
		_ataho->setPortion(_vPoInven[invenIndex].hp, _vPoInven[invenIndex].mp);
		//스마슈일 때
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

	//statusScene에 들어갈 소모품 이미지
	if (inventory.name == "약초")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("약초",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(0);
		inventory.img->setFrameY(3);
	}
	if (inventory.name == "마법의 물약") 
	{
		inventory.img = IMAGEMANAGER->addFrameImage("마법물약",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(3);
		inventory.img->setFrameY(3);
	}
	//statusScene에 들어갈 장비 이미지
	if (inventory.name == "술")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("술",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(1);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "화주")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("화주",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(4);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "특급주")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("특급주",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(2);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "명주 귀신살")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("명주 귀신살",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(5);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "권법가 도복")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("권법가 도복",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(7);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "호랑이 도복")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("호랑이 도복",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(9);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "나찰의 도복")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("나찰의 도복",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(10);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "백호 도복")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("백호 도복",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(11);
		inventory.img->setFrameY(0);
	}
	if (inventory.name == "청룡도")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("청룡도",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(1);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "불타는 마검")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("불타는 마검",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(2);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "나찰의 흉인")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("나찰의 흉인",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(4);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "마인아수라")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("마인아수라",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(5);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "가죽 갑옷")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("가죽 갑옷",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(7);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "철편 갑옷")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("철편 갑옷",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(9);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "어설트 슈트")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("어설트 슈트",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(10);
		inventory.img->setFrameY(2);
	}
	if (inventory.name == "투신의 갑옷")
	{
		inventory.img = IMAGEMANAGER->addFrameImage("투신의 갑옷",
			"image/ui/아이템.bmp", 600, 250, 12, 5, false, RGB(0, 0, 0));
		inventory.img->setFrameX(11);
		inventory.img->setFrameY(2);
	}

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
