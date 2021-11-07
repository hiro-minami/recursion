#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next, *prev;
        Node(int value) {
            this->data = value;
            this->next = NULL;
            this->prev = NULL;
        }
};

class Deque {
    public:
        Node *head, *tail;
        Deque() {
            this->head = NULL;
            this->tail = NULL;
        }
        int *peekFront() {
            if(this->head == NULL) return NULL;
            return &this->head->data;
        }
        int *peekBack() {
            if(this->tail == NULL) return this->peekFront();
            return &this->tail->data;
        }
       // リストの先頭に要素を挿入
       void enqueueFront(int data) {
           if(this->head == NULL) {
               this->head = new Node(data);
               this->tail = this->head;
           } else {
               Node *newNode = new Node(data);
               this->head->prev = newNode;
               newNode->next = this->head;
               this->head = newNode;
           }
       }
       // リストの末尾に要素を挿入
       void enqueueBack(int data) {
           if(this->head == NULL) {
                this->head = new Node(data);
                this->tail = this->head;
           } else {
               Node *newNode = new Node(data);
               this->tail->next = newNode;
               newNode->prev = this->tail;
               this->tail = newNode;
           }
       }
       // リストの先頭にある要素を削除して返す
       int *dequeueFront() {
           if(this->head == NULL) return NULL;
           Node *temp = this->head;
           this->head = this->head->next;
           // headがnullだった場合、もともとの要素は1つ->tailもnullにする
           if(this->head != NULL) this->head->prev = NULL;
           else this->tail = NULL;
            return &temp->data;
       }
       // リストの末尾にある要素を削除して返す
       int *dequeueBack() {
           if(this->tail == NULL) return NULL;
           Node *temp = this->tail;
           this->tail = this->tail->prev;
           // tailがnullだった場合、もともとの要素は1つ->headもnullにする
           if(this->tail != NULL) this->tail->next = NULL;
           else this->head = NULL;
           return &temp->data;
       }
};

int main() {
    Deque *q = new Deque();
    cout << q->peekFront() << endl;
    cout << q->peekBack() << endl;

    q->enqueueBack(4);
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

    q->enqueueBack(50);
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

    cout << "dequeued :" + to_string(*(q->dequeueFront())) << endl;
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

    q->enqueueFront(36);
    q->enqueueFront(96);
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

    cout << "dequeued :" + to_string(*(q->dequeueBack())) << endl;
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

    cout << "Emptying" << endl;
    q->dequeueBack();
    q->dequeueBack();
    q->dequeueBack();
    q->dequeueBack();

    // cout << "Emptying" << endl;
    // q->dequeueFront();
    // q->dequeueFront();
    // q->dequeueFront();
    // q->dequeueFront();

    cout << q->peekFront() << endl;
    cout << q->peekBack() << endl;
}