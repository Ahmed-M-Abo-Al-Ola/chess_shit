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


bool utils::is_on_first_rank(const int& indix)
{
    return 8 - indix / 8 == 1;
}


bool utils::is_on_second_rank(const int& indix)
{
    return 8 - indix / 8 == 2;
}


bool utils::is_on_third_rank(const int& indix)
{
    return 8 - indix / 8 == 3;
}


bool utils::is_on_forth_rank(const int& indix)
{
    return 8 - indix / 8 == 4;
}


bool utils::is_on_fifth_rank(const int& indix)
{
    return 8 - indix / 8 == 5;
}


bool utils::is_on_sixth_rank(const int& indix)
{
    return 8 - indix / 8 == 6;
}


bool utils::is_on_seventh_rank(const int& indix)
{
    return 8 - indix / 8 == 7;
}


bool utils::is_on_eighth_rank(const int& indix)
{
    return 8 - indix / 8 == 8;
}


bool utils::is_on_a_file(const int& indix)
{
    return indix % 8 == 0;
}


bool utils::is_on_h_file(const int& indix)
{
    return indix % 8 == 7;
}


bool utils::is_on_b_file(const int& indix)
{
    return indix % 8 == 1;
}


bool utils::is_on_g_file(const int& indix)
{
    return indix % 8 == 6;
}
