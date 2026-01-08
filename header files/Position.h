# pragma once
#include <string>
using namespace std;

class Position {
    private:
        string board;
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
};