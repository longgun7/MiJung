#pragma once
#include "gameNode.h"


enum MOVE
{
	LEFT, RIGHT ,FRONT , BACK,
	LEFTMOVE, RIGHTMOVE , DOWNMOVE , UPMOVE , 
	SOLOSKILL1, SOLOSKILL2, SOLOSKILL3,
	AREASKILL1, AREASKILL2, AREASKILL3,
	DRINK
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
	image*  _image;		  //�̹���
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
	player();
	~player();
};

