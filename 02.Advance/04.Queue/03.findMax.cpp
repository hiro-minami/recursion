#include <iostream>
#include <vector>
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
            if(this->tail == NULL) return NULL;
            return &this->tail->data;
        }
        void enqueueFront(int data) {
            if(this->head == NULL) {
                this->head = new Node(data);
                this->tail = this->head;
            } else {
                Node *node = new Node(data);
                this->head->prev = node;
                node->next = this->head;
                this->head = node;
            }
        }
        void enqueueBack(int data) {
            if(this->head == NULL) {
                this->head = new Node(data);
                this->tail = this->head;
            } else {
                Node *node = new Node(data);
                this->tail->next = node;
                node->prev = this->tail;
                this->tail = node;
            }
        }
        int *dequeueFront() {
            if(this->head == NULL) return NULL;

            Node *temp = this->head;
            this->head = this->head->next;
            if(this->head != NULL) this->head->prev = NULL;
            else this->tail = NULL;
            return &temp->data;
        }
        int *dequeueBack() {
            if(this->tail == NULL) return NULL;
            
            Node *temp = this->tail;
            this->tail = this->tail->prev;
            if(this->tail != NULL) this->tail->next = NULL;
            else this->head = NULL;
            return &temp->data;
        }
};

// 最大値を求める関数
int getMax(vector<int> arr) {
    Deque *deq = new Deque();
    // 最初の要素を追加
    deq->enqueueFront(arr[0]);
    for(int i=1; i<arr.size(); i++) {
        // 最大値はでキューの先頭、そうでない数は最後尾に追加
        if(arr[i] > *(deq->peekFront())) deq->enqueueFront(arr[i]);
        else deq->enqueueBack(arr[i]);
    }
    // 先頭が最大値となる
    return *(deq->peekFront());
}

int main() {
    cout << getMax({34,35,64,34,10,2,14,5,353,23,35,63,23}) << endl;
}