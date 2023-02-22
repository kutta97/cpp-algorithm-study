#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;

bool isBalanced() {
    stack<char> stk;
    for (char c : s) {
        if (c == '[' || c == '(') stk.push(c);
        if (c == ']') {
            if (stk.empty() || stk.top() != '[') return false;
            stk.pop();
        }
        if (c == ')') {
            if (stk.empty() || stk.top() != '(') return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    while (true) {
        getline(cin, s);
        if (s == ".") break;
        cout << (isBalanced() ? "yes" : "no") << '\n';
    }

    return 0;
}