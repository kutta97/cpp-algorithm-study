#include <iostream>
using namespace std;
int n;

int solve() {
    int cnt = 1;
    int ret = 1;

    while (true) {
        if (cnt % n == 0) break;
        cnt = (cnt * 10) + 1;
        cnt %= n;
        ret++;
    }

    return ret;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        cout << solve() << '\n';   
    }
    return 0;
}