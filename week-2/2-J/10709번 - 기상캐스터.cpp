#include <iostream>
using namespace std;

int H, W;
char map[101][101];
int cloud[101][101];

void solve() {
    for (int i = 0; i < H; i++) {
        int cnt = 0;
        for (int j = 0; j < W; j++) {
            if (map[i][j] == 'c') {
                cloud[i][j] = 0;
                cnt = 1;
            }
            if (map[i][j] == '.') {
                if (cnt) cloud[i][j] = cnt++;
                else cloud[i][j] = -1;
            }
        }
    }
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }
    solve();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << cloud[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}