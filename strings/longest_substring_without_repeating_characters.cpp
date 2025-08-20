#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int ans = 0;
    int l = 0, r = 0;
    unordered_set<char> a;

    while (r < s.size()) {
        if (a.find(s[r]) == a.end()) {
            a.insert(s[r]);
            r++;
            ans = max(ans, r - l);
        } else {
            a.erase(s[l]);
            l++;
        }
    }

    cout << "Length of longest substring without repeating characters: " << ans << endl;

    return 0;
}//Normally takes O(n**3) this way takes O(n)