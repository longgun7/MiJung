#pragma once
#include"gameNode.h"
#include"mapToolScene.h"
#include"playScene.h"
class startScene: public gameNode
{
private:
	

public:
	startScene();
	~startScene();



	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

