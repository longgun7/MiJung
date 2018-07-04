#pragma once
#include"gameNode.h"



class startScene: public gameNode
{
private:
	float _uiX, _uiY;
	float _loadX, _loadY;

	int _index, _loadIndex;
	bool _isLoadCheck;
	
	
public:
	startScene();
	~startScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI();//폰트 배치
};

