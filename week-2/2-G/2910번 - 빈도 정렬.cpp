#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, C;
map<int, int> mp, mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int,int> a, pair<int, int> b){
    if (a.first == b.first) {
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}

int main(){
	cin >> N >> C;

    int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp; mp[tmp]++;
        if (mp_first[tmp] == 0) mp_first[tmp] = i + 1;
	}

    for (auto it : mp) {
        v.push_back({it.second, it.first});
    }

	sort(v.begin(), v.end(), cmp);

    for (auto it : v) {
        for (int i = 0; i < it.first; i++) {
            cout << it.second << ' ';
        }
    }
	 
	return 0;
}
