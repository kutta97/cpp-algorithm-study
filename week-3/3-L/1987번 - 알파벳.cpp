#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int R, C, ret;
int visited[30];
char map[21][21];

void solve(int y, int x, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int next = map[ny][nx] - 'A';
        if (visited[next]) continue;

        visited[next] = 1;
        solve(ny, nx, cnt + 1);
        visited[next] = 0;
    }
    return;
}
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    visited[(int)map[0][0] - 'A'] = 1;
    solve(0, 0, 1);
    cout << ret << '\n';
    return 0;
}