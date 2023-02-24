#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200000;

int N, K;
int visited[MAX + 4];
int cnt[MAX + 4];

void solve(int n) {
    visited[n] = 1;
    cnt[n] = 1;

    queue<int> q;
    q.push(n);
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int next : {now - 1, now + 1, now * 2}) {
            if (next < 0 || next > MAX) continue;
            if (visited[next] == visited[now] + 1) {
                cnt[next] += cnt[now];
            }
            if (visited[next]) continue;
            q.push(next);
            visited[next] = visited[now] + 1;
            cnt[next] += cnt[now];
        }
    }
}

int main() {
    cin >> N >> K;
    if (N == K) {
        puts("0"); puts("1");
        return 0;
    }
    solve(N);

    cout << visited[K] - 1 << '\n';
    cout << cnt[K] << '\n';
    return 0;
}