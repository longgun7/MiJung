#pragma once
#include "gameNode.h"


enum MOVE
{
	LEFT, RIGHT, DOWN, UP,
	LEFTMOVE, RIGHTMOVE, DOWNMOVE, UPMOVE,
	SOLOSKILL1, SOLOSKILL2, SOLOSKILL3,
	AREASKILL1, AREASKILL2, AREASKILL3,
	DRINK,DRUNKEN, FIGHTMODE
};

enum ROPEWALKING
{
	FRONT,LEFT1,LEFT2,LEFT3,RIGHT4,RIGHT1,RIGHT2,RIGHT3,RIGHT4
};

class player :public gameNode

{
private:

	float	_x, _y;		  //��ǥ
	float   _gravity;	  //�߷�
	float   _jumpPower;   //�����Ŀ�
	bool    _isJumping;   //��������
	bool	_isMove;	  //������ ����
	bool    _isMotionLive;//��ų, �����¿� ������ ����
	image*  _img;		  //�̹���
	int		_imageFrame;  //�̹���������
	int		_frame;		  //������
	int     _skillFrame;  //��ų������
	int		_moveSpeed;	  //���ǵ�
	
	string	_imageName;   //�̹����̸�
	MOVE	_move;		  //������ ����
	RECT	_rc;		  //��Ʈ

public:

	HRESULT init();
	void update();
	void render();
	void release();
	void image();
	void imageFrame();
	void keyManager();
	void move();
	void ropeWalk();
	float getX() { return _x; }
	float getY() { return _y; }
	player();
	~player();
};

