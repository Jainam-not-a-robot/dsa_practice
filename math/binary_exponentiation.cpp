#include<iostream>
using namespace std;

int main() {
    int a = 8, b = 5; // Compute 8^5
    int ans = 1;

    while (b > 0) {
        if (b % 2 == 1) {    // If current bit is 1
            ans *= a;
        }
        a *= a;   // Square base
        b /= 2;   // Move to next bit
    }

    cout << ans << endl;
    return 0;
}
