#include "SnakeBody.h"
#include "GameItem.h"
#include <curses.h>


SnakeBody::SnakeBody():isDead(false) {
	preHead = make_pair(10, 11);
	nowHead = make_pair(10, 10);
	snakebody.push_back({10,10});
	snakebody.push_back({ 10,11 });
	snakebody.push_back({ 10,12 });
	nowDirection = KEY_LEFT;
}



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
	//Tail방향으로 이동 시 실패 
	if (movePos == preHead) {
		isDead = true;
		return;
	}
	//자신의 body를 통과하는 경우
	auto it = find(snakebody.begin(), snakebody.end(), movePos);
	if (it != snakebody.end()) {
		isDead = true;
		return;
	}

	//벽을 통과하는 경우
	if (movePos.first == 0 || movePos.first == MAP_XSIZE || movePos.second == 0 || movePos.second == MAP_YSIZE) {
		isDead = true;
		return;
	}

	snakebody.push_front(movePos);
	snakebody.pop_back();
	preHead = nowHead;
	nowHead = movePos;

	//Poison item 먹은 경우
	auto it1 = find(itemManager->getPoison().begin(), itemManager->getPoison().end(), movePos);
	auto it2 = find(itemManager->getGrow().begin(), itemManager->getGrow().end(), movePos);
	if (it1!=itemManager->getPoison().end()) {
		snakebody.pop_back();
		GameItem::used_poison++;
	}
	//Grow item 먹은 경우
	
	else if (it2!=itemManager->getGrow().end()) {
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
		GameItem::used_grow++;
	}


	//뱀의 길이가 2이하인 경우 
	if (snakebody.size() <= 2) {
		isDead = true;
		return;
	}

	

}

void SnakeBody::draw() {
	deque<pair<int, int>>::iterator it = snakebody.begin();
	for (it ; it != snakebody.end(); it++) {
		mvprintw(it->first, it->second, "#");
	}
}