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
	_image = IMAGEMANAGER->addFrameImage("아이템", "아이템.bmp", 0, 0, 600, 250, true, RGB(255, 0, 255));
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
	check();
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

void item::check()
{

	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		if (_viItem->frameY == 0) _viItem->itemCheck = _atahoe;
		if (_viItem->frameY == 1) _viItem->itemCheck = _smashue;
		if (_viItem->frameX == 0) _viItem->itemCheck = WEAPONE1;
		if (_viItem->frameX == 1) _viItem->itemCheck = WEAPONE2;
		if (_viItem->frameX == 2) _viItem->itemCheck = WEAPONE3;
		if (_viItem->frameX == 3) _viItem->itemCheck = WEAPONE4;
		if (_viItem->frameX == 6) _viItem->itemCheck = ARMOR1;
		if (_viItem->frameX == 7) _viItem->itemCheck = ARMOR2;
		if (_viItem->frameX == 8) _viItem->itemCheck = ARMOR3;
		if (_viItem->frameX == 9) _viItem->itemCheck = ARMOR4;
	}

}

void item::itemStat()
{
	switch (_atahoe)
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

	switch (_smashue)
	{
	case WEAPONE1:
		_atk = 7;
		_luck = 8;
		_critical = 10;
		break;
	case WEAPONE2:
		_atk = 9;
		_luck = 10;
		_critical = 12;
		break;
	case WEAPONE3:
		_atk = 11;
		_luck = 12;
		_critical = 14;
		break;
	case WEAPONE4:
		_atk = 13;
		_luck = 14;
		_critical = 16;
		break;
	case ARMOR1:
		_def = 7;
		_speed = 8;
		break;
	case ARMOR2:
		_def = 9;
		_speed = 10;
		break;
	case ARMOR3:
		_def = 11;
		_speed = 12;
		break;
	case ARMOR4:
		_def = 13;
		_speed = 14;
		break;
	}
}
