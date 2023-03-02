#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define prev prev_arr
const int MAX = 200001;

int n, k, ret;
int visited[MAX];
int prev[MAX];

void solve(int x) {
    visited[x] = 1;

    queue<int> q;
    q.push(x);
    while (q.size()) {
        int now = q.front(); q.pop();
        if (now == k) {
            ret = visited[k];
            break;
        }
        for (int next : {now + 1, now - 1, now * 2}) {
            if (next >= MAX || next < 0) continue;
            if (visited[next]) continue;
            visited[next] = visited[now] + 1;
            prev[next] = now;
            q.push(next);
        }
    }
}

vector<int> getRoute() {
    vector<int> v;

    for (int i = k; i != n; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    
    return v;
}

int main() {
    vector<int> v;
    cin >> n >> k;
    
    solve(n);
    v = getRoute();
    
    cout << ret - 1 << '\n';
    for (int i : v) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}