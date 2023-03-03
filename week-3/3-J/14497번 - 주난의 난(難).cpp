#include <iostream>
#include <queue>

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

using namespace std;
int n, m, x1, y1, x2, y2;
typedef pair<int, int> pii;
char map[301][301];
int visited[301][301];
int ret;
queue<int> q;

void bfs(int y, int x) {
    q.push(1000 * y + x);
    visited[y][x] = 1;
    int cnt = 0;
    while (map[y2][x2] != '0') {
        cnt++;
        queue<int> temp;
        while (q.size()) {
            y = q.front() / 1000;
            x = q.front() % 1000;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if (map[ny][nx] == '0') {
                    q.push(1000 * ny + nx);
                }
                if (map[ny][nx] == '1' || map[ny][nx] == '#') {
                    map[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                }
            }
        }
        q = temp;
    }
}

int main() {
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    bfs(y1, x1);
    cout << visited[y2][x2] << '\n';
}