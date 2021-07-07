#include <iostream>
using namespace std;
#include <cmath>

/*
    近似値かどうか判定する関数
    input: double a, double b
    output: bool
    outline:
        return abs(a/b - b) < (b * 0.0001)
*/
bool isSquareRootCloseEnough(double a, double b) {
    return abs(a/b - b) < (b * 0.0001);
}

/*
    ヘルパー関数
    input: double x, double guess
    output: double
    outline:
        isSquareRootCloseEnough(x, guess) == true -> return guess
        else return squareRootHelper(x, (guess + x/guess)/2)
*/
double squareRootHelper(double x, double guess) {
    if(isSquareRootCloseEnough(x, guess) == true) return guess;
    return squareRootHelper(x, (guess + x/guess)/2);
}

/*
    近似値を求める関数
    input: double x
    output: double
    outline:
        return squareRootHelper(x, 1)
*/
double squareRoot(double x) {
    return squareRootHelper(x, 1);
}

int main(){
    cout << squareRoot(65) << endl; // 8.06226
    return 0;
}