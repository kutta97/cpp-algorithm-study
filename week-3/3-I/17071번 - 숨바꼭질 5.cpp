#include <iostream>
#include <queue>
using namespace std;

const int MAX = 500000;
int visited[2][MAX + 1];
int N, K;

int solve(int x) {
    queue<int> q;
    int turn = 1;
    bool ok = false;

    visited[0][x] = 1;
    q.push(x);
    while (q.size()) {
        K += turn;
        if (K > MAX) break;
        if (visited[turn % 2][K]) {
            ok = true;
            break;
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            x = q.front(); q.pop();
            for (int nx : {x - 1, x + 1, x * 2}) {
                if (nx < 0 || nx > MAX || visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                if (nx == K) {
                    ok = true;
                    break;
                }
                q.push(nx);
            }
            if (ok) break;
        }
        if (ok) break;
        turn++;
    }
    if (!ok) return -1;
    return turn;
}

int main() {
    cin >> N >> K;
    if (N == K) {
        cout << 0 << "\n";
        return 0;
    }

    cout << solve(N) << "\n";
    return 0;
}
