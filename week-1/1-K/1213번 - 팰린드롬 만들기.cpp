#include <iostream>
#include <string>
using namespace std;

string s;
int alpha[200] = {0,};

string solve() {
    string ret = "";
    bool flag = 0;
    char mid;

    for (int i = 'Z'; i >= 'A'; i--) {
        if (alpha[i]) {
            if (alpha[i] & 1) {        
                if (flag) return "I'm Sorry Hansoo";
                flag = true;

                mid = (char)i;
                alpha[i]--;
            }
            for (int j = 0; j < alpha[i]; j += 2) {
                ret = (char)i + ret;
                ret += (char)i;
            }
        }
    }
    if (mid) ret.insert(ret.begin() + ret.length() / 2, mid);
    return ret;
}

int main() {
    cin >> s;
    for (char c : s) alpha[c]++;
    cout << solve() << '\n';
    return 0;
}