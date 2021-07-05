#include <iostream>
using namespace std;

// ある数値を受け取って、1を足して返す
int addOf1(int x) {
    return x + 1;
}

// ある数値を受け取って、1を足して返す
int wholeNumberAddition(int x, int y) {
    if(y <= 0) return x;
    return wholeNumberAddition(x+1, y-1);
}

// ある数値を受け取って、1を引いて返す
int wholeNumberSubstraction(int x, int y) {
    if(y <= 0) return x;
    return wholeNumberSubstraction(x-1, y-1);
}

int main() {
    cout << addOf1(5) << endl;

    cout << wholeNumberAddition(5,4) << endl;
    cout << wholeNumberAddition(10,23) << endl;

    cout << wholeNumberSubstraction(5,4) << endl;  
    cout << wholeNumberSubstraction(23,10) << endl;  
 
    return 0;
}