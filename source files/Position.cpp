#include "..\header files\Position.h"
#include "..\header files\utils.h"
#include "..\header files\Move.h"
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <iostream>
#include <algorithm>


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


vector<Move> Position::find_rook_moves(const int& index)
{
    vector<Move> generated_moves;
    int current_index;

    // look upwards
    if (utils::is_on_eighth_rank(index) == false)
    {
        current_index = index - 8;
        while(true)
        {
            if (board[current_index] == '.')
            {
                generated_moves.push_back(Move(index, current_index));
                if (utils::is_on_eighth_rank(current_index) == true)
                {
                    break;
                }
                current_index -= 8;
                continue;
            }
            if (isupper(board[current_index]) != isupper(board[index]))
            {
                generated_moves.push_back(Move(index, current_index));
            }
            break;
        }
    }

    // look downwards
    if (utils::is_on_first_rank(index) == false)
    {
        current_index = index + 8;
        while(true)
        {
            if (board[current_index] == '.')
            {
                generated_moves.push_back(Move(index, current_index));
                if (utils::is_on_first_rank(current_index) == true)
                {
                    break;
                }
                current_index += 8;
                continue;
            }
            if (isupper(board[current_index]) != isupper(board[index]))
            {
                generated_moves.push_back(Move(index, current_index));
            }
            break;
        }
    }

    // look rightwards
    if (utils::is_on_h_file(index) == false)
    {
        current_index = index + 1;
        while(true)
        {
            if (board[current_index] == '.')
            {
                generated_moves.push_back(Move(index, current_index));
                if (utils::is_on_h_file(current_index) == true)
                {
                    break;
                }
                current_index++;
                continue;
            }
            if (isupper(board[current_index]) != isupper(board[index]))
            {
                generated_moves.push_back(Move(index, current_index));
            }
            break;
        }
    }

    // look leftwards
    if (utils::is_on_a_file(index) == false)
    {
        current_index = index - 1;
        while(true)
        {
            if (board[current_index] == '.')
            {
                generated_moves.push_back(Move(index, current_index));
                if (utils::is_on_a_file(current_index) == true)
                {
                    break;
                }
                current_index--;
                continue;
            }
            if (isupper(board[current_index]) != isupper(board[index]))
            {
                generated_moves.push_back(Move(index, current_index));
            }
            break;
        }
    }

    return generated_moves;
}


vector<Move> Position::find_bishop_moves(const int& index)
{
    vector<Move> generated_moves;
    int current_square;

    // look upwards to the right
    if (utils::is_on_eighth_rank(index) == false && utils::is_on_h_file(index) == false)
    {
        current_square = index - 7;
        while(true)
        {
            if (board[current_square] == '.')
            {
                generated_moves.push_back(Move(index, current_square));
                if (utils::is_on_eighth_rank(current_square) == true || utils::is_on_h_file(current_square) == true)
                {
                    break;
                }
                current_square -= 7;
                continue;
            }

            if (isupper(board[current_square]) != isupper(board[index]))
            {
                generated_moves.push_back(Move(index, current_square));
            }
            break;
        }
    }

    // look upwards to the left
    if (utils::is_on_eighth_rank(index) == false && utils::is_on_a_file(index) == false)
    {
        current_square = index - 9;
        while(true)
        {
            if (board[current_square] == '.')
            {
                generated_moves.push_back(Move(index, current_square));
                if (utils::is_on_eighth_rank(current_square) == true || utils::is_on_a_file(current_square) == true)
                {
                    break;
                }
                current_square -= 9;
                continue;
            }

            if (isupper(board[current_square]) != isupper(board[index]))
            {
                generated_moves.push_back(Move(index, current_square));
            }
            break;
        }
    }

    // look downwards to the right
    if (utils::is_on_first_rank(index) == false && utils::is_on_h_file(index) == false)
    {
        current_square = index + 9;
        while(true)
        {
            if (board[current_square] == '.')
            {
                generated_moves.push_back(Move(index, current_square));
                if (utils::is_on_first_rank(current_square) == true || utils::is_on_h_file(current_square) == true)
                {
                    break;
                }
                current_square += 9;
                continue;
            }

            if (isupper(board[current_square]) != isupper(board[index]))
            {
                generated_moves.push_back(Move(index, current_square));
            }
            break;
        }
    }

    // look downwards to the left
    if (utils::is_on_first_rank(index) == false && utils::is_on_a_file(index) == false)
    {
        current_square = index + 7;
        while(true)
        {
            if (board[current_square] == '.')
            {
                generated_moves.push_back(Move(index, current_square));
                if (utils::is_on_first_rank(current_square) == true || utils::is_on_a_file(current_square) == true)
                {
                    break;
                }
                current_square += 7;
                continue;
            }

            if (isupper(board[current_square]) != isupper(board[index]))
            {
                generated_moves.push_back(Move(index, current_square));
            }
            break;
        }
    }

    return generated_moves;
}


vector<Move> Position::find_queen_moves(const int& index)
{
    vector<Move> generated_moves = find_rook_moves(index);
    vector<Move> diagonal_moves = find_bishop_moves(index);
    generated_moves.insert(generated_moves.end(), diagonal_moves.begin(), diagonal_moves.end());
    return generated_moves;
}



