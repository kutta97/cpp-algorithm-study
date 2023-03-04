#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1501;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int R, C, swanY, swanX;
int visited[MAX][MAX];
int visited_swan[MAX][MAX];
char map[MAX][MAX];
queue<pair<int, int>> waterQ, water_tempQ;
queue<pair<int, int>> swanQ, swan_tempQ;

void Qclear(queue<pair<int, int>> &q) {
    q = queue<pair<int, int>>();
}

void water_melting() {
    int y, x;
    while (waterQ.size()) {
        tie(y, x) = waterQ.front();
        waterQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (visited[ny][nx]) continue;
            if (map[ny][nx] == 'X') {
                visited[ny][nx] = 1;
                water_tempQ.push({ny, nx});
                map[ny][nx] = '.';
            }
        }
    }
}

bool move_swan() {
    int y, x;
    while (swanQ.size()) {
        tie(y, x) = swanQ.front();
        swanQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (visited_swan[ny][nx]) continue;
            visited_swan[ny][nx] = 1;
            if (map[ny][nx] == '.') swanQ.push({ny, nx});
            if (map[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            if (map[ny][nx] == 'L') return true;
        }
    }
    return false;
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'L') {
                swanY = i, swanX = j;
            }
            if (map[i][j] == '.' || map[i][j] == 'L'){
                visited[i][j] = 1;
                waterQ.push({i, j});
            }
        }
    }
    swanQ.push({swanY, swanX});
    visited_swan[swanY][swanX] = 1;

    int day = 0;
    while (true) {
        if (move_swan()) break;
        water_melting();
        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day << "\n";
    return 0;
}
