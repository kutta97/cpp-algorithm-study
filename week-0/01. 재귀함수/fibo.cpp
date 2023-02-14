#include <iostream>
using namespace std;

int fibo(int n) {
	if (n == 0 || n == 1) return n; // 기저 사례
	return fibo(n - 1) + fibo(n - 2);
}

int n = 7;
int main() {
	cout << fibo(n) << '\n';
	return 0;
}