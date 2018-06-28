#pragma once
#include "gameNode.h"


enum MOVE
{
	LEFT, RIGHT ,FRONT , BACK,
	LEFTMOVE, RIGHTMOVE , DOWNMOVE , UPMOVE
};


class player :public gameNode

{
private:

	float	_x, _y;		 //��ǥ
	bool	_isMove;	 //������ ����
	image*  _image;		 //�̹���
	int		_imageFrame; //�̹���������
	int		_frame;		 //������
	int		_moveSpeed;	 //���ǵ�
	string	_imageName;  //�̹����̸�
	MOVE	_move;		 //������ ����
	RECT	_rc;		 //��Ʈ

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

