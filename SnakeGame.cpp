#include "SnakeGame.h"


SnakeGame::SnakeGame() {
	gameDelay = 2;
	
	map = new Map();
	player= new SnakeBody();
	//gate= new Gate();
	itemManager= new GameItem();
	

}

SnakeGame::~SnakeGame() {
	delete player;
	delete map;
	//delete gate;
	delete itemManager;
}

void SnakeGame::gameStart() {
	initscr();
	noecho(); //입력값 숨기기
	curs_set(false); //커서 숨기기
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	int ch;
	while (1) {
		
		
		map->draw();
		itemManager->generateItem(player);
		player->draw();
		ch = getch();
		if (ch != ERR) {
			player->move(ch, itemManager);
			if (player->isDead == true) {
				break;
			}
		}

		refresh();

		Sleep(gameDelay);
		clear();
	}

	endwin();
}
