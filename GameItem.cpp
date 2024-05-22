#include "GameItem.h"
#include <cstdlib>
#include <ctime>
#include <curses.h>
#include <algorithm>
#define MAP_XSIZE 45
#define MAP_YSIZE 22



void GameItem::generateItem(SnakeBody * snake) {
	 
	item.clear();
	srand((unsigned int)time(NULL));
	vector <pair<int, int>> possible;
	
	for (int i = 1; i < MAP_YSIZE; i++) {
		for (int j = 1; j < MAP_XSIZE; j++) {
			possible.push_back({ i,j });
		}
	}

	deque<pair<int, int>>::iterator it = snake->snakebody.begin();
	for (it; it != snake->snakebody.end();it++) {
		auto del = find(possible.begin(), possible.end(), *it);
		if (del != possible.end()) {
			possible.erase(del);
		}
	}
	//grow item
	int idx = rand() % possible.size();
	item.push_back(possible[idx]);

	int idx2 = rand() % possible.size();
	while (idx== idx2) {
		idx2 = rand() % possible.size();
	}
	item.push_back(possible[idx2]);

	draw();
}

void GameItem::draw() {
	pair<int, int> grow = item[0];
	pair<int, int> trim = item[1];

	mvprintw(grow.first, grow.second, "G");
	mvprintw(trim.first, trim.second, "P");
	
}


