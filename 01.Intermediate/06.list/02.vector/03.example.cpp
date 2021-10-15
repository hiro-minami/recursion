#include <iostream>
#include <vector>
using namespace std;

// a,bが与えられるので、aからbまでの中で2の倍数を空の動的配列に追加する関数、evenRangeという関数を作成し、printListによって出力してください。
vector<int> evenRange(int a, int b) {
    vector<int> v;
    for(int i=a; i<b+1; i++) {
        if (i % 2 == 0) v.push_back(i);
    }
    return v;
}

// 自然数nが与えられるので、1からnまでに含まれる素数を空の動的配列に追加する、primeNumberを作成し、printListで出力してください。
vector<int> primeNumber(int n) {
    vector<int> primeList;
    for(int i=1; i<n+1; i++) {
        if (isPrime(i) == true) primeList.push_back(i);
    }
    return primeList;
}

bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

void printList(vector<int> intArr) {
    for(int i=0; i<intArr.size(); i++) {
        cout << intArr.at(i) << endl;
    }
}

int main() {

    vector<int> evenList = evenRange(10,20);
    printList(evenList);

    vector<int> primeList = primeNumber(97);
    printList(primeList);

    return 0;
}