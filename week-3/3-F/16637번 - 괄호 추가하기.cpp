#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int n, ret = INT_MIN;
char input;

vector<int> num;
vector<char> opr;

int calc(char op, int a, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
}

void solve(int here, int _num) {
    if (here == num.size() - 1) {
        ret = max(ret, _num);
        return;
    }

    solve(here + 1, calc(opr[here], _num, num[here + 1]));
    if (here + 2 <= num.size() - 1) {
        int temp = calc(opr[here + 1], num[here + 1], num[here + 2]);
        solve(here + 2, calc(opr[here], _num, temp));
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (i % 2 == 0)
            num.push_back(input - '0');
        else
            opr.push_back(input);
    }
    solve(0, num[0]);
    cout << ret << "\n";
    return 0;
}