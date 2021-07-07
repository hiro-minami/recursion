/*
    Michaela は今日昼寝をしてしまったため、なかなか寝付くことができません。
    そこで羊を 1 匹ずつ数えて眠りを待つことにしました。自然数 count が与えられるので、
    夢の中で count 匹羊を数える、sheeps という関数を作成してください。

    入力のデータ型： integer count
    出力のデータ型： string
    sheeps(2) --> 1 sheep ~ 2 sheep ~ 
    sheeps(4) --> 1 sheep ~ 2 sheep ~ 3 sheep ~ 4 sheep ~ 
    sheeps(5) --> 1 sheep ~ 2 sheep ~ 3 sheep ~ 4 sheep ~ 5 sheep ~ 
    sheeps(10) --> 1 sheep ~ 2 sheep ~ 3 sheep ~ 4 sheep ~ 5 sheep ~ 6 sheep ~ 7 sheep ~ 8 sheep ~ 9 sheep ~ 10 sheep ~ 
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Helper関数を使う
string sheepsHelper(int count, string str) {
    if(count <= 0) return str;
    return sheepsHelper(count-1, to_string(count) + " sheep ~ " + str);
}

string sheeps(int count){
    return sheepsHelper(count, "");
}

int main() {
    cout << sheeps(2) << endl;
    cout << sheeps(4) << endl;
    cout << sheeps(5) << endl;
    cout << sheeps(10) << endl;
    return 0;
}