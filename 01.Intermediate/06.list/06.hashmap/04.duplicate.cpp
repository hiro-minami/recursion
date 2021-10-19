#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}
// 重複を含むリストからデータをハッシュマップに詰める
void printDuplicates(vector<int> inputList) {
    unordered_map<int, int> hashmap;
    for(int num : inputList) {
        if(hashmap[num] == 0) hashmap[num] = 1;
        else hashmap[num] = hashmap[num] + 1;
    }

    // autoを使うことで型を推論してくれる
    // begin().メソッドを使うことでハッシュマップの先頭の要素を取得できる
    auto iterator = hashmap.begin();
    vector<int> keyList;
    // ハッシュマップの最後の要素まで繰り返し
    while(iterator != hashmap.end()) {
        // 配列にキーを追加します
        keyList.push_back(iterator->first);
        ++iterator;
    }

    // keyの出力（配列とは違い、順番は保証されない）
    printArray(keyList);
    for(int key : keyList) {
        cout << to_string(key) + " has " + to_string(hashmap[key]) + " duplicates" << endl;
    }
}

// アルファベットで構成される文字列が与えられるのでそれがパングラムかどうか判定する、
// isPangramという関数を作成してください。パングラムとは、a-zまでの全てのアルファベットを含んだ文字列のことを指します。
bool isPangram(string str) {
    unordered_map<char, int> hashMap;
    for(int i=0; i<str.length(); i++) {
        if(hashMap[tolower(str[i])] == 0) hashMap[tolower(str[i])] = 1;
        else hashMap[tolower(str[i])] = hashMap[tolower(str[i])] + 1;
    }
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<alphabet.length(); i++) {
        if(hashMap[alphabet[i]] == 0) return false;
    }
    return true;
}

// 文字列stringが与えられるので、全ての文字が同じ数だけ含まれているかどうか判定するcharAppearXTimesという関数を作成してください。
bool charAppearXTimes(string str) {
    unordered_map<char, int> hashMap;
    for(int i=0; i<str.length(); i++) {
        if(hashMap[tolower(str[i])] == 0) hashMap[tolower(str[i])] = 1;
        else hashMap[tolower(str[i])] = hashMap[tolower(str[i])] + 1;
    }
    auto iterator = hashMap.begin();
    int value = iterator->second;
    while(iterator != hashMap.end()) {
        if(iterator->second != value) return false;
        ++iterator;
    }
    return true;
}

int main(){
    printDuplicates({1,1,1,1,1,2,2,2,2,2,2,3,3,3,4,5,6,6,6,6,7,8,8,8,9,9,9});
    printDuplicates({7,7,6,6,3,5,3,9,2,5,5,4,6,4,1,4,1,7,2});

    cout << isPangram("we promptly judged antique ivory buckles for the next prize") << endl;
    cout << isPangram("sheep for a unique zebra when quick red vixens jump over the yacht") << endl;
    cout << isPangram("a quick brown fox jumps over the lazy dog") << endl;

    cout << charAppearXTimes("babacddc") << endl;
    cout << charAppearXTimes("aaabbbcccddd") << endl;
    cout << charAppearXTimes("aaabbccdd") << endl;
    cout << charAppearXTimes("zadbchvwxbwhdxvcza") << endl;
    cout << charAppearXTimes("zadbchvwxbwhdxvczb") << endl;
}