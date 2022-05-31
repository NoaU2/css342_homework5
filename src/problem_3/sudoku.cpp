#include <set>
#include "sudoku.h"

Sudoku::~Sudoku() {
    delete[] challenge;
}

bool Sudoku::solve() {
    /*
     * TODO: homework
     */
    return solve(0, 0);
}

bool Sudoku::solve(size_t row, size_t col) {
    /*
     * TODO: homework
     * This helper function is OPTIONAL.
     * Use this or change it to your like.
     * If you do, remember to change the same in the .h file.
     */
    if(row > 8 && col == 0){
        return true;
    }
    if(*challenge_board(row, col) != 0){
        if(col == 8){
            solve((row + 1), 0);
        }
        else{
            solve(row, (col + 1));
        }
    }
    else {
        std::set<int> candidates;
        for (int i = 0; i < SUDOKU_BOARD_SIZE; i++) {
            candidates.insert(i + 1);
        }

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
        return false;
    }
}
