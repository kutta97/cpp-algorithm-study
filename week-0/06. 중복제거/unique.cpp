#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v {4, 4, 1, 2, 3, 3, 3, 2, 5, 6};
int main() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i : v) cout << i << " ";
    cout << '\n';
    return 0;
}