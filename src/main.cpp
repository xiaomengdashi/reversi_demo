#include <reversi.h>
#include <string>
#include <iostream>
using namespace std;

int main(int   argc, char*   argv[])
{
//    string filename = "/Users/kolane/Desktop/CLionProjects/reversi_demo/file/init5.txt";
    string filename = argv[1];
    Chess chess(filename);
//    chess.ShowChess();
    chess.IsCanPlayChess();
    chess.ReverseChess();

    return 0;
}