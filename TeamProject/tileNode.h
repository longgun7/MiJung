#pragma once

//터레인
enum TERRAIN
{
	TR_UNMOVE, TR_MOVE, TR_DOOR,
	TR_LEFTPORTAL, TR_RIGHTPORTAL, TR_UPPORTAL, TR_DOWNPORTAL,
	TR_NONE
};

//오브젝트 
enum OBJECT
{
	OBJ_EXIST,
	OBJ_NPC,
	OBJ_PLAYER1,
	OBJ_PLAYER2,
	OBJ_ENEMY,
	OBJ_NONE
};

#define ATTR_UNMOVE 0x00000001		//못가는 지형

// 타일 규격
#define TILESIZE 25

// 타일 갯수
#define TILEX 150
#define TILEY 150

// 화면에 보여질 타일 갯수
#define SHOWTILEX 40
#define SHOWTILEY 30

// 타일 전체 사이즈 3750 x 3750
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

// 타일셋 타일셋 갯수
#define SAMPLETILEX 39
#define SAMPLETILEY 13

// 타일에 대한 구조체
struct tagTile
{
	RECT	rc;					//렉트
	TERRAIN terrain;			//지형 이넘문
	OBJECT	obj;				//오브젝트 이넘문	
	int		terrainFrameX;		//지형 프레임 번호(이미지)
	int		terrainFrameY;		//지형 프레임 번호
	int		objFrameX;			//오브젝트 프레임 번호
	int		objFrameY;			//오브젝트 프레임 번호
	DWORD	attribute;			//타일 속성
};

// 타일셋 구조체
struct tagSampleTile
{
	RECT	rcTile;				//타일셋 
	TERRAIN terrain;			//지형 이넘문
	OBJECT	obj;				//오브젝트 이넘문	
	int		terrainFrameX;		//타일셋 프레임 번호
	int		terrainFrameY;		//타일셋 프레임 번호
	int		objFrameX;			//오브젝트 프레임 번호
	int		objFrameY;			//오브젝트 프레임 번호
};

// 현재 타일
struct tagCurrentTile
{
	int x;
	int y;
};