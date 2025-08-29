#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int i = mid / matrix[0].size();  // row
            int j = mid % matrix[0].size();  // col

            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Found " << target << " in the matrix." << endl;
    } else {
        cout << target << " not found in the matrix." << endl;
    }

    return 0;
}
