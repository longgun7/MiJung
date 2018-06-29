#pragma once
#include "gameNode.h"


enum SMOVE
{
	S_LEFT, S_RIGHT, S_FRONT, S_BACK,
	S_LEFTMOVE, S_RIGHTMOVE, S_DOWNMOVE, S_UPMOVE,
	S_SOLOSKILL1, S_SOLOSKILL2, S_SOLOSKILL3,
	S_AREASKILL1, S_AREASKILL2, S_AREASKILL3,
};

class player2 :public gameNode
{
private:

	float	_x, _y;		  //��ǥ
	bool	_isMove;	  //������ ����
	bool	_isMotionLive;//��ų,�����¿� ������ ����
	image*  _image;		  //�̹���
	int		_imageFrame;  //�̹���������
	int		_frame;		  //������
	int     _skillFrame;  //��ų ������
	int		_moveSpeed;	  //���ǵ�
	string	_imageName;   //�̹����̸�
	SMOVE	_move;		  //������ ����
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
	
	player2();
	~player2();
};
