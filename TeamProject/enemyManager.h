#pragma once
#include "gameNode.h"
#include "fildSkeleton.h"
#include "enemys.h"
#include "playerManager.h"

#define MAXSKELETON 20
#define PLAYMAPSIZEY 525

class playerManager;

class enemyManager : public gameNode
{
private:

	vector<enemy*>			 _vEnemy;
	vector<enemy*>::iterator _viEnemy;

private:

	//vFildSkeleton _vFildSkeleton;		// ���͸� ����ϱ� ���� _vSkeleton ����
	//viFildSkeleton _viFildSkeleton;		// ���͸� ����ϱ� ���� _viSkeleton ����

	playerManager* _pm;
	
	fildSkeleton* _fildSkeleton;		// ���̷��� �Լ��� ����ϱ� ���� ����
	
	int _randNum;						// ���� ����� ��������
	int _enemyIndex;					// ���° ������

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemy(float x ,float y);						// �� ��ġ �Լ�
	void hitEnemy(int index, int damge);					// ���° �ְ� �������� �޾Ҵ���
	void hitPlayer();										// �÷��̾����� ������ �ִ� �Լ�
	void randEnemy();										// �������� �� �����ǰ� �ϴ� �Լ�
	void removeEnemy(int arrNum);							// ���� �����ִ� �Լ�
	void setMotion(DIRECTION direction);

	vector<enemy*>			 getVEnmey() { return _vEnemy; }			// �ܺο��� ���ʹ� ���Ϳ� ���� �����ϰ� ��ȯ
	vector<enemy*>::iterator getVIEnmey() { return _viEnemy; }			// �ܺο��� ���ʹ� ���� ���ͷ����Ϳ� ���� �����ϰ� ��ȯ

	void AdressLinkPlayerManager(playerManager* pm) { _pm = pm; }		// ���漱���� �÷��̾� �Ŵ����� ������ �����´�

	enemyManager();
	~enemyManager();
};