#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    int parking[101] = {0,};
    int fee = 0;

    cin >> A >> B >> C;

    for (int i = 0; i < 3; i++) {
        int arrive, leave;
        cin >> arrive >> leave;

        for (int j = arrive; j < leave; j++) parking[j]++;
    }

    for (int i : parking) {
        if (i == 0) continue;
        if (i == 1) fee += A;
        if (i == 2) fee += (B * 2);
        if (i == 3) fee += (C * 3);
    }

    cout << fee << '\n';

    return 0;
}