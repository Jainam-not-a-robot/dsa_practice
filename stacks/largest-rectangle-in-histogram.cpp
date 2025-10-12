#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> width(heights.size(), 1);
        
        // Next smaller on right
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (s.empty()) width[i] += heights.size() - 1 - i;
            else width[i] += s.top() - i - 1;
            s.push(i);
        }

        stack<int> s1;
        // Next smaller on left
        for (int i = 0; i < heights.size(); i++) {
            while (!s1.empty() && heights[s1.top()] >= heights[i]) s1.pop();
            if (s1.empty()) width[i] += i;
            else width[i] += i - s1.top() - 1;
            s1.push(i);
        }

        int ans = 0;
        for (int i = 0; i < heights.size(); i++) 
            ans = max(ans, heights[i] * width[i]);
        
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) cin >> heights[i];

    int result = sol.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}
