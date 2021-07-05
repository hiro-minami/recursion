#include <iostream>
using namespace std;

// g(i)
int g(int i) {
    return i;
}

// 総和
int summationOfi(int a, int b) {
    if(b < a) return 0;
    return g(b) + summationOfi(a, b-1);
}

// 総和を使って掛け算
int summationOfc(int a, int b) {
    if(b <= 0) return 0;
    return g(a) + summationOfc(a, b-1);
}

int main() {
    cout << summationOfi(1, 5) << endl;
    cout << summationOfi(1, 10) << endl;

    cout << summationOfc(2, 5) << endl;
    cout << summationOfc(3, 5) << endl;
    return 0;
}