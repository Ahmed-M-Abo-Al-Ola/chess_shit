#include "..\header files\Position.h"
#include <string>
#include <sstream>
#include <cctype>


Position::Position(const string& new_fen)
{
    stringstream ss;
    ss << new_fen;
    string new_board;
    char new_turn;
    string castling_rights;
    string new_enpassant_square;
    int new_half_moves;
    int new_full_moves;

    ss >> new_board;
    ss >> new_turn;
    ss >> castling_rights;
    ss >> new_enpassant_square;
    ss >> new_half_moves;
    ss >> new_full_moves;

    int current_square_index = 0;
    for (char c: new_board)
    {
        if (c == '//') {continue;}
        if (isdigit(c) == true)
        {
            current_square_index += c - '0';
            continue;
        }
        board[current_square_index] = c;
        current_square_index++;
    }

    turn = new_turn == 'w';

    whiteKingSideCastlingRight = whiteQueenSideCastlingRight = blackKingSideCastlingRight = blackQueenSideCastlingRight = false;
    for (char c: castling_rights)
    {
        switch (c)
        {
        case 'K':
            whiteKingSideCastlingRight = true;
            break;

        case 'k':
            blackKingSideCastlingRight = true;
            break;
        
        case 'Q':
            whiteQueenSideCastlingRight = true;
            break;

        case 'q':
            blackQueenSideCastlingRight = true;
            break;
        }
    }
    
}