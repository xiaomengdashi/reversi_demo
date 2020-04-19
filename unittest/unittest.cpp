#include "gtest/gtest.h"
#include "reversi.h"

TEST(ISRIGHT, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init.txt";
    Chess chess;
    chess.InitBoard(filename);
    EXPECT_EQ( chess.IsRight(3,2), true);
}

TEST(ISLEFT, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init.txt";
    Chess chess;
    chess.InitBoard(filename);
    EXPECT_EQ( chess.IsLeft(4,5), true);
}

TEST(ISUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init.txt";
    Chess chess;
    chess.InitBoard(filename);
    EXPECT_EQ( chess.IsUp(5,4), true);
}

TEST(ISDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init.txt";
    Chess chess;
    chess.InitBoard(filename);
    EXPECT_EQ( chess.IsDown(2,3), true);
}

TEST(ISRIGHTUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init2.txt";
    Chess chess;
    chess.InitBoard(filename);
    EXPECT_EQ( chess.IsRightUp(5,2), true);
}

TEST(ISRIGHTDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init2.txt";
    Chess chess;
    chess.InitBoard(filename);
    EXPECT_EQ( chess.IsRightDown(3,2), true);
}

TEST(ISLEFTUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init2.txt";
    Chess chess;
    chess.InitBoard(filename);
    EXPECT_EQ( chess.IsLeftUp(2,3), true);
}

TEST(ISLEFTDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init2.txt";
    Chess chess;
    chess.InitBoard(filename);
    EXPECT_EQ( chess.IsLeftDown(0,3), true);
}