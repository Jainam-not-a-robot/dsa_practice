#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Count fresh oranges and enqueue all rotten ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;

        while (!q.empty()) {
            bool rotten = false;
            int a = q.size();

            for (int x = 0; x < a; x++) {
                pair<int,int> el = q.front();
                q.pop();
                int i = el.first;
                int j = el.second;
                visited[i][j] = true;

                // Down
                if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 1) {
                    rotten = true;
                    visited[i + 1][j] = true;
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                    fresh--;
                }
                // Right
                if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 1) {
                    rotten = true;
                    visited[i][j + 1] = true;
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                    fresh--;
                }
                // Up
                if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) {
                    rotten = true;
                    visited[i - 1][j] = true;
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                    fresh--;
                }
                // Left ✅ fixed (was i-1 before)
                if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1) {
                    rotten = true;
                    visited[i][j - 1] = true;
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                    fresh--;
                }
            }

            if (rotten) cnt++;
        }

        if (fresh) return -1;
        return cnt;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = sol.orangesRotting(grid);

    cout << "Minutes until all oranges rot: " << result << endl;

    return 0;
}
