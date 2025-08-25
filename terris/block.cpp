#include "block.h"

Block::Block()
{
    cellsize=40;
    rotationstate=0;
    colors= getcellcolor();
    rowoffset=0;
    coloffset=0;
}

void Block::draw(int offsetX, int offsetY)
{
    vector<position> tiles = getcellposition();
    for (position item: tiles)
    {
        DrawRectangle(item.col*cellsize+offsetX, item.row*cellsize+offsetY, cellsize-1,cellsize-1, colors[id]);
    }
}

void Block::move(int rows, int cols)
{
    rowoffset+=rows;
    coloffset+=cols;
}

vector<position> Block::getcellposition()
{
    vector<position> tiles = cells[rotationstate];
    vector<position> movedtiles;
    for (position item: tiles)
    {
        position newpos = position(item.row+rowoffset, item.col+coloffset);
        movedtiles.push_back(newpos);
    }
    return movedtiles;
}

void Block::rotate()
{
    rotationstate++;
    if (rotationstate == (int)cells.size())
    {
        rotationstate=0;
    }
}

void Block::undorotate()
{
    rotationstate--;
    if (rotationstate==-1) 
    {
        rotationstate= cells.size()-1;
    }
}
