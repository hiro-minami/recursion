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
        void enquereFront(int data) {
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

vector<int> getMaxWindows(vector<int>arr, int k) {
    if(k > arr.size()) return {};
    vector<int> results;
    Deque *deque = new Deque();

    // 最初のウィンドウを作成する
    for(int i=0; i<k; i++) {
        // dequeが空になるか、arr[i]がdequeの末尾より小さくなるまでdequeueを繰り返す
        while(deque->peekBack() != NULL && arr[i] >= arr[*(deque->peekBack())]) {
            deque->dequeueBack();
        }
        // 小さい値が無くなった後、末尾に追加する
        deque->enqueueBack(i);
    }

    // リストの末尾まで繰り返し
    for(int i=k; i<arr.size(); i++) {
        // 先頭は最大なのでresultに格納する
        results.push_back(arr[*(deque->peekFront())]);

        // 範囲外となるインデックスを排除する（i - kは左端になる。）
        while(deque->peekFront() != NULL && *(deque->peekFront()) <= i-k) {
            deque->dequeueFront();
        }

        // i番目の値を追加する
        while(deque->peekBack() != NULL && arr[i] >= arr[*(deque->peekBack())]) {
            deque->dequeueBack();
        }
        deque->enqueueBack(i);
    }

    // 最後のmaxを格納する
    results.push_back(arr[*(deque->peekFront())]);

    return results;
}

void printArray(vector<int> intArr){
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    printArray(getMaxWindows({34,35,64,34,10,2,14,5,353,23,35,63,23}, 4));
}