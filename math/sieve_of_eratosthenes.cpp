#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> v(n, true);
    v[0] = false;
    v[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (v[i]) {
            for (int j = i * i; j < n; j += i) {
                v[j] = false;
            }
        }
    }
    return count(v.begin(), v.end(), true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of primes less than " << n << " = " << countPrimes(n) << "\n";
    return 0;
}
