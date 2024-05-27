#pragma once
#include "DrawInter.h"
#include "Map.h"

class Gate : public DrawInter {
public:
    Gate(int BoardxSize, int BoardySize);
    void draw() override;
    void generate();
    int getX1() const;
    int getY1() const;
    int getX2() const;
    int getY2() const;

private:
    int gate1X, gate1Y, gate2X, gate2Y;
    int BoardxSize, BoardySize;
};
