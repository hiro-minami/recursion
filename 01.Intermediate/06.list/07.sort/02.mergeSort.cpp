#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// ①startとendが同じになったらstartの値を返す（もう分解できなくなるまで繰り返す）
// ②真ん中の値を求める
// ③左右の値を分解するため、再帰呼び出しをする
// ④回答用のvectorを準備。合わせて左右のvectorに対応するindexと繰り返しの終了条件を作成
// ⑤小さい方の値を順次回答用のvectorに詰めていく
vector<int> mergeSortHelper(int start, int end, vector<int> list) {
    // 要素が1つだけの時はその値を返す
    if(start == end) return {list[start]};
    // 左右に分けるために真ん中の値を取得する
    int mid = floor((start + end) / 2);
    // 左右それぞれ分割する
    vector<int> sortedLeft = mergeSortHelper(start, mid, list);
    vector<int> sortedRight = mergeSortHelper(mid+1, end, list);

    // 分割した配列の最後に最大値を入れることでマージされた全ての値を整列後の配列に代入することができる
    sortedLeft.push_back(numeric_limits<int>::max());
    sortedRight.push_back(numeric_limits<int>::max());

    vector<int> combinedArray;

    // インデックスと繰り返し数を取得
    int len = sortedLeft.size() + sortedRight.size() - 2;
    int leftIndex = 0;
    int rightIndex = 0;

    while(leftIndex + rightIndex < len) {
        if(sortedLeft[leftIndex] <= sortedRight[rightIndex]) {
            combinedArray.push_back(sortedLeft[leftIndex]);
            leftIndex++;
        } else {
            combinedArray.push_back(sortedRight[rightIndex]);
            rightIndex++;
        }
    }

    return combinedArray;
}

vector<int> mergeSort(vector<int> list) {
    return mergeSortHelper(0, list.size(), list);
}

void printArray(vector<int> list) {
    cout << "[";
    for(int value : list) {
        cout << value << " ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> dArr = {34,4546,32,3,2,8,6,76,56,45,34,566,1};
    vector<int> sortedArr = mergeSort(dArr);
    printArray(sortedArr);
    return 0;
}