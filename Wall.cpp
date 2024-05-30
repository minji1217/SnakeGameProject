#include "Wall.h"
#include <algorithm>
#include <curses.h>

#define LEFT 0
#define RIGHT 45
#define TOP 0
#define BOTTOM 45
//모서리 (0,0) (45,0) (45,45) (0,45)

void Wall::init() {
	deque<pair<int, int>>::iterator it = wall.begin();
	for (it; it != wall.end(); it++) {
		*it = { 0,0 };
	}
}

void Wall::makeWall() {
	srand((unsigned int)time(NULL));
	init();
	//맵 사이즈 46,23 => wall은 1~44, 1~21
	int len = rand() % 5 + 3; //3~7
	int r = rand() % 20+2; //2~21
	int c = rand() % 42+2; //2~43

	
	//up down left right
	vector<pair<int,int>> dir= { {-1,0},{1,0},{0,-1},{0,1} };


	int sum = 0;
	
	wall.push_front({ r,c });
	while (sum < len) {
		pair<int, int> head = wall.front();
		int direction = rand() % 4; //상하좌우 배열 요소 중 선택
		pair<int, int> nextHead;


		//만약 상하좌우가 모두 wall로 지정된 경우라면 패스 
		bool check = false; //wall이 아닌 경우가 나온다면 true로 만든다
		pair<int, int> chk;
		for (int i = 0; i < 4; i++) {

			chk = { head.first + dir[i].first, head.second + dir[i].second };
			if (find(wall.begin(), wall.end(), chk) == wall.end()) {
				check = true;
			}
		}

		if (check == false) {
			break;
		}

		//여기까지 왔다는 건 wall추가할 수 있다는것
		

		for (int i = 0; i < 4; i++) {
			nextHead = { head.first + dir[i].first, head.second + dir[i].second };
			if (nextHead.first > 1 && nextHead.first < 22 && nextHead.second > 1 && nextHead.second < 44 && find(wall.begin(), wall.end(), nextHead) == wall.end()) {
				wall.push_front(nextHead);
				sum++;
				break;
			}
		}

	}

	draw();

}



void Wall::draw() {
	deque<pair<int, int>>::iterator it = wall.begin();
	for (it;it != wall.end(); it++) {
		int row = (*it).first;
		int col = (*it).second;
		mvprintw(row, col, "X");
	}
}
