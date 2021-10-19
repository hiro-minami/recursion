#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 引数needleはポインタで渡すことによって高速に動作する
int needleInHaystack(vector<string> haystack, const string& needle) {
    for(int i=0; i<haystack.size(); i++) {
        if(haystack.at(i) == needle) return i;
    }
    return -1;
}

void printAtIndex(int index, vector<string> words) {
    if(index >= 0 && index < words.size()) cout <<　"Printing: ->" << words.at(index) << "<- at index: " << index << endl;
    else cout << "Index out of scope!" << endl;
}

int main() {
    vector<string> words = {"Take", "Restaurant", "Family", "Running", "Tea", "Apples"};

    // Runningを探す
    printAtIndex(needleInHaystack(words, "Running"), words);

    // "Apple"という文字列を配列の中から探します。
    printAtIndex(needleInHaystack(words, "Apples"), words);

    // "Train"という存在しない文字列を配列の中から探します。
    printAtIndex(needleInHaystack(words, "Train"), words);

    return 0;
}