#pragma once
#include <curses.h>
#include "DrawInter.h"

class Map : public DrawInter {
public:
	Map();
	void draw();

private:
	int BoardxSize;
	int BoardySize;
	int window_xSize;
	int window_ySize;
};