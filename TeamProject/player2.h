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

	float	_angle;        //바라보는 앵글    
	float	_x, _y;		  //좌표
	bool	_isMove;	  //움직임 여부
	bool	_isMotionLive;//스킬,상하좌우 움직임 여부
	image*  _img;		  //이미지
	int		_imageFrame;  //이미지프레임
	int		_frame;		  //프레임
	int     _skillFrame;  //스킬 프레임
	int		_moveSpeed;	  //스피드
	string	_imageName;   //이미지이름
	SMOVE	_move;		  //움직임 상태
	RECT	_rc;		  //렉트

public:
	
	HRESULT init(float x , float y);
	void update();
	void render();
	void release();
	void image();
	void imageFrame();
	void angleManager(float x , float y);
	void move();
	
	//void setX
	player2();
	~player2();
};

