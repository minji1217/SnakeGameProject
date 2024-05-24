#pragma once
#include <deque>
#include <vector>
#include <utility>
#include "GameItem.h"
#include "DrawInter.h"
#define MAP_XSIZE 22
#define MAP_YSIZE 45
using namespace std;

class GameItem;

class SnakeBody: public DrawInter
{
public:
	SnakeBody();
	static bool successLength; //목표 뱀길이 달성여부 
	static int used_grow;
	static int used_poison;
	static int used_gate;
	int maxLength;
	int maxGrowth;
	int maxPoison;
	int maxGate;
	bool isDead;
	void draw();
	void move(int ch, GameItem * itemManager);
	pair<int, int> getHead()const { return nowHead; }
	deque<pair<int, int>> snakebody;
	void init();
private:
	
	pair<int, int> preHead;
	pair<int, int> nowHead;
	int nowDirection;
	
	
};

