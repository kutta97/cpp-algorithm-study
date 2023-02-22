#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M;
int map[101][101];
int visited[101][101];
vector<pair<int, int>> v;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int cheese_time, cheese_cnt;

void dfs(int y, int x) {
    visited[y][x] = 1;
    if (map[y][x] == 1) {
        v.push_back({y, x});
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
    return;
}

bool isCheeseGone() {
    bool flag = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) flag = false;
        }
    }
    return flag;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) cheese_cnt++;
        }
    }

    while(true) {
        cheese_cnt = 0;
        memset(visited, 0, sizeof(visited));
        v.clear();
        dfs(0, 0);
        for (auto melt : v) {
            cheese_cnt++;
            map[melt.first][melt.second] = 0;
        }
        cheese_time++;
        if (isCheeseGone()) break;
    }

    cout << cheese_time << '\n';
    cout << cheese_cnt << '\n';
    return 0;
}