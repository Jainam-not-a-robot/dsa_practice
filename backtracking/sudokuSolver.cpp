#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(vector<vector<char>>& board, int rows, int cols, int num) {
        for (int i = 0; i < 9; i++) {
            if (board[i][cols] == num + '0') return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[rows][i] == num + '0') return false;
        }
        int a = rows / 3;
        int b = cols / 3;
        for (int i = a * 3; i < a * 3 + 3; i++) {
            for (int j = b * 3; j < b * 3 + 3; j++) {
                if (board[i][j] == num + '0') return false;
            }
        }
        return true;
    }

    bool sudokuSolver(vector<vector<char>>& board, int rows, int cols) {
        if (cols == 9) {
            rows++;
            cols = 0;
        }
        if (rows == 9) {
            return true;
        }
        if (board[rows][cols] == '.') {
            for (int num = 1; num <= 9; num++) {
                if (isSafe(board, rows, cols, num)) {
                    board[rows][cols] = num + '0';
                    if (sudokuSolver(board, rows, cols + 1)) return true;
                    board[rows][cols] = '.';
                }
            }
        } else {
            return sudokuSolver(board, rows, cols + 1);
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    // Input the Sudoku board
    // Use '.' for empty cells
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    obj.solveSudoku(board);

    // Print solved Sudoku
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

