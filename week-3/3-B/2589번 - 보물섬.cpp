#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
char map[51][51];
int visited[51][51];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int mx;

void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));

    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (map[ny][nx] == 'W' || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            mx = max(mx, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L') bfs(i, j);
        }
    }
    cout << mx - 1 << '\n';
    return 0;
}