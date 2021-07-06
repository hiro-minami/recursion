#include <iostream>
using namespace std;

int g(int i) {
    return i;
}

/*
    総積を求める
    b < aの時、return 1
    b >= aの時、return b * productSequenceOfi(a, b-1)
*/
int productSequenceOfi(int a, int b) {
    if(b < a) return 1;
    return g(b) * productSequenceOfi(a, b-1);
}

/*
    累乗を求める
    b <= 0の時、return 1
    b > 0の時、return g(a) * muliplyOfc(a, b-1)
*/
int muliplyOfc(int a, int b) {
    if(b <= 0) return 1;
    return muliplyOfc(a, b-1);
}

int main(){
    cout << productSequenceOfi(1, 7) << endl;
    cout << productSequenceOfi(1, 3) << endl;

    cout << muliplyOfc(2, 5) << endl;
    cout << muliplyOfc(3, 5) << endl;
    return 0;
}