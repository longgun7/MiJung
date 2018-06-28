#pragma once
#include"gameNode.h"
#include"statusScene.h"
#include"townScene.h"
#include"fieldScene.h"
#include"battleScene.h"

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

