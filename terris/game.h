#pragma once
#include "grid.h"
#include "blocks.cpp"

using namespace std;

class game
{
public:
    game();
    Block getrandomBlock();
    vector<Block> getallblocks();
    void draw();
    void handleinput();
    void moveblockleft();
    void moveblockright();
    void moveblockdown();
    bool gameover;
    grid Grid;
    int score;

private:
    bool checkborrder();
    void rotateblock();
    void lockblock();
    bool blockfit();
    void reset();
    void scoreupdate(int lineclear, int movedownpoint);
    vector<Block> blocks;
    Block bcurrent;
    Block bnext; 
};