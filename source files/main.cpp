#include "..\tests\header files\position_test.h"
#include "..\tests\header files\utils_test.h"
#include "..\header files\Position.h"
#include "..\header files\utils.h"
using namespace std;

int main(int argc, char const *argv[])
{
    test_utils_square_name_to_square_index();
    test_position_constructor();
    Position p("r2q2kr/pp1nbppp/2np1n2/2pPp3/2P1P3/2N2N2/PP1BBPPP/R2Q1RK1 b KQk c3 28 14");
    utils::print_board(p.get_board());
    return 0;
}
