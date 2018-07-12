#pragma once
#include "gameNode.h"
#include "Skill.h"
#include "SumsuSkill.h"
#include "gameEffect.h"
//#include "SumsuSkill.h"
enum SMOVE
{
	S_LEFT, S_RIGHT, S_DOWN, S_UP,
	S_LEFTMOVE, S_RIGHTMOVE, S_DOWNMOVE, S_UPMOVE,
	S_BASICSKILL1,
	S_SOLOSKILL1, S_SOLOSKILL2, S_AREASKILL1,
	S_AREASKILL3, S_SOLOSKILL3, S_AREASKILL2,
	S_FIGHTREADY , S_ROPEWALKING , S_DANGER , S_AFRAID,
	S_DEFENCE,S_NOCKDOWN,S_ESCAPE, S_SEREMONI,
	S_HPUP,S_MPUP,
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
	
	int     _exp;
	int     _compareExp;
	bool     _isExpSet;

	float  _angle2[5];
	float  _x2[5], _y2[5];
	RECT   _rc2[5];
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
	int		_enemyIndex;  //적 번호
	string	_imageName;   //이미지이름
	SMOVE	_move;		  //움직임 상태
	RECT	_rc;		  //렉트
	S_TagAttribute _attribute;
	S_SCENEMODE _sceneMode; //씬에 따라 행동이 바뀜

	RECT _skillRC[7];
	
	//아타호 이펙트 빌려와서 쓴거
	atahoTargetSkill2* _soloSkillEffect;
	enemyManager* _em; //전방선언
	//스마슈 고유 스킬
	sumsuCut* _attackEffect;
	sumsuAreaSkill1* _areaSkill1;
	sumsuAreaSkill2* _areaSkill2;
	sumsuAreaSkill3* _areaSkill3;
	sumsuTargetSkill2* _soloSkill2;
	sumsuTargetSkill3* _soloSkill3;
	gameEffect* _gameEffect;
public:
	
	HRESULT init(float x , float y);
	void update();
	void render();
	void release();
	void playerImage();
	void imageFrame();
	void fieldKeyManager(float x , float y, float angle);
	void battleKeyManager();
	void move();
	void randEffect();
	void randAreaEffect();
	void s_event();
	void levelCheck();
	void strongestSwordEffect(); //제일 센 무기 이펙트
	void setPlayerDamage(int damage); //데미지 넣을 것
	void setSoloDamage(int plusDamage);
	void setAreaDamage(int plusDamage);
	void setExp(int exp);
	void setStat(int atk, int def, int luck, int cri, int speed);
	void setPortion(int hp, int mp);
	
	bool getIsExpSet() { return _isExpSet; }


	float getY() { return _y; }
	
	// 추가(민경)
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	void setIsJumping(bool isJumping) { _isJumping = isJumping; }
	
	SMOVE getMove() { return _move; }
	void setMove(SMOVE move)
	{
		_move = move;
		_isMotionLive = true;
	}
	
	void setSkill(int choiceIndex, int skillIndex, int monIndex);
	
	void setMounting(bool mounting) { _isSwordMounting = mounting; } //무기 장착여부
	
	S_TagAttribute getAttribute() { return _attribute; } //속성접근자
	void setAttribute(S_TagAttribute attribute) { _attribute = attribute; }

	S_SCENEMODE getSceneMode() { return _sceneMode; }
	void setSceneMode(S_SCENEMODE scene, SMOVE move)//씬 전환
	{
		_sceneMode = scene;
		
		_move = move;
	}
	void setEventMode(S_SCENEMODE mode);
	void setEnemyManagerAdressLink(enemyManager* em) { _em = em; }
	int getSkillFrame() { return _skillFrame; }
	void setEnemyIndex(int index) { _enemyIndex = index; }
	void setIsMotionLive(bool motion) { _isMotionLive = motion; }
	image* getImage() { return _img; }
	
	player2();
	~player2();
};

