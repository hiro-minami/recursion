#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// リストとリストを受け取り、データのリストを探索する
bool linearSearchExists(vector<int> hayStack, int needle) {
    for(int data : hayStack) {
        if(data == needle) return true;
    }
    return false;
}

// 計算量はO(リストのサイズ * リストのサイズ)なので最大でO(n^2)になってしまう
vector<int> listIntersection(vector<int> targetList, vector<int> searchList) {
    vector<int> results;
    for(int searchData : searchList) {
        if(linearSearchExists(targetList, searchData)) results.push_back(searchData);
    }
    return results;
}

// ハッシュマップに詰めてO(n)にすることができる
vector<int> listIntersectionForHashMap(vector<int> targetList, vector<int> searchList) {
    unordered_map<int, int> hashmap;
    vector<int> result;
    for(int target : targetList) {
        hashmap[target] = target;
    }
    for(int search : searchList) {
        if(hashmap[search] != 0) result.push_back(search);
    }
    return result;
}

void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    printArray(listIntersection({1,2,3,4,5,6},{1,4,4,5,8,9,10,11}));
    printArray(listIntersection({3,4,5,10,2,20,4,5},{4,20,22,2,2,2,10,1,4}));
    printArray(listIntersection({2,3,4,54,10,5,9,11},{3,10,23,10,0,5,9,2}));
}