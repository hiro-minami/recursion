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

class Queue {
    public:
        Node *head, *tail;
        Queue() {
            this->head = NULL;
            this->tail = NULL;
        }
        // 先頭の要素を返す
        int *peekFront() {
            if(this->head == NULL) return NULL;
            return &this->head->data;
        }
        int *peekBack() {
            if(this->tail == NULL) return this->peekFront();
            return &this->tail->data;
        }
        // リストの末尾に要素を挿入
        void enqueue(int data) {
            if(this->head == NULL) this->head = new Node(data);
            else if(this->tail == NULL) {
                this->tail = new Node(data);
                this->head->next = this->tail;
            } else {
                this->tail->next = new Node(data);
                this->tail = this->tail->next;
            }
        }
        // リストの先頭を取得して削除
        Node *dequeue() {
            if(this->head == NULL) return NULL;
            Node *temp = this->head;
            // headの次が空なら、tailも空になる
            if(this->head->next == NULL) {
                this->head = NULL;
                this->tail = NULL;
            } else this->head = this->head->next;
            return temp;
        }
};

int main(){
    Queue *q = new Queue();
    cout << q->peekFront() << endl;
    cout << q->peekBack() << endl;

    q->enqueue(4);
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

    q->enqueue(50);
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

    q->enqueue(64);
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

    cout << "dequeued :" + to_string(q->dequeue()->data) << endl;
    cout << *(q->peekFront()) << endl;
    cout << *(q->peekBack()) << endl;

}