#include "SnakeGame.h"
#include <iostream>
#include <cstdlib>
#include "Windows.h"

using namespace std;

int main() {
	int playGame=0; //���� ����Ƚ��
	SnakeGame* game = new SnakeGame;
	game->gameStart();
	while (game->gameStart() == true) {
		playGame++;
		delete game;
		
		printf("�̼� ����! ���� ���� ��ٷ� ����");
		cin.ignore();
		system("cls");
		game = new SnakeGame();
		if (playGame == 5) {
			break;
		}
	}

	
}