#include "SnakeGame.h"
#include "Windows.h"

int SnakeGame::playGame = 0;

SnakeGame::SnakeGame() {
	
	map = new Map();
	player= new SnakeBody();
	//gate= new Gate();
	itemManager= new GameItem();
	playGame++;
	player->init();
	
}



SnakeGame::~SnakeGame() {
	delete player;
	delete map;
	//delete gate;
	delete itemManager;
}

bool SnakeGame::gameStart() {
	initscr();
	noecho(); //�Է°� �����
	curs_set(false); //Ŀ�� �����
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	getmaxyx(stdscr, max_xpos, max_ypos); //xpos, ypos�� ���� �࿭�� ��Ÿ�� ��ǥ�� �ƴ϶� �����ǥ���� ���� ���� ��ǥ
	

	start_color();
	init_color(1, 0, 1000, 0);
	init_color(2, 0, 0, 1000);
	init_pair(1, 1, 2);
	init_pair(2,2,1);

	int ch;
	while (1) {
		mvprintw(25,0,"===========================================ROUND %d===============================================", SnakeGame::playGame);
		map->draw();
		printMissionBoard();
		printStatusBoard();
		itemManager->generateItem(player);
		itemManager->draw();

		player->draw();
		ch = getch();
		if (ch != ERR) {
			player->move(ch, itemManager);
			if (player->isDead == true) {
				endwin();
				return false;
			}
		}
		if (isSuccess()) {
			endwin();
			return true;
		}
		Sleep(5);
		
		refresh();
		
		werase(stdscr);
		
	}

	endwin();
}

bool SnakeGame::isSuccess() {
	if (/*SnakeBody::used_gate == player->maxGate  &&*/ player->successLength==true &&\
		SnakeBody::used_grow >= player->maxGrowth && SnakeBody::used_poison >= player->maxPoison) {
		return true;
	}
	else {
		return false;
	}
}



void SnakeGame::printStatusBoard() {
	//��ü ���� �������� 23,46��

	//���� �� ���� �ϱ⶧���� ������ �ݹݾ�
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

void SnakeGame::printMissionBoard() {

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
	if (SnakeBody::successLength) {
		addstr("( V )");
	}
	else if (player->snakebody.size() == player->maxLength) {
		addstr("( V )");
		SnakeBody::successLength = true;
	}
	else {
		addstr("(   )");
	}
	mvaddstr(14, 50, "+: ");
	printw("%-3d", player->maxGrowth);
	if (SnakeBody::used_grow>=player->maxGrowth) {
		//��ǥ ���� �޼��ߴٸ� �� ���ķδ� ��� ��ǥ�޼��ߴٰ� üũǥ��
		addstr("( V )");
	}
	else {
		addstr("(   )");
	}
	mvaddstr(15, 50, "-: ");
	printw("%-3d", player->maxPoison);
	if (SnakeBody::used_poison>= player->maxPoison) {
		addstr("( V )");
	}
	else {
		addstr("(   )");
	}
	mvaddstr(16, 50, "G: ");
	printw("%-3d", player->maxGate);
	if (SnakeBody::used_gate >= player->maxGate) {
		addstr("( V )");
	}
	else {
		addstr("(   )");
	}
	
	
}