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

	float	_x, _y;		 //좌표
	bool	_isMove;	 //움직임 여부
	bool	_isSkillMove;//스킬움직임 여부
	image*  _image;		 //이미지
	int		_imageFrame; //이미지프레임
	int		_frame;		 //프레임
	int     _frame2;     //프레임2
	int		_moveSpeed;	 //스피드
	string	_imageName;  //이미지이름
	SMOVE	_move;		 //움직임 상태
	RECT	_rc;		 //렉트
	
	RECT    _skillRc1;
	RECT    _skillRc2;
	RECT    _skillRc3;
	RECT    _skillRc4;
	RECT    _skillRc5;
	RECT    _skillRc6;
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

