#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int temperature[100001];
int ret;

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> temperature[i];
        temperature[i] += temperature[i - 1];
    }

    ret = temperature[K];
    for(int i = K; i <= N; i++){
		ret = max(ret, temperature[i] - temperature[i - K]);
	}
    cout << ret << '\n';

    return 0;
}