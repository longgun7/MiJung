#pragma once
#include"gameNode.h"



class startScene: public gameNode
{
private:
	float _uiX, _uiY;
	float _loadX, _loadY;

	int _index, _loadIndex;
	bool _isLoadCheck;
	
	bool _isCount;		//ī��Ʈ ������?
	int _frameCount;	
public:
	startScene();
	~startScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI();//��Ʈ ��ġ
};

