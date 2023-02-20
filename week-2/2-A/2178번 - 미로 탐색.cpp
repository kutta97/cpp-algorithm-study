#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
int visited[101][101];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	visited[sy][sx] = 1;
	q.push({sy, sx});

	int y, x;
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (map[ny][nx] == 0 || visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			map[i][j] = input[j] - '0';
		}
	}
	bfs(0, 0);
	cout << visited[n - 1][m - 1] << '\n';
	return 0;
}