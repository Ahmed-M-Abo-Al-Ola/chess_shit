#include "..\header files\Position.h"
#include "..\header files\utils.h"
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <iostream>


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

    for (char c: new_board)
    {
        if (c == '/')
        {
            continue;
        }
        if (isdigit(c) == true)
        {
            board += string(c-'0', '.');

            continue;
        }
        board += c;
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
    
    if (new_enpassant_square != "-")
    {
        enPassantSquare = utils::square_name_to_square_index(new_enpassant_square);
    }
    else
    {
        enPassantSquare = -1;
    }

    halfMoves = new_half_moves;

    fullMoves = new_full_moves;
}


string Position::get_board() const
{
    return board;
}


bool Position::get_turn() const
{
    return turn;
}


bool Position::get_white_king_side_castling_right() const
{
    return whiteKingSideCastlingRight;
}


bool Position::get_white_queen_side_castling_right() const
{
    return whiteQueenSideCastlingRight;
}


bool Position::get_black_king_side_castling_right() const
{
    return blackKingSideCastlingRight;
}


bool Position::get_black_queen_side_castling_right() const
{
    return blackQueenSideCastlingRight;
}


int Position::get_en_passant_square() const
{
    return enPassantSquare;
}


int Position::get_half_moves() const
{
    return halfMoves;
}


int Position::get_full_moves() const
{
    return fullMoves;
}

