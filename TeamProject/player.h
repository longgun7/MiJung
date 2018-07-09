#pragma once
#include "gameNode.h"
#include "Skill.h"
#include "gameEffect.h"

enum MOVE
{
	//FIELDMODE
	LEFT, RIGHT, DOWN, UP,
	LEFTMOVE, RIGHTMOVE, DOWNMOVE, UPMOVE,
	//BATTLEMODE
	BASICSKILL1, BASICSKILL2, BASICSKILL3,
	SOLOSKILL1, SOLOSKILL2, SOLOSKILL3,
	AREASKILL1, AREASKILL2, AREASKILL3,
	DRINK,DRUNKEN, FIGHTREADY, DAMAGE,
	DEFENCE, SEREMONI,ESCAPE,NOCKDOWN,
	//EVENTMODE
	FRONT,LEFT1,LEFT2,LEFT3,LEFT4,RIGHT1,RIGHT2,RIGHT3,RIGHT4,
	WOODFRONT, WOODLEFT1, WOODLEFT2, WOODLEFT3, WOODLEFT4, WOODRIGHT1, WOODRIGHT2, WOODRIGHT3, WOODRIGHT4
};

enum SCENEMODE
{
	FIELDMODE, BATTLEMODE , EVENTMODE
};

struct tagEffectImage1
{
	int frame;
	int frameImage;
	image*  img;

};
struct tagAttribute
{
	int		atk;	//공격력
	int     def;   //방어력 
	int     luck;  //운
	int		cri;   //크리티컬
	int     speed; //스피드
	int     currentHp;    //hp
	int     maxHp;        //총 hp
	int     currentMp;    //mp
	int		maxMp;		   //총 mp
	int     currentExp;   //exp
	int		maxExp;       //총 exp
	int     level;        //level
	bool    isLevelUp;		 //레벨업 여부
};

class enemyManager;
class player :public gameNode

{
private:

	
    int		_imageFrame;     //이미지프레임
	int		_frame;		     //프레임
	int     _skillFrame;     //스킬프레임
	int		_moveSpeed;	     //스피드
	int     _slopeFrame;     //기울기 프레임
	int     _slopeNum;		 //기울기 번호
	int     _rndDirection;   //랜덤으로 기울기
	int     _enemyIndex;     //적 인덱스

	float	_x, _y;		     //좌표
	float   _gravity;	     //중력
	float   _jumpPower;      //점프파워

	bool    _isJumping;      //점프여부
	bool    _isMotionLive;   //스킬, 상하좌우 움직임 여부
	bool	_isWoodDrop;     //이벤트 모드할 때 물통을 들고있는지 아닌지
	bool    _isWeaponMounting; //무기 장착여부

	image*  _img;		     //이미지
	string	_imageName;      //이미지이름
	MOVE	_move;		     //움직임 상태
	RECT	_rc;		     //렉트
	RECT	_skillRC[9];
	SCENEMODE _sceneMode;	 //씬에 따라 움직임
	tagAttribute _attribute; //속성
	tagEffectImage1 _effectImage;
	atahoTargetSkill1* _soloSkillEffect1;
	atahoTargetSkill2* _soloSkillEffect2;
	atahoTargetSkill3* _soloSkillEffect3;
	atahoAreaSkill2* _areaSkillEffect2;
	atahoAreaSkill3* _areaSkillEffect3;
	gameEffect* _gameEffect;
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
	void levelCheck();
	void setPlayerDamage(int damage); //데미지 넣을 것
	void setSoloDamage(int plusDamage);
	void setAreaDamage(int plusDamage);
	void setExp(int exp) { _attribute.currentExp += exp; }
	void setStat(int atk, int def, int luck, int cri, int speed);
	void setPortion(int hp, int mp);
	void randEffect();
	void randAreaEffect();
	
	void effectImage();
	
	float getX() { return _x; }
	void setX(float x) { _x = x; }
	
	float getY() { return _y; }
	void setY(float y) { _y = y; }
	
	MOVE getMove() { return _move; } //상태정의 접근자

	tagAttribute getAttribute() { return _attribute; } //속성접근자
	void setAttribute(tagAttribute attribute) { _attribute = attribute; }

	SCENEMODE getSCENEMODE() { return _sceneMode; } //씬 접근자

	bool getIsJumping() { return _isJumping; } //점핑여부
	int getSlopeNum() { return _slopeNum; }

	void setSwordMounting(bool mounting) { _isWeaponMounting = mounting; } //무기 장착여부
	
	void setEnemyManagerAdressLink(enemyManager* em) { _em = em; } //전방선언
	
	void setScene(SCENEMODE _scene,float x , float y , MOVE move) //씬전환모음
	{
		_sceneMode = _scene;
		_x = x;
		_y = y;
		_move = move;
	}
	
	image* getImge() { return _img; } //이미지프레임 접근자

	void setEnemyIndex(int index) { _enemyIndex = index; }

	void setMove(MOVE move);
	
	RECT getRC() { return _rc; } // 플레이어 렉트 접근 추가(민경)
	
	
	player();
	~player();
};

