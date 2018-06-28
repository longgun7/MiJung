#pragma once
#include "gameNode.h"

class statusScene : public gameNode
{
public:
	statusScene();
	~statusScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

