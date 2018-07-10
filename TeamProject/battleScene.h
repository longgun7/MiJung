#pragma once
#include"gameNode.h"

enum PLAYER_TURN
{
	ATAHO_TURN,
	SUMSU_TURN
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

	int _choiceIndex;			//��ų Ÿ�� �ε���
	int _skillIndex;			//��ų �ε���
	int _monIndex;				//���� ���� �ε���

	float _choiceX, _choiceY;	//��� ���� ��ư ��ǥ
	float _skillX, _skillY;		//��ų ���� ��ư	��ǥ
	float _monX, _monY;			//���� ���� ��ư ��ǥ

	bool _isTurn;				//��ų�� �����ΰ�
	bool _isSkillCheck;			//��ų �����ߴ�?
	bool _isMonCheck;			//���� üũ�ߴ�?(�⺻,���ΰ��� ��)
	
	PLAYER_TURN _playerTurn;	//��Ÿȣ ������ ��ų ��

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
};

