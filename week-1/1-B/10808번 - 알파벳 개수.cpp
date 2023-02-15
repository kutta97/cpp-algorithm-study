#include <iostream>
#include <string>
using namespace std;

string s;
int cnt[26];

int main() {
    cin >> s;

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i : cnt) cout << i << ' ';

    return 0;
}