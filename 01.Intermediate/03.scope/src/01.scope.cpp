#include <iostream>
using namespace std;

string userName() {
    // ローカルスコープ
    string firstName = "Emily";
    string lastName = "Robertson";

    return firstName + "-" + lastName;
}

// グローバルスコープ
string firstName = "Masamune";
string lastName = "Watanabe";

int main() {
    // グローバルスコープのfirstName, lastNameを見ている
    cout << firstName + " - " + lastName << endl;

    // main関数のスコープで使えるfirstName, lastNameを宣言
    string firstName = "Fernando";
    string lastName = "Yamato";

    // 上で宣言したfirstName, lastNameを見ている
    cout << firstName + " - " + lastName << endl;

    // userName()で宣言したfirstName, lastNameを見ている
    cout << userName() << endl;

    // main関数のスコープで使えるfirstName, lastNameを上書き
    firstName = "Andy";
    lastName = "Jordan";

    // 上で変更したfirstName, lastNameを見ている
    cout << firstName + " - " + lastName << endl;

    return 0;
}