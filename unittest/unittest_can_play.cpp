#include "gtest/gtest.h"
#include "reversi.h"
using namespace std;

TEST(ISRIGHT, TRUE)
{
    string filename = "../../file/init.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsRight(3,2), true);
}

TEST(ISLEFT, TRUE)
{
    string filename = "../../file/init.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsLeft(4,5), true);
}

TEST(ISUP, TRUE)
{
    string filename = "../../file/init.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsUp(5,4), true);
}

TEST(ISDOWN, TRUE)
{
    string filename = "../../file/init.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsDown(2,3), true);
}

TEST(ISRIGHTUP, TRUE)
{
    string filename = "../../file/init2.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsRightUp(5,2), true);
}

TEST(ISRIGHTDOWN, TRUE)
{
    string filename = "../../file/init2.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsRightDown(3,2), true);
}

TEST(ISLEFTUP, TRUE)
{
    string filename = "../../file/init2.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsLeftUp(2,3), true);
}

TEST(ISLEFTDOWN, TRUE)
{
    string filename = "../../file/init2.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsLeftDown(0,3), true);
}

TEST(ISCANPLAYPOINT, TRUE)
{
    string filename = "../../file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsCanPlayPoint(4,4), true);
}

TEST(ISCANPLAY, TRUE)
{
    string filename = "../../file/init3.txt";
    Chess chess(filename);
    EXPECT_EQ( chess.IsCanPlayChess(), true);
}