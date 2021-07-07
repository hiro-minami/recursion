#include <iostream>
using namespace std;

/*
    共通の接頭辞を返すヘルパー関数
    input: string s1, string s2, string prefix
    output: string
    outline:
        s1[0] != s2[0] -> return prefix
        else return commonPrefixHelper(s1.substr(1), s2.substr(1), prefix + s1[0]);
*/
string commonPrefixHelper(string s1, string s2, string prefix) {
    if(s1[0] != s2[0]) return prefix;
    return commonPrefixHelper(s1.substr(1), s2.substr(1), prefix + s1[0]);
}

/*
    共通の接頭辞を返す関数
    input: string s1, string s2
    output: string
    outline:
        return commonPrefixHelper(s1, s2, "");
*/
string commonPrefix(string s1, string s2) {
    return commonPrefixHelper(s1, s2, "");
}

/*
    reduceByFiveのヘルパー関数
    input: int num, int curr, bool addFlg（終わりを求めるためnum、足し算をするかどうか判定するためaddFlg）
    output: string
    outline:
        if(num == curr && addFlg == true) return "";
        else if(curr < 0 || addFlg == true) return reduceByFiveHelper(num, curr + 5, true)
        else return reduceByFiveHelper(num, curr - 5, false)
*/
string reduceByFiveHelper(int num, int curr, bool addFlg) {
    if(num == curr && addFlg == true) {
        cout << curr << endl;
        return "";
    } else if(curr < 0 || addFlg == true) {
        cout << curr << endl;
        return reduceByFiveHelper(num, curr + 5, true);
    } else {
        cout << curr << endl;
        return reduceByFiveHelper(num, curr - 5, false);
    }
}

/*
    負の数になるまで5を引いていき、その後5を足していく関数
    input: int num
    output: string
    outline:
        return reduceByFiveHelper(num, num, false)
*/
string reduceByFive(int num) {
    return reduceByFiveHelper(num, num, false);
}

int main() {
    // "abc"
    cout << commonPrefix("abcdefg","abcxyz") << endl;
    // "auto"
    cout << commonPrefix("autopilot","autobiography") << endl;
    // "a"
    cout << commonPrefix("aaa","a") << endl;
    // 16,11,6,1,-4,1,6,11,16
    reduceByFive(16);

    // 9,4,-1,4,9
    reduceByFive(9);

    // 5,0,-5,0,5
    reduceByFive(5);
}