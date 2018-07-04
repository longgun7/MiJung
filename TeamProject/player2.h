#pragma once
#include "gameNode.h"
#include "Skill.h"

enum SMOVE
{
	S_LEFT, S_RIGHT, S_DOWN, S_UP,
	S_LEFTMOVE, S_RIGHTMOVE, S_DOWNMOVE, S_UPMOVE,
	S_SOLOSKILL1, S_SOLOSKILL2, S_SOLOSKILL3,
	S_AREASKILL1, S_AREASKILL2, S_AREASKILL3,
	S_FIGHTREADY , S_ROPEWALKING , S_FALLING , S_AFRAID
};

enum S_SCENEMODE
{
	S_FIELDMODE, S_BATTLEMODE , S_EVENTMODE
};

struct tagEffectImage
{
	int frame;
	int frameImage;
	image*  img;
	
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
class player2 :public gameNode
{
private:

	float	_angle;        //�ٶ󺸴� �ޱ�    
	float	_x, _y;		  //��ǥ
	float	_jumpPower;   //�����Ŀ�
	float   _gravity;     //�߷�
	bool    _isJumping;    //�������� 
	bool	_isMotionLive;//��ų,�����¿� ������ ����
	image*  _img;		  //�̹���
	
	int		_imageFrame;  //�̹���������
	int		_frame;		  //������
	int     _skillFrame;  //��ų ������
	int     _eventFrame;  //�̺�Ʈ������
	int		_moveSpeed;	  //���ǵ�
	string	_imageName;   //�̹����̸�
	SMOVE	_move;		  //������ ����
	RECT	_rc;		  //��Ʈ
	S_TagAttribute _attribute;
	S_SCENEMODE _sceneMode; //���� ���� �ൿ�� �ٲ�
	tagEffectImage _effectImage;
	atahoTargetSkill2* _soloSkillEffect;
public:
	
	HRESULT init(float x , float y);
	void update();
	void render();
	void release();
	void image();
	void imageFrame();
	void angleManager(float x , float y);
	void move();
	void s_event();
	void effectImage();
	float getY() { return _y; }
	void setIsJumping(bool isJumping) { _isJumping = isJumping; }
	void setMove(SMOVE move) { _move = move; }

	S_TagAttribute getAttribute() { return _attribute; } //�Ӽ�������
	void setAttribute(S_TagAttribute attribute) { _attribute = attribute; }

	S_SCENEMODE getSceneMode() { return _sceneMode; }
	void setSceneMode(S_SCENEMODE scene, float x, float y, SMOVE move)//�� ��ȯ
	{
		_sceneMode = scene;
		_x = x;
		_y = y;
		_move = move;
	}
	player2();
	~player2();
};

