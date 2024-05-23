#include "GameItem.h"
#include <cstdlib>
#include <ctime>
#include <curses.h>
#include <algorithm>
#define MAP_XSIZE 45
#define MAP_YSIZE 22



void GameItem::generateItem(SnakeBody * snake) {
	//�� ��� ��ﶧ���� �������� ��ġ�� ��� �ٲ�����
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

	int itemSize; //grow,poison item � ������ ����
	itemSize = 20;//rand() % 2 + 2; //�ּ� 2������ 3������ 

	for (int i = 0; i < itemSize; i++) {
		int whatItem; //���� ������ ������� 0�̸� grow, 1�̸� trim
		int idx; //������ ������ �� �ִ� ĭ�� ��� ��ġ �� �����ϰ� �̾Ƽ� �ش��ϴ� ĭ�� ������ ����
		whatItem = rand() % 2;
		idx = rand() % possible.size();
		if (whatItem) {
			//1�� ���
			while (find(poison.begin(), poison.end(), possible[idx]) != poison.end() && find(grow.begin(),grow.end(), possible[idx])!=grow.end()) {
				//���� �ߺ��� �ִٸ�
				idx = rand() % possible.size();
			}
			poison.push_back(possible[idx]);
		}
		else {
			//0�� ��� 
			//�̶� �������� �ߺ��� �� �ֱ⿡ �ߺ������ϴ� while������
			while (find(poison.begin(), poison.end(), possible[idx]) != poison.end() && find(grow.begin(), grow.end(), possible[idx]) != grow.end()) {
				//���� �ߺ��� �ִٸ�
				idx = rand() % possible.size();
			}
			//�������´ٸ� �̹� ������ ������ ��ǥ�� �ٸ� ��
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


