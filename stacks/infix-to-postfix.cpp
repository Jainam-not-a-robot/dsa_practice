#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void postfix(string infix, string &ans) {
    stack<char> s;

    for (auto &x : infix) {
        if (isalnum(x)) { 
            // operand (a,b,c,... or digits)
            ans += x;
        }
        else if (x == '(') {
            s.push(x);
        }
        else if (x == ')') {
            while (!s.empty() && s.top() != '(') {
                ans += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // remove '('
        }
        else { // operator + - * /
            while (!s.empty() && precedence(s.top()) >= precedence(x)) {
                ans += s.top();
                s.pop();
            }
            s.push(x);
        }
    }

    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
}
int main() {
    string infix = "(a+b)*(c*d-e)*f/g";
    string ans = "";
    postfix(infix, ans);
    cout << ans << endl;  // expected: ab+cd*e-f*g*/
}
