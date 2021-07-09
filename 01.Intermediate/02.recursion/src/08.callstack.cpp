#include <iostream>
using namespace std;
#include <math.h>

// x - y
int subtract(int x, int y) {
    int myResult = x - y;
    return myResult;
}

// base^power
double powerFunc(int base, int power) {
    return pow(base, power);
}

int main() {
    // subtract() -> powerFunc() -> *の順番で計算される
    cout << subtract(4, 10) * 20 * powerFunc(2, 5) << endl;
    return 0;
}