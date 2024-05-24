#include "GameItem.h"
#include <cstdlib>
#include <ctime>
#include <curses.h>
#include <algorithm>
#define MAP_XSIZE 45
#define MAP_YSIZE 22



void GameItem::generateItem(SnakeBody * snake) {
	//맵 계속 띄울때마다 아이템의 위치도 계속 바뀌어야함
	poison.clear();
	grow.clear();

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

	int itemSize; //grow,poison item 몇개 생성할 건지
	itemSize = 50;//rand() % 2 + 2; //최소 2개에서 3개까지 

	for (int i = 0; i < itemSize; i++) {
		int whatItem; //무슨 아이템 만들건지 0이면 grow, 1이면 trim
		int idx; //아이템 생성할 수 있는 칸의 모든 위치 중 랜덤하게 뽑아서 해당하는 칸에 아이템 생성
		whatItem = rand() % 2;
		idx = rand() % possible.size();
		if (whatItem) {
			//1인 경우
			while (find(poison.begin(), poison.end(), possible[idx]) != poison.end() || find(grow.begin(),grow.end(), possible[idx])!=grow.end()) {
				//만약 중복이 있다면
				idx = rand() % possible.size();
			}
			poison.push_back(possible[idx]);
		}
		else {
			//0인 경우 
			//이때 아이템이 중복될 수 있기에 중복방지하는 while문생성
			while (find(poison.begin(), poison.end(), possible[idx]) != poison.end() || find(grow.begin(), grow.end(), possible[idx]) != grow.end()) {
				//만약 중복이 있다면
				idx = rand() % possible.size();
			}
			//빠져나온다면 이미 생성된 아이템 좌표와 다른 곳
			grow.push_back(possible[idx]);
			
		}
	}
	
	
}

void GameItem::draw() {
	vector<pair<int, int>>::iterator it1 = poison.begin();
	for (it1; it1 != poison.end(); it1++) {
		mvprintw(it1->first, it1->second, "P");
	}
	vector<pair<int, int>>::iterator it2 = grow.begin();
	for (it2; it2 != grow.end(); it2++) {
		mvprintw(it2->first, it2->second, "G");
	}
	
	
}


