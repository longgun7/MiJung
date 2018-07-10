#pragma once

//�ͷ���
enum TERRAIN
{
	TR_UNMOVE, TR_MOVE, TR_DOOR,
	TR_LEFTPORTAL, TR_RIGHTPORTAL, TR_UPPORTAL, TR_DOWNPORTAL,
	TR_NONE
};

//������Ʈ 
enum OBJECT
{
	OBJ_EXIST,
	OBJ_NPC,
	OBJ_PLAYER1,
	OBJ_PLAYER2,
	OBJ_ENEMY,
	OBJ_NONE
};

#define ATTR_UNMOVE 0x00000001		//������ ����

// Ÿ�� �԰�
#define TILESIZE 25

// Ÿ�� ����
#define TILEX 150
#define TILEY 150

// ȭ�鿡 ������ Ÿ�� ����
#define SHOWTILEX 40
#define SHOWTILEY 30

// Ÿ�� ��ü ������ 3750 x 3750
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

// Ÿ�ϼ� Ÿ�ϼ� ����
#define SAMPLETILEX 39
#define SAMPLETILEY 13

// Ÿ�Ͽ� ���� ����ü
struct tagTile
{
	RECT	rc;					//��Ʈ
	TERRAIN terrain;			//���� �̳ѹ�
	OBJECT	obj;				//������Ʈ �̳ѹ�	
	int		terrainFrameX;		//���� ������ ��ȣ(�̹���)
	int		terrainFrameY;		//���� ������ ��ȣ
	int		objFrameX;			//������Ʈ ������ ��ȣ
	int		objFrameY;			//������Ʈ ������ ��ȣ
	DWORD	attribute;			//Ÿ�� �Ӽ�
};

// Ÿ�ϼ� ����ü
struct tagSampleTile
{
	RECT	rcTile;				//Ÿ�ϼ� 
	TERRAIN terrain;			//���� �̳ѹ�
	OBJECT	obj;				//������Ʈ �̳ѹ�	
	int		terrainFrameX;		//Ÿ�ϼ� ������ ��ȣ
	int		terrainFrameY;		//Ÿ�ϼ� ������ ��ȣ
	int		objFrameX;			//������Ʈ ������ ��ȣ
	int		objFrameY;			//������Ʈ ������ ��ȣ
};

// ���� Ÿ��
struct tagCurrentTile
{
	int x;
	int y;
};