#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>

//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

class mapToolScene : public gameNode
{
private:
	vector<tagCurrentTile>				_vCurrentTile;
	vector<tagCurrentTile>::iterator	_viCurrentTile;

private:
	tagSampleTile	_sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile			_tiles[TILEX * TILEY];

	image*			_sampleImg;

	// ��ư
	image*			_townButtonImg;
	image*			_InHouseButtonImg;
	image*			_field1ButtonImg;
	image*			_field2ButtonImg;
	image*			_field3ButtonImg;
	image*			_saveButtonImg;

	string _tileSetName;
	string _tileName;

	// ȭ�鿡 ������ Ÿ�� �ε��� ���۹�ȣ, ����ȣ
	int startIdX, endIdX;
	int startIdY, endIdY;

	// ����, �ܾƿ��� ����
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
	void setMoveTile();

	void keyInput();
	void buttonClick();

	void save();
	void load();

	// ȭ�鿡 ������ Ÿ�� �ε��� ��ȣ ����
	void setShowTileIndex();

	vector<tagCurrentTile> sortVCurrentTile();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

};

