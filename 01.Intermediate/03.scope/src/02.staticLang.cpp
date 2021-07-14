#include <iostream>
using namespace std;

// グローバルスコープ
// 変数、関数の定義しかできないので計算をここでするとエラーになる
int x = 34;
int y = 10;

// パラメータはローカルスコープなので、ここでのxはローカルスコープ
double square(int x) {
    return x * x;
}

// xはローカルスコープ
// yはローカルスコープで定義されていないため、グローバルスコープを見ている
double globalMult(int x) {
    return x * y;
}

// 名前空間
namespace a {
    int x = 3;
    int y = 10;

    int multiply(int x) {
        // a::multiplyスコープにはyが存在しないため、親スコープのyを見ている
        return x * y;
    }
    // 名前空間の入れ子
    namespace b {
        int x = 15;

        // スコープが異なるので同じ名前でも宣言できる
        int multiply(int x) {
            // b::multiply関数スコープにはyが存在しないため、親スコープのy（正確にはa::y）を見ている
            return x * y;
        }
    }
}

int main() {
    // main関数のスコープ

    // xを出力
    // main関数にてxは宣言されていないため、グローバルスコープのxを見ている
    cout << x << endl;

    // xを宣言
    int x = 56;

    // xを出力
    // main関数にてxが宣言されているため、ローカルスコープのxを見ている
    cout << x << endl;

    cout << square(4) << endl; // 16
    cout << globalMult(4) << endl; // 40

    cout << a::x << endl; // 3

    cout << a::multiply(5) << endl; // 50

    cout << a::b::x << endl; //15

    cout << a::b::multiply(2) << endl; // 20
    return 0;
}