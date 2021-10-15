#include <iostream>
using namespace std;

// 例題1
// 文字列によって構成される配列が与えられるので、配列内に存在する全ての文字数をカウントする、countCharという関数を作成してください。

// ["The wood", "Pecked peckers", "At the inn", "Tomorrowland"] -> 44
// ["He","fumbled","in","the,darkness","looking","for","the","light","switch"] -> 47
// ["I","am","never","at","home","on","Sundays"] -> 23
int countChar(string sentences[], int length) {
    int total = 0;
    for(int i=0; i<length; i++) {
        string sentence = sentences[i];
        total += sentence.length();
    }
    return total;
}


// 例題2
// 小文字によって構成される配列が与えられるので、n以降の文字（o,p,q,rなど）をカウントする、higherThanNという関数を作成してください。

// ["the wood", "pecked peckers", "at the inn", "tomorrowland"] -> 20
// ["he","fumbled","in","the","darkness","looking","for","the","light","switch"] -> 17
// ["he","is","never","at","home","on","weekends"] -> 11
int higherThanN(string sentences[], int length) {
    int count = 0;
    for(int i=0; i<length; i++) {
        string sentence = sentences[i];
        for(int j=0; j<sentence.length(); j++) {
            // charの比較は文字コードの比較になる
            if((unsigned char)sentence[j] >= (unsigned char)'n') count++;
        }
    }
    return count;
}

int main() {

    // 例題1
    // 44
    string list1[] = {"The wood", "Pecked peckers", "At the inn", "Tomorrowland"};
    cout << countChar(list1, sizeof(list1) / sizeof(string)) << endl;
    // 47
    string list2[] = {"He","fumbled","in","the,darkness","looking","for","the","light","switch"};
    cout << countChar(list2, sizeof(list2) / sizeof(string)) << endl;
    // 23
    string list3[] = {"I","am","never","at","home","on","Sundays"};
    cout << countChar(list3, sizeof(list3) / sizeof(string)) << endl;


    // 例題2
    // 20
    string list4[] = {"the wood", "pecked peckers", "at the inn", "tomorrowland"};
    cout << higherThanN(list4, sizeof(list4) / sizeof(string)) << endl;
    // 17
    string list5[] = {"he","fumbled","in","the","darkness","looking","for","the","light","switch"};
    cout << higherThanN(list5, sizeof(list5) / sizeof(string)) << endl;
    // 11
    string list6[] = {"he","is","never","at","home","on","weekends"};
    cout << higherThanN(list6, sizeof(list6) / sizeof(string)) << endl;

    return 0;
}