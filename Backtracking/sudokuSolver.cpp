#include <iostream>

using namespace std; 

#define N 9

bool isValid(int row, int col, int sudoku[N][N], int n) {
    for(int i = 0; i < N; i++) {
        if(sudoku[i][col] == n) {
            return false;
        }

        if(sudoku[row][i] == n) {
            return false;
        }

        if(sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == n) {
            return false;
        }
    }

    return true;
}

bool solveSudoku(int sudoku[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(sudoku[i][j] == 0) {
                for(int k = 1; k < N + 1; k++) {
                    if(isValid(i, j, sudoku, k)) {
                        sudoku[i][j] = k;
                        if(solveSudoku(sudoku) == true) {
                            return true;
                        }
                        else {
                            sudoku[i][j] = 0;
                        }
                    }
                }

                return false;
            }

        }
    }

    return true;
}

int main() {
    int sudoku[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if(solveSudoku(sudoku)) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}