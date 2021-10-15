#include <iostream>
using namespace std;

void printIntArray(int[] intArr, int length) {
    for(int i=0; i<length; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {20,13,-12,2,5};
    // sizeof関数を使うことで引数にとるデータがと取るバイト数を取ることができる
    // arrはintの配列なので、1つのデータにつき4バイト持っているので4で割れば配列の長さが取得できる
    printIntArray(arr, sizeof(arr)/sizeof(int));

    // []に個数が指定されない場合、{}の中の要素数が設定される
    int arr1[] = {1,2,3,4,5};
    printIntArray(arr1, sizeof(arr1)/sizeof(int));

    // 初期値{}が設定されていない場合は初期値が入る。intなら0
    int arr2[3] = {};
    printIntArray(arr2, sizeof(arr2)/sizeof(int));

    // 一部の要素だけに値を入れた場合、残りの要素は初期値になる
    int arr3[10] = {3,42, -20, 1, 0};
    printIntArray(arr3, sizeof(arr3)/sizeof(int));

    // arr4[5]によってメモリに5スポットを宣言する
    int arr4[5]
    cout << arr4[2] << endl;
    // メモリアドレスの中にあるデータを出力します。この場合、コンピュータで元々使われていたゴミデータが出力されます。

    // データが初期化されていない場合は、各データを個別に割り当てる必要があります。
    for(int i = 0; i < sizeof(arr4)/sizeof(int); i++){
        arr4[i] = 0;
    }

    printIntArray(arr4, sizeof(arr4)/sizeof(int));

    // []演算子で配列の指定の要素にアクセスすることができます。これによって、変数と同じように値を書き換えることが可能です。
    arr4[3] = 34;
    arr4[1] = 40;
    printIntArray(arr4, sizeof(arr4)/sizeof(int));

    return 0;

}