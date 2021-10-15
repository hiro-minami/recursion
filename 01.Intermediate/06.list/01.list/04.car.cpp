#include <iostream>
using namespace std;

class Car {
    public:
        string make;
        string model;
        int year;

        Car(string make, string model, int year) {
            this->make = make;
            this->model = model;
            this->year = year;
        }
}

// 車を指すポインタの配列を作成する
void printArray(Car* car[], int length) {
    for(int i=0; i<length; i++) {
        cout << arr[i]->make << " - " << arr[i]->model << " Year " << arr[i]->year << endl;
    }
}

int main(){
    // 残念ながらC++では、一文でオブジェクトの配列を初期化する方法はありません。オブジェクトのコンストラクタを呼び出して、各車の初期データを設定します。
    // 配列にアクセスするためにポインタを使うことになります。一方、動的配列ははるか簡単に動作します。

    // Car cars[3];は空のコンストラクタで、3台の車を作成します。初期データを設定します。

    /** オブジェクトの配列を作成します。
        3つのcarポインタの配列を設定します。これらはポインタなので、carオブジェクトのメモリアドレスを参照します。
        最初は、これらのポインタは初期化されていません。作成中の各車の新しいメモリアドレスへ初期化します。
    **/
    Car *cars[4];
    cars[0] = new Car("Toyota", "Camry", 2000);
    cars[1] = new Car("BMW", "X1 Sports", 2019);
    cars[2] = new Car("Nissan", "GT-R", 2020);
    cars[3] = new Car("Honda", "S2000", 1996);

    // ->はヒープメモリからオブジェクトを取り出すことを意味し、「.」アクセス演算子と同じ意味を持ちます。
    // object->methodは(object).methodと同じ意味を持ちます。
    cout << "First car model: " << cars[0]->model << endl;

    printArray(cars, 4);

    int arr[5] = {20,13,-12,2,5};

    // arr[5]は長さ5なので、6番目の要素のデータを割り当てることができない。
    // 正確には割り当てることはできるが、そのデータは配列とは関係のないものになる、結果、意図しない副作用を起こす可能性がある
    // 新しい要素を追加するためには、新しい配列を用意する必要がある。
    int arr2[6] = {};

    for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
        arr2[i] = arr[i];
    }

    // 6番目の要素に値を入れる
    arr2[5] = 7;
    printArray(arr2, sizeof(arr2)/sizeof(int));

    return 0;
}