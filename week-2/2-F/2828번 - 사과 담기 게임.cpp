#include <iostream>
using namespace std;

int n, m, j;
int l, r;
int apple, ret;

int main () {
	cin >> n >> m >> j; 
	l = 1;  
	while (j--) {
		r = l + (m - 1);
		cin >> apple;
		if(apple >= l && apple <= r) continue;
		if (apple < l) {
            ret += (l - apple);
            l = apple;
        }
        if (apple > r) {
            ret += (apple - r); 
            l += (apple - r);
        }
	} 
	cout << ret << "\n"; 
	return 0;
}