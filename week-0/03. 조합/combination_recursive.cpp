#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n = 5;
int k = 3;
int a[5] = {1, 2, 3, 4, 5};

void printV(vector<int> &v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << '\n';
}

void combi(int start, vector<int> v) {
	if (v.size() == k) {
		printV(v);
		return;
	}
	for (int i = start + 1; i < n; i++) {
		v.push_back(a[i]);
		combi(i, v);
		v.pop_back();
	}
	return;
}

int main() {
	vector<int> v;
	combi(-1, v);
	return 0;
}