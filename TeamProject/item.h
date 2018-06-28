#pragma once
#include <vector>
#include "gameNode.h"

enum itemKind
{
	WEAPONE1, WEAPONE2, WEAPONE3, WEAPONE4,
	ARMOR1, ARMOR2, ARMOR3, ARMOR4
};

enum postionKind
{
	HPPOTION, MPPOTION
};

struct tagItem
{

	int frameX;
	int frameY;
	float x;
	float y;
	int atk;
	int def;
	int luck;
	float speed;
	int critical;
	RECT rc;
	itemKind itemCheck;
	postionKind checkPotion;

};

struct tagPotion
{
	int hp;
	int mp;
};

class item : public gameNode
{
private:
	vector<tagItem>				_vItem;
	vector<tagItem>::iterator   _viItem;

	vector<tagPotion>			_vPotion;
	vector<tagPotion>::iterator	_viPotion;

	image*	 _image;

	int		 _itemMax;
	itemKind _atahoe;
	itemKind _smashue;
	postionKind _potion;
	
	int		 _atk;
	int		 _def;
	int		 _luck;
	int		 _critical;
	float    _speed;

public:
	item();
	~item();

	HRESULT init(int itemMax);
	void update();
	void render();
	void release();
	void makeItem(int frameX, int frameY,float x ,float y);
	void check();
	void itemStat();

	vector<tagItem>			  getVItem() { return _vItem; }
	vector<tagItem>::iterator getVIItem() { return _viItem; }
};