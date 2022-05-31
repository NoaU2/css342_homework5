#include "gtest/gtest.h"
#include "unit_test_sudoku.h"

TEST(sudoku, constructor_equal) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int *challenge = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        challenge[i] = expect_val(i);
    }

    SudokuLocator locator(ROWS, COLS);
    Sudoku sudoku(challenge, locator);

    ASSERT_TRUE(sudoku == challenge);
    ASSERT_EQ(sudoku, challenge);
    challenge[0] = 99;
    ASSERT_FALSE(sudoku == challenge);
    delete[] challenge;
}

TEST(sudoku, locator_getter_setter) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int *challenge = new int[SIZE];
    SudokuLocator locator(ROWS, COLS);
    Sudoku sudoku(challenge, locator);

    int val = 0;
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            sudoku(row, col) = expect_val(val++);
        }
    }
    val = 0;
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            ASSERT_EQ(sudoku(row, col), expect_val(val++));
        }
    }
    delete[] challenge;
}

TEST(sudoku, challenge_row_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                           5, 2, 9, 1, 3, 4, 7, 6, 8,
                           4, 8, 7, 6, 2, 9, 5, 3, 1,
                           2, 6, 3, 4, 1, 5, 9, 8, 7,
                           9, 7, 4, 8, 6, 3, 1, 2, 5,
                           8, 5, 1, 7, 9, 2, 6, 4, 3,
                           1, 3, 8, 9, 4, 7, 2, 5, 6,
                           6, 9, 2, 3, 5, 1, 8, 7, 4,
                           7, 4, 5, 2, 8, 6, 3, 1, 9};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, challenge_col_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 2, 9, 1, 3, 4, 7, 6, 8,
                           0, 8, 7, 6, 2, 9, 5, 3, 1,
                           0, 6, 3, 4, 1, 5, 9, 8, 7,
                           0, 7, 4, 8, 6, 3, 1, 2, 5,
                           0, 5, 1, 7, 9, 2, 6, 4, 3,
                           0, 3, 8, 9, 4, 7, 2, 5, 6,
                           0, 9, 2, 3, 5, 1, 8, 7, 4,
                           0, 4, 5, 2, 8, 6, 3, 1, 9};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, challenge_paritial_diag_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;

    int challenge[SIZE] = {0, 1, 6, 5, 7, 8, 4, 9, 2,
                           5, 0, 9, 1, 3, 4, 7, 6, 8,
                           4, 8, 7, 6, 2, 9, 5, 3, 1,
                           2, 6, 3, 4, 1, 5, 9, 8, 7,
                           9, 7, 4, 8, 6, 3, 1, 2, 5,
                           8, 5, 1, 7, 9, 2, 6, 4, 3,
                           1, 3, 8, 9, 4, 7, 2, 5, 6,
                           6, 9, 2, 3, 5, 1, 8, 7, 4,
                           7, 4, 5, 2, 8, 6, 3, 1, 9};
    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, challenge_diag_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {0, 1, 6, 5, 7, 8, 4, 9, 2,
                           5, 0, 9, 1, 3, 4, 7, 6, 8,
                           4, 8, 0, 6, 2, 9, 5, 3, 1,
                           2, 6, 3, 0, 1, 5, 9, 8, 7,
                           9, 7, 4, 8, 0, 3, 1, 2, 5,
                           8, 5, 1, 7, 9, 0, 6, 4, 3,
                           1, 3, 8, 9, 4, 7, 0, 5, 6,
                           6, 9, 2, 3, 5, 1, 8, 0, 4,
                           7, 4, 5, 2, 8, 6, 3, 1, 0};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, challenge_reverse_diag_empty) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 0,
                           5, 2, 9, 1, 3, 4, 7, 0, 8,
                           4, 8, 7, 6, 2, 9, 0, 3, 1,
                           2, 6, 3, 4, 1, 0, 9, 8, 7,
                           9, 7, 4, 8, 0, 3, 1, 2, 5,
                           8, 5, 1, 0, 9, 2, 6, 4, 3,
                           1, 3, 0, 9, 4, 7, 2, 5, 6,
                           6, 0, 2, 3, 5, 1, 8, 7, 4,
                           0, 4, 5, 2, 8, 6, 3, 1, 9};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, real_challenge_1) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {3, 0, 6, 5, 0, 8, 4, 0, 0,
                           5, 2, 0, 0, 0, 0, 0, 0, 0,
                           0, 8, 7, 0, 0, 0, 0, 3, 1,
                           0, 0, 3, 0, 1, 0, 0, 8, 0,
                           9, 0, 0, 8, 6, 3, 0, 0, 5,
                           0, 5, 0, 0, 9, 0, 6, 0, 0,
                           1, 3, 0, 0, 0, 0, 2, 5, 0,
                           0, 0, 0, 0, 0, 0, 0, 7, 4,
                           0, 0, 5, 2, 0, 6, 3, 0, 0};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, real_challenge_2) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {3, 0, 6, 5, 0, 8, 4, 0, 0,
                           5, 2, 0, 0, 0, 0, 0, 0, 0,
                           0, 8, 7, 0, 0, 0, 0, 3, 1,
                           0, 0, 3, 0, 1, 0, 0, 8, 0,
                           9, 0, 0, 8, 6, 3, 0, 0, 5,
                           0, 5, 0, 0, 9, 0, 6, 0, 0,
                           1, 3, 0, 0, 0, 0, 2, 5, 0,
                           0, 0, 0, 0, 0, 0, 0, 7, 4,
                           0, 0, 5, 2, 0, 6, 3, 0, 0};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, real_challenge_3_already_solved) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                           5, 2, 9, 1, 3, 4, 7, 6, 8,
                           4, 8, 7, 6, 2, 9, 5, 3, 1,
                           2, 6, 3, 4, 1, 5, 9, 8, 7,
                           9, 7, 4, 8, 6, 3, 1, 2, 5,
                           8, 5, 1, 7, 9, 2, 6, 4, 3,
                           1, 3, 8, 9, 4, 7, 2, 5, 6,
                           6, 9, 2, 3, 5, 1, 8, 7, 4,
                           7, 4, 5, 2, 8, 6, 3, 1, 9};

    int expected_solution[SIZE] = {3, 1, 6, 5, 7, 8, 4, 9, 2,
                                   5, 2, 9, 1, 3, 4, 7, 6, 8,
                                   4, 8, 7, 6, 2, 9, 5, 3, 1,
                                   2, 6, 3, 4, 1, 5, 9, 8, 7,
                                   9, 7, 4, 8, 6, 3, 1, 2, 5,
                                   8, 5, 1, 7, 9, 2, 6, 4, 3,
                                   1, 3, 8, 9, 4, 7, 2, 5, 6,
                                   6, 9, 2, 3, 5, 1, 8, 7, 4,
                                   7, 4, 5, 2, 8, 6, 3, 1, 9};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, no_solution) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {6, 0, 6, 5, 0, 8, 4, 0, 0,
                           5, 2, 0, 0, 0, 0, 0, 0, 0,
                           0, 8, 7, 0, 0, 0, 0, 3, 1,
                           0, 0, 3, 0, 1, 0, 0, 8, 0,
                           9, 0, 0, 8, 6, 3, 0, 0, 5,
                           0, 5, 0, 0, 9, 0, 6, 0, 0,
                           1, 3, 0, 0, 0, 0, 2, 5, 0,
                           0, 0, 0, 0, 0, 0, 0, 7, 4,
                           0, 0, 5, 2, 0, 6, 3, 0, 0};

    SudokuLocator locator(ROWS, COLS);
    Sudoku sudoku(challenge, locator);
    ASSERT_FALSE(sudoku.solve());
}

