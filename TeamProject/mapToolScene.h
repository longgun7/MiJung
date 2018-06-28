#pragma once
#include"gameNode.h"

class mapToolScene : public gameNode
{
public:
	mapToolScene();
	~mapToolScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

