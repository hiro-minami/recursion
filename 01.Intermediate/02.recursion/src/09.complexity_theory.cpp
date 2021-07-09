#include <iostream>
using namespace std;

// 総和（O(n)）
int simpleSummation(int count) {
    if(count <= 0) return 0;
    return count + simpleSummation(count - 1);
}

// 割り算（O(log_n^2)）
int divideBy2CountHelper(int n, int count) {
    if(n / 2 < 1) return count;
    return divideBy2CountHelper(n / 2, count + 1);
}

int divideBy2Count(int n) {
    return divideBy2CountHelper(n, 0);
}

// 総和の総和（O(n^2)）
int simpleSummationOfSummations(int count) {
    if(count <= 0) return 0;
    return simpleSummation(count) + simpleSummationOfSummations(count - 1);
}

int main() {
    // 総和
    cout << simpleSummation(5) << endl;
    // 割り算
    cout << divideBy2Count(64) << endl;
    cout << divideBy2Count(1024) << endl;
    // 総和の総和
    cout << simpleSummationOfSummations(4) << endl;
    cout << simpleSummationOfSummations(3) << endl;
    cout << simpleSummationOfSummations(2) << endl;
    cout << simpleSummationOfSummations(10) << endl;
    return 0;
}