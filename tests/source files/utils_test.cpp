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

