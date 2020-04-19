//
// Created by kolane on 2020/4/19.
//

#include "gtest/gtest.h"
#include "reversi.h"
using namespace std;

TEST(REVERSERIGHT, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ(chess.GetPointState(4,5), "W");
    chess.ReverseRight(4,4);
    EXPECT_EQ(chess.GetPointState(4,5), "B");
}

TEST(REVERSEUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ(chess.GetPointState(3,4), "W");
    chess.ReverseUp(4,4);
    EXPECT_EQ(chess.GetPointState(3,4), "B");
}

TEST(REVERSELEFT, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ(chess.GetPointState(4,3), "W");
    chess.ReverseLeft(4,4);
    EXPECT_EQ(chess.GetPointState(4,3), "B");
}

TEST(REVERSEDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ(chess.GetPointState(5,4), "W");
    chess.ReverseDown(4,4);
    EXPECT_EQ(chess.GetPointState(5,4), "B");
}

TEST(REVERSERIGHTUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ(chess.GetPointState(3,5), "W");
    chess.ReverseRightUp(4,4);
    EXPECT_EQ(chess.GetPointState(3,5), "B");
}

TEST(REVERSERIGHTDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ(chess.GetPointState(5,5), "W");
    chess.ReverseRightDown(4,4);
    EXPECT_EQ(chess.GetPointState(5,5), "B");
}

TEST(REVERSELEFTUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ(chess.GetPointState(3,3), "W");
    chess.ReverseLeftUp(4,4);
    EXPECT_EQ(chess.GetPointState(3,3), "B");
}

TEST(REVERSELEFTDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ(chess.GetPointState(5,3), "W");
    chess.ReverseLeftDown(4,4);
    EXPECT_EQ(chess.GetPointState(5,3), "B");
}