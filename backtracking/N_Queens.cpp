#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(vector<string>& v, int cols, int rows) {
        // check column
        for (int i = 0; i < cols; i++) {
            if (v[i][rows] == 'Q') return false;
        }
        // check row
        for (int j = 0; j < rows; j++) {
            if (v[cols][j] == 'Q') return false;
        }
        // check top-left diagonal
        for (int i = 1; i <= min(rows, cols); i++) {
            if (v[cols - i][rows - i] == 'Q') return false;
        }
        // check top-right diagonal
        for (int i = 1; (rows - i >= 0) && (cols + i < v.size()); i++) {
            if (v[cols + i][rows - i] == 'Q') return false;
        }
        return true;
    }

    void setQueen(vector<string>& v, int rows, vector<vector<string>>& final_answer) {
        int n = v.size();
        if (rows == n) {
            final_answer.push_back(v);
            return;
        }
        for (int cols = 0; cols < n; cols++) {
            if (isSafe(v, cols, rows)) {
                v[cols][rows] = 'Q';
                setQueen(v, rows + 1, final_answer);
                v[cols][rows] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> final_answer;
        vector<string> v(n, string(n, '.'));
        setQueen(v, 0, final_answer);
        return final_answer;
    }
};

int main() {
    int n;
    cout << "Enter N for N-Queens: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);

    cout << "Number of solutions: " << ans.size() << "\n";
    for (auto &board : ans) {
        for (auto &row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
