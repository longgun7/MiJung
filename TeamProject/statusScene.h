#pragma once
#include "gameNode.h"

struct tagPlayerData
{
	int level;
	int currentHp;
	int maxHp;
	int currentMp;
	int maxMp;
	int currentExp;
	int maxExp;
	int atk;
	int def;
	int speed;
	int luck;
};
class playerManager;
class enemyManager;
class itemManager;
class statusScene : public gameNode
{
private:
	tagPlayerData _player1Data;
	tagPlayerData _player2Data;
	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;

	bool _isCheck;		
	bool _isItemCheck;	

	float _uiX, _uiY;
	float _invenX, _invenY;

	int _setIndex;
	int _invenIndex;
	int _invenTypeIndex;
	

	
	
public:
	statusScene();
	~statusScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
	void keyManager(void);
	void addImage(void);
	
	void iconChange(void);
	void itemChoice(void);
	void fontUI(void);
	
};

