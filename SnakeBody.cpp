#include "SnakeBody.h"
#include "GameItem.h"
#include "SnakeGame.h"
#include <cstdlib>
#include <ctime>
#include <curses.h>


SnakeBody::SnakeBody():isDead(false){
	srand((unsigned int)time(NULL));
	maxLength = rand() % 3 + 5; //5~7
	maxPoison = rand() % 3 + 2; //2~4
	maxGrowth = rand() % 3 + 2; //2~4
	maxGate = rand() % 2 + 1; //1~2
	preHead = make_pair(10, 11);
	nowHead = make_pair(10, 10);
	snakebody.push_back({10,10});
	snakebody.push_back({ 10,11 });
	snakebody.push_back({ 10,12 });
	nowDirection = KEY_LEFT;
}

bool SnakeBody::successLength = false;
int SnakeBody::used_grow=0;
int SnakeBody::used_poison=0;
int SnakeBody::used_gate = 0;

void SnakeBody::move(int ch, GameItem * itemManager) {
	pair<int, int> movePos;
	
	switch (ch) {
	case KEY_LEFT:
		movePos = make_pair(nowHead.first, nowHead.second - 1);
		nowDirection = KEY_LEFT;
		break;
	case KEY_RIGHT:
		movePos = make_pair(nowHead.first, nowHead.second + 1);
		nowDirection = KEY_RIGHT;
		break;
	case KEY_UP:
		movePos = make_pair(nowHead.first - 1, nowHead.second);
		nowDirection = KEY_UP;
		break;
	case KEY_DOWN:
		movePos = make_pair(nowHead.first + 1, nowHead.second);
		nowDirection = KEY_DOWN;
		break;
	}
	//Tail�������� �̵� �� ���� 
	if (movePos == preHead) {
		isDead = true;
		return;
	}
	//�ڽ��� body�� ����ϴ� ���
	auto it = find(snakebody.begin(), snakebody.end(), movePos);
	if (it != snakebody.end()) {
		isDead = true;
		return;
	}

	//���� ����ϴ� ���
	if (movePos.first == 0 || movePos.first == MAP_XSIZE || movePos.second == 0 || movePos.second == MAP_YSIZE) {
		isDead = true;
		return;
	}

	snakebody.push_front(movePos);
	snakebody.pop_back();
	preHead = nowHead;
	nowHead = movePos;

	//Poison item ���� ���
	vector<pair<int, int>> poison = itemManager->getPoison();
	vector<pair<int, int>> grow = itemManager->getGrow();
	vector<pair<int,int>>::iterator it1 = find(poison.begin(), poison.end(), movePos);
	vector<pair<int, int>>::iterator it2 = find(grow.begin(), grow.end(), movePos);
	if (it1!=poison.end()) {
		snakebody.pop_back();
		used_poison++;
	}
	else if (it2!=grow.end()) {
		//grow item���� ��� 
		switch (nowDirection) {
		case KEY_UP:
			snakebody.push_front({ nowHead.first - 1, nowHead.second });
			break;
		case KEY_DOWN:
			snakebody.push_front({ nowHead.first +1, nowHead.second });
			break;
		case KEY_LEFT:
			snakebody.push_front({ nowHead.first , nowHead.second-1 });
			break;
		case KEY_RIGHT:
			snakebody.push_front({ nowHead.first , nowHead.second+1 });
			break;
		}

		preHead = nowHead;
		nowHead = snakebody.front();
		used_grow++;
	}


	//���� ���̰� 2������ ��� 
	if (snakebody.size() <= 2) {
		isDead = true;
		return;
	}

	

}

void SnakeBody::draw() {
	deque<pair<int, int>>::iterator it = snakebody.begin();
	for (it ; it != snakebody.end(); it++) {
		if (it == snakebody.begin()) {
			mvaddch(it->first, it->second, '#' | COLOR_PAIR(1));
		}
		mvprintw(it->first, it->second, "#");
	}
}