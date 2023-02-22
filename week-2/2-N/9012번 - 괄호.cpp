#include <iostream>
#include <string>
#include <stack>
using namespace std;

int T;
string ps;

bool isValidPs() {
    stack<char> stk;

    for (char c : ps) {
        if (c == '(') stk.push(c);
        if (c == ')') {
            if (stk.size() == 0) return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    cin >> T;
    while (T--) {
        cin >> ps;
        cout << (isValidPs() ? "YES" : "NO") << '\n';
    }
    return 0;
}