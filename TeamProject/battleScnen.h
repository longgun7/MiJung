#pragma once
#include"gameNode.h"
class battleScnen : public gameNode
{
public:
	battleScnen();
	~battleScnen();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);
};

