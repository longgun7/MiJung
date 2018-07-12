#pragma once

class playerManager;
class enemyManager;
class itemManager;

class shop
{
private:

	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;

	int  _buyNum;
	int  _totalNum;
	bool _purchase;
	int  _index;
	image*  _uiImg;
public:
	shop();
	~shop();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI();
	void shopRemove();
	void setItem();
	void buyItem();


	int getBuyNum() { return _buyNum; }

};

