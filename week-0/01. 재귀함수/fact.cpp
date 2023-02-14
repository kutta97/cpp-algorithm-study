#include <iostream>
using namespace std;

int fact(int n) {
	if (n == 1 || n == 0) return 1; // 기저 사례
	return n * fact(n - 1);
}

int fact1(int n) {
	int ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
	return ret;
}

int n = 5;
int main() {
	cout << fact(n) << " " << fact1(n) << '\n';
	return 0;
}