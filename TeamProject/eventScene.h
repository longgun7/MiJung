#pragma once
#include "gameNode.h"
class eventScene : public gameNode
{
private:

public:
	eventScene();
	~eventScene();
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

