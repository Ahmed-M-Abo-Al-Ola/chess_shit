class Move {
    private:
        int initialSquare;
        int terminalSquare;
        char specialMove;
    public:
        Move(int initial_square, int terminal_square, char special_move = '-');
};