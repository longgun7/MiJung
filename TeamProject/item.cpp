#include "stdafx.h"
#include "item.h"


item::item()
{
}


item::~item()
{
}

HRESULT item::init(int itemMax)
{
	IMAGEMANAGER->addFrameImage("아이템", "image/item/아이템.bmp", 600, 250, 12, 5, true, RGB(255, 0, 255));

	_image = IMAGEMANAGER->findImage("아이템");
	_itemMax = itemMax;

	return S_OK;
}

void item::update()
{
}

void item::render()
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		//Rectangle(getMemDC(),_viItem->rc.left , _viItem->rc.top , _viItem->rc.right , _viItem->rc.bottom );
		_image->frameRender(CAMERA->getCameraDC(), _viItem->rc.left, _viItem->rc.top, _viItem->frameX, _viItem->frameY);
	}

	for (_viPotion = _vPotion.begin(); _viPotion != _vPotion.end(); ++_viPotion)
	{
		//Rectangle(getMemDC(), _viPotion->rc.left, _viPotion->rc.top, _viPotion->rc.right, _viPotion->rc.bottom);
		_image->frameRender(CAMERA->getCameraDC(), _viPotion->rc.left, _viPotion->rc.top, _viPotion->frameX, _viPotion->frameY);
	}
}

void item::release()
{
}

void item::makeItem(int frameX, int frameY, float x, float y)
{
	if (_vItem.size() > _itemMax) return;

	tagItem item;
	ZeroMemory(&item, sizeof(item));

	item.frameX = frameX;
	item.frameY = frameY;

	if (item.frameX == 0) item.itemCheck = WEAPONE1;
	else if (item.frameX == 1) item.itemCheck = WEAPONE2;             //아이템 이미지 번호여부에 따라서 아이템 유형이 바뀌고 아이템 유형에 따라 아타호의 스텟이 정해진다.
	else if (item.frameX == 2) item.itemCheck = WEAPONE3;
	else if (item.frameX == 3) item.itemCheck = WEAPONE4;
	else if (item.frameX == 6) item.itemCheck = ARMOR1;
	else if (item.frameX == 7) item.itemCheck = ARMOR2;
	else if (item.frameX == 8) item.itemCheck = ARMOR3;
	else if (item.frameX == 9) item.itemCheck = ARMOR4;

	if		(item.frameY == 0)	atahoestat(item.itemCheck);
	else if (item.frameY == 2)	smashustat(item.itemCheck);


	item.atk = _atk;
	item.def = _def;
	item.critical = _critical;
	item.luck = _luck;
	item.speed = _speed;
	item.x = x;
	item.y = y;
	item.rc = RectMakeCenter(item.x, item.y, _image->getFrameWidth(), _image->getFrameHeight());

	
}

void item::makeItem(string itemName,float x ,float y)
{
	if (_vItem.size() > _itemMax) return;

	tagItem item;
	ZeroMemory(&item, sizeof(item));

	item.atk =		INIDATA->loadDataInterger("item", itemName.c_str(), "공격력");
	item.luck =		INIDATA->loadDataInterger("item", itemName.c_str(), "운");
	item.critical = INIDATA->loadDataInterger("item", itemName.c_str(), "크리티컬확률");
	item.def =		INIDATA->loadDataInterger("item", itemName.c_str(), "방어력");
	item.speed =	INIDATA->loadDataInterger("item", itemName.c_str(), "스피드");
	item.frameX =	INIDATA->loadDataInterger("item", itemName.c_str(), "frameX");
	item.frameY =	INIDATA->loadDataInterger("item", itemName.c_str(), "frameY");
	item.name =		INIDATA->loadDataString("item", itemName.c_str(), "이름");
	item.cost =		INIDATA->loadDataInterger("item", itemName.c_str(), "비용");
	item.num		= 0;

	item.x = x;
	item.y = y;
	item.rc = RectMakeCenter(item.x, item.y, _image->getFrameWidth(), _image->getFrameHeight());

	_vItem.push_back(item);
}

