#include <iostream>
#include <vector>
using namespace std;

// 挿入ソート
// ランキングなど、すでにソートがある程度できているリストのソートで採用すると力を発揮する
// ソートを実装するときは、参照渡しをすることで効率的に実行できる
void insertionSort(vector<int> &list) {
    for(int i=1; i<list.size(); i++) {
        // 左端に挿入される項目を指定
        int currentValue = list[i];
        for(int j-1; j>=0; j--) {
            if(currentValue <= list[j]) {
                 list[j+1] = list[j];
                 list[j] = currentValue;
            } else break;
        }
    }
}

int main() {
    vector<int> dArr = {34,4546,32,3,2,8,6,76,56,45,34,566,1};
    
    printArray(dArr);
    insertionSort(dArr); // 昇順に並び替え
    printArray(dArr); // ソートされた配列
    
    return 0;
}