//
// Created by kolane on 2020/4/18.
//
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "reversi.h"

using namespace std;


Chess::Chess()= default;

Chess::Chess(std::string &filename)
{
    ifstream in(filename);

    for (auto & i : chess_)
    {
        for (char & j : i)
        {
            in >> j;
        }
    }
    in.close();
}

void Chess::ShowChess()
{
    for (int i=0; i < MAX_SIZE; i++)
    {
        cout << "=";
    }
    cout << endl;
    for (auto & i : chess_)
    {
        for (char j : i)
        {
            cout << j;
        }
        cout << endl;
    }
}

string Chess::LocationToString(int x, int y)
{
    return to_string(x) + to_string(y);
}

bool Chess::IsRight(int x, int y)
{
    int tx = x, ty = y+1, step = 0;    //tx,ty分别用来表示右方向各点在数组中的索引
    bool is_play = false;            //初始化为不能吃子,表示该方向不能下

    while(true)
    {
        if (ty > 9) break;             //处于边界，退出循环，该方向不能吃子
        if (chess_[tx][ty] == '0') break;      //空子，退出循环，该方向不能吃子
        if (chess_[tx][ty] != 'B') step++;    //（tx,ty）所在的方格上的棋不一样，step加1，有连续step个对方的棋子与（x，y）上的棋相邻
        else
        {
            if(step>0) is_play = true;
            break;
        }    // （tx,ty）所在的方格上的棋一样，同时在(tx,ty)和(x,y)之间如果有连续step个对方的棋子，则表示该方向上可以吃子，修改is_play状态。
        ty++;
    }

    if (is_play)
    {
        direction_[x][y][0] = 1;
        can_reverse_point_set_.insert(this->LocationToString(x, y));
    }
    return is_play;
}

