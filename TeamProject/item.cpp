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
		_image->frameRender(getMemDC(), _viItem->rc.left, _viItem->rc.top, _viItem->frameX, _viItem->frameY);
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
	else if (item.frameX == 1) item.itemCheck = WEAPONE2;
	else if (item.frameX == 2) item.itemCheck = WEAPONE3;
	else if (item.frameX == 3) item.itemCheck = WEAPONE4;
	else if (item.frameX == 6) item.itemCheck = ARMOR1;
	else if (item.frameX == 7) item.itemCheck = ARMOR2;
	else if (item.frameX == 8) item.itemCheck = ARMOR3;
	else if (item.frameX == 9) item.itemCheck = ARMOR4;

	if (item.frameY == 0)		atahoestat(item.itemCheck);
	else if (item.frameY == 2)	smashustat(item.itemCheck);


	item.atk = _atk;
	item.def = _def;
	item.critical = _critical;
	item.luck = _luck;
	item.speed = _speed;
	item.x = x;
	item.y = y;
	item.rc = RectMakeCenter(item.x, item.y, _image->getFrameWidth(), _image->getFrameHeight());

	_vItem.push_back(item);
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

