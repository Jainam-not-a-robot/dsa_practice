#include <iostream>
#include <vector>
using namespace std;

// Swap function using pointers
void swap(int *n1, int *n2){
    int t = *n1;
    *n1 = *n2;
    *n2 = t;
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // l = next position to place 0
        // m = current element being processed
        // h = next position to place 2
        int l = 0, m = 0, h = nums.size() - 1;

        // Process elements until m crosses h
        while(m <= h){
            if(nums[m] == 0) {
                // Current element is 0
                // Swap it with the element at l (next 0 position)
                // Increment both l and m since the 0 is in correct place
                swap(&nums[l++], &nums[m++]);
            }
            else if(nums[m] == 1) {
                // Current element is 1
                // Already in the correct section, just move to next element
                m++;
            }
            else {
                // Current element is 2
                // Swap it with the element at h (next 2 position)
                // Decrement h to move the 2 to the end
                // Do not increment m here because the swapped element at m may be 0 or 1
                swap(&nums[m], &nums[h--]);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements (0, 1, 2 only): ";
    for(int i = 0; i < n; i++){
        cin >> val;
        nums.push_back(val);
    }

    sol.sortColors(nums);

    cout << "Sorted colors: ";
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
