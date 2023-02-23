#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

const int INF = 987654321;

int N, M;
int map[51][51];
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;

int chick_len = INF;

int getChickenLen(vector<int> open) {
    int city_len = 0;
    for (auto house : houses) {
        int house_len = INF;
        for (auto i : open) {
            int len = abs(house.first - chickens[i].first) + abs(house.second - chickens[i].second);
            house_len = min(house_len, len);
        }
        city_len += house_len;
    }
    return city_len;
}

void combi(int start, vector<int> v) {
    if (v.size() == M) {
        chick_len = min(chick_len, getChickenLen(v));
        return;
    }
    for (int i = start + 1; i < chickens.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return ;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) chickens.push_back({i, j});
            if (map[i][j] == 1) houses.push_back({i, j});
        }
    }

    vector<int> open;
    combi(-1, open);

    cout << chick_len << '\n';

    return 0;
}