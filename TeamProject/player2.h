#pragma once
#include "gameNode.h"


enum SMOVE
{
	SLEFT, SRIGHT, SFRONT, SBACK,
	SLEFTMOVE, SRIGHTMOVE, SDOWNMOVE, SUPMOVE
};

class player2 :public gameNode
{
private:

	float	_x, _y;		 //��ǥ
	bool	_isMove;	 //������ ����
	image*  _image;		 //�̹���
	int		_imageFrame; //�̹���������
	int		_frame;		 //������
	int		_moveSpeed;	 //���ǵ�
	string	_imageName;  //�̹����̸�
	SMOVE	_move;		 //������ ����
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
	
	player2();
	~player2();
};