bool Chess::IsLeft(int x, int y)
{
    int tx = x, ty = y-1, step = 0;
    bool is_play = false;

    while(true)
    {
        if (ty < 0) break;
        if (chess_[tx][ty] == '0') break;
        if (chess_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        ty--;
    }

    if (is_play)
    {
        can_reverse_point_set_.insert(this->LocationToString(x, y));
        direction_[x][y][4] = 1;
    }
    return is_play;
}

bool Chess::IsUp(int x, int y)
{
    int tx = x-1, ty = y, step = 0;
    bool is_play = false;

    while(true)
    {
        if (tx < 0) break;
        if (chess_[tx][ty] == '0') break;
        if (chess_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx--;
    }

    if (is_play)
    {
        direction_[x][y][2] = 1;
        can_reverse_point_set_.insert(this->LocationToString(x, y));
    }

    return is_play;
}

bool Chess::IsDown(int x, int y)
{
    int tx = x+1, ty = y, step = 0;
    bool is_play = false;

    while(true)
    {
        if (tx > MAX_SIZE-1) break;
        if (chess_[tx][ty] == '0') break;
        if (chess_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx++;
    }

    if (is_play)
    {
        can_reverse_point_set_.insert(this->LocationToString(x, y));
        direction_[x][y][6] = 1;
    }

    return is_play;
}

bool Chess::IsRightUp(int x, int y)
{
    int tx = x-1, ty = y+1, step = 0;
    bool is_play = false;

    while(true)
    {
        if (tx < 0 || ty > MAX_SIZE-1) break;
        if (chess_[tx][ty] == '0') break;
        if (chess_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx--;
        ty++;
    }

    if (is_play)
    {
        can_reverse_point_set_.insert(this->LocationToString(x, y));
        direction_[x][y][1] = 1;
    }
    return is_play;
}

bool Chess::IsRightDown(int x, int y)
{
    int tx = x+1, ty = y+1, step = 0;
    bool is_play = false;

    while(true)
    {
        if (tx > MAX_SIZE-1 || ty > MAX_SIZE-1) break;
        if (chess_[tx][ty] == '0') break;
        if (chess_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx++;
        ty++;
    }
    if (is_play)
    {
        can_reverse_point_set_.insert(this->LocationToString(x, y));
        direction_[x][y][7] = 1;
    }

    return is_play;
}

bool Chess::IsLeftUp(int x, int y)
{
    int tx = x-1, ty = y-1, step = 0;
    bool is_play = false;

    while(true)
    {
        if (tx < 0 || ty < 0) break;
        if (chess_[tx][ty] == '0') break;
        if (chess_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx--;
        ty--;
    }
    if (is_play)
    {
        can_reverse_point_set_.insert(this->LocationToString(x, y));
        direction_[x][y][3] = 1;
    }

    return is_play;
}

bool Chess::IsLeftDown(int x, int y)
{
    int tx = x+1, ty = y-1, step = 0;
    bool is_play = false;

    while(true)
    {
        if (tx > MAX_SIZE-1 || ty < 0) break;
        if (chess_[tx][ty] == '0') break;
        if (chess_[tx][ty] != 'B') step++;
        else
        {
            if (step > 0) is_play = true;
            break;
        }
        tx++;
        ty--;
    }
    if (is_play)
    {
        can_reverse_point_set_.insert(this->LocationToString(x, y));
        direction_[x][y][5] = 1;
    }

    return is_play;
}

bool Chess::IsCanPlayPoint(int x, int y)
{
    bool is_play = false;
    if ((IsRight(x, y))){direction_[x][y][0] = 1;is_play= true;}
    if ((IsRightUp(x, y))) {direction_[x][y][1] = 1;is_play= true;}
    if ((IsUp(x, y))) {direction_[x][y][2] = 1;is_play= true;}
    if ((IsLeftUp(x, y))) {direction_[x][y][3] = 1;is_play= true;}
    if ((IsLeft(x, y))) {direction_[x][y][4] = 1;is_play= true;}
    if ((IsLeftDown(x, y))) {direction_[x][y][5] = 1;is_play= true;}
    if ((IsDown(x, y))) {direction_[x][y][6] = 1;is_play= true;}
    if ((IsRightDown(x, y))) {direction_[x][y][7] = 1;is_play= true;}

    return is_play;
}

bool Chess::IsCanPlayChess()
{
    bool is_play = false;
    for (int i=0; i<MAX_SIZE; i++)
    {
        for (int j=0; j<MAX_SIZE; j++)
        {
            if (chess_[i][j] == '0')
            {
                if (this->IsCanPlayPoint(i,j))
                    is_play = true;
            }
        }
    }
    return is_play;
}

void Chess::ReverseRight(int x, int y)
{
    chess_[x][y] = 'B';
    int tx = x, ty = y+1;
    while(true)
    {
        if (chess_[tx][ty] != 'B')
        {
            chess_[tx][ty] = 'B';
            ty++;
        }
        else break;
    }
}

void Chess::ReverseLeft(int x, int y)
{
    chess_[x][y] = 'B';
    int tx = x, ty = y-1;
    while(true)
    {
        if (chess_[tx][ty] != 'B')
        {
            chess_[tx][ty] = 'B';
            ty--;
        }
        else break;
    }
}

void Chess::ReverseUp(int x, int y)
{
    chess_[x][y] = 'B';
    int tx = x-1, ty = y;
    while(true)
    {
        if (chess_[tx][ty] != 'B')
        {
            chess_[tx][ty] = 'B';
            tx--;
        }
        else break;
    }
}

void Chess::ReverseDown(int x, int y)
{
    chess_[x][y] = 'B';
    int tx = x+1, ty = y;
    while(true)
    {
        if (chess_[tx][ty] != 'B')
        {
            chess_[tx][ty] = 'B';
            tx++;
        }
        else break;
    }
}

void Chess::ReverseRightUp(int x, int y)
{
    chess_[x][y] = 'B';
    int tx = x-1, ty = y+1;
    while(true)
    {
        if (chess_[tx][ty] != 'B')
        {
            chess_[tx][ty] = 'B';
            tx--;
            ty++;
        }
        else break;
    }
}

void Chess::ReverseRightDown(int x, int y)
{
    chess_[x][y] = 'B';
    int tx = x+1, ty = y+1;
    while(true)
    {
        if (chess_[tx][ty] != 'B')
        {
            chess_[tx][ty] = 'B';
            tx++;
            ty++;
        }
        else break;
    }
}

void Chess::ReverseLeftUp(int x, int y)
{
    chess_[x][y] = 'B';
    int tx = x-1, ty = y-1;
    while(true)
    {
        if (chess_[tx][ty] != 'B')
        {
            chess_[tx][ty] = 'B';
            tx--;
            ty--;
        }
        else break;
    }
}

void Chess::ReverseLeftDown(int x, int y)
{
    chess_[x][y] = 'B';
    int tx = x+1, ty = y-1;
    while(true)
    {
        if (chess_[tx][ty] != 'B')
        {
            chess_[tx][ty] = 'B';
            tx++;
            ty--;
        }
        else break;
    }
}

void Chess::ReversePoint(int x, int y)
{
    chess_[x][y] = 'B';
    if (direction_[x][y][0]) ReverseRight(x, y);
    if (direction_[x][y][4]) ReverseLeft(x, y);
    if (direction_[x][y][2]) ReverseUp(x, y);
    if (direction_[x][y][6]) ReverseDown(x, y);
    if (direction_[x][y][1]) ReverseRightUp(x, y);
    if (direction_[x][y][7]) ReverseRightDown(x, y);
    if (direction_[x][y][3]) ReverseLeftUp(x, y);
    if (direction_[x][y][5]) ReverseLeftDown(x, y);
}

void Chess::ReverseChess()
{
    Chess chess2;
    for (int i=0;i<MAX_SIZE;i++)  // 备份棋盘位置
    {
        for (int j = 0; j < MAX_SIZE; ++j) {
            chess2.chess_[i][j] = this->chess_[i][j];
        }
    }

    set<string>::iterator it; //定义前向迭代器
    for(it=can_reverse_point_set_.begin();it!=can_reverse_point_set_.end();it++)
    {
        int location = std::atoi((*it).c_str());
        this->ReversePoint(location/10, location%10);
        this->ShowChess();

        ofstream out("../../file/final.txt", iostream::app);
        for (int i=0; i < MAX_SIZE; i++)
        {
            out << "=";
        }
        out << '\n';

        for (auto & ches : chess_)
        {
            for (char che : ches)
            {
                out << che;
            }
            out << '\n';
        }
        out.close();

        for (int i=0;i<MAX_SIZE;i++)  // 还原原棋盘位置
        {
            for (int j = 0; j < MAX_SIZE; ++j)
            {
                this->chess_[i][j] = chess2.chess_[i][j];
            }
        }
    }
}

std::string Chess::GetPointState(int x, int y)
{
    std::string state;
    if (chess_[x][y] == '0') state = "0";
    else if (chess_[x][y] == 'B') state = "B";
    else state = "W";

    return state;
}