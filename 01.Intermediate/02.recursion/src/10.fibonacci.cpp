#include <iostream>
using namespace std;

/*
    フィボナッチ数列
    input: int n
    output: int
    outline:
        n == 0 -> return 0
        n == 1 -> return 1
        else -> return fibonacciNumber(n-1) + fibonacciNumber(n-2)
*/
int fibonacciNumber(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}

int main() {
    cout << fibonacciNumber(3) << endl;
    cout << fibonacciNumber(5) << endl;
    cout << fibonacciNumber(8) << endl;
    cout << fibonacciNumber(10) << endl;
    return 0;
}