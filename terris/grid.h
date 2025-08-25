#pragma once
#include <vector>
#include <raylib.h>

using namespace std;

class grid
{
    public:
        grid();
        void initialize();
        void print();
        void draw();
        bool borrder(int row, int col);
        bool checkcell(int row, int col);
        int clearfullrow();
        int Grid[20][10];
    private:
        bool fullrow(int row);
        void clear(int row);
        void moverowdown(int row, int numrows);
        int numrows;
        int numcols;
        int cellsize;
        vector<Color> colors;
};