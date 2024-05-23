#include "SnakeGame.h"
#include "Windows.h"

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

	getmaxyx(stdscr, max_xpos, max_ypos); //xpos, ypos는 각각 행열로 나타낸 좌표가 아니라 평면좌표에서 봤을 때의 좌표
	

	start_color();

	int ch;
	while (1) {
		
		map->draw();
		printMissionBoard();
		printStatusBoard();
		itemManager->generateItem(player);
		
		player->draw();
		ch = getch();
		if (ch != ERR) {
			player->move(ch, itemManager);
			if (player->isDead == true) {
				break;
			}
		}
		if (isSuccess()) {
			clear();
			finish();
		}
		Sleep(5);
		
		refresh();
		
		werase(stdscr);
		
	}

	endwin();
}

bool SnakeGame::isSuccess() {
	if (SnakeBody::used_gate == player->maxGate && SnakeBody::used_poison == player->maxPoison &&
		SnakeBody::used_grow == player->maxGrowth && SnakeBody::used_grow == player->maxGrowth) {
		return true;
	}
	else {
		return false;
	}
}

void SnakeGame::finish() {
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 | 15 << 4); //fg: blue, bg: white
		printf("SUCCESS!");
	}
}

void SnakeGame::printMissionBoard() {
	//전체 게임 보드판이 23,46임

	//판을 두 개로 하기때문에 사이즈 반반씩
	for (int r = 0; r < 7; r++) {
		for (int c = 48; c < 70; c++) {
			if (r == 0 || r == 6) {
				mvprintw(r, c, "*");
			}
			else if (c == 48 || c == 69) {
				mvprintw(r, c, "*");
			}
		}
	}

	mvaddstr(1, 50, "Score Board");
	mvaddstr(2, 50, "B: ");
	printw("%d / %d", player->snakebody.size(),player->maxLength );
	mvaddstr(3, 50, "+: ");
	printw("%d", player->used_grow);
	mvaddstr(4, 50, "-: ");
	printw("%d", player->used_poison);
	mvaddstr(5, 50, "G: ");
	printw("%d", player->used_gate);
}

void SnakeGame::printStatusBoard() {

	for (int r = 11; r < 18; r++) {
		for (int c = 48; c < 70; c++) {
			if (r == 11 || r == 17) {
				mvprintw(r, c, "*");
			}
			else if (c == 48 || c == 69) {
				mvprintw(r, c, "*");
			}
		}
	}

	mvaddstr(12, 50, "Mission");
	mvaddstr(13, 50, "B: ");
	printw("%-3d", player->maxLength);
	if (player->snakebody.size() == player->maxLength) {
		addstr("( V )");
	}
	else {
		addstr("(   )");
	}
	mvaddstr(14, 50, "+: ");
	printw("%-3d", player->maxGrowth);
	if (SnakeBody::used_grow == player->maxGrowth) {
		addstr("( V )");
	}
	else {
		addstr("(   )");
	}
	mvaddstr(15, 50, "-: ");
	printw("%-3d", player->maxPoison);
	if (SnakeBody::used_poison== player->maxPoison) {
		addstr("( V )");
	}
	else {
		addstr("(   )");
	}
	mvaddstr(16, 50, "G: ");
	printw("%-3d", player->maxGate);
	if (SnakeBody::used_gate == player->maxGate) {
		addstr("( V )");
	}
	else {
		addstr("(   )");
	}
	
	
}