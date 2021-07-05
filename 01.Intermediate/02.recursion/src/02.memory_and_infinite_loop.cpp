#include <iostream>
using namespace std;

// ある数値を受け取って、1を足して返す
int wholeNumberAddition(int x, int y) {
    // yが0になった時、追加する1がないため、ループを終了する
    if(y <= 0) return x;
    return wholeNumberAddition(x+1, y-1);
}

int main(){

    cout << wholeNumberAddition(5,4) << endl;
    cout << wholeNumberAddition(10,23) << endl;

    return 0;
}