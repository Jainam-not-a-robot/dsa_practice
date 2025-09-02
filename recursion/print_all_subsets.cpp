#include <bits/stdc++.h>
using namespace std;

void printingSubsets(vector<int>& v, vector<int>& ans, int i) {
    if (i == v.size()) {
        for (auto &x : ans) cout << x << " ";
        cout << endl;
        return;
    }
    ans.push_back(v[i]);
    printingSubsets(v, ans, i + 1);
    ans.pop_back();
    printingSubsets(v, ans, i + 1);
}

int main() {
    vector<int> v = {1, 2, 3};  // Example input
    vector<int> ans;            // To store current subset

    cout << "All subsets:\n";
    printingSubsets(v, ans, 0);

    return 0;
}
