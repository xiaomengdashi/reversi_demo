#include "gtest/gtest.h"
#include "reversi.h"

TEST(ISRIGHT, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init.txt";
    Board board;
    board.InitBoard(filename);
    EXPECT_EQ( board.IsRight(3,2), true);
}

TEST(ISLEFT, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init.txt";
    Board board;
    board.InitBoard(filename);
    EXPECT_EQ( board.IsLeft(4,5), true);
}

TEST(ISUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init.txt";
    Board board;
    board.InitBoard(filename);
    EXPECT_EQ( board.IsUp(5,4), true);
}

TEST(ISDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init.txt";
    Board board;
    board.InitBoard(filename);
    EXPECT_EQ( board.IsDown(2,3), true);
}

TEST(ISRIGHTUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init2.txt";
    Board board;
    board.InitBoard(filename);
    EXPECT_EQ( board.IsRightUp(5,2), true);
}

TEST(ISRIGHTDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init2.txt";
    Board board;
    board.InitBoard(filename);
    EXPECT_EQ( board.IsRightDown(3,2), true);
}

TEST(ISLEFTUP, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init2.txt";
    Board board;
    board.InitBoard(filename);
    EXPECT_EQ( board.IsLeftUp(2,3), true);
}

TEST(ISLEFTDOWN, TRUE)
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init2.txt";
    Board board;
    board.InitBoard(filename);
    EXPECT_EQ( board.IsLeftDown(0,3), true);
}