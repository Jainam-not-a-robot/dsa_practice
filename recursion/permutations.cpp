#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permutationRecursion(vector<int>& nums, int i, vector<vector<int>>& final_ans) {
    if (i == nums.size()) {
        final_ans.push_back(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        permutationRecursion(nums, i + 1, final_ans);
        swap(nums[i], nums[j]); // backtrack
    }
}

int main() {
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> final_ans;
    
    permutationRecursion(nums, 0, final_ans);

    cout << "All permutations:\n";
    for (const auto& perm : final_ans) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}
