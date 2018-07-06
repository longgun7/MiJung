#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>

//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
enum CTRL
{
	CTRL_TOWN,
	CTRL_INHOUSE,
	CTRL_FIELD1,
	CTRL_FIELD2,
	CTRL_FIELD3,
	CTRL_SAVE,			//세이브 버튼
	CTRL_LOAD,			//로드 버튼
	CTRL_END
};

struct tagButton
{
	RECT rc;
	string ctrlName;
};

class mapToolScene : public gameNode
{
private:
	vector<tagCurrentTile>				_vCurrentTile;
	vector<tagCurrentTile>::iterator	_viCurrentTile;

private:
	tagSampleTile	_sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile			_tiles[TILEX * TILEY];
	tagButton		_button[6];
	CTRL			_ctrl;

	image*			_sampleImg;
	
	string			_tileSetName;

	// 화면에 보여질 타일 인덱스 시작번호, 끝번호
	int startIdX, endIdX;
	int startIdY, endIdY;

	// 줌인, 줌아웃용 변수
	float _zoom;

	POINT _ptFirstClick;
	POINT _ptLastClick;

	RECT drawRc;

	bool _isLButtonFirstDown;
	bool _isLButtonDown;
	bool _isShowTileSet;
	bool _isShowMoveTile;
	bool _isShowMiniMap;

public:
	mapToolScene();
	~mapToolScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void setImageInit();
	void setup();
	void setMap();
	void setChangeMoveTile();

	void keyInput();
	void buttonClick();

	void save();
	void load();

	// 화면에 보여질 타일 인덱스 번호 설정
	void setShowTileIndex();

	vector<tagCurrentTile> sortVCurrentTile();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

};

