#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;
        if (visited[i][j]) return;

        visited[i][j] = true;

        dfs(i - 1, j, visited, grid); // up
        dfs(i + 1, j, visited, grid); // down
        dfs(i, j - 1, visited, grid); // left
        dfs(i, j + 1, visited, grid); // right
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, visited, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int result = sol.numIslands(grid);

    cout << "Number of islands: " << result << endl;

    return 0;
}
