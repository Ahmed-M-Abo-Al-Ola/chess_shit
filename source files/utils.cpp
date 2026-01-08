#include "..\header files\utils.h"
#include <string>
#include <iostream>
using namespace std;

int utils::square_name_to_square_index(const string& name)
{
    return (name[0] - 'a') + (8 - (name[1] - '0')) * 8;
}


void utils::print_board(const string& board)
{
    string result = "  " + string(49, '-') + "\n";
    string row;
    for (int i = 0; i < 8; i++)
    {
        row = to_string(8-i) + " |";
        for (int j = 0; j < 8; j++)
        {
            row += "  " + string(1, board[(i*8)+j]) + "  |";
        }
        row += "\n";
        result += row;
        result += "  " + string(49, '-') + "\n";
    }
    result += "     a     b     c     d     e     f     g     h\n";
    cout << result;
}