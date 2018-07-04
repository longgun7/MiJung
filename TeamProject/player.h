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
	DRINK,DRUNKEN, FIGHTREADY, DAMAGE,
	//EVENTMODE
	FRONT,LEFT1,LEFT2,LEFT3,LEFT4,RIGHT1,RIGHT2,RIGHT3,RIGHT4,
	WOODFRONT, WOODLEFT1, WOODLEFT2, WOODLEFT3, WOODLEFT4, WOODRIGHT1, WOODRIGHT2, WOODRIGHT3, WOODRIGHT4
};

enum SCENEMODE
{
	FIELDMODE, BATTLEMODE , EVENTMODE
};

struct tagAttribute
{
	int		atk;	//���ݷ�
	int     def;   //���� 
	int     luck;  //��
	int		cri;   //ũ��Ƽ��
	int     speed; //���ǵ�
	int     currentHp;    //hp
	int     maxHp;        //�� hp
	int     currentMp;    //mp
	int		maxMp;		   //�� mp
	int     currentExp;   //exp
	int		maxExp;       //�� exp
	int     level;        //level
	bool    isLevelUp;		 //������ ����
};
class enemyManager;
class player :public gameNode

{
private:

	
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
	
	
	image*  _img;		     //�̹���
	string	_imageName;      //�̹����̸�
	MOVE	_move;		     //������ ����
	RECT	_rc;		     //��Ʈ
	SCENEMODE _sceneMode;	 //���� ���� ������
	tagAttribute _attribute; //�Ӽ�

	atahoTargetSkill1* _soloSkillEffect1;
	atahoTargetSkill2* _soloSkillEffect2;
	atahoTargetSkill3* _soloSkillEffect3;
	atahoAreaSkill2* _areaSkillEffect2;
	atahoAreaSkill3* _areaSkillEffect3;
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
	void levelCheck();

	
	float getX() { return _x; }
	void setX(float x) { _x = x; }
	
	float getY() { return _y; }
	void setY(float y) { _y = y; }
	
	MOVE getMove() { return _move; } //�������� ������
	void setMove(MOVE move) { _move = move; }

	tagAttribute getAttribute() { return _attribute; } //�Ӽ�������
	void setAttribute(tagAttribute attribute) { _attribute = attribute; }

	SCENEMODE getSCENEMODE() { return _sceneMode; } //�� ������

	bool getIsJumping() { return _isJumping; } //���ο���
	int getSlopeNum() { return _slopeNum; }

	void EnemyManagerAdressLink(enemyManager* em) { _em = em; } //���漱��
	
	void setScene(SCENEMODE _scene,float x , float y , MOVE move) //����ȯ����
	{
		_sceneMode = _scene;
		_x = x;
		_y = y;
		_move = move;
	}
	
	int getFrameX() { return _imageFrame; } //�̹��������� ������

	
	player();
	~player();
};

