#pragma once
#define GROW 0
#define TRIM 1
#include <vector>
#include <utility>
#include "SnakeBody.h"
#include "SnakeGame.h"

using namespace std;

class SnakeBody;

class GameItem: public DrawInter
{
protected:
	vector <pair<int, int>> item; //grow, trim item 각각 한개씩
	
public:	
	GameItem() {
		item.push_back({ 0,0 });
		item.push_back({ 0,0 });
	}
	void generateItem(SnakeBody * snake);
	void draw();
	pair<int, int> getGrow() {
		return item[0];
	}
	pair<int, int> getPoison() {
		return item[1];
	}
	
};

