#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

// 分解された関数群
// ランダムな数字を取得する関数
int randomInteger(int min, int max) {
    srand(time(0));
    rand();

    return floor(((double) rand() / RAND_MAX) * (max - min + 1) + min);
}

// 母音かどうか判定
bool isVowel(char c) {
    string vowel = "aiueo";
    return (vowel.find(c) == std::string::npos) ? false : true;
}

// 偶数判定
bool isEven(int n) {
    return (n % 2 == 0) ? true : false;
}


// 関数呼び出しのための関数群
/*
    母音判定
        ランダムな数字を取得する関数呼び出し
        母音かどうか判定する関数呼び出し
*/
bool isRandomCharVowel(string str) {
    int randomIndex = randomInteger(0, str.length()-1);
    return isVowel(str[randomIndex]);
}

/*
    偶数判定
        ランダムな数字を2つ取得する
        文字コードを足し算する
        偶数かどうか判定する関数呼び出し
*/
bool isRandomEncodeEven(string str1, string str2) {
    int randomIndex1 = randomInteger(0, str1.length()-1);
    int randomIndex2 = randomInteger(0, str2.length()-1);
    int addCharCode = (int)str1[randomIndex1] + (int)str2[randomIndex2];
    return isEven(addCharCode);
}


int main() {
    // 例題1
    cout << isRandomCharVowel("abcdefgh") << endl;
    cout << isRandomCharVowel("recursion") << endl;

    // 例題2
    cout << isRandomEncodeEven("recursion", "programming") << endl;
    cout << isRandomEncodeEven("HELLO", "hello") << endl;
}