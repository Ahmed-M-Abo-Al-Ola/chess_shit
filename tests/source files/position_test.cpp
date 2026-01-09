#include "..\..\header files\Position.h"
#include "..\header files\position_test.h"
#include "..\..\header files\Move.h"
#include <cassert>
#include <vector>
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


void test_rook_move_generation()
{
    vector<Move> expected_moves;

    // test for open lines
    Position p1("8/8/8/4R3/8/8/8/8 w - - 0 1");
    expected_moves = {Move(28, 20), Move(28, 12), Move(28, 4), Move(28, 36), Move(28, 44),
        Move(28, 52), Move(28, 60), Move(28, 29), Move(28, 30), Move(28, 31), Move(28, 27),
        Move(28, 26), Move(28, 25), Move(28, 24)};
    assert(p1.find_rook_moves(28) == expected_moves);

    // test for blockage
    Position p2("8/8/4P3/3PRP2/4P3/8/8/8 w - - 0 1");
    expected_moves = {};
    assert(p2.find_rook_moves(28) == expected_moves);

    // test for open squares then blockage
    Position p3("8/4P3/8/2P1R1P1/8/4P3/8/8 w - - 0 1");
    expected_moves = {Move(28, 20), Move(28, 36), Move(28, 29), Move(28, 27)};
    assert(p3.find_rook_moves(28) == expected_moves);

    // test for enemy captures
    Position p4("8/4p3/8/2p1R1p1/8/4p3/8/8 w - - 0 1");
    expected_moves = {Move(28, 20), Move(28, 12), Move(28, 36), Move(28, 44), Move(28, 29),
        Move(28, 30), Move(28, 27), Move(28, 26)};
    assert(p4.find_rook_moves(28) == expected_moves);

    // test for edge placement (top and left edges)
    Position p5("R1P5/8/P7/8/8/8/8/8 w - - 0 1");
    expected_moves = {Move(0, 8), Move(0, 1)};
    assert(p5.find_rook_moves(0) == expected_moves);

    // test for edge placement (bottom and right edges)
    Position p6("8/8/8/8/8/7P/8/5P1R w - - 0 1");
    expected_moves = {Move(63, 55), Move(63, 62)};
    assert(p6.find_rook_moves(63) == expected_moves);

    cout << "Rook move generation works properly." << endl;
}


void test_bishop_move_generation()
{
    vector<Move> expected_moves;

    // test for open diagonals
    Position p1("8/8/8/4B3/8/8/8/8 w - - 0 1");
    expected_moves = {Move(28, 21), Move(28, 14), Move(28, 7), Move(28, 19), Move(28, 10),
        Move(28, 1), Move(28, 37), Move(28, 46), Move(28, 55), Move(28, 35), Move(28, 42),
        Move(28, 49), Move(28, 56)};
    assert(p1.find_bishop_moves(28) == expected_moves);

    // test for blockage
    Position p2("8/8/2P1P3/3B4/2P1P3/8/8/8 w - - 0 1");
    expected_moves = {};
    assert(p2.find_bishop_moves(27) == expected_moves);

    // test for open squares then blockage
    Position p3("8/1P3P2/8/3B4/8/1P3P2/8/8 w - - 0 1");
    expected_moves = {Move(27, 20), Move(27, 18), Move(27, 36), Move(27, 34)};
    assert(p3.find_bishop_moves(27) == expected_moves);

    // test for enemy captures
    Position p4("8/1p3p2/8/3B4/8/1p3p2/8/8 w - - 0 1");
    expected_moves = {Move(27, 20), Move(27, 13), Move(27, 18), Move(27, 9), Move(27, 36), 
        Move(27, 45), Move(27, 34), Move(27, 41)};
    assert(p4.find_bishop_moves(27) == expected_moves);

    // test for edge placement (top edge)
    Position p5("4B3/8/2P3P1/8/8/8/8/8 w - - 0 1");
    expected_moves = {Move(4, 13), Move(4, 11)};
    assert(p5.find_bishop_moves(4) == expected_moves);

    // test for edge placement (bottom edge)
    Position p6("8/8/8/8/8/2P3P1/8/4B3 w - - 0 1");
    expected_moves = {Move(60, 53), Move(60, 51)};
    assert(p6.find_bishop_moves(60) == expected_moves);

    // test for edge placement (right edge)
    Position p7("8/8/5P2/8/7B/8/5P2/8 w - - 0 1");
    expected_moves = {Move(39, 30), Move(39, 46)};
    assert(p7.find_bishop_moves(39) == expected_moves);

    // test for edge placement (left edge)
    Position p8("8/2P5/8/B7/8/2P5/8/8 w - - 0 1");
    expected_moves = {Move(24, 17), Move(24, 33)};
    assert(p8.find_bishop_moves(24) == expected_moves);
    
    cout << "The bishop move generation works properly." << endl;
}