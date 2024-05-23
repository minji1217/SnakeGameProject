#pragma once
#define GROW 0
#define TRIM 1
#include <vector>
#include <utility>
#include "SnakeBody.h"
#include "SnakeGame.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

class SnakeBody;

class GameItem: public DrawInter
{
protected:
	vector <pair<int, int>> poison;
	vector <pair<int, int>> grow;
	
	
public:	
	GameItem() {
	}
	void generateItem(SnakeBody * snake);
	void draw();
	vector<pair<int, int>> getGrow() {
		return grow;
	}
	vector<pair<int, int>> getPoison() {
		return poison;
	}
	
};

