#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <utility>
#include <deque>
#include "DrawInter.h"

using namespace std;


class Wall:public DrawInter
{
private:
	deque <pair<int, int>> wall;

public:
	void init();
	void draw();
	void makeWall();
	
};

