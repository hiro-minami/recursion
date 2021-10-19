#include <iostream>
#include <vector>
using namespace std;

// タビュレーションは下から上に上がっていく動的計画法
long int tabulationFib(int n) {
    vector<long int> cache;
    for(int i=0; i<=n; i++) {
        cache.push_back(0);
    }
    // キャッシュの0,1を先に設定しておく
    cache[1] = 1;
    for(int i=2; i<=n; i++) {
        cache[n] = cache[n-1] + cache[n-2];
    }
    return cache[n];
}

int main(){
    cout << tabulationFib(50) << endl;
    return 0;
}