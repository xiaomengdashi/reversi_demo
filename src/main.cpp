#include <reversi.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init5.txt";
    Chess chess(filename);
//    chess.ShowChess();
    chess.IsCanPlayChess();
    chess.ReverseChess();

    return 0;
}