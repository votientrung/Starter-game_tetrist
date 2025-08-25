#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "color.h"

using namespace std;

class Block
{
public:
    Block();
    void draw(int offsetX, int offsetY);
    void move(int rows, int cols);
    vector<position> getcellposition();
    void rotate();
    void undorotate();
    int id;
    map<int, vector<position>> cells;
private:
    int cellsize;
    int rotationstate;
    vector<Color> colors;
    int rowoffset;
    int coloffset;
};