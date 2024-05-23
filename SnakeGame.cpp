#include "SnakeGame.h"


SnakeGame::SnakeGame() {
	
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

	start_color();
	
	WINDOW* w1 = printMissionBoard();
	WINDOW* w2 = printScoreBoard();
	wrefresh(w1);
	wrefresh(w2);
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

		
		Sleep(5);
		werase(stdscr);
		
	}

	endwin();
}


WINDOW * SnakeGame::printMissionBoard() {
	WINDOW* win = newwin(30, 20, 0, 50);
	for (int i = 0; i < 20; i++) {
		int j = 0;
		for ( j = 0; j < 30; j++) {
			if (i == 0 || i == 19 || j == 0 || j == 28) {
				mvwprintw(win, i, j, "X");
			}
		}
		
	}
	

	return win;
}
WINDOW * SnakeGame::printScoreBoard() {

	WINDOW* win = newwin(30, 20, 20, 50);
	box(win,0,0);
	return win;
}