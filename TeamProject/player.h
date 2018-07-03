#pragma once
#include "gameNode.h"
#include "Skill.h"


enum MOVE
{
	//FIELDMODE
	LEFT, RIGHT, DOWN, UP,
	LEFTMOVE, RIGHTMOVE, DOWNMOVE, UPMOVE,
	//BATTLEMODE
	BASICSKILL1, BASICSKILL2, BASICSKILL3,
	SOLOSKILL1, SOLOSKILL2, SOLOSKILL3,
	AREASKILL1, AREASKILL2, AREASKILL3,
	DRINK,DRUNKEN, FIGHTREADY,
	//EVENTMODE
	FRONT,LEFT1,LEFT2,LEFT3,LEFT4,RIGHT1,RIGHT2,RIGHT3,RIGHT4,
	WOODFRONT, WOODLEFT1, WOODLEFT2, WOODLEFT3, WOODLEFT4, WOODRIGHT1, WOODRIGHT2, WOODRIGHT3, WOODRIGHT4
};

enum SCENEMODE
{
	FIELDMODE, BATTLEMODE , EVENTMODE
};

class enemyManager;
class player :public gameNode

{
private:

	int		_atk;	//���ݷ�
	int     _def;   //���� 
	int     _luck;  //��
	int		_cri;   //ũ��Ƽ��
	int     _speed; //���ǵ�
	int     _currentHp;    //hp
	int     _maxHp;        //�� hp
	int     _currentMp;    //mp
	int		_maxMp;		   //�� mp
	int     _currentExp;   //exp
	int		_maxExp;       //�� exp
	int     _level;        //level
    int		_imageFrame;     //�̹���������
	int		_frame;		     //������
	int     _skillFrame;     //��ų������
	int		_moveSpeed;	     //���ǵ�
	int     _slopeFrame;     //���� ������
	int     _slopeNum;		 //���� ��ȣ
	int     _rndDirection;   //�������� ����

	float	_x, _y;		     //��ǥ
	float   _gravity;	     //�߷�
	float   _jumpPower;      //�����Ŀ�

	bool    _isJumping;      //��������
	bool    _isMotionLive;   //��ų, �����¿� ������ ����
	bool	_isWoodDrop;     //�̺�Ʈ ����� �� ������ ����ִ��� �ƴ���
	bool    _isLevelUp;		 //������ ����
	
	image*  _img;		     //�̹���
	string	_imageName;      //�̹����̸�
	MOVE	_move;		     //������ ����
	RECT	_rc;		     //��Ʈ
	SCENEMODE _sceneMode;	 //���� ���� ������

	atahoTargetSkill1* _soloSkillEffect1;
	atahoTargetSkill2* _soloSkillEffect2;
	atahoTargetSkill3* _soloSkillEffect3;

	//���ʹ� �Ŵ��� ���漱��
	enemyManager* _em;
public:
	
	HRESULT init();
	void update();
	void render();
	void release();
	void playerImage();
	void imageFrame();
	void fieldKeyManager();
	void battleKeyManager();
	void eventKeyManager();
	void slopeNumImage();    //���� �ѹ��� ���� �̹��� ��ȭ
	void move();
	void ropeWalk();
	void levelCheck();

	

	float getX() { return _x; }
	float getY() { return _y; }
	SCENEMODE getSCENEMODE() { return _sceneMode; }
	bool getIsJumping() { return _isJumping; }
	int getSlopeNum() { return _slopeNum; }
	void EnemyManagerAdressLink(enemyManager* em) { _em = em; }
	int getFrameX() { return _imageFrame; }
	
	player();
	~player();
};

