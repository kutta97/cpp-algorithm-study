#include <iostream>
#include <string>
using namespace std;

string s;

char rot13(char c) {
    if (c >= 'a' && c <= 'z') {
        if (c + 13 > 'z') return c - 13;
        return c + 13;
    }
    if (c >= 'A' && c <= 'Z') {
        if (c + 13 > 'Z') return c - 13;
        return c + 13;
    }
    return c;
}

int main() {
    getline(cin, s);
    for (char c : s) cout << rot13(c);
    return 0;
}