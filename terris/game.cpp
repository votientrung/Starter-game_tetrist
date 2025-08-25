#include "game.h"
#include <random>
#include <time.h>

game::game()
{
    Grid =grid();
    blocks = getallblocks();
    bcurrent=getrandomBlock();
    bnext= getrandomBlock();
    gameover= false;
    score=0;

}

Block game::getrandomBlock()
{   
    if (blocks.empty())
    {
        blocks= getallblocks();
    }
    int randomindex= rand() % blocks.size();
    Block block = blocks[randomindex];
    blocks.erase(blocks.begin()+randomindex);
    return block;
}

vector<Block> game::getallblocks()
{
    return {Iblock(), Jblock(), Lblock(), Oblock(), Sblock(), Zblock(), Tblock()};
}

void game::draw()
{
    Grid.draw();
    bcurrent.draw(11,11);
    bnext.draw(356,383);
}

void game::handleinput()
{
    int keypress = GetKeyPressed();
    if (gameover && keypress !=0)
    {
        gameover=false;
        reset();
    }
    switch(keypress)
    {
        case KEY_LEFT:moveblockleft();
        break;
        case KEY_RIGHT:moveblockright();
        break;
        case KEY_DOWN:moveblockdown();
        break;
        case KEY_UP: rotateblock();
        break;
    }
}

void game::moveblockleft()
{
    if (!gameover)
    {
        bcurrent.move(0,-1);
        if (checkborrder() || blockfit()==false)
        {
            bcurrent.move(0,1);
        }
    }
}

void game::moveblockright()
{
    if (!gameover)
    {
        bcurrent.move(0,1);
        if (checkborrder() || blockfit()==false)
        {
            bcurrent.move(0,-1);
        }
    }
}

void game::moveblockdown()
{
    if (!gameover)
    {
        bcurrent.move(1,0);
        if (checkborrder() || blockfit()==false)
        {
            bcurrent.move(-1,0);
            lockblock();
            Grid.clearfullrow();
        }
    }

}

bool game::checkborrder()
{
    vector<position> tiles= bcurrent.getcellposition();
    for (position item: tiles)
    {
        if (Grid.borrder(item.row,item.col))
        {
            return true;
        }
    }
    return false;
}

void game::rotateblock()
{
    if (!gameover)
    {
        bcurrent.rotate();
        if (checkborrder())
        {
            bcurrent.undorotate();
        }
    }
}

void game::lockblock()
{
    vector<position> tiles =bcurrent.getcellposition();
    for (position item:tiles)
    {
        Grid.Grid[item.row][item.col] = bcurrent.id;
    }
    bcurrent=bnext;
    if (blockfit()==false)
    {
        gameover=true;
    }
    bnext=getrandomBlock();
    int rowclear = Grid.clearfullrow();
    scoreupdate(rowclear,1);
}

bool game::blockfit()
{
    vector<position> tiles = bcurrent.getcellposition();
    for (position item:tiles)
    {
        if (Grid.checkcell(item.row,item.col) == false)
        {
            return false;
        }
    }
    return true;
}

void game::reset()
{
    Grid.initialize();
    blocks =  getallblocks();
    bnext = getrandomBlock();
}

void game::scoreupdate(int lineclear, int movedownpoint)
{
    switch (lineclear)
    {
    case 1:
        score+=100;
        break;
    case 2:
        score+=300;
        break;
    case 3:
        score+=500;
        break; 
    default:
        break;
    }
    score+=movedownpoint;
}
