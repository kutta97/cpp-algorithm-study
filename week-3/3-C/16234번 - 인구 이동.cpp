#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <vector>
using namespace std;

int N, L, R;
int map[101][101];
int visited[101][101];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

vector<pair<int, int>> union_list;
int closed;

void movePopluaton(int popluation_sum) {
    int p = popluation_sum / union_list.size();
    for (auto u : union_list) {
        map[u.first][u.second] = p;
    }
}

bool closeBorder(int a, int b) {
    int sub = abs(a - b);
    return !(sub >= L && sub <= R);
}

int dfs(int y, int x) {
    visited[y][x] = 1;
    int popluation = map[y][x];
    union_list.push_back({y, x});

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (visited[ny][nx]) continue;
        if (closeBorder(map[y][x], map[ny][nx])) continue;
        popluation += dfs(ny, nx);
    }
    return popluation;
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int day = 0;
    int popluation = 0;
    while (true) {
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                union_list.clear();
                popluation = dfs(i, j);
                if (union_list.size() == 1) continue;
                movePopluaton(popluation);
                flag = true;
            }
        }
        if (!flag) break;
        day++;
    }

    cout << day << '\n';

    return 0;
}