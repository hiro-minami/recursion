#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

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
                Node *newNode = new Node(data);
                this->head->prev = newNode;
                newNode->next = this->head;
                this->head = newNode;
            }
        }
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

vector<int> minWindowArrK(vector<int> intArr, int k){
    if(intArr.size() < k) return {};
    vector<int> results;
    Deque *deque = new Deque();
    for(int i=0; i<k; i++) {
        // dequeが空になるか、それとも先頭の方が小さいか
        while(deque->peekBack() != NULL && intArr[*(deque->peekBack())] >= intArr[i]) {
            deque->dequeueBack();
        } 
        deque->enqueueBack(i);
    }
    for(int i=k; i<intArr.size(); i++) {
        results.push_back(intArr[*(deque->peekFront())]);
        while(deque->peekFront() != NULL && *(deque->peekFront()) <= i-k) {
            deque->dequeueFront();
        }
        while(deque->peekBack() != NULL && intArr[*(deque->peekBack())] >= intArr[i]) {
            deque->dequeueBack();
        } 
        deque->enqueueBack(i);
    }
    results.push_back(intArr[*(deque->peekFront())]);
    return results;
}