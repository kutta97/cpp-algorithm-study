#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M;
int map[10][10];
int visited[10][10];

int safe_zone = 0;

vector<pair<int, int>> space;
vector<pair<int, int>> virus;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
    visited[y][x] = 2;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (map[ny][nx] != 0 || visited[ny][nx]) continue;      
        dfs(ny, nx);
    }
}

int solve() {
    memset(visited, 0, sizeof(visited));
    for (auto vi : virus) {
        dfs(vi.first, vi.second);
    }

    int safe = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && visited[i][j] != 2) {
                safe++;
            }
        }
    }
    return safe;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) space.push_back({i, j});
            if (map[i][j] == 2) virus.push_back({i, j});
        }
    }

    for (int i = 0; i < space.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                map[space[i].first][space[i].second] = 1;
                map[space[j].first][space[j].second] = 1;
                map[space[k].first][space[k].second] = 1;
                safe_zone = max(safe_zone, solve());
                map[space[i].first][space[i].second] = 0;
                map[space[j].first][space[j].second] = 0;
                map[space[k].first][space[k].second] = 0;
            }
        }
    }

    cout << safe_zone << '\n';
    
    return 0;
}