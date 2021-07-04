#include <iostream>
using namespace std;

// kg : キログラム, mpss(meter per second squared) =　m / s ^ 2 : メートル毎秒の2乗
// 物体の質量と加速度を引数にして、物体に働くNを返す
// kgとmpssを掛け算した結果を返す
double forceNewtons(double kg, double mpss) {
    return kg*mpss;
}

// 惑星名を引数にとり、それぞれの重力加速度（mpss）を返す
// デフォルトは0
double planetGravityMpss(string planet) {
    if(planet == "Earth") return 9.80665;
    if(planet == "Jupiter") return 24.79;
    if(planet == "Neptune") return 11.15;
    return 0;
}

// ポンドを受け取ってkgに変換する
// ポンド * 0.453592でkgに変換できる
double poundsToKg(double pounds) {
    return pounds*0.453592;
}

// 進んだ距離の分だけ作用した力によって伝達されるジュールの量（エネルギー量）を返す
// 物体に加わる力newtonsと進んだ距離metersが引数
double joulesByWork(double newtons, double meters) {
    return newtons*meters;
}

// 追加する関数
// planet, pounds, metersを引数として、伝達されるジュールの量を返す
double energyMovingPoundsByPlanet(string planet, double pounds, double meters) {
    return joulesByWork(forceNewtons(poundsToKg(pounds), planetGravityMpss(planet)), meters);
}

// main
int main() {
    // 関数の合成をしていない
    cout << forceNewtons(80, 9.807) << endl;

    // planetGravityMpss()の結果をforceNewtons()に引数として渡している(関数合成している)
    cout << forceNewtons(80, planetGravityMpss("Earth")) << endl;
    cout << forceNewtons(80, planetGravityMpss("Jupiter")) << endl;

    // 海王星上の175ポンドの物体に働く力を返す
    // poundsToKg()の結果とplanetGravityMpss()の結果をforceNewtons()に引数として渡している(関数合成している)
    cout << forceNewtons(poundsToKg(175), planetGravityMpss("Neptune")) << endl;

    // 地球上で175ポンドを10メートル移動するのに必要なエネルギー量を返す
    // forceNewtons()の結果をjoulesByWork()に引数として渡している(関数合成している)
    cout << joulesByWork(forceNewtons(poundsToKg(175), planetGravityMpss("Earth")), 10) << endl;

    // 関数の合成をしていない
    cout << joulesByWork(30, 10.5) << endl;

    // 追加する
    // 木星で65ポンドの物体を35メートル移動するのに必要なエネルギーを返す
    cout<< energyMovingPoundsByPlanet("Jupiter", 65, 35) << endl;

    return 0;
}