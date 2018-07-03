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
	DRINK,DRUNKEN, FIGHTREADY,
	//EVENTMODE
	FRONT,LEFT1,LEFT2,LEFT3,LEFT4,RIGHT1,RIGHT2,RIGHT3,RIGHT4,
	WOODFRONT, WOODLEFT1, WOODLEFT2, WOODLEFT3, WOODLEFT4, WOODRIGHT1, WOODRIGHT2, WOODRIGHT3, WOODRIGHT4
};

enum SCENEMODE
{
	FIELDMODE, BATTLEMODE , EVENTMODE
};

class enemyManager;
class player :public gameNode

{
private:

	int		_atk;	//공격력
	int     _def;   //방어력 
	int     _luck;  //운
	int		_cri;   //크리티컬
	int     _speed; //스피드
	int     _currentHp;    //hp
	int     _maxHp;        //총 hp
	int     _currentMp;    //mp
	int		_maxMp;		   //총 mp
	int     _currentExp;   //exp
	int		_maxExp;       //총 exp
	int     _level;        //level
    int		_imageFrame;     //이미지프레임
	int		_frame;		     //프레임
	int     _skillFrame;     //스킬프레임
	int		_moveSpeed;	     //스피드
	int     _slopeFrame;     //기울기 프레임
	int     _slopeNum;		 //기울기 번호
	int     _rndDirection;   //랜덤으로 기울기

	float	_x, _y;		     //좌표
	float   _gravity;	     //중력
	float   _jumpPower;      //점프파워

	bool    _isJumping;      //점프여부
	bool    _isMotionLive;   //스킬, 상하좌우 움직임 여부
	bool	_isWoodDrop;     //이벤트 모드할 때 물통을 들고있는지 아닌지
	bool    _isLevelUp;		 //레벨업 여부
	
	image*  _img;		     //이미지
	string	_imageName;      //이미지이름
	MOVE	_move;		     //움직임 상태
	RECT	_rc;		     //렉트
	SCENEMODE _sceneMode;	 //씬에 따라 움직임

	atahoTargetSkill1* _soloSkillEffect1;
	atahoTargetSkill2* _soloSkillEffect2;
	atahoTargetSkill3* _soloSkillEffect3;

	//에너미 매니저 전방선언
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
	void slopeNumImage();    //기울기 넘버에 따라 이미지 변화
	void move();
	void ropeWalk();
	void levelCheck();

	

	float getX() { return _x; }
	float getY() { return _y; }
	SCENEMODE getSCENEMODE() { return _sceneMode; }
	bool getIsJumping() { return _isJumping; }
	int getSlopeNum() { return _slopeNum; }
	void EnemyManagerAdressLink(enemyManager* em) { _em = em; }
	int getFrameX() { return _imageFrame; }
	
	player();
	~player();
};

