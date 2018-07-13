#pragma once
#include"gameNode.h"

enum PLAYER_TURN
{
	ATAHO_TURN,
	SUMSU_TURN
};
enum GAME_TURN
{
	ATAHO_CHOICE,
	SUMSU_CHOICE,
	ATAHO_ATTACK,
	SUMSU_ATTACK,
	ENEMY_ATTACK,

};

class playerManager;
class enemyManager;
class itemManager;
class battleScene : public gameNode
{
private: 
	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;

	GAME_TURN _gameTurn;

	int _choiceIndex;			//��ų Ÿ�� �ε���
	int _skillIndex;			//��ų �ε���
	int _monIndex;				//���� ���� �ε���

	//��~�� ��� X
	int _sChoiceIndex;
	int _sSkillIndex;
	int _sMonIndex;

	float _choiceX, _choiceY;	//��� ���� ��ư ��ǥ
	float _skillX, _skillY;		//��ų ���� ��ư	��ǥ
	float _monX, _monY;			//���� ���� ��ư ��ǥ

	//-------------------enum ���� �� �κ�--------------
	bool _isTurn;				//��ų�� �����ΰ�
	bool _isSkillCheck;			//��ų �����ߴ�?
	bool _isMonCheck;			//���� üũ�ߴ�?(�⺻,���ΰ��� ��)
	bool _isFight;				//��ų�� �� �����ϰ� ��Ʋ�ϴ�?
	//--------------------------------------------------

	bool _isAtahoSkillFire;		//��ų�� �߻� �Ǿ��°�?
	bool _isSumsuSkillFire;		//��ų�� �߻� �Ǿ��°�?
	
	PLAYER_TURN _playerTurn;	//��Ÿȣ ������ ��ų ��

	int totalExp;
	int totalMoney;

	bool _isSceneCount;
	int sceneCount;

public:
	battleScene();
	~battleScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void addImage(void);	
	void fontUI(void);
	void iconChange(void);			//������ ����
	void skillChoice(void);			//��ų����
	void atahoSkillCheck();
	void sumsuSkillCheck();

	void setEnemyDead(int index);
};

