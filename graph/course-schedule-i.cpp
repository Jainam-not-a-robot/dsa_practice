#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recPath) {
        visited[u] = true;
        recPath[u] = true;

        for (int &x : graph[u]) {
            if (!visited[x]) {
                if (dfs(x, graph, visited, recPath)) return true;
            } else if (recPath[x]) {
                return true; // cycle detected
            }
        }

        recPath[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (auto &it : prerequisites) {
            graph[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, recPath)) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example 1: possible to finish all courses
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << (sol.canFinish(numCourses1, prerequisites1) ? "Can finish all courses" : "Cannot finish all courses") << endl;

    // Example 2: cycle exists, cannot finish
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << (sol.canFinish(numCourses2, prerequisites2) ? "Can finish all courses" : "Cannot finish all courses") << endl;

    return 0;
}
