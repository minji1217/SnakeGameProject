#include "Gate.h"
#include <vector>
#include <iostream>
#include <utility>
#include "SnakeBody.h"
#include "Gate.h"
#include <cstdlib>
#include <iostream>


Gate::Gate() : BoardxSize(46), BoardySize(23) {
    generate();
}

void Gate::generate() {
    gate1.first = rand() % BoardxSize;
    gate1.second = rand() % BoardySize;
    gate2.first = rand() % BoardxSize;
    gate2.first = rand() % BoardySize;

    // Ensure gates do not overlap with each other
    while (gate1X == gate2X && gate1Y == gate2Y) {
        gate1X = rand() % BoardxSize;
        gate1Y = rand() % BoardySize;
        gate2X = rand() % BoardxSize;
        gate2Y = rand() % BoardySize;
    }
}

void Gate::draw() {

    for (it; it != snakebody.end(); it++) {
        if (it == snakebody.begin()) {
            mvaddch(it->first, it->second, ' ' | COLOR_PAIR(3));
        }
        else {
            mvaddch(it->first, it->second, ' ' | COLOR_PAIR(3));
        }
    }
}
