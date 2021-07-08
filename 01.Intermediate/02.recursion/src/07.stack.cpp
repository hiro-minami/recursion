#include <iostream>
using namespace std;

/*
    0からcountまで足し算する
    input: int count
    output: int
    outline:
        count <= 0 -> return 0
        else return count + simpleSummation(count - 1)
*/
int simpleSummation(int count) {
    if(count <= 0) return 0;
    return count + simpleSummation(count - 1);
}

int main() {
    cout << simpleSummation(5) << endl; // 15
    return 0;
}