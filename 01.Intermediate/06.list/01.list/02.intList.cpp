#include <iostream>
using namespace std;

// 例題1
// 整数によって構成される固定配列が与えられるので、配列内の全ての要素を足し合わせた数値を返す、sumArrayElementという関数を作成してください
// [3,43,5,4,2,100,6] --> 163
// [1,2,3,4,5,6] --> 21
// [32,21,10,3,5,6] --> 77
// なぜlengthが渡されるのか？
// 　->C++では、引数として配列を渡すとその配列のポインタが渡されるようになっているから。
int sumArrayElement(int arr[], int length) {
    int total = 0;
    for(int i=0; i<length; i++) {
        total += arr[i];
    }
    return total;
}

// 例題2
// 整数によって構成される固定配列が与えられるので、配列内の最大値を返す、maxValueという関数を作成してください
// [3,43,5,4,2,100,6] --> 100
// [1,2,3,4,5,6] --> 6
// [32,21,10,3,5,60,18,32,] --> 60
int maxValue(int arr[], int length) {
    int max = arr[0];
    for(int i=1; i<length; i++) {
        max = (max < arr[i]) ? arr[i] : max;
    }
    return max;
}

int main() {

    // 例題1
    // [3,43,5,4,2,100,6] --> 163
    int list1[] = {3,43,5,4,2,100,6};
    cout << sumArrayElement(list1, sizeof(list1)/ sizeof(int)) << endl;

    // [1,2,3,4,5,6] --> 21
    int list2[] = {1,2,3,4,5,6};
    cout << sumArrayElement(list2, sizeof(list2)/ sizeof(int)) << endl;

    // [32,21,10,3,5,6] --> 77
    int list3[] = {32,21,10,3,5,6};
    cout << sumArrayElement(list3, sizeof(list3)/ sizeof(int)) << endl;

    // 例題2
    // [3,43,5,4,2,100,6] --> 100
    cout << maxValue(list1, sizeof(list1)/ sizeof(int)) << endl;

    // [1,2,3,4,5,6] --> 6
    cout << maxValue(list2, sizeof(list2)/ sizeof(int)) << endl;

    // [32,21,10,3,5,60,18,32,] --> 60
    int list4[] = {32,21,10,3,5,60,18,32};
    cout << maxValue(list4, sizeof(list4)/ sizeof(int)) << endl;

    return 0;
}