// https://www.telegraph.co.uk/news/science/science-news/9359579/Worlds-hardest-sudoku-can-you-crack-it.html
TEST(sudoku, challenge_3_world_hardest) {
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {8, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 3, 6, 0, 0, 0, 0, 0,
                           0, 7, 0, 0, 9, 0, 2, 0, 0,
                           0, 5, 0, 0, 0, 7, 0, 0, 0,
                           0, 0, 0, 0, 4, 5, 7, 0, 0,
                           0, 0, 0, 1, 0, 0, 0, 3, 0,
                           0, 0, 1, 0, 0, 0, 0, 6, 8,
                           0, 0, 8, 5, 0, 0, 0, 1, 0,
                           0, 9, 0, 0, 0, 0, 4, 0, 0};

    int expected_solution[SIZE] = {8, 1, 2, 7, 5, 3, 6, 4, 9,
                                   9, 4, 3, 6, 8, 2, 1, 7, 5,
                                   6, 7, 5, 4, 9, 1, 2, 8, 3,
                                   1, 5, 4, 2, 3, 7, 8, 9, 6,
                                   3, 6, 9, 8, 4, 5, 7, 2, 1,
                                   2, 8, 7, 1, 6, 9, 5, 3, 4,
                                   5, 2, 1, 9, 7, 4, 3, 6, 8,
                                   4, 3, 8, 5, 2, 6, 9, 1, 7,
                                   7, 9, 6, 3, 1, 8, 4, 5, 2};

    assert_solution(challenge, expected_solution, ROWS, COLS);
}

TEST(sudoku, PlayingMyOwnSudoku) {
    //time to play my own game of sudoku
    const size_t ROWS = 9, COLS = 9;
    const size_t SIZE = ROWS * COLS;
    int challenge[SIZE] = {8, 0, 1, 0, 0, 0, 0, 4, 5,
                           0, 4, 0, 8, 0, 1, 7, 0, 6,
                           0, 5, 6, 0, 0, 0, 8, 0, 0,
                           0, 9, 0, 7, 0, 0, 1, 0, 0,
                           1, 0, 0, 0, 8, 0, 0, 0, 0,
                           0, 0, 0, 2, 0, 0, 5, 3, 8,
                           0, 0, 5, 0, 4, 0, 0, 8, 0,
                           4, 2, 7, 0, 0, 0, 0, 1, 0,
                           0, 0, 0, 0, 9, 0, 2, 0, 4};

    int expected_solution[SIZE] = {8, 7, 1, 9, 2, 6, 3, 4, 5,
                                   3, 4, 9, 8, 5, 1, 7, 2, 6,
                                   2, 5, 6, 4, 7, 3, 8, 9, 1,
                                   5, 9, 8, 7, 3, 4, 1, 6, 2,
                                   1, 3, 2, 6, 8, 5, 4, 7, 9,
                                   7, 6, 4, 2, 1, 9, 5, 3, 8,
                                   9, 1, 5, 3, 4, 2, 6, 8, 7,
                                   4, 2, 7, 5, 6, 8, 9, 1, 3,
                                   6, 8, 3, 1, 9, 7, 2, 5, 4};

    assert_solution(challenge, expected_solution, ROWS, COLS);

}
