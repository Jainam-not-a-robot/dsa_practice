#include <bits/stdc++.h>
using namespace std;

class Solution {
    void recurse(vector<vector<int>> maze, int rows, int cols, vector<string>& final_ans, string ans) {
        int n = maze.size();
        maze[rows][cols] = 0;
        if (rows == n - 1 && cols == n - 1) {
            final_ans.push_back(ans);
            return;
        }

        // Move Down
        if (rows + 1 < n && maze[rows + 1][cols] == 1) {
            ans.push_back('D');
            recurse(maze, rows + 1, cols, final_ans, ans);
            ans.pop_back();
        }

        // Move Left
        if (cols - 1 >= 0 && maze[rows][cols - 1] == 1) {
            ans.push_back('L');
            recurse(maze, rows, cols - 1, final_ans, ans);
            ans.pop_back();
        }

        // Move Right
        if (cols + 1 < n && maze[rows][cols + 1] == 1) {
            ans.push_back('R');
            recurse(maze, rows, cols + 1, final_ans, ans);
            ans.pop_back();
        }

        // Move Up
        if (rows - 1 >= 0 && maze[rows - 1][cols] == 1) {
            ans.push_back('U');
            recurse(maze, rows - 1, cols, final_ans, ans);
            ans.pop_back();
        }
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> final_ans;
        string ans;
        if (maze[0][0] == 1) {
            recurse(maze, 0, 0, final_ans, ans);
        }
        return final_ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);

    if (paths.empty()) {
        cout << -1 << endl;
    } else {
        sort(paths.begin(), paths.end()); // GFG expects lexicographic order
        for (string &path : paths) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
