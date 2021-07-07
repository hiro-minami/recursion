/*
    Catherine は与えられた単語や文章を逆側から読み上げる遊びを友達とやっています。
    文字列 string が与えられるので、string を反転した文字列を返す reverseString という関数を再帰を使って定義してください。

    入力のデータ型： string string
    出力のデータ型： string
    reverseString("abcd") --> dcba
    reverseString("recursion") --> noisrucer
    reverseString("I am a software engineer") --> reenigne erawtfos a ma I
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string reverseStringHelper(string str, int count, string ans) {
    if(count < 0) return ans;
    return reverseStringHelper(str, count-1, ans + str[count]);
}

string reverseString(string string){
    return reverseStringHelper(string, string.length()-1, "");
}

int main() {
    cout << reverseString("abcd") << endl;
    cout << reverseString("recursion") << endl;
    cout << reverseString("I am a software engineer") << endl;
    return 0;
}