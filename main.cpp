#include "SnakeGame.h"
#include <iostream>
#include <cstdlib>
#include "Windows.h"

using namespace std;

int main() {
	int playGame=0; //���� ����Ƚ��(�� 5����� ����)
	
	while (playGame<=5) {
		playGame++;
		SnakeGame* game = new SnakeGame();
		
		if (game->gameStart() == true) {
			delete game;
			printf("�̼� ����! ���� ���� ��ٷ� ����");
			cin.ignore();
			system("cls");
		}
		else {
			delete game;
			printf("�̼� ����! �絵���ϼ���!");
			cin.ignore();
			break;
		}
	}

	return 0;
	
}