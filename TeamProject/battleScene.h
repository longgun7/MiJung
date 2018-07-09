#pragma once
#include"gameNode.h"

class playerManager;
class enemyManager;
class itemManager;
class battleScene : public gameNode
{
private: 
	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;

	int _choiceIndex;			//스킬 타입 인덱스
	int _skillIndex;			//스킬 인덱스
	int _monIndex;

	float _choiceX, _choiceY;	//모드 선택 버튼 좌표
	float _skillX, _skillY;		//스킬 선택 버튼	좌표
	float _monX, _monY;			//몬스터 선택 버튼 좌표

	bool _isTurn;				//스킬쓸 차례인가
	bool _isSkillCheck;			//스킬 선택했늬?
	bool _isMonCheck;			//몬스터 체크했늬?(기본,개인공격 시)
	

public:
	battleScene();
	~battleScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void fontUI(void);
};

