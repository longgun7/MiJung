#pragma once
#include"gameNode.h"
class playScene : public gameNode
{
public:
	playScene();
	~playScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

