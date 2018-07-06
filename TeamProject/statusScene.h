#pragma once
#include "gameNode.h"


class statusScene : public gameNode
{
private:

	bool _isCheck;		
	bool _isItemCheck;	

	float _uiX, _uiY;
	float _invenX, _invenY;

	int _setIndex;
	int _invenIndex;

	bool _isState;
	
public:
	statusScene();
	~statusScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	bool getIsState() { return _isState; }
	void loadData();
	void fontUI(void);
};

