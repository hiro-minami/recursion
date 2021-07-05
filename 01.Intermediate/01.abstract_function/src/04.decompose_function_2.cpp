#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

/*
    関数を以下の要領で分ける
        1. ランダムなインデックスを生成する関数
        2. 文字コードが奇数か偶数かを判定する関数
        3. 文字のインデックスを把握するための文字列を返す関数
        4. 1~3の関数を呼び出してランダムな文字の文字コードが偶数か奇数かを出力する関数
*/
int randomInteger(int min, int max) {
    srand(time(0));
    rand();

    // 0~1 * (max - min + 1) + minで0~最後のインデックスの値を取得する
    return floor(((double) rand() / RAND_MAX) * (max - min + 1) + min);
}

bool isCharCodeEven(char c) {
    return (c % 2 == 0) ? true : false;
}

string chosenCharacter(int index, string str) {
    return string("The char [") + str[index] + "] at index " + to_string(index);
}

string randomCharEvenOrOdd(string str) {
    int randomIndex = randomInteger(0, str.length()-1);
    bool isCharEven = isCharCodeEven(str[randomIndex]);
    string message = chosenCharacter(randomIndex, str);

    return isCharEven ? message + " is Even" : message + " is Odd";
}

int main() {
    cout << randomCharEvenOrOdd("Don't tell me lies.") << endl;
}