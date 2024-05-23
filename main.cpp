#include "SnakeGame.h"
#include <iostream>
#include <cstdlib>
#include "Windows.h"

using namespace std;

int main() {
	int playGame=0; //게임 실행횟수
	SnakeGame* game = new SnakeGame;
	game->gameStart();
	while (game->gameStart() == true) {
		playGame++;
		delete game;
		
		printf("미션 성공! 다음 라운드 곧바로 시작");
		cin.ignore();
		system("cls");
		game = new SnakeGame();
		if (playGame == 5) {
			break;
		}
	}

	
}