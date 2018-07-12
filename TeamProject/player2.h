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
class player2 :public gameNode
{
private:

	float	_angle;        //�ٶ󺸴� �ޱ�    
	float	_x, _y;		  //��ǥ
	
	int     _exp;
	int     _compareExp;
	bool     _isExpSet;

	float  _angle2[5];
	float  _x2[5], _y2[5];
	RECT   _rc2[5];
	float	_jumpPower;   //�����Ŀ�
	float   _gravity;     //�߷�
	bool    _isJumping;    //�������� 
	bool	_isMotionLive;//��ų,�����¿� ������ ����
	bool    _isSwordMounting; //���� ��������
	image*  _img;		  //�̹���	
	int		_imageFrame;  //�̹���������
	int		_frame;		  //������
	int     _skillFrame;  //��ų ������
	int     _eventFrame;  //�̺�Ʈ������
	int		_moveSpeed;	  //���ǵ�
	int		_enemyIndex;  //�� ��ȣ
	string	_imageName;   //�̹����̸�
	SMOVE	_move;		  //������ ����
	RECT	_rc;		  //��Ʈ
	S_TagAttribute _attribute;
	S_SCENEMODE _sceneMode; //���� ���� �ൿ�� �ٲ�

	RECT _skillRC[7];
	
	//��Ÿȣ ����Ʈ �����ͼ� ����
	atahoTargetSkill2* _soloSkillEffect;
	enemyManager* _em; //���漱��
	//������ ���� ��ų
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
	void strongestSwordEffect(); //���� �� ���� ����Ʈ
	void setPlayerDamage(int damage); //������ ���� ��
	void setSoloDamage(int plusDamage);
	void setAreaDamage(int plusDamage);
	void setExp(int exp);
	void setStat(int atk, int def, int luck, int cri, int speed);
	void setPortion(int hp, int mp);
	
	bool getIsExpSet() { return _isExpSet; }


	float getY() { return _y; }
	
	// �߰�(�ΰ�)
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
	
	void setMounting(bool mounting) { _isSwordMounting = mounting; } //���� ��������
	
	S_TagAttribute getAttribute() { return _attribute; } //�Ӽ�������
	void setAttribute(S_TagAttribute attribute) { _attribute = attribute; }

	S_SCENEMODE getSceneMode() { return _sceneMode; }
	void setSceneMode(S_SCENEMODE scene, SMOVE move)//�� ��ȯ
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

