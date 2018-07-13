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
	HPUP,MPUP, ATTACKEND, ENDSEREMONI,
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
	int		atk;	//���ݷ�
	int     def;   //���� 
	int     luck;  //��
	int		cri;   //ũ��Ƽ��
	int     speed; //���ǵ�
	int     currentHp;    //hp
	int     maxHp;        //�� hp
	int     currentMp;    //mp
	int		maxMp;		   //�� mp
	int     currentExp;   //exp
	int		maxExp;       //�� exp
	int     level;        //level
	bool    isLevelUp;		 //������ ����
};

class playMap;
class enemyManager;

class player :public gameNode

{
private:

	
    int		_imageFrame;     //�̹���������
	int		_frame;		     //������
	int     _skillFrame;     //��ų������
	int		_moveSpeed;	     //���ǵ�
	int     _slopeFrame;     //���� ������
	int     _slopeNum;		 //���� ��ȣ
	int     _rndDirection;   //�������� ����
	int     _enemyIndex;     //�� �ε���

	
	int     _exp;
	int     _compareExp;
	bool     _isExpSet;
	

	float	_x, _y;		     //��ǥ
	float   _gravity;	     //�߷�
	float   _jumpPower;      //�����Ŀ�
	float   _angle;          //��Ÿȣ �ޱ�
	bool    _isJumping;      //��������
	bool    _isMotionLive;   //��ų, �����¿� ������ ����
	bool	_isWoodDrop;     //�̺�Ʈ ����� �� ������ ����ִ��� �ƴ���
	bool    _isWeaponMounting; //���� ��������

	image*  _img;		     //�̹���
	string	_imageName;      //�̹����̸�
	MOVE	_move;		     //������ ����
	RECT	_rc;		     //��Ʈ
	RECT	_skillRC[9];
	SCENEMODE _sceneMode;	 //���� ���� ������
	tagAttribute _attribute; //�Ӽ�
	tagEffectImage1 _effectImage;
	atahoTargetSkill1* _soloSkillEffect1;
	atahoTargetSkill2* _soloSkillEffect2;
	atahoTargetSkill3* _soloSkillEffect3;
	atahoAreaSkill2* _areaSkillEffect2;
	atahoAreaSkill3* _areaSkillEffect3;
	gameEffect* _gameEffect;
	
	//���ʹ� �Ŵ��� ���漱��
	enemyManager* _em;

	// �߰�(�ΰ�)
	RECT _zOrderRC;
	playMap* _map;
	RECT _rangeRC;

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
	void slopeNumImage();    //���� �ѹ��� ���� �̹��� ��ȭ
	void move();
	void levelCheck();
	void setPlayerDamage(int damage); //������ ���� ��
	void setSoloDamage(int plusDamage);
	void setAreaDamage(int plusDamage);
	void setExp(int exp);
	void setStat(int atk, int def, int luck, int cri, int speed);
	void setPortion(int hp, int mp);
	void randEffect();
	void randAreaEffect();
	void effectImage();	
	float getX() { return _x; }
	void setX(float x) { _x = x; }	
	float getY() { return _y; }
	void setY(float y) { _y = y; }	
	float getAngle() { return _angle; }                                                                                                                                                                    
	MOVE getMove() { return _move; } //�������� ������
	void setIsMotionLive(bool motion) { _isMotionLive = motion; }
	tagAttribute getAttribute() { return _attribute; } //�Ӽ�������
	bool getIsJumping() { return _isJumping; } //���ο���
	int getSlopeNum() { return _slopeNum; }
	void setSwordMounting(bool mounting) { _isWeaponMounting = mounting; } //���� ��������	
	void setEnemyManagerAdressLink(enemyManager* em) { _em = em; } //���漱��	
	void setSceneMode(SCENEMODE _scene, MOVE move) //����ȯ����
	{
		_sceneMode = _scene;
		
		_move = move;
	}
	SCENEMODE getSceneMode() { return _sceneMode; } //�� ������
	image* getImge() { return _img; } //�̹��������� ������

	void setEnemyIndex(int index) { _enemyIndex = index; }
	void setIsJumping(bool jumping) { _isJumping = jumping; }
	
	void setMove(MOVE move)
	{
		_move = move;
		_isMotionLive = true;
	}
	void setSlopeNum(int num) { _slopeNum = num; }
	void setIsWoodDrop(bool drop) {  _isWoodDrop = drop; }
	void setSkil(int choiceIndex, int skillIndex,int monIndex);
	int getSkillFrame() { return _skillFrame; }	
	void setEventMode(SCENEMODE mode);
	image* getImg() { return _img; }
	// �߰�(�ΰ�)
	RECT getRC() { return _rc; }
	RECT getZorderRC() { return _zOrderRC; }
	RECT getRangeRC() { return _rangeRC; }
	
	void tileMove(void);
	void setplayMapMemoryAddressLink(playMap* map) { _map = map; }

	void setAttribute(int atk, int def,  int cri, int speed, int currentHp, int maxHp, int currentMp, int maxMp, int currentExp, int maxExp, int level)
	{
		_attribute.atk = atk;
		_attribute.def = def;
		_attribute.cri = cri;
		_attribute.speed = speed;
		_attribute.currentHp = currentHp;
		_attribute.maxHp = maxHp;
		_attribute.currentMp = currentMp;
		_attribute.maxMp = maxMp;
		_attribute.currentExp = currentExp;
		_attribute.maxExp = maxExp;
		_attribute.level = level;
	}
	void setAttributeTest(int currentHp, int currentMp)
	{
		_attribute.currentHp = currentHp;
		_attribute.currentMp = currentMp;
	}

	player();
	~player();
};

