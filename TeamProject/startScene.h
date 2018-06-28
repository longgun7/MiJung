#pragma once
#include"gameNode.h"
#include"mapToolScene.h"
class startScene: public gameNode
{

public:
	startScene();
	~startScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

