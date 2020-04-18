//
// Created by kolane on 2020/4/18.
//
#include <string>
#include <iostream>
#include <fstream>

#include "reversi.h"

using namespace std;

void Board::InitBoard(const string& filename)
{
    ifstream in(filename);

    for (auto & i : board_)
    {
        for (char & j : i)
        {
            in >> j;
        }
    }
    in.close();
}

void Board::ShowBoard()
{
    for (auto & i : board_)
    {
        for (char j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

bool Board::IsRight(int x, int y)
{
    int tx = x, ty = y+1, step = 0;    //tx,ty分别用来表示右方向各点在数组中的索引
    bool is_play = false;            //初始化为不能吃子,表示该方向不能下

    while(1)
    {
        if (tx > 9) break;             //处于边界，退出循环，该方向不能吃子
        if (board_[ty][tx] == 0) break;      //空子，退出循环，该方向不能吃子
        if (board_[ty][tx] != 'B') step++;    //（tx,ty）所在的方格上的棋不一样，step加1，有连续step个对方的棋子与（x，y）上的棋相邻
        else
        {
            if(step>0) is_play = true;
            break;
        }    // （tx,ty）所在的方格上的棋一样，同时在(tx,ty)和(x,y)之间如果有连续step个对方的棋子，则表示该方向上可以吃子，修改is_play状态。
        tx++;
    }

//    CanPlayPointSet.insert((x, y));
    return is_play;
}

bool Board::IsLeft(int x, int y)
{
    int tx = x, ty = y-1, step = 0;
    bool is_play = false;

    while(1)
    {
        if (tx < 0) break;
        if (board_[tx][tx] == 0) break;
        if (board_[ty][tx] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx--;
    }

    return is_play;
}

bool Board::IsUp(int x, int y)
{
    int tx = x-1, ty = y, step = 0;
    bool is_play = false;

    while(1)
    {
        if (tx < 0) break;
        if (board_[tx][ty] == 0) break;
        if (board_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx--;
    }

    return is_play;
}

bool Board::IsDown(int x, int y)
{
    int tx = x+1, ty = y, step = 0;
    bool is_play = false;

    while(1)
    {
        if (ty < 0) break;
        if (board_[tx][ty] == 0) break;
        if (board_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx++;
    }

    return is_play;
}

bool Board::IsRightUp(int x, int y)
{
    int tx = x-1, ty = y+1, step = 0;
    bool is_play = false;

    while(1)
    {
        if (tx < 0 || ty > MAX_SIZE) break;
        if (board_[tx][ty] == 0) break;
        if (board_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx--;
        ty++;
    }

    return is_play;
}

bool Board::IsRightDown(int x, int y)
{
    int tx = x+1, ty = y+1, step = 0;
    bool is_play = false;

    while(1)
    {
        if (tx > MAX_SIZE || ty > MAX_SIZE) break;
        if (board_[tx][ty] == 0) break;
        if (board_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx++;
        ty++;
    }

    return is_play;
}

bool Board::IsLeftUp(int x, int y)
{
    int tx = x-1, ty = y-1, step = 0;
    bool is_play = false;

    while(1)
    {
        if (tx < 0 || ty < 0) break;
        if (board_[tx][ty] == 0) break;
        if (board_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx--;
        ty--;
    }

    return is_play;
}

bool Board::IsLeftDown(int x, int y)
{
    int tx = x+1, ty = y-1, step = 0;
    bool is_play = false;

    while(1)
    {
        if (tx > MAX_SIZE || ty < 0) break;
        if (board_[tx][ty] == 0) break;
        if (board_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx++;
        ty--;
    }

    return is_play;
}


