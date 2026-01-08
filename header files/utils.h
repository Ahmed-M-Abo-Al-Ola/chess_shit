#pragma once
#include <string>
using namespace std;

namespace utils {
    int square_name_to_square_index(const string& name);
    void print_board(const string& board);
    bool is_on_first_rank(const int& indix);
    bool is_on_second_rank(const int& indix);
    bool is_on_third_rank(const int& indix);
    bool is_on_forth_rank(const int& indix);
    bool is_on_fifth_rank(const int& indix);
    bool is_on_sixth_rank(const int& indix);
    bool is_on_seventh_rank(const int& indix);
    bool is_on_eighth_rank(const int& indix);
    bool is_on_a_file(const int& indix);
    bool is_on_b_file(const int& indix);
    bool is_on_g_file(const int& indix);
    bool is_on_h_file(const int& indix);
}