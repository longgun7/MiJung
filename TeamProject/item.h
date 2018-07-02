#pragma once
#include <vector>
#include "gameNode.h"

enum itemKind
{
	WEAPONE1, WEAPONE2, WEAPONE3, WEAPONE4,
	ARMOR1, ARMOR2, ARMOR3, ARMOR4
};

enum potionKind
{
	HPPOTION1, MPPOTION1
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
	string naem;
	RECT rc;
	itemKind itemCheck;

};

struct tagPotion
{

	int frameX;
	int frameY;
	float x;
	float y;
	int hp;
	int mp;
	string name;
	RECT rc;
	potionKind potionCheck;

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
	potionKind _potion;
	
	int		 _atk;
	int		 _def;
	int		 _luck;
	int		 _critical;
	float    _speed;
	int		 _hp;
	int		 _mp;

public:
	item();
	~item();

	HRESULT init(int itemMax);
	void update();
	void render();
	void release();
	void makeItem(int frameX, int frameY,float x ,float y);
	void makeItem(const char* itemName, float x ,float y);
	void makepotion(int frameX, int frameY, float x, float y);
	void makepotion(const char* potionName, float x, float y);
	void atahoestat(itemKind itemkind);
	void smashustat(itemKind itemkind);
	void potionAbility(potionKind potionkind);

	vector<tagItem>				getVItem() { return _vItem; }
	vector<tagItem>::iterator	getVIItem() { return _viItem; }
	
	vector<tagPotion>			getVPotion() { return _vPotion; }
	vector<tagPotion>::iterator	getVIPotion() { return _viPotion; }

};