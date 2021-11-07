#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int value) {
            this->data = value;
            this->next = NULL;
        }
};

class Stack {
    public:
        Node *head;
        Stack() {
            this->head = NULL;
        }
        void push(int data) {
            Node *temp = this->head;
            this->head = new Node(data);
            this->head->next = temp;
        }
        int *pop() {
            if(this->head == NULL) return NULL;
            Node *temp = this->head;
            this->head = this->head->next;
            return &temp->data;
        }
        int *peek() {
            if(this->head == NULL) return NULL;
            return &this->head->data;
        }
};

// リストを受け取り、単調減少している部分リストを返す関数を実装します。
// リストの途中で単調増加する部分が出現したら、部分リストをリセットします。
vector<int> consecutiveWalk(vector<int> arr) {
    // Stackの宣言
    Stack *stack = new Stack();
    stack->push(arr[0]);
    for(int i=1; i<arr.size(); i++) {
        // スタックの上にある要素より、arr[i]が大きい場合、スタックをリセットします。
        if(arr[i] >= *(stack->peek()) {
            while(stack->pop() != NULL);
        }
        // スタックにプッシュ
        stack->push(arr[i]);
    }
    vector<int> results;
    // resultsは逆向きになっているので、配列の先頭から要素を追加していきます
    while(stack->peek() != NULL) {
        results.insert(results.begin(), *(stack->pop()));
    }
    return results;
}

void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

int main(){

    // [5,3,2]
    printArray(consecutiveWalk({3,4,20,45,56,6,4,3,5,3,2}));
    // [64,3,0,-34,-54]
    printArray(consecutiveWalk({4,5,4,2,4,3646,34,64,3,0,-34,-54}));
    // [4]
    printArray(consecutiveWalk({4,5,4,2,4,3646,34,64,3,0,-34,-54,4}));

}