/*
    Juan は小学 1 年生の息子に足し算を教える方法として、桁数を分解して足し合わせるという方法を思いつきました。
    自然数 digits が与えられるので、桁数を分解して足し合わせる、splitAndAdd という関数を再帰を使って作成してください。
    例えば、98 は、9 + 8 = 17 となり、9728 は、9 + 7 + 2 + 8 = 26 となります。

    入力のデータ型： integer digits
    出力のデータ型： integer
    splitAndAdd(19) --> 10
    splitAndAdd(898) --> 25
    splitAndAdd(23387) --> 23
    splitAndAdd(1066) --> 13
    splitAndAdd(546125) --> 23
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
    数字を分解して足す
    1. digitsが1桁の場合、sumにdigitsを足して返す
    2. digitsを10で割った商をdigitsに、sumにdigitsを10で割ったあまりを足した値をsumに入れて再帰
*/
int splitAndAddHelper(int digits, int sum) {
    if(digits < 10) return sum + digits;
    return splitAndAddHelper(floor(digits / 10), sum + (digits % 10));
}

int splitAndAdd(int digits){
    return splitAndAddHelper(digits, 0);
}
