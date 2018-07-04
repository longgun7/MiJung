#pragma once
#include "gameNode.h"
#include "playSceneManager.h"

//환세이취호전 시작
class playGround : public gameNode
{
private:
	playSceneManager * _psm;
	
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	

	playGround();
	~playGround();
};

