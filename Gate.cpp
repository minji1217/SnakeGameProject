#include "Gate.h"
#include <cstdlib>
#include <iostream>

Gate::Gate(int BoardxSize, int BoardySize) : BoardxSize(BoardxSize), BoardySize(BoardySize) {
    generate();
}

void Gate::generate() {
    gate1X = rand() % BoardxSize;
    gate1Y = rand() % BoardySize;
    gate2X = rand() % BoardxSize;
    gate2Y = rand() % BoardySize;

    // Ensure gates do not overlap with each other
    while (gate1X == gate2X && gate1Y == gate2Y) {
        gate1X = rand() % BoardxSize;
        gate1Y = rand() % BoardySize;
        gate2X = rand() % BoardxSize;
        gate2Y = rand() % BoardySize;
    }
}

void Gate::draw() {
    std::cout << "Gate 1: (" << gate1X << ", " << gate1Y << ")\n";
    std::cout << "Gate 2: (" << gate2X << ", " << gate2Y << ")\n";
}

int Gate::getX1() const { return gate1X; }
int Gate::getY1() const { return gate1Y; }
int Gate::getX2() const { return gate2X; }
int Gate::getY2() const { return gate2Y; }
