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
	noecho(); //�Է°� �����
	curs_set(false); //Ŀ�� �����
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
