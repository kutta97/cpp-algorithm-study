#include <iostream>
#include <string.h>
using namespace std;

int N;
int map[101][101];
int visited[101][101];

int rain;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (map[ny][nx] <= rain || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
    return;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int ret = 1;
    for (int r = 1; r <= 100; r++) {
        memset(visited, 0, sizeof(visited));
        rain = r;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] <= rain || visited[i][j]) continue;
                cnt++; dfs(i, j);
            }
        }
        if (ret < cnt) ret = cnt;
    }

    cout << ret << '\n';

    return 0;
}