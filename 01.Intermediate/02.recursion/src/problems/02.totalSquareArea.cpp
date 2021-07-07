/*
    1 辺 1 の正方形をスタートとして、1 辺の長さ、正方形の個数を列ごとに増加させていきます。
    i 列の中には 1 辺 i の正方形が i 個あり、i 列に含まれる正方形の合計面積を計測します。
    自然数 x が与えられるので、1 列から x 列までに含まれる全ての正方形の面積の合計値を返す、
    totalSquareArea という関数を再帰によって作成してください。総和や 3 乗を計算するために必要な他の関数は用いて構いません。

    入力のデータ型： integer x
    出力のデータ型： integer
    totalSquareArea(1) --> 1
    totalSquareArea(2) --> 9
    totalSquareArea(3) --> 36
    totalSquareArea(4) --> 100
    totalSquareArea(5) --> 225
    totalSquareArea(12) --> 6084
    totalSquareArea(10) --> 3025
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 3乗した値をΣ計算
int totalSquareArea(int x){
    if(x <= 0) return 0;
    return pow(x, 3) + totalSquareArea(x-1);
}

int main() {
    cout << totalSquareArea(1) << endl;
    cout << totalSquareArea(2) << endl;
    cout << totalSquareArea(3) << endl;
    cout << totalSquareArea(4) << endl;
    cout << totalSquareArea(5) << endl;
    cout << totalSquareArea(12) << endl;
    cout << totalSquareArea(10) << endl;
    return 0;
}