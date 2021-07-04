#include <iostream>
#include <cmath>
using namespace std;

//少数が存在するか調べ、trueかfalseを返す
bool hasDecimal(double x) {
    // fmodはfload modのこと。これを使うことで余りを求めることができる
    return fmod(x, 1) != 0;
}

// 完全な平方かどうかチェックする。与えられた数字の平方根が整数であれば完全な平方
bool isPerfectSquare(int x) {
    // 小数ではない場合、trueを返す
    return !hasDecimal(sqrt(x));
}

/*
    例題1
    整数を受け取って、4乗した数値が偶数であればtrue、奇数ならfalseを返すcheck4thPowerという関数を関数の合成を使って作成する
    使用する関数：isEven(int) → 整数を受け取って偶数ならtrue、奇数ならfalseを返す
*/
// 偶数かどうか判定する
bool isEven(int x) {
    return fmod(x, 2) == 0;
}

bool check4thPower(int x) {
    // 関数内で関数を呼び出している
    return isEven(pow(x, 4));
}

/*
    例題２
    複利を使って合計金額を計算する銀行ソフトウェアを作成する
    将来最終的に得られる金額は複利を使って、P(1+i)^nとして計算される（P：元金、i：年率、n：期間）
    今、最初の元金が偶数なら年率1.02%、奇数なら年率1.03%になる。関数の合成を使って将来的に得られる金額を返す
    使用する関数1：multiply(double x, double y) → x*y
    使用する関数2：evenOrOdd(int x) → 整数を受け取って偶数なら0.02、奇数なら0.03を返す
*/
double multiply(double x, double y) {
    return x*y;
}

double evenOrOdd(int x) {
    // isEvenをすでに定義しているので呼び出す
    return (isEven(x))? 0.02: 0.03;
}

double goalMoney(int capital, int year) {
    // P(1+i)^2
    return multiply(capital, pow(1+evenOrOdd(capital), year));
}

int main(){
    cout << (isPerfectSquare(169)? "True" : "False") << endl; // True
    cout << (isPerfectSquare(35)? "True" : "False") << endl; // False

    // 例題1の関数を呼び出し、出力してみましょう。
    cout << check4thPower(1) << endl;
    cout << check4thPower(2) << endl;
    cout << check4thPower(3) << endl;
    cout << check4thPower(10) << endl;
    // check4thPower(1) → false
    // check4thPower(2) → true
    // check4thPower(3) → false
    // check4thPower(10) → true

    // 例題2の関数を呼び出し、出力してみましょう。
    cout << goalMoney(10, 1) << endl;
    cout << goalMoney(9, 1) << endl;
    cout << goalMoney(10, 29) << endl;
    // goalMoney(10, 1) → 10.2
    // goalMoney(9, 1) → 9.27
    // goalMoney(10, 29) → 17.758446902974065
}