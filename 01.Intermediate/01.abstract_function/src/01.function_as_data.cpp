#include <iostream>
#include <regex>
#include <string>
using namespace std;


// 文字列を引数として受け取り、その文字列を2回繰り返した値を返す
string doubleSubstring(string str) {
    return str + str;
}

// main
int main() {
    string str = "hello";
    // doubleSubstring()はstring型を返す→string型の組み込み関数を使うことができる
    // doubleSubstring()の戻り値にsubstrメソッドを使って、ある文字を削除することができる
    // さらにsubstrメソッドの戻り値にfincメソッドを使って、"ll"のインデックスを返すことができる
    cout << doubleSubstring(str).substr(1).find("ll") << endl;

    // 例題1
    string mail = "recursion@info.com";

    /*
        メソッドチェーンを使って、「Com」という文字を出力する
        1. substrメソッドを使って「com」のみ出力する
        2. toupperメソッドを使って、cのみ大文字にする
        3. 大文字にしたcとomを結合する
    */
    string com = mail.substr(mail.find(".")+1, 3);
    cout << string("") + (char)toupper(com[0]) + mail.substr(1) << endl;

    /*
        メソッドチェーンを使って、「%info.com」を出力する
        1. substrを使って@info.comのみ出力する
        2. @info.comの中から@を探し、repleceメソッドを使って%に変換する
    */
    cout << mail.substr(mail.find("@")).replace(0, 1, "%") << endl;

    /*
        メソッドチェーンを使って、「RecuRsion」を出力する
        1. substrメソッドを使って、recursionのみ出力する
        2. 0番目のrと4番目のrをreplaceメソッドを使ってRに変換する（それぞれreplaceメソッドを呼び出す）
    */
    cout << mail.substr(0, mail.find("@")).replace(0, 1, "R").replace(4, 1, "R") << endl;

    // 正規表現を使ったバージョン（#include <regex>忘れない）
    // regex_replace(対象の文字列, regex(正規表現を指定),置換する文字)メソッドを使う
    cout << regex_replace(mail.substr(0, mail.find("@")), regex("r"), "R");
}