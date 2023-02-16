#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string pattern, prefix, suffix;
string filename;

string match() {
    if (prefix.length() + suffix.length() > filename.length()) {
        return "NE";
    }
    if (prefix != filename.substr(0, prefix.length())) {
        return "NE";
    }
    if (suffix != filename.substr(filename.length() - suffix.length())) {
        return "NE";
    }
    return "DA";
}

int main() {
    cin >> N;
    cin >> pattern;

    int pos = pattern.find('*');
    prefix = pattern.substr(0, pos);
    suffix = pattern.substr(pos + 1);

    for (int i = 0; i < N; i++) {
        cin >> filename;
        cout << match() << '\n';
    }

    return 0;
}