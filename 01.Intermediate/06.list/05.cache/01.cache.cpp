#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> allNPrimesSieve(int num) {
    // キャッシュの準備
    vector<bool> cache;
    for(int i=0; i<num; i++) {
        cache.push_back(true);
    }

    // 篩の開始
    for(int current=2; current<ceil(sqrt(num)); current++) {
        // すでに篩にかけられた値は飛ばす
        if(!cache[current]) continue;
        int i = 2;
        int ip = i * current;
        while(ip < num) {
            cache[ip] = false;
            i += 1;
            ip = i * current;
        }
    }

    // キャッシュに残った値を新しい配列に格納する
    vector<int> result;
    for(int i=2; i<cache.size(); i++) {
        if(cache[i]) result.push_back(i);
    }

    return result;
}

int sumList(vector<int> list) {
    int total = 0;
    for(int i=0; i<list.size(); i++) {
        total += list.at(i);
    }
    return total;
}

int sumPrimeUpToN(int num) {
    return sumList(allNPrimesSieve(num));
}

int main(){
    vector<int> arr = allNPrimesSieve(100);

    cout << "[";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;

    cout << "size: " << allNPrimesSieve(100).size() << endl;

    cout << "sum(53): " << sumPrimeUpToN(53) << endl;
    cout << "sum(89): " << sumPrimeUpToN(89) << endl;
    cout << "sum(97): " << sumPrimeUpToN(97) << endl;

    return 0;
}