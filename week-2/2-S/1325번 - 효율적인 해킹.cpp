#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M, A, B;

vector<int> adj[10001];
int visited[10001];
int mx, hacked[10001];

vector<int> ret;

int dfs(int here) {
    visited[here] = 1;
    int ret = 1;
    for (auto there : adj[here]) {
        if (visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        adj[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        hacked[i] = dfs(i);
        mx = max(mx, hacked[i]);
    }

    for (int i = 1; i <= N; i++) if (hacked[i] == mx) cout << i << ' ';
    return 0;
}