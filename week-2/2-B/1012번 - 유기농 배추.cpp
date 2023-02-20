#include <iostream>
#include <string.h>
using namespace std;

int T;
int N, M, K;
int cabbage[51][51];
int visited[51][51];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (cabbage[ny][nx] == 0 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> T;
    while (T--) {
        int worm = 0;
        memset(cabbage, 0, sizeof(cabbage));
        memset(visited, 0, sizeof(visited));

        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            cabbage[y][x] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!cabbage[i][j] || visited[i][j]) continue;
                worm++; dfs(i, j);
            }
        }
        cout << worm << '\n';
    }
    return 0;
}