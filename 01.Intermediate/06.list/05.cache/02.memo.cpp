#include <iostream>
#include <vector>
using namespace std;

// メモ化は、ツリー構造を上から下に続くアルゴリズム
// 仮引数に&（アドレス）を渡すことで参照渡しを実装する
long int memoizationFibHelper(long int num, vector<long int> &cache) {
    // キャッシュされていないフィボナッチ数列を処理する
    // フィボナッチのnを再帰的に計算し、キャッシュに追加する
    if(cache[num] == 0) {
        if(num == 0) cache[num] = 0;
        else if(num == 1) cache[num] = 1;
        else cache[num] = memoizationFibHelper(num-1, cache) + memoizationFibHelper(num-2, cache);
    }
    // フィボナッチはすでに計算されている
    return cache[num];
}

long int memoizationFib(int num) {
    vector<long int> cache;
    for(int i=0; i<=num; i++) {
        cache.push_back(0);
    }
    return memoizationFibHelper(num, cache);
}

int main() {
    cout << memoizationFib(50) << endl;
    return 0;
}