#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0;
        int cnt = 1;
        int end = 1;
        int idx = 0;

        while (end < chars.size()) {
            if (chars[start] == chars[end]) {
                cnt++;
                end++;
            }
            else {
                if (cnt == 1) {
                    chars[idx++] = chars[start++];
                    end++;
                }
                else {
                    chars[idx++] = chars[start];
                    string s1 = to_string(cnt);
                    for (auto &x : s1) chars[idx++] = x;
                    cnt = 1;
                    start = end;
                    end++;
                }
            }
        }

        if (cnt == 1) {
            chars[idx++] = chars[start++];
            end++;
        }
        else {
            chars[idx++] = chars[start];
            string s1 = to_string(cnt);
            for (auto &x : s1) chars[idx++] = x;
            cnt = 1;
            start = end;
            end++;
        }

        chars.resize(idx);
        return chars.size();
    }
};

int main() {
    Solution sol;

    vector<char> chars = {'a','a','b','b','c','c','c'};
    int newLen = sol.compress(chars);

    cout << "Compressed length: " << newLen << endl;
    cout << "Compressed chars: ";
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
