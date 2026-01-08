#include "..\header files\utils.h"
#include <string>

int utils::square_name_to_square_index(const string& name)
{
    return (name[0] - 'a') + (8 - (name[1] - '0')) * 8;
}