#pragma once
#include"gameNode.h"
class fieldScene : public gameNode
{
public:
	fieldScene();
	~fieldScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

