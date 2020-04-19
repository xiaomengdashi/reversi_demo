#include <reversi.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init5.txt";
    Chess chess;
    chess.InitBoard(filename);
    chess.IsCanPlay();
//    chess.IsCanPlayPoint(4,4);
//    chess.ReversePoint(4,4);
    chess.ReverseBoard();

    return 0;
}