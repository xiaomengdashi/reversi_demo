#include <reversi.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    string filename = "../../file/init5.txt";
    if (argv[1])
        filename = argv[1];
    Chess chess(filename);
//    chess.ShowChess();
    chess.IsCanPlayChess();
    chess.ReverseChess();

    return 0;
}