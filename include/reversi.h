//
// Created by kolane on 2020/4/18.
//

#ifndef REVERSI_DEMO_REVERSI_H
#define REVERSI_DEMO_REVERSI_H

#include <string>
#include <set>

#define MAX_SIZE 8
using namespace std;

class Chess
{
public:
    void InitBoard(const string& filename);
    void IsCanPlay();
    void ShowBoard();
    void ReverseBoard();

public:
    bool IsCanPlayPoint(int x, int y);   // 该点8个方向能下棋的个数
    void ReversePoint(int x, int y);     //

    // 从该点上下左右边判断是否能下
    bool IsRight(int x, int y);    //  右
    bool IsLeft(int x, int y);
    bool IsUp(int x, int y);
    bool IsDown(int x, int y);

    // 从该点各斜边方向判断是否能下
    bool IsRightUp(int x, int y);
    bool IsRightDown(int x, int y);
    bool IsLeftUp(int x, int y);
    bool IsLeftDown(int x, int y);

private:
    // 反转该点的某一方向
    void ReverseRight(int x, int y);
    void ReverseLeft(int x, int y);
    void ReverseUp(int x, int y);
    void ReverseDown(int x, int y);
    void ReverseRightUp(int x, int y);
    void ReverseRightDown(int x, int y);
    void ReverseLeftUp(int x, int y);
    void ReverseLeftDown(int x, int y);

private:
    string InsertPoint(int x, int y);

private:
    char chess_[MAX_SIZE][MAX_SIZE] = {0};
    set <string> can_reverse_point_set_;   // 可以落子的点的集合
    int direction_[MAX_SIZE][MAX_SIZE][MAX_SIZE]={0};  // 64个点的8个方向判断
};
#endif //REVERSI_DEMO_REVERSI_H
