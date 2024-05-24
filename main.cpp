#include "SnakeGame.h"
#include <iostream>
#include <cstdlib>
#include "Windows.h"

using namespace std;

int main() {
	int playGame=0; //게임 실행횟수(총 5라운드로 구성)
	
	while (playGame<=5) {
		playGame++;
		SnakeGame* game = new SnakeGame();
		
		if (game->gameStart() == true) {
			delete game;
			printf("미션 성공! 다음 라운드 곧바로 시작");
			cin.ignore();
			system("cls");
		}
		else {
			delete game;
			printf("미션 실패! 재도전하세요!");
			cin.ignore();
			break;
		}
	}

	return 0;
	
}