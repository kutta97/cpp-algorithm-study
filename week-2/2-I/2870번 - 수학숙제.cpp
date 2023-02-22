#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string s;

vector<string> v;

bool isDigit(char c) {
    return (c - '0') >= 0 && (c - '0') <= 9;
}

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void findNumber() {
    bool flag = false;

    string number = "";
    for (char c : s) {
        if (isDigit(c)) {
            flag = true;
            if (number == "0") number = c;
            else number += c;
        } else {
            if (flag) v.push_back(number);
            flag = false;
            number = "";
        }
    }
    if (flag) v.push_back(number);
}

int main() {
    cin >> N;
    while (N--) {
        cin >> s;
        findNumber();
    }

    sort(v.begin(), v.end(), cmp);
    
    for (auto it : v) {
        cout << it << '\n';
    }
    return 0;
}