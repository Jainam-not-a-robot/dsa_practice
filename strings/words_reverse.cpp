#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string ans = "";
    string word = "";
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            word += s[i];
        }
        else {
            if (!word.empty()) {
                reverse(word.begin(), word.end());
                if (!ans.empty()) ans += ' ';
                ans += word;
                word = "";
            }
        }
    }
    if (!word.empty()) {
        reverse(word.begin(), word.end());
        if (!ans.empty()) ans += ' ';
        ans += word;
    }
    cout << ans << endl;
    return 0;
}
