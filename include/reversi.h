//
// Created by kolane on 2020/4/18.
//

#ifndef REVERSI_DEMO_REVERSI_H
#define REVERSI_DEMO_REVERSI_H

#include <string>
#include <set>

#define MAX_SIZE 8

class Chess
{
public:
    Chess();
    Chess(std::string& filename);
    void ShowChess();

    bool IsCanPlayPoint(int x, int y);   // 点(x,y)8个方向是否能落子
    void ReversePoint(int x, int y);     // 翻转点(x,y)各方向的对方棋子
    bool IsCanPlayChess();
    void ReverseChess();
    std::string GetPointState(int x, int y);

public:
    // 从点(x,y)上下左右及斜边方向判断是否能落子
    bool IsRight(int x, int y);
    bool IsLeft(int x, int y);
    bool IsUp(int x, int y);
    bool IsDown(int x, int y);
    bool IsRightUp(int x, int y);
    bool IsRightDown(int x, int y);
    bool IsLeftUp(int x, int y);
    bool IsLeftDown(int x, int y);

public:
    // 根据点(x,y)各方向，吃对方的棋子
    void ReverseRight(int x, int y);
    void ReverseLeft(int x, int y);
    void ReverseUp(int x, int y);
    void ReverseDown(int x, int y);
    void ReverseRightUp(int x, int y);
    void ReverseRightDown(int x, int y);
    void ReverseLeftUp(int x, int y);
    void ReverseLeftDown(int x, int y);

private:
    std::string LocationToString(int x, int y);  // 坐标(x,y)转化成字符串: (1,2)--> "12"

private:
    char chess_[MAX_SIZE][MAX_SIZE] = {0};
    std::set <std::string> can_reverse_point_set_;   // 可以落子的位置点的集合
    int direction_[MAX_SIZE][MAX_SIZE][MAX_SIZE]={0};  // 8*8个点的8个方向能否落子的数组，第三个参数从逆时针方向分别为0~7
};
#endif //REVERSI_DEMO_REVERSI_H
