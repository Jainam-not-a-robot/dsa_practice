#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        vector<int> prefix_sum(nums.size() + 1);
        prefix_sum[0] = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefix_sum[i + 1] = sum;
            if (m.find(sum - k) != m.end()) cnt += m[sum - k];
            m[sum]++;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;

    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
