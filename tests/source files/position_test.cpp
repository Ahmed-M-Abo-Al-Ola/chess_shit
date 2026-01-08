#include "..\..\header files\Position.h"
#include "..\header files\position_test.h"
#include <cassert>
#include <iostream>
using namespace std;

void test_position_constructor()
{
    // test default position
    Position p1;
    assert(p1.get_board() == "rnbqkbnrpppppppp................................PPPPPPPPRNBQKBNR");
    assert(p1.get_turn() == true);
    assert(p1.get_white_king_side_castling_right() == true);
    assert(p1.get_white_queen_side_castling_right() == true);
    assert(p1.get_black_king_side_castling_right() == true);
    assert(p1.get_black_queen_side_castling_right() == true);
    assert(p1.get_en_passant_square() == -1);
    assert(p1.get_half_moves() == 0);
    assert(p1.get_full_moves() == 1);

    // test a random position
    Position p2("r2q2kr/pp1nbppp/2np1n2/2pPp3/2P1P3/2N2N2/PP1BBPPP/R2Q1RK1 b KQk c3 28 14");
    assert(p2.get_board() == "r..q..krpp.nbppp..np.n....pPp.....P.P.....N..N..PP.BBPPPR..Q.RK.");
    assert(p2.get_turn() == false);
    assert(p2.get_white_king_side_castling_right() == true);
    assert(p2.get_white_queen_side_castling_right() == true);
    assert(p2.get_black_king_side_castling_right() == true);
    assert(p2.get_black_queen_side_castling_right() == false);
    assert(p2.get_en_passant_square() == 42);
    assert(p2.get_half_moves() == 28);
    assert(p2.get_full_moves() == 14);

    cout << "The position constructor works properly." << endl;
}
