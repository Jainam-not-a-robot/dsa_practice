#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> v;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate j

            int l = j + 1, r = n - 1;

            while (l < r) {
                long long ans = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                if (ans == (long long)target) {
                    v.push_back({nums[i], nums[j], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (ans > (long long)target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
    }

    return v;
}

int main() {
    // Example input
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << " are:\n";
    for (auto& quad : result) {
        cout << "[ ";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
