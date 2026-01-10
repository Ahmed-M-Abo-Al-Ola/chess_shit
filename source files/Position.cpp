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


vector<Move> Position::find_rook_moves(const int& index) const
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


vector<Move> Position::find_bishop_moves(const int& index) const
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


vector<Move> Position::find_queen_moves(const int& index) const
{
    vector<Move> generated_moves = find_rook_moves(index);
    vector<Move> diagonal_moves = find_bishop_moves(index);
    generated_moves.insert(generated_moves.end(), diagonal_moves.begin(), diagonal_moves.end());
    return generated_moves;
}


vector<Move> Position::find_knight_moves(const int& index) const
{
    vector<Move> generated_moves;

    // look for the right two moves
    if (utils::is_on_g_file(index) == false && utils::is_on_h_file(index) == false)
    {
        // look for the top move
        if (utils::is_on_eighth_rank(index) == false && 
            (board[index-6] == '.' || isupper(board[index-6]) != isupper(board[index])))
        {
            generated_moves.push_back(Move(index, index-6));
        }

        // look for the bottom move
        if (utils::is_on_first_rank(index) == false && 
            (board[index+10] == '.' || isupper(board[index+10]) != isupper(board[index])))
        {
            generated_moves.push_back(Move(index, index+10));
        }
    }

    // look for the left two moves
    if (utils::is_on_a_file(index) == false && utils::is_on_b_file(index) == false)
    {
        // look for the top move
        if (utils::is_on_eighth_rank(index) == false && 
            (board[index-10] == '.' || isupper(board[index-10]) != isupper(board[index])))
        {
            generated_moves.push_back(Move(index, index-10));
        }

        // look for the bottom move
        if (utils::is_on_first_rank(index) == false && 
            (board[index+6] == '.' || isupper(board[index+6]) != isupper(board[index])))
        {
            generated_moves.push_back(Move(index, index+6));
        }
    }

    // look for the top two moves
    if (utils::is_on_seventh_rank(index) == false && utils::is_on_eighth_rank(index) == false)
    {
        // look for the right move
        if (utils::is_on_h_file(index) == false && 
            (board[index-15] == '.' || isupper(board[index-15]) != isupper(board[index])))
        {
            generated_moves.push_back(Move(index, index-15));
        }

        // look for the left move
        if (utils::is_on_a_file(index) == false && 
            (board[index-17] == '.' || isupper(board[index-17]) != isupper(board[index])))
        {
            generated_moves.push_back(Move(index, index-17));
        }
    }

    // look for the bottom two moves
    if (utils::is_on_first_rank(index) == false && utils::is_on_second_rank(index) == false)
    {
        // look for the right move
        if (utils::is_on_h_file(index) == false && 
            (board[index+17] == '.' || isupper(board[index+17]) != isupper(board[index])))
        {
            generated_moves.push_back(Move(index, index+17));
        }

        // look for the left move
        if (utils::is_on_a_file(index) == false && 
            (board[index+15] == '.' || isupper(board[index+15]) != isupper(board[index])))
        {
            generated_moves.push_back(Move(index, index+15));
        }
    }

    return generated_moves;
}


vector<Move> Position::find_pawn_moves(const int& index) const
{
    if (isupper(board[index]) == true)
    {
        return find_white_pawn_moves(index);
    }
    else
    {
        return find_black_pawn_moves(index);
    }
}


vector<Move> Position::find_white_pawn_moves(const int& index) const
{
    vector<Move> generated_moves;

    // find single moves
    if (board[index-8] == '.')
    {
        if (utils::is_on_eighth_rank(index-8) == true)
        {
            generated_moves.push_back(Move(index, index-8, 'Q'));
            generated_moves.push_back(Move(index, index-8, 'N'));
            generated_moves.push_back(Move(index, index-8, 'R'));
            generated_moves.push_back(Move(index, index-8, 'B'));
        }
        else
        {
            generated_moves.push_back(Move(index, index-8));
        }

        // find double moves
        if (utils::is_on_second_rank(index) == true && board[index-16] == '.')
        {
            generated_moves.push_back(Move(index, index-16));
        }
    }

    // find captures
    if (board[index-7] != '.' && isupper(board[index-7]) != true)
    {
        if (utils::is_on_eighth_rank(index-7) == true)
        {
            generated_moves.push_back(Move(index, index-7, 'Q'));
            generated_moves.push_back(Move(index, index-7, 'N'));
            generated_moves.push_back(Move(index, index-7, 'R'));
            generated_moves.push_back(Move(index, index-7, 'B'));
        }
        else
        {
            generated_moves.push_back(Move(index, index-7));
        }   
    }

    if (board[index-9] != '.' && isupper(board[index-9]) != true)
    {
        if (utils::is_on_eighth_rank(index-9) == true)
        {
            generated_moves.push_back(Move(index, index-9, 'Q'));
            generated_moves.push_back(Move(index, index-9, 'N'));
            generated_moves.push_back(Move(index, index-9, 'R'));
            generated_moves.push_back(Move(index, index-9, 'B'));
        }
        else
        {
            generated_moves.push_back(Move(index, index-9));
        }   
    }

    // check for en passant
    if (enPassantSquare != -1 && utils::is_on_sixth_rank(enPassantSquare) && 
        (index-7 == enPassantSquare || index-9 == enPassantSquare))
    {
        generated_moves.push_back(Move(index, enPassantSquare, 'E'));
    }

    return generated_moves;
}


vector<Move> Position::find_black_pawn_moves(const int& index) const
{
        vector<Move> generated_moves;

    // find single moves
    if (board[index+8] == '.')
    {
        if (utils::is_on_first_rank(index+8) == true)
        {
            generated_moves.push_back(Move(index, index+8, 'q'));
            generated_moves.push_back(Move(index, index+8, 'n'));
            generated_moves.push_back(Move(index, index+8, 'r'));
            generated_moves.push_back(Move(index, index+8, 'b'));
        }
        else
        {
            generated_moves.push_back(Move(index, index+8));
        }

        // find double moves
        if (utils::is_on_seventh_rank(index) == true && board[index+16] == '.')
        {
            generated_moves.push_back(Move(index, index+16));
        }
    }

    // find captures
    if (board[index+9] != '.' && isupper(board[index+9]) != false)
    {
        if (utils::is_on_first_rank(index+9) == true)
        {
            generated_moves.push_back(Move(index, index+9, 'q'));
            generated_moves.push_back(Move(index, index+9, 'n'));
            generated_moves.push_back(Move(index, index+9, 'r'));
            generated_moves.push_back(Move(index, index+9, 'b'));
        }
        else
        {
            generated_moves.push_back(Move(index, index+9));
        }   
    }

    if (board[index+7] != '.' && isupper(board[index+7]) != false)
    {
        if (utils::is_on_first_rank(index+7) == true)
        {
            generated_moves.push_back(Move(index, index+7, 'q'));
            generated_moves.push_back(Move(index, index+7, 'n'));
            generated_moves.push_back(Move(index, index+7, 'r'));
            generated_moves.push_back(Move(index, index+7, 'b'));
        }
        else
        {
            generated_moves.push_back(Move(index, index+7));
        }   
    }

    // check for en passant
    if (enPassantSquare != -1 && utils::is_on_third_rank(enPassantSquare) && 
        (index+7 == enPassantSquare || index+9 == enPassantSquare))
    {
        generated_moves.push_back(Move(index, enPassantSquare, 'e'));
    }

    return generated_moves;
}











