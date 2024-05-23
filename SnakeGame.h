#pragma once
#include "Map.h"
#include "SnakeBody.h"
#include "Gate.h"
#include "GameItem.h"
#include "Windows.h"
#include "DrawInter.h"
#include <curses.h>
#include <cstdlib>
using namespace std;

class GameItem;
class SnakeBody;

class SnakeGame
{
public:
	~SnakeGame();
	SnakeGame();
	void gameStart();
	void printMissionBoard();
	void printStatusBoard();

	void finish();
	bool isSuccess();

private:
	
	int max_xpos; //����
	int max_ypos; //����
	Map* map;
	SnakeBody* player;
	GameItem* itemManager;
	

};

