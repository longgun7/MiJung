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

	float	_x, _y;		     //��ǥ
	float   _gravity;	     //�߷�
	float   _jumpPower;      //�����Ŀ�

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
	
	MOVE getMove() { return _move; } //�������� ������

	tagAttribute getAttribute() { return _attribute; } //�Ӽ�������
	void setAttribute(tagAttribute attribute) { _attribute = attribute; }

	SCENEMODE getSCENEMODE() { return _sceneMode; } //�� ������

	bool getIsJumping() { return _isJumping; } //���ο���
	int getSlopeNum() { return _slopeNum; }

	void setSwordMounting(bool mounting) { _isWeaponMounting = mounting; } //���� ��������
	
	void setEnemyManagerAdressLink(enemyManager* em) { _em = em; } //���漱��
	
	void setScene(SCENEMODE _scene,float x , float y , MOVE move) //����ȯ����
	{
		_sceneMode = _scene;
		_x = x;
		_y = y;
		_move = move;
	}
	
	image* getImge() { return _img; } //�̹��������� ������

	void setEnemyIndex(int index) { _enemyIndex = index; }

	void setMove(MOVE move);
	
	RECT getRC() { return _rc; } // �÷��̾� ��Ʈ ���� �߰�(�ΰ�)
	
	
	player();
	~player();
};

