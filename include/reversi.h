//
// Created by kolane on 2020/4/18.
//

#ifndef REVERSI_DEMO_REVERSI_H
#define REVERSI_DEMO_REVERSI_H

#include <string>
#include <set>

#define MAX_SIZE 8
using namespace std;

class Board
{
public:
    void InitBoard(const string& filename);
    int IsCanPlay(int x, int y);   // 该点8个方向能下棋的个数
    void ShowBoard();

public:
    // // 从该点上下左右边判断是否能下
    bool IsRight(int x, int y);    //  右
    bool IsLeft(int x, int y);
    bool IsUp(int x, int y);
    bool IsDown(int x, int y);

    // // 从该点各斜边方向判断是否能下
    bool IsRightUp(int x, int y);
    bool IsRightDown(int x, int y);
    bool IsLeftUp(int x, int y);
    bool IsLeftDown(int x, int y);

private:
    char board_[MAX_SIZE][MAX_SIZE] = {" "};
    set <int> CanPlayPointSet;
};


#endif //REVERSI_DEMO_REVERSI_H
