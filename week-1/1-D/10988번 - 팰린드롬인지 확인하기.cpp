#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string word;

int palindrome() {
    string r = word;
    reverse(r.begin(), r.end());
    return word == r;
}

int main() {
    cin >> word;
    cout << palindrome() << '\n';
    return 0;
}