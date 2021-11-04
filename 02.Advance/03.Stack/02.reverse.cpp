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

vector<int> reverse(vector<int> arr) {
    // Stackの作成
    Stack *s = new Stack();
    // arrの中身をStackに格納
    for(int num : arr) {
        s->push(num);
    }
    // reverseの宣言
    vector<int> reverseArr;
    while(s->peek() != NULL) {
        reverseArr.push_back(*(s->pop()));
    }
    return reverseArr;
}

void printArray(vector<int> arr) {
    cout << "[";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

int main(){

    vector<int> arr = {1,2,3,4,5,6};
    printArray(reverse(arr));

}