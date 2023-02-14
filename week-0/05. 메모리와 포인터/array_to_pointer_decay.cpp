#include <iostream>
using namespace std;

int a[3] = {1, 2, 3};
int main() {
    int *c = a;

    cout << a << '\n';
    cout << c << '\n';
    cout << &a[0] << '\n';

    cout << a + 1 << '\n';
    cout << c + 1<< '\n';
    cout << &a[1] << '\n';

    return 0;
}