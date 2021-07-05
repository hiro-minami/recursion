#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;


// メイン関数で呼び出すための関数
string randomCharEvenOrOdd(string str) {
    /*
        乱数を生成
            srand(), time(), rand()を組み合わせることで乱数を発生できる
            srand()を使うことでrand()による乱数生成パターンを毎回変更する
        どうやってsrand()を使って乱数生成パターンを変更するのか
            time(0)を利用する←現在時刻を利用して乱数生成パターンを作成・変更する
                現在時刻は毎回違うため
    */
    srand(time(0));
    rand();

    // 文字列の最後のインデックスを変数に代入
    int maxIndex = str.length() - 1;

    /*
        ランダムな整数を取得する
            rand() / RAND_MAXによって、0~1までの値をランダムに得ることができる（小数点は切り捨て）
            (rand() / RAND_MAX) * (maxIndex + 1)で0~最後のインデックスまでの値をランダムに得る
    */
    int randomIndex = floor(((double) rand() / (RAND_MAX)) * (maxIndex + 1));

    // 文字をランダムに取得
    char randomChar = str[randomIndex];

    // 最初のcharはstringに変換しないといけない
    string message = string("[") + randomChar+"]" + " at index " + to_string(randomIndex) + " is ";

    bool isEven = false;

    if(randomChar % 2 == 0) isEven = true;

    message = isEven ? message + " is Even" : message + " is Odd";

    return message;
}

int main() {
    cout << randomCharEvenOrOdd("Don't tell me lies.") << endl;
    return 0;
}