#include <iostream>
#include <string>
using namespace std;

int N;
int alpha[26];
string name;
string answer;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> name;

        int initial = name[0];
        alpha[initial - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] < 5) continue;
        answer += (i + 'a');
    }

    if (answer.empty()) answer = "PREDAJA";
    cout << answer << '\n';
    return 0;
}