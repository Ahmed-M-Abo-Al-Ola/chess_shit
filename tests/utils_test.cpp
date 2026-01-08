#include "..\header files\utils.h"
#include <string>
#include <cassert>
#include <iostream>

int main(int argc, char const *argv[])
{
    assert(utils::square_name_to_square_index("a8") == 0);
    
    assert(utils::square_name_to_square_index("b8") == 1);

    assert(utils::square_name_to_square_index("a7") == 8);

    assert(utils::square_name_to_square_index("b7") == 9);

    cout << "utils::square_name_to_square_index() works properly." << endl;

    return 0;
}

