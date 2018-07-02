#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>

class mapToolScene : public gameNode
{
private:
	vector<tagCurrentTile>				_vCurrentTile;
	vector<tagCurrentTile>::iterator	_viCurrentTile;

private:
	//tagCurrentTile	_currentTile;
	tagSampleTile	_sampleTile[SAMPLETILEX * SAMPLETILEY];
	tagTile			_tiles[TILEX * TILEY];

	image*			_sampleImg;

	// ȭ�鿡 ������ Ÿ�� �ε��� ���۹�ȣ, ����ȣ
	int startIdX, endIdX;
	int startIdY, endIdY;

	// ����, �ܾƿ��� ����
	float _zoom;

	POINT _ptFirstClick;
	POINT _ptLastClick;

	bool _isLButtonFirstDown;
	bool _isLButtonDown;
	bool _isShowTileSet;

	bool _isShowMiniMap;

public:
	mapToolScene();
	~mapToolScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void setup();
	void setMap();

	// ȭ�鿡 ������ Ÿ�� �ε��� ��ȣ ����
	void setShowTileIndex();

	vector<tagCurrentTile> sortVCurrentTile();

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

};

