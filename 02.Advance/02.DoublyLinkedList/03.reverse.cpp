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

class DoublyLinkedList {
    public:
        Node *head, *tail;
        DoublyLinkedList(vector<int> arr) {
            if(arr.size() <= 0) {
                this->head = NULL;
                this->tail = this->head;
                return;
            }
            this->head = new Node(arr[0]);
            Node *currentNode = this->head;
            for(int i=1; i<arr.size(); i++) {
                currentNode->next = new Node(arr[i]);
                currentNode->next->prev = currentNode;
                currentNode = currentNode->next;
            }
            this->tail = currentNode;
        }
        Node *at(int index) {
            Node *iterator = this->head;
            while(iterator != NULL) {
                iterator = iterator->next;
                if(iterator == NULL) return NULL;
            }
            return iterator;
        }
        /*
        * ①reverse、iterator、currentNodeをそれぞれ作成
        * ②currentNode->nextをiteratorにする
        * ③iteratorを前に移動させる
        * ④iterator->nextをnullにする
        * ⑤currentNode->next->prevをcurrentNodeに設定する
        * ⑥currentNodeをcurrentNode->nextにする
        * ⑦headをreverse、tailをcurrentNodeにする
        */
        void reverse() {
            Node *reverse = this->tail;
            Node *iterator = this->tail->prev;
            Node *currentNode = reverse;
            while(iterator != NULL) {
                // currentNode->next
                currentNode->next = iterator;
                // iterator->prev
                iterator = iterator->prev;
                // iterator->nextをNULLに設定する
                if(iterator != NULL) iterator->next = NULL;
                // currentNode->next->prevの設定
                currentNode->next->prev = currentNode;
                // currentNode->next
                currentNode = currentNode->next;
            }
            this->head = reverse;
            this->tail = currentNode;
        }
        void printInReverse() {
            Node *iterator = this->tail;
            string str = "";
            while(iterator != NULL) {
                str += to_string(iterator->data) + " ";
                iterator = iterator->prev;
            }
            cout << str << endl;
        }
        void printList(){
            Node *iterator = this->head;
            string str = "";
            while(iterator != NULL){
                str += to_string(iterator->data) + " ";
                iterator = iterator->next;
            }
            cout << str << endl;
        }        
};

int main(){

    DoublyLinkedList *numList = new DoublyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});

    numList->printList();
    numList->printInReverse();

    numList->printList();
    numList->reverse();
    numList->printList();

}