#include <iostream>
#include <string>
using namespace std;

int i = 0;
string s = "kutta";
int main() {
    int *a = &i;
    cout << &i << '\n';
    cout << a << '\n';
    cout << sizeof(a) << '\n';

    string *b = &s;
    cout << &s << '\n';
    cout << b << '\n';
    cout << sizeof(b) << '\n';

    return 0;
}