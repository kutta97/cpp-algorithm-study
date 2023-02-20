#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int map[101][101];
int visited[101][101];

vector<int> areas;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int x1, x2, y1, y2;

void fill() {
    for (int y = y1; y < y2; y++) {
        for (int x = x1; x < x2; x++) {
             map[y][x]++;
        }
    }
}

int dfs(int y, int x) {
    visited[y][x] = 1;
    int area = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if (map[ny][nx] || visited[ny][nx]) continue;
        area += dfs(ny, nx);
    }
    return area;
}

int main() {
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {  
        cin >> x1 >> y1 >> x2 >> y2;
        fill();
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] || visited[i][j]) continue;
            areas.push_back(dfs(i, j));
        }
    }

    sort(areas.begin(), areas.end());
    cout << areas.size() << '\n';
    for (int a : areas) cout << a << ' ';
    cout << '\n';

    return 0;
}