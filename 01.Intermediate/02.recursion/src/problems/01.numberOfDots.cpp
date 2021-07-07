/*
    図のように三角数の数列があります。天才 Pascal は小学生の時にこの並びを見て規則的な発見をしました。
    整数 x が与えられるので、x 番目の三角形に含まれるドットの数を返す、numberOfDots という関数を再帰を使って作成してください。

    入力のデータ型： integer x
    出力のデータ型： integer
    numberOfDots(2) --> 3
    numberOfDots(4) --> 10
    numberOfDots(5) --> 15
    numberOfDots(10) --> 55
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Σ計算
int numberOfDots(int x){
    if(x <= 0) return 0;
    return x + numberOfDots(x-1);
}

int main() {
    cout << numberOfDots(2) << endl;
    cout << numberOfDots(4) << endl;
    cout << numberOfDots(5) << endl;
    cout << numberOfDots(10) << endl;
    return 0;
}