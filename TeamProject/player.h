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

	float	_x, _y;		  //좌표
	float   _gravity;	  //중력
	float   _jumpPower;   //점프파워
	bool    _isJumping;   //점프여부
	bool	_isMove;	  //움직임 여부
	bool    _isMotionLive;//스킬, 상하좌우 움직임 여부
	image*  _img;		  //이미지
	int		_imageFrame;  //이미지프레임
	int		_frame;		  //프레임
	int     _skillFrame;  //스킬프레임
	int		_moveSpeed;	  //스피드
	
	string	_imageName;   //이미지이름
	MOVE	_move;		  //움직임 상태
	RECT	_rc;		  //렉트

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

