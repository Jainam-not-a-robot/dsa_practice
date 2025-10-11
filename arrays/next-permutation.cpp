#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size() - 1;
        for(int i = n-1; i >= 0; i--){
            if(arr[i+1] > arr[i]){
                // Find the first element from the end greater than arr[i]
                int min_idx = 0;
                for(int j = n; j > i; j--){
                    if(arr[j] > arr[i]){
                        min_idx = j;
                        break;
                    }
                }
                swap(arr[i], arr[min_idx]);

                // Reverse the suffix
                int left = i+1, right = n;
                while(left < right){
                    swap(arr[left], arr[right]);
                    left++; right--;
                }

                break;
            }

            // Handle the last permutation (fully descending)
            if(i == 0){
                for(int j = 0; j <= n/2; j++)
                    swap(arr[j], arr[n-j]);
            }
        }        
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    // Example input
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sol.nextPermutation(arr);

    cout << "Next permutation: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
