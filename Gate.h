#pragma once
#include "DrawInter.h"
#include <utility>
#include "Map.h"

class Gate : public DrawInter {
public:
    Gate();
    void draw() override;
    void generate();
    pair<int, int> gate1;
    pair<int, int> gate2;

private:
    int gate1X, gate1Y, gate2X, gate2Y;
    int BoardxSize, BoardySize;
};
