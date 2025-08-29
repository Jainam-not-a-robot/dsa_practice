#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < min(matrix.size(), matrix[0].size()); i++) {
            int l = i * matrix[0].size() + i;
            // left to right in row i
            int r = l + matrix[0].size() - i - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (matrix[i][m % matrix[0].size()] == target) return true;
                else if (matrix[i][m % matrix[0].size()] > target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            l = i * matrix[0].size() + i;
            // top to bottom in column i
            r = l + (matrix.size() - i - 1) * matrix[0].size();
            while (l <= r) {
                int m = (l + r) / 2;
                if (matrix[m / matrix[0].size()][i] == target) return true;
                else if (matrix[m / matrix[0].size()][i] > target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    int rows, cols, target;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix elements (row-wise):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter target value: ";
    cin >> target;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Found " << target << " in the matrix.\n";
    } else {
        cout << target << " not found in the matrix.\n";
    }

    return 0;
}
