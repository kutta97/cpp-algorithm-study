#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N;

int map[11][11];
int visited[11][11];

int ret = INT_MAX;

int setFlower(int y, int x) {
    visited[y][x] = 1;
    int cost = map[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        cost += map[ny][nx];
    }
    return cost;
}

void eraseFlower(int y, int x) {
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

bool check(int y, int x) {
    if (visited[y][x]) return false;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) return false;
        if (visited[ny][nx]) return false;
    }
    return true;
}

void flower(int cnt, int sum) {
    if (cnt == 3) {
        ret = min(ret, sum);
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!check(i, j)) continue;
            flower(cnt + 1, sum + setFlower(i, j));
            eraseFlower(i, j);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    flower(0, 0);
    cout << ret;
}