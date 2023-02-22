#include <iostream>
#include <string>
using namespace std;

int N, team;
string time_score;

int team1, team2;
int score1, score2;

void printTime(int time) {
    int min = time / 60;
    int sec = time % 60;
    
    min >= 0 && min <= 9 ? cout << '0' << min : cout << min;
    cout << ':';
    sec >= 0 && sec <= 9 ? cout << '0' << sec : cout << sec;
    cout << '\n';
}

int stringToSec(string s) {
    int min = atoi(s.substr(0, 2).c_str());
    int sec = atoi(s.substr(3).c_str());
    return (min * 60) + sec;
}

int main() {
    cin >> N;
    
    int time_curr = 0;
    int time_prev = 0;
    for (int i = 0; i < N; i++) {
        cin >> team >> time_score;

        time_curr = stringToSec(time_score) - time_prev;

        if (score1 > score2) team1 += time_curr;
        if (score2 > score1) team2 += time_curr;

        team == 1 ? score1++ : score2++;
        time_prev = stringToSec(time_score);
    }

    time_curr = (48 * 60) - time_prev;
    if (score1 > score2) team1 += time_curr;
    if (score2 > score1) team2 += time_curr;

    printTime(team1); printTime(team2);
    return 0;
}