#pragma once
#include"gameNode.h"
#include "progressBar.h"

enum PLAYER_TURN
{
	ATAHO_TURN,
	SUMSU_TURN
};
enum GAME_TURN
{
	ATAHO_CHOICE,
	SUMSU_CHOICE,
	ATAHO_ATTACK,
	SUMSU_ATTACK,
	ENEMY_ATTACK,
	BATTLE_WIN,
	BATTLE_ESCAPE
};

class playerManager;
class enemyManager;
class itemManager;
class battleScene : public gameNode
{
private: 
	playerManager * _pm;
	enemyManager * _em;
	itemManager* _im;

	GAME_TURN _gameTurn;

	int _choiceIndex;			//스킬 타입 인덱스
	int _skillIndex;			//스킬 인덱스
	int _monIndex;				//몬스터 선택 인덱스

	//아~직 사용 X
	int _sChoiceIndex;
	int _sSkillIndex;
	int _sMonIndex;

	float _choiceX, _choiceY;	//모드 선택 버튼 좌표
	float _skillX, _skillY;		//스킬 선택 버튼	좌표
	float _monX, _monY;			//몬스터 선택 버튼 좌표

	//-------------------enum 으로 뺄 부분--------------
	bool _isTurn;				//스킬쓸 차례인가
	bool _isSkillCheck;			//스킬 선택했늬?
	bool _isMonCheck;			//몬스터 체크했늬?(기본,개인공격 시)
	bool _isFight;				//스킬을 다 선택하고 배틀하늬?
	//--------------------------------------------------

	bool _isAtahoSkillFire;		//스킬이 발사 되었는가?
	bool _isSumsuSkillFire;		//스킬이 발사 되었는가?
	
	PLAYER_TURN _playerTurn;	//아타호 스마슈 스킬 턴

	int totalExp;
	int totalMoney;

	bool _isSceneCount;
	int sceneCount;
	bool _isDeadEnemy;	// (추가)에너미가 죽은 상태면 턴 넘기지 말고 기다리게하는 bool값

	string _nowSong;
	
	vector<progressBar*>			_vEnemyHpBar;
	vector<progressBar*>::iterator	_viEnemyHpBar;

public:
	battleScene();
	~battleScene();

	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void addImage(void);	
	void fontUI(void);
	void iconChange(void);			//아이콘 변경
	void skillChoice(void);			//스킬선택
	void atahoSkillCheck();
	void sumsuSkillCheck();

	void setEnemyDead(int index);
};