void item::makepotion(int frameX, int frameY, float x, float y)
{
	if (_vPotion.size() > _itemMax) return;

	tagPotion potion;
	ZeroMemory(&potion, sizeof(potion));
	
	potion.frameX = frameX;
	potion.frameY = frameY;

	if (potion.frameX == 0) potion.potionCheck = HPPOTION1;
	if (potion.frameX == 2) potion.potionCheck = MPPOTION1;

	potionAbility(potion.potionCheck);

	potion.hp = _hp;
	potion.mp = _mp;
	potion.x = x;
	potion.y = y;
	potion.rc = RectMakeCenter(potion.x, potion.y, _image->getFrameWidth(), _image->getFrameHeight());

	_vPotion.push_back(potion);

}

void item::makepotion(string potionName, float x, float y)
{

	if (_vPotion.size() > _itemMax) return;

	tagPotion potion;
	ZeroMemory(&potion, sizeof(potion));

	potion.frameX = INIDATA->loadDataInterger("item", potionName.c_str(), "frameX");
	potion.frameY = INIDATA->loadDataInterger("item", potionName.c_str(), "frameY");
	potion.hp =		INIDATA->loadDataInterger("item", potionName.c_str(), "HP회복");
	potion.mp =		INIDATA->loadDataInterger("item", potionName.c_str(), "MP회복");
	potion.name =	INIDATA->loadDataString("item", potionName.c_str(), "이름");
	potion.cost =	INIDATA->loadDataInterger("item", potionName.c_str(), "비용");
	potion.num =	0;

	potion.x = x;
	potion.y = y;
	potion.rc = RectMakeCenter(potion.x, potion.y, _image->getFrameWidth(), _image->getFrameHeight());

	_vPotion.push_back(potion);

}

void item::atahoestat(itemKind itemkind)
{
	switch (itemkind)
	{
	case WEAPONE1:
		_atk = 5;
		_luck = 5;
		_critical = 3;

		break;
	case WEAPONE2:
		_atk = 8;
		_luck = 8;
		_critical = 5;

		break;
	case WEAPONE3:
		_atk = 10;
		_luck = 10;
		_critical = 7;

		break;
	case WEAPONE4:
		_atk = 15;
		_luck = 15;
		_critical = 10;

		break;
	case ARMOR1:
		_def = 4;
		_speed = 4;
		break;
	case ARMOR2:
		_def = 6;
		_speed = 6;
		break;
	case ARMOR3:
		_def = 8;
		_speed = 8;
		break;
	case ARMOR4:
		_def = 10;
		_speed = 10;
		break;

	}
}

void item::smashustat(itemKind itemkind)
{

	switch (itemkind)
	{
	case WEAPONE1:
		_atk = 7;
		_luck = 7;
		_critical = 5;

		break;
	case WEAPONE2:
		_atk = 9;
		_luck = 10;
		_critical = 9;

		break;
	case WEAPONE3:
		_atk = 12;
		_luck = 12;
		_critical = 12;

		break;
	case WEAPONE4:
		_atk = 16;
		_luck = 14;
		_critical = 15;

		break;
	case ARMOR1:
		_def = 4;
		_speed = 4;
		break;
	case ARMOR2:
		_def = 6;
		_speed = 6;
		break;
	case ARMOR3:
		_def = 8;
		_speed = 8;
		break;
	case ARMOR4:
		_def = 10;
		_speed = 10;
	}
}

void item::potionAbility(potionKind potionkind)
{
	switch (potionkind)
	{
	case HPPOTION1:
		_hp = 10;
		break;
	case MPPOTION1:
		_mp = 5;
		break;
	}
}

void item::removeItem(int arrNum)
{
	_vItem.erase(_vItem.begin() + arrNum);
}

void item::removePotion(int arrNum)
{
	_vPotion.erase(_vPotion.begin() + arrNum);
}



