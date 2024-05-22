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
};