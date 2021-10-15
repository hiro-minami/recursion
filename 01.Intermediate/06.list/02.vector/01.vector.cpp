#include <iostream>
#include <vector>
using namespace std;

// 動的配列を取得し，その内容を出力します。
void printArray(vector<int> intArr) {
    for(int i=0; i<intArr.size(); i++) {
        // vectorはatメソッドを使ってn番目の要素を取得することができる
        cout << intArr.at(i) << " ";
    }
    cout << endl;
}

int main() {
    // 動的配列ばC++ではvectorと呼ばれる。vector<データ型>で宣言できる
    vector<int> dArr = {2,3,4,1,-10,200};
    printArray(dArr);

    // push_backメソッドを使うことで動的配列に値を追加できる
    dArr.push_back(10);
    dArr.push_back(340);
    dArr.push_back(543);
    dArr.push_back(-23);

    // dArrの新しい状態を出力する。
    printArray(dArr);

    return 0;
}