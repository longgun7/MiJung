#pragma once
#include "gameNode.h"


enum MOVE
{
	//FIELDMODE
	LEFT, RIGHT, DOWN, UP,
	LEFTMOVE, RIGHTMOVE, DOWNMOVE, UPMOVE,
	//BATTLEMODE
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

class player :public gameNode

{
private:

	float	_x, _y;		     //��ǥ
	float   _gravity;	     //�߷�
	float   _jumpPower;      //�����Ŀ�
	bool    _isJumping;      //��������
	bool    _isMotionLive;   //��ų, �����¿� ������ ����
	bool	_isWoodDrop;     //�̺�Ʈ ����� �� ������ ����ִ��� �ƴ���
	image*  _img;		     //�̹���
	int		_imageFrame;     //�̹���������
	int		_frame;		     //������
	int     _skillFrame;     //��ų������
	int		_moveSpeed;	     //���ǵ�
	int     _slopeFrame;     //���� ������
	int     _slopeNum;		 //���� ��ȣ
	int     _rndDirection;   //�������� ����
	string	_imageName;      //�̹����̸�
	MOVE	_move;		     //������ ����
	RECT	_rc;		     //��Ʈ
	SCENEMODE _sceneMode;	 //���� ���� ������
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
	float getX() { return _x; }
	float getY() { return _y; }
	SCENEMODE getSCENEMODE() { return _sceneMode; }
	bool getIsJumping() { return _isJumping; }
	player();
	~player();
};

