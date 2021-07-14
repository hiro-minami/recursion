#include <iostream>
using namespace std;

// クラスを生成
class Rectangle{
    public:
        double width;
        double height;
        // コンストラクタ
        Rectangle(double width, double height) {
            this -> width = width;
            this -> height = height;
        }
        string getRectangleString() {
            return "The rectangle has a width of " + to_string(this->width) + " and a height of: " + to_string(this->height);
        }
};

class Car {
    private:
        string make;
        string model;
        int year;
        string vin;
    public:
        string color;
        Car(string make, string model, int year, string vin, string color) {
            this -> make = make;
            this -> model = model;
            this -> year = year;
            this -> vin = vin;
            this -> color = color;
        }
        string getCarString(){
            // Carクラスのスコープ内なので、privateでもアクセス可能
            return this->make + " " + this->model + " " + to_string(this->year) + " " + this->vin + " " + this->color;
        }
        // privateの値を取得するためにはGetterメソッドを使う
        string getMake() {
            return this -> make;
        }
        string getModel() {
            return this -> model;
        }
        int getYear() {
            return this -> year;
        }
        string getVin() {
            return this -> vin;
        }
        // privateの値を変更するときはSetterメソッドを使う
        void setModel(string newModelValue) {
            this -> model = newModelValue;
        }
};

int main() {
    // newを使わずにインスタンスを生成できる
    Rectangle rectangle1(20,100);
    cout << rectangle1.getRectangleString() << endl;
    Rectangle rectangle2(46,30);
    cout << rectangle2.getRectangleString() << endl;
    Rectangle rectangle3(20,20);
    cout << rectangle3.getRectangleString() << endl;
    Rectangle rectangle4(40, 20);
    cout << rectangle4.getRectangleString() << endl;

    // Carのインスタンスを生成
    Car teslaS("Tesla", "Model S", 2013, "5YJSA1CN0DFP13393", "Black");
    cout << teslaS.getCarString() << endl;

    // publicは編集可能
    teslaS.color = "White";
    cout << teslaS.getCarString() << endl;
}