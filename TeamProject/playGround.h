#pragma once
#include "gameNode.h"
//환세이취호전 시작
class playGround : public gameNode
{
private:
	

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	playGround();
	~playGround();
};

