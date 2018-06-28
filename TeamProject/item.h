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
	HPRECOVERY, MPRECOVERY
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

	int _itemMax;


public:
	item();
	~item();

	HRESULT init();
	void update();
	void render();
	void release();
	void makeItem(int itemMax, int frameX, int frameY, int atk, int def, int luck, float speed);
	void check();
};