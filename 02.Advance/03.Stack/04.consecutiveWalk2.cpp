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

// リストを受け取り、単調増加している部分リストを返す
vector<int> consecutiveWalk(vector<int> arr) {
    Stack *stack = new Stack();
    stack->push(arr[0]);
    for(int i=1; i<arr.size(); i++) {
        // stack->peekで取得した値の方が大きい場合、Stackを空にする
        if(arr[i] <= *(stack->peek())) {
            while(stack->pop() != NULL);
        }
        stack->push(arr[i]);
    }
    vector<int> result;
    while(stack->peek() != NULL) {
        result.insert(result.begin(), *(stack->pop()));
    }
    return result;
}

void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    printArray(consecutiveWalk({3,4,20,45,56,6,4,3,2,3,9})); // [2,3,9]
    printArray(consecutiveWalk({4,5,4,2,4,3646,34,64,3,0,-34,-54})); // [-54]
    printArray(consecutiveWalk({4,5,4,2,4,3646,34,64,3,0,-34,-54,4})); // [-54,4]
}