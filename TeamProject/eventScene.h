#pragma once
#include "gameNode.h"
#include"eventMode.h"

class eventScene : public gameNode
{
private:
	eventMode * _event;

public:
	eventScene();
	~eventScene();
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

