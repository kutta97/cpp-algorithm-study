#include <iostream>
using namespace std;

int N, M;
int materials[15001];

int cnt;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> materials[i];
    }
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			if (materials[i] + materials[j] == M) cnt++;
		}
	}
	cout << cnt << "\n";

    return 0;
}