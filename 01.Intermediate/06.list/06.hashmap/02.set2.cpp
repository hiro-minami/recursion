#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
//リストと値を受け取り、リスト内にある値のインデックスを返す、searchListという関数をハッシュマップを使って作成してください。
// 値がリスト内に複数ある場合は先に出てきたインデックスを返してください。もし発見されない場合は-1を返してください。
int searchList(vector<int> list, int n) {
    unordered_map<int, int> hashMap;
    for(int i=0; i<list.size(); i++) {
        hashMap[list[i]] = i;
    }
    return hashMap[n] != 0 ? hashMap[n] : -1;
}

int main() {
    vector<int> sampleList = {3,10,23,3,4,50,2,3,4,18,6,1,-2};

    // 2
    cout << searchList(sampleList,23) << endl;

    // 12
    cout << searchList(sampleList,-2) << endl;

    // -1
    cout << searchList(sampleList,100) << endl;
}