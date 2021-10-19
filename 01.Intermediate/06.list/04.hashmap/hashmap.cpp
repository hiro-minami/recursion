#include <iostream>
#include <map> // mapライブラリーを読み込みます。
using namespace std;

int main() {
    // 連想配列を初期化するには、{} initialize構文を使用します。
    // キーと値のペアを内部に配置します。構文は次のようになります: {key,value}。
    // 静的型付け言語なので、データ型を指定する必要があります。map<key型,value型>
    map<string, string> myPet = {
        {"name", "fluffy"},
        {"species", "Pomeranian"},
        {"furColor", "Brown"},
        {"born", "2018/05/06"},
        {"favoriteFood", "Carrot sticks"}
    };

    // nameの取得
    cout << myPet["name"] << endl;
    // ペットのfavorite foodを取得
    cout << myPet["favoriteFood"] << endl;
    // このmyPet辞書にさらに情報を追加
    myPet["napTimes"] = "11:00am, 3:30pm, 9:00pm";
    cout << myPet["napTimes"] << endl;

    map<string, int> car = {
        {"Honda Civic", 24000},
        {"Chevrolet Traverse", 30000},
        {"Toyota Camry", 25000},
        {"Subaru Outback", 27000},
        {"Tesla X", 100000}
    };

    // Tesla XとToyota Camryを取得
    cout << car["Tesla X"] << endl;
    cout << car["Toyota Camry"] << endl;

    // BMW X3 -> 42,000 を追加
    car["BMW X3"] = 42000;
    cout << car["BMW X3"] << endl;

    return 0;
}