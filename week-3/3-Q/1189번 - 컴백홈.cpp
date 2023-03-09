#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int R, C, K;
char map[6][6];
int visited[6][6];

int solve(int y, int x) {
    if (y == 0 && x == C - 1) {
        if (visited[y][x] == K) return 1;
        return 0;
    }
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (visited[ny][nx] || map[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[y][x] + 1;
        ret += solve(ny, nx);
        visited[ny][nx] = 0;
    }
    return ret;
}

int main() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    visited[R - 1][0] = 1;
    cout << solve(R - 1, 0) << '\n';
    return 0;
}