#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printArray(vector<int> intArr) {
    cout << "[";
    for(int i=0; i<intArr.size(); i++) {
        cout << intArr.at(i) << " ";
    }
    cout << "]" << endl;
}

int main() {
    // 初期配列を2つの項目に設定する
    vector<int> dArr = {2, 3};

    cout << "Insert/Delete at the beginning O(n)" << endl;
    printArray(dArr);

    // 配列の先頭に要素を追加します。O(n)
    cout << "要素を追加します" << endl;
    dArr.insert(dArr.begin(), 3);
    dArr.insert(dArr.begin(), {3,43,5234,34});
    printArray(dArr);

    // 配列の先頭の要素を削除するO(n)
    cout << "要素削除" << endl;
    dArr.erase(dArr.begin());
    printArray(dArr);

    // インデックス2の位置にある要素を削除します。O(n)
    dArr.erase(dArr.begin() + 2);
    printArray(dArr);

    cout << "Insert/Delete at the middle O(n)" << endl;
    // 配列の真ん中に要素を追加する
    cout << "要素追加" << endl;
    dArr.insert(dArr.begin() + floor(dArr.size()/2), 4);
    printArray(dArr);
    dArr.insert(dArr.begin() + floor(dArr.size()/2), {343,32,23,24,12,23,98,767});
    printArray(dArr);

    // 配列の途中の要素を削除します。
    cout << "要素削除" << endl;
    dArr.erase(dArr.begin() + floor(dArr.size()/2));
    // 配列の途中から、5つ先まで削除します。
    dArr.erase(dArr.begin() + dArr.size()/2, (dArr.begin()+floor(dArr.size()/2)) + 5);
    printArray(dArr);
    cout << endl;

    cout << "Insert/Delete at the end O(1)" << endl;
    // 配列の最後に要素を追加します。
    cout << "要素追加" << endl;
    dArr.push_back(4);
    printArray(dArr);

    // 配列の最後に要素を追加します。
    dArr.insert(dArr.end(), {6,3,4,54});
    printArray(dArr);

    // 配列の最後を削除します。
    // 1つの要素を削除します。
    cout << "要素削除" << endl;
    dArr.pop_back();
    printArray(dArr);
    cout << "Pop 5 from end " << endl;
    // 後ろから5つの要素を削除します。(for文でゴリ押し)
    cout << "要素削除" << endl;
    for(int i = 0; i < 5; i++) {
        dArr.pop_back();
    }
    printArray(dArr);

    return 0;
}