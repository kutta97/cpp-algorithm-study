#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

char map[1004][1004];
pair<int, int> J;

int N, M, ret;

int fire_check[1004][1004];
int person_check[1004][1004];

queue<pair<int, int>> q;

void fire() {
    int y, x;
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (fire_check[ny][nx] != 0 || map[ny][nx]=='#') continue;
			fire_check[ny][nx] = fire_check[y][x] + 1;
			q.push({ny, nx});
		}
	}
}

void escape(int y, int x) {
    person_check[y][x] = 1;
    q.push({y,x});
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
		if (y == 0 || y == N - 1 || x == 0 || x == M - 1){
            ret = person_check[y][x];
            break;
		}
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (person_check[ny][nx] || map[ny][nx]=='#') continue;
			if (fire_check[ny][nx] <= person_check[y][x] + 1 && fire_check[ny][nx] != 0) continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
		}
	} 
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'F') {
                fire_check[i][j] = 1; q.push({i, j});
            }
            if (map[i][j] == 'J') {
                J.first = i; J.second = j;
            }
        }
    } 

    fire();
    escape(J.first, J.second);

    if (ret != 0) cout << ret << "\n";
    else cout << "IMPOSSIBLE \n";
    return 0;
}