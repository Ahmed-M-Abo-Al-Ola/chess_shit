# pragma once
#include "Move.h"
#include <string>
#include <vector>
using namespace std;

class Position {
    private:
        string board;
        vector<Move> legalMoves;
        bool turn;
        bool whiteKingSideCastlingRight;
        bool whiteQueenSideCastlingRight;
        bool blackKingSideCastlingRight;
        bool blackQueenSideCastlingRight;
        int enPassantSquare;
        int halfMoves;
        int fullMoves;

    public:
        Position (const string& new_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        string get_board() const;
        bool get_turn() const;
        bool get_white_king_side_castling_right() const;
        bool get_white_queen_side_castling_right() const;
        bool get_black_king_side_castling_right() const;
        bool get_black_queen_side_castling_right() const;
        int get_en_passant_square() const;
        int get_half_moves() const;
        int get_full_moves() const;
        vector<Move> find_rook_moves(const int& index);
        vector<Move> find_bishop_moves(const int& index);
        vector<Move> find_queen_moves(const int& index);
};