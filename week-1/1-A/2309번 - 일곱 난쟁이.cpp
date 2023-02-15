#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int dwarfs[9] = {0};
    int visit[9] = {0};

    for (int i = 0; i < 9; i++) {
        cin >> dwarfs[i];
    }
    for (int i = 2; i < 9; i++) {
        visit[i] = 1;
    }

    sort(dwarfs, dwarfs + 9);

    do {
        int sum = 0;
        for(int i = 0; i < 9; i++) {
            if (visit[i]) sum += dwarfs[i];
        }
        if(sum == 100) break;
    } while(next_permutation(visit, visit + 9)); 

    for (int i = 0; i < 9; i++) {
        if (visit[i]) cout << dwarfs[i] << '\n';
    }

    return 0;
}