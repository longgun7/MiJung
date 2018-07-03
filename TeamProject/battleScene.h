#pragma once
#include"gameNode.h"
class battleScene : public gameNode
{
private: 
	bool _isTurn; //스킬쓸 차례인가

public:
	battleScene();
	~battleScene();

	

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

