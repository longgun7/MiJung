#pragma once
#include"gameNode.h"
class endScene : public gameNode
{
public:
	endScene();
	~endScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

