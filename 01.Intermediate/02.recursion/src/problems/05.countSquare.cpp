/*
    Thomas は図画工作で色紙を使って飛行機を作成しています。色紙にはさまざまなサイズが用意されており、選択することができます。
    今、Thomas は長方形の色紙からできるだけ大きく、かつ同じ大きさの正方形を何枚も切り取ることを計画しています。
    長方形の大きさとして、縦 x、横 yが与えられるので、正方形の合計枚数を返す、countSquare という関数を作成してください。

    入力のデータ型： integer x, integer y
    出力のデータ型： integer
    countSquare(28,32) --> 56
    countSquare(20,32) --> 40
    countSquare(8177,3315) --> 555
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
    1. 最大公約数を求める
    2. 長方形の面積から最大公約数の正方形の面積を割った商が合計枚数
*/
int gcd(int x, int y) {
    if(x%y == 0) return y;
    return gcd(y, x%y);
}

int countSquare(int x,int y){
    return (x * y) / pow(gcd(x, y), 2);
}
