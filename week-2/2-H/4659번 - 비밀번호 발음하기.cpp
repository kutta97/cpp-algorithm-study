#include <iostream>
#include <string>
using namespace std;

string input;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isAcceptable() {
    bool is_include_vowel = false;
    int cnt_v = 0;
    int cnt_c = 0;

    for (int i = 0; i < input.size(); i++) {
        if (isVowel(input[i])) {
            is_include_vowel = true;
            cnt_c = 0; cnt_v++;
        } else {
            cnt_c++; cnt_v = 0;
        }
        if (cnt_v == 3 || cnt_c == 3) return false;
        if (i > 0) {
            if (input[i - 1] == input[i] && input[i] != 'e' && input[i] != 'o') return false;
        }
    }
    if (!is_include_vowel) return false;
    return true;
}

int main() {
    while (true) {
        cin >> input;
        if (input == "end") break;
        cout << '<' << input << '>' << " is ";
        cout << (isAcceptable() ? "acceptable." : "not acceptable.") << '\n';
    }
    return 0;
}