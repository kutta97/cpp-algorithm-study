#include <iostream>
#include <vector>
using namespace std;

int N;
int node, root, leaf;
vector<int> tree[51];

int dfs(int here) {
    int ret = 0;
    int child = 0;
    for (auto there : tree[here]) {
        if (there == node) continue;
        ret += dfs(there);
        child++;
    }
    if (child == 0) return 1;
    return ret;
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> node;
        if (node == -1) root = i;
        else tree[node].push_back(i);
    }
    cin >> node;

    if (node != root) {
        leaf = dfs(root);
    }
    cout << leaf << '\n';

    return 0;
}