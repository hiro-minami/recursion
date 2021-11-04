#include <iostream>
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
            Node *tempNode = this->head;
            this->head = new Node(data);
            this->head->next = tempNode;
        }
        // intとNULLを返すためにはポインタメソッドにする必要がある
        int *pop() {
            if(this->head == NULL) return NULL;
            Node *temp = this->head;
            this->head = this->head->next;
            return &temp->data; // intのデータのアドレスを返している
        }
        int *peek() {
            if(this->head == NULL) return NULL;
            return &this->head->data;
        }
};

int main() {
    Stack *stack = new Stack();
    stack->push(2);

    // *を変数の前につけることで参照解除することができる
    cout << stack->peek() << endl;
    cout << *(stack->peek()) << endl;
    stack->push(4);
    stack->push(3);
    stack->push(1);
    stack->pop();
    cout << stack->peek() << endl;
    cout << *(stack->peek()) << endl;

    stack->pop();
    stack->pop();
    stack->pop();
    // cout << *(s->peek()) << endl;   // NULLが返るため、参照解除するとエラーが出る
    cout << stack->peek() << endl;

}