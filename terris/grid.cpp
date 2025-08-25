#include "grid.h"
#include <iostream>
#include <color.h>

using namespace std;

grid::grid()
{
    numrows = 20;
    numcols = 10;
    cellsize = 40;
    initialize();
    colors = getcellcolor();
}

void grid::initialize()
{
    for (int row=0; row<numrows; row++)
    {
        for (int col=0; col<numcols; col++)
        {
            Grid[row][col] = 0;
        }


    }
}

void grid::print()
{
    for (int row=0; row<numrows; row++)
    {
        for (int col=0; col<numcols; col++)
        {
            cout<< Grid[row][col]<<" ";
        }
        cout<<endl;
    }
}


void grid::draw()
{
    for (int row=0; row<numrows; row++)
    {
        for (int col=0; col<numcols; col++)
        {
            int cellvalue = Grid[row][col];
            DrawRectangle(col*cellsize+11, row*cellsize+11, cellsize-1, cellsize-1, colors[cellvalue]);            
        }
        
    }
}

bool grid::borrder(int row, int col)
{
    if (row>=0 && row< numrows && col>=0 && col< numcols)
    {
        return false;
    }
    return true;

}

bool grid::checkcell(int row, int col)
{
    if (Grid[row][col]==0)
    return true;
    else return false;
}

int grid::clearfullrow()
{
    int complete=0;
    for (int row=numrows-1; row>=0; row--)
    {
        if (fullrow(row))
        {
            clear(row);
            complete++;
        }
        else if (complete>0)
        {
            moverowdown(row,complete);
        }
    }
    return complete;
}

bool grid::fullrow(int row)
{
    for (int col=0; col<numcols; col++)
    {
        if(Grid[row][col]==0)
        return false;
    }
    return true;
}

void grid::clear(int row)
{
     for (int col=0; col<numcols; col++)
    {
        Grid[row][col]=0;
    }
}

void grid::moverowdown(int row, int numrows)
{
    for (int col=0; col<numcols ; col++)
    {
        Grid[row+numrows][col]=Grid[row][col];
        Grid[row][col]=0;
    }
}
