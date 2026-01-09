#pragma once

class Move {
    private:
        int initialSquare;
        int terminalSquare;
        char specialMove;
    public:
        Move(int initial_square, int terminal_square, char special_move = '-');
        bool operator==(const Move& another) const;
        int get_initial_square() const;
        int get_terminal_square() const;
};