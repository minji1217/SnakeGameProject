#include "Map.h"


Map::Map():BoardxSize(46),BoardySize(23),window_xSize(70),window_ySize(50) {
}

void Map::draw() {

	for (int i = 0; i < BoardySize; i++) {
		for (int j = 0; j < BoardxSize; j++) {
			if (i == 0 || i == BoardySize - 1) {
				mvprintw(i, j, "X");
			}
			else if (j == 0 || j == BoardxSize - 1) {
				mvprintw(i, j, "X");
			}
		}
	}


	
	
}