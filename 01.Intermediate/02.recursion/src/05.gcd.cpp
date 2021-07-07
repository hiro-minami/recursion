#include <iostream>
using namespace std;

/*
    最大公約数を引き算を使って求める
    大きい方から小さい方を引いて再帰。同じ値になったらそれが答え。
    1. m == n return m
    2. m > n return culcGcdByDiv(m-n, n)
    3. else return culcGcdByDiv(m, n-m)
*/
int culcGcdBySub(int m, int n) {
    if(m == n) return m;
    else if(m > n) return culcGcdBySub(m-n, n);
    return culcGcdBySub(m, n-m);
}

/*
    最大公約数を割り算を使って求める
    大きい方から小さい方の割り算のあまりが0なら小さい方が答え
    1. m % n == 0 return n
    2. else return 
*/
int culcGcdByDiv(int m, int n) {
    if(m%n == 0) return n;
    return culcGcdByDiv(n, m%n);
}


int main(){

    // 引き算を使った最大公約数の求め方
    cout << culcGcdBySub(44,242) << endl;
    cout << culcGcdBySub(45,210) << endl;

    // 割り算の余りを使った最大公約数の求め方
    cout << culcGcdByDiv(44,242) << endl;
    cout << culcGcdByDiv(3355,2379) << endl;

    return 0;
}