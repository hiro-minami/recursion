#include <iostream>
// 重複を避けるmap
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// リスト内のyを検索し、存在すればtrue、そうでなければfalseを返す
string existsWithinList(vector<int> listL, int y) {
    unordered_map<int, int> hashMap;
    // 拡張forループ
    for(int num : listL) {
        hashMap[num] = num;
    }
    return hashMap[y] != 0 ? "true" : "false";
}

int main() {
    // リストを検索します。
    vector<int> sampleList = { 3,10,23,3,4,50,2,3,4,18,6,1,-2 };
    cout << existsWithinList(sampleList, 23) << endl;
    cout << existsWithinList(sampleList, -2) << endl;
    cout << existsWithinList(sampleList, 100) << endl;
}