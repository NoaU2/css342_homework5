#include <set>
#include "sudoku.h"

Sudoku::~Sudoku() {
    delete[] challenge;
}

bool Sudoku::solve() {

    return solve(0, 0);
}

bool Sudoku::solve(size_t row, size_t col) {

    //initial check to see if the problem has been solved
    if(row > 8 && col == 0){
        return true;
    }
    //keep going if the number is pre filled
    if(*challenge_board(row, col) != 0){
        if(col == 8){
            return solve((row + 1), 0);
        }
        else{
            return solve(row, (col + 1));
        }
    }
    else {
        std::set<int> candidates;
        for (int i = 0; i < SUDOKU_BOARD_SIZE; i++) {
            candidates.insert(i + 1);
        }
        //checks row and column for numbers
        for (int i = 0; i < SUDOKU_BOARD_SIZE; i++) {
            int *val = challenge_board(row, i);
            if (*val != 0) {
                candidates.erase(*val);
            }

            val = challenge_board(i, col);
            if (*val != 0) {
                candidates.erase(*val);
            }

        }
        //checks square for numbers
        size_t square_start_row = (row / 3) * 3;
        size_t square_start_col = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int *val = challenge_board(square_start_row + i, square_start_col + j);
                if (*val != 0) {
                    candidates.erase(*val);
                }
            }
        }
        //goes through the list of candidates and recursively check them
        for (int candidate: candidates) {
            set_board_val(row, col, candidate);
            bool foundSolution = false;
            if(col == 8){
                foundSolution = solve((row + 1), 0);
            }
            else{
                foundSolution = solve(row, (col + 1));
            }
            if (foundSolution) {
                return true;
            }
            set_board_val(row, col, 0);
        }
        //returns false if there are no candidates left
        return false;
    }
}
