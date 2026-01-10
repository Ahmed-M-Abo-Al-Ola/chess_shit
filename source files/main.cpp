#include "..\tests\header files\position_test.h"
#include "..\tests\header files\utils_test.h"
#include "..\header files\Position.h"
#include "..\header files\utils.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    test_utils_square_name_to_square_index();
    test_position_constructor();
    test_square_positions_functions();
    test_rook_move_generation();
    test_bishop_move_generation();
    test_knight_move_generation();
    test_pawn_move_generation();
    test_king_move_generation();
    return 0;
}
