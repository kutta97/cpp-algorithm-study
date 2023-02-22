#include <iostream>
#include <algorithm>
using namespace std;

int t, a;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> t; 
	while (t--) {
		cin >> a;
		int ret2 = 0, ret5 = 0;
		for (int i = 2; i <= a; i *= 2) {
			ret2 += a / i;
		}
		for (int i = 5; i <= a; i *= 5) {
			ret5 += a / i;
		}
		cout << min(ret2, ret5) << "\n";
	} 
	return 0;
}