#include "..\..\header files\utils.h"
#include "..\header files\utils_test.h"
#include <cassert>
#include <iostream>
using namespace std;

void test_utils_square_name_to_square_index()
{
    assert(utils::square_name_to_square_index("a8") == 0);
    
    assert(utils::square_name_to_square_index("b8") == 1);

    assert(utils::square_name_to_square_index("a7") == 8);

    assert(utils::square_name_to_square_index("b7") == 9);

    cout << "utils::square_name_to_square_index() works properly." << endl;
}


void test_square_positions_functions()
{
    // test is_on_first_rank()
    assert(utils::is_on_first_rank(56) == true);
    assert(utils::is_on_first_rank(60) == true);
    assert(utils::is_on_first_rank(63) == true);
    assert(utils::is_on_first_rank(50) == false);

    // test is_on_second_rank()
    assert(utils::is_on_second_rank(48) == true);
    assert(utils::is_on_second_rank(50) == true);
    assert(utils::is_on_second_rank(55) == true);
    assert(utils::is_on_second_rank(20) == false);

    // test is_on_third_rank()
    assert(utils::is_on_third_rank(40) == true);
    assert(utils::is_on_third_rank(45) == true);
    assert(utils::is_on_third_rank(47) == true);
    assert(utils::is_on_third_rank(1) == false);

    // test is_on_forth_rank()
    assert(utils::is_on_forth_rank(32) == true);
    assert(utils::is_on_forth_rank(33) == true);
    assert(utils::is_on_forth_rank(39) == true);
    assert(utils::is_on_forth_rank(10) == false);

    // test is_on_fifth_rank()
    assert(utils::is_on_fifth_rank(24) == true);
    assert(utils::is_on_fifth_rank(27) == true);
    assert(utils::is_on_fifth_rank(31) == true);
    assert(utils::is_on_fifth_rank(23) == false);

    // test is_on_sixth_rank()
    assert(utils::is_on_sixth_rank(16) == true);
    assert(utils::is_on_sixth_rank(20) == true);
    assert(utils::is_on_sixth_rank(23) == true);
    assert(utils::is_on_sixth_rank(63) == false);

    // test is_on_seventh_rank()
    assert(utils::is_on_seventh_rank(8) == true);
    assert(utils::is_on_seventh_rank(11) == true);
    assert(utils::is_on_seventh_rank(15) == true);
    assert(utils::is_on_seventh_rank(36) == false);

    // test is_on_eighth_rank()
    assert(utils::is_on_eighth_rank(0) == true);
    assert(utils::is_on_eighth_rank(5) == true);
    assert(utils::is_on_eighth_rank(7) == true);
    assert(utils::is_on_eighth_rank(8) == false);

    // test is_on_a_file()
    assert(utils::is_on_a_file(0) == true);
    assert(utils::is_on_a_file(48) == true);
    assert(utils::is_on_a_file(56) == true);
    assert(utils::is_on_a_file(11) == false);

    // test is_on_b_file()
    assert(utils::is_on_b_file(1) == true);
    assert(utils::is_on_b_file(17) == true);
    assert(utils::is_on_b_file(49) == true);
    assert(utils::is_on_b_file(15) == false);

    // test is_on_g_file()
    assert(utils::is_on_g_file(6) == true);
    assert(utils::is_on_g_file(14) == true);
    assert(utils::is_on_g_file(62) == true);
    assert(utils::is_on_g_file(11) == false);

    // test is_on_h_file()
    assert(utils::is_on_h_file(7) == true);
    assert(utils::is_on_h_file(15) == true);
    assert(utils::is_on_h_file(63) == true);
    assert(utils::is_on_h_file(14) == false);

    cout << "The square position functions work properly." << endl;
}

