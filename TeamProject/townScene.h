#pragma once
#include"gameNode.h"
#include"barScnen.h"
class townScene : public gameNode
{
public:
	townScene();
	~townScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);
};

