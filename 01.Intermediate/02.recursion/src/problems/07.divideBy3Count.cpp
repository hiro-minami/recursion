/*
    3 の累乗 n が与えられるので、整数 n を 3 で除算できる回数を返す、divideBy3Count という関数を作成してください。

    入力のデータ型： integer n
    出力のデータ型： integer
    divideBy3Count(1) --> 0
    divideBy3Count(3) --> 1
    divideBy3Count(27) --> 3
    divideBy3Count(729) --> 6
    divideBy3Count(6561) --> 8
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
    3で割り続ける関数のヘルパー関数
    input: int n, int count
    output: int
    outline:
        3で割った商が0以下の時->countを返す
        それ以外->n / 3, count + 1を引数にして再帰
*/
int divideBy3CountHelper(int n, int count) {
    if(n / 3 <= 0) return count;
    return divideBy3CountHelper(n / 3, count + 1);
}

int divideBy3Count(int n){
    return divideBy3CountHelper(n, 0);
}