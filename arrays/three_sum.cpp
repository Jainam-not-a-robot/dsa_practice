#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> v;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        int l = i + 1, r = nums.size() - 1;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        while (l < r) {
            if (nums[l] + nums[r] + nums[i] == 0) {
                vector<int> v2 = {nums[i], nums[l], nums[r]};
                v.push_back(v2);
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            } else if (nums[l] + nums[r] + nums[i] > 0) {
                r--;
            } else {
                l++;
            }
        }
    }
    return v;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets that sum to zero are:\n";
    for (auto triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
