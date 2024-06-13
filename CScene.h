#pragma once
#include"Game.h"
class CSnake;
class CMap;
class CItems;
class CGates;
class CScene
{
private:
	int map[30][30][2]{0};
    CSnake * Snake;
	CMap * CurrentMap;
	CItems * Items;
	CGates * Gates;
    int snakey,snakex;
    int input;
	bool youDie;
public:
	CScene();
	~CScene();
	void Run();
	void Init();
	void Update();
	void Render();
	void MapUpdate();
	void SetDie(bool isDie);
	int GetMapW(int y,int x);
	void SetMapW(int y,int x,int w);
	void SetMapW(int y,int x,int w,int w2);
	void ItemCollision(int y,int x);
	void GateCollision(int y,int x,int dir);
	void GateOn();
	void GateOff();
};