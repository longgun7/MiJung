#pragma once
#include"gameNode.h"
class barScnen : public gameNode
{
public:
	barScnen();
	~barScnen();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

