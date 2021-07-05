#include <iostream>
#include <string>
using namespace std;

// 分解した関数群
/*
    明日学校があるかどうか判定する
    input:  string day, bool isHoliday
    output: bool
    outline:
        day == "Saturday" || day == "sunday" || isHoliday == true -> false
        else -> true
*/
bool haveClassesTomorrow(string day, bool isHoliday) {
    if (day == "Saturday" || day == "sunday" || isHoliday == true) return false;
    return true;
}

/*
    閏年かどうか判定する
    input:  int year
    output: bool
    outline:
        1. year % 400 == 0 -> true
        2. year % 4 == 0 && year %100 != 0 -> true
        3. else -> false
*/
bool isLeapYear(int year) {
    if(year % 400 == 0) return true;
    else if(year % 4 == 0 && year % 100 != 0) return true;
    return false;
}

/*
    カラオケの値段を求める
    input:  int people
    output: int
    outline:
        1. int perPerson
        2-1. people <= 3 -> perPerson = 8
        2-2. people < 10 -> perPerson = 6
        2-3. else -> perPerson = 5
        3. return perPerson * people
*/
int culcKaraokeFee(int people) {
    int perPerson;

    if(people <= 3) perPerson = 8;
    else if(people < 10) perPerson = 6;
    else perPerson = 5;

    return perPerson * people;
}

// 関数呼び出しのための関数群
/*
    カラオケで請求される金額を返す
    input:  string day, bool isHoliday, int lastDigits, int num
    ouptut: int
    outline:
        1. int price = culcKaraokeFee(num)
        2. haveClassesTomorrow(day, isHoliday) == false -> price *= 4
        3. isLeapYear(lastDigits) == true -> price /= 2
        4. return price
*/
int getKaraokeFee(string day, bool isHoliday, int lastDigits, int num) {
    int price = culcKaraokeFee(num);

    if(haveClassesTomorrow(day, isHoliday) == false) price *= 4;
    if(isLeapYear(lastDigits) == true) price /= 2;
    
    return price;
}

// main
int main(){
    // 120
    cout << getKaraokeFee("Sunday", true, 1900, 5) << endl;
    // 120
    cout << getKaraokeFee("Sunday", true, 2000, 12) << endl;
    // 64
    cout << getKaraokeFee("Saturday", false, 1900, 2) << endl;
    // 48
    cout << getKaraokeFee("Saturday", false, 2000, 4) << endl;
    // 24
    cout << getKaraokeFee("Monday", false, 2002, 3) << endl;
    // 200
    cout << getKaraokeFee("Monday", true, 2024, 20) << endl;
}