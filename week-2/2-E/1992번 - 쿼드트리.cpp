#include <iostream>
#include <string>
using namespace std;

int N;
char map[65][65];

string quard(int y, int x, int size) {
    if (size == 1) return string(1, map[y][x]);
    char b = map[y][x];
    string ret = "";
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (b != map[i][j]) {
                ret += '(';
                ret += quard(y, x, size / 2);
                ret += quard(y, x + size / 2, size / 2);
                ret += quard(y + size / 2, x, size / 2);
                ret += quard(y + size / 2, x + size / 2, size / 2);
                ret += ')';
                return ret;
            }
        }
    }
    return string(1, map[y][x]);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            map[i][j] = s[j];
        }
    }

    cout << quard(0, 0, N) << '\n';
    return 0;
}