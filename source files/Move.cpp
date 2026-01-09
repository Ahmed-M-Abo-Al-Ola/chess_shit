#include "..\header files\Move.h"

Move::Move(int initial_square, int terminal_square, char special_move)
{
    this->initialSquare = initial_square;
    this->terminalSquare = terminal_square;
    this->specialMove = special_move;
}


bool Move::operator==(const Move& another) const
{
    return this->initialSquare == another.initialSquare &&
        this->terminalSquare == another.terminalSquare &&
        this->specialMove == another.specialMove;
}


int Move::get_initial_square() const
{
    return initialSquare;
}


int Move::get_terminal_square() const
{
    return terminalSquare;
}


