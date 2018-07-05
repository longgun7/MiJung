#pragma once
#include "gameNode.h"
#include "Skill.h"
//#include "SumsuSkill.h"
enum SMOVE
{
	S_LEFT, S_RIGHT, S_DOWN, S_UP,
	S_LEFTMOVE, S_RIGHTMOVE, S_DOWNMOVE, S_UPMOVE,
	S_SOLOSKILL1, S_SOLOSKILL2, S_SOLOSKILL3,
	S_AREASKILL1, S_AREASKILL2, S_AREASKILL3,
	S_FIGHTREADY , S_ROPEWALKING , S_DANGER , S_AFRAID,
	S_DEFENCE,S_NOCKDOWN
};

enum S_SCENEMODE
{
	S_FIELDMODE, S_BATTLEMODE , S_EVENTMODE
};



struct S_TagAttribute
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
class player2 :public gameNode
{
private:

	float	_angle;        //바라보는 앵글    
	float	_x, _y;		  //좌표
	float	_jumpPower;   //점프파워
	float   _gravity;     //중력
	bool    _isJumping;    //점프여부 
	bool	_isMotionLive;//스킬,상하좌우 움직임 여부
	bool    _isSwordMounting; //무기 장착여부
	image*  _img;		  //이미지	
	int		_imageFrame;  //이미지프레임
	int		_frame;		  //프레임
	int     _skillFrame;  //스킬 프레임
	int     _eventFrame;  //이벤트프레임
	int		_moveSpeed;	  //스피드
	string	_imageName;   //이미지이름
	SMOVE	_move;		  //움직임 상태
	RECT	_rc;		  //렉트
	S_TagAttribute _attribute;
	S_SCENEMODE _sceneMode; //씬에 따라 행동이 바뀜
	
	//아타호 이펙트 빌려와서 쓴거
	atahoTargetSkill2* _soloSkillEffect;
	enemyManager* _em; //전방선언
	//스마슈 고유 스킬
//	sumsuCut* _attackEffect;
	//sumsuAreaSkill1* _areaSkill1;
	//sumsuTargetSkill2* _soloSkill2;
	//sumsuTargetSkill3* _soloSkill3;
public:
	
	HRESULT init(float x , float y);
	void update();
	void render();
	void release();
	void image();
	void imageFrame();
	void fieldKeyManager(float x , float y);
	void battleKeyManager();
	void move();
	void s_event();
	void strongestSwordEffect(); //제일 센 무기 이펙트
	
	float getY() { return _y; }
	
	void setIsJumping(bool isJumping) { _isJumping = isJumping; }
	
	void setMove(SMOVE move) { _move = move; }
	
	void setMounting(bool mounting) { _isSwordMounting = mounting; } //무기 장착여부
	
	S_TagAttribute getAttribute() { return _attribute; } //속성접근자
	void setAttribute(S_TagAttribute attribute) { _attribute = attribute; }

	S_SCENEMODE getSceneMode() { return _sceneMode; }
	void setSceneMode(S_SCENEMODE scene, float x, float y, SMOVE move)//씬 전환
	{
		_sceneMode = scene;
		_x = x;
		_y = y;
		_move = move;
	}

	void setEnemyManagerAdressLink(enemyManager* em) { _em = em; }
	void setDamage(int damage);
	
	player2();
	~player2();
};

