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
        void addNextNode(Node *newNode) {
            Node *tempNode = this->next;
            this->next = newNode;
            newNode->next = tempNode;
        }
};

class SinglyLinkedList {
    public:
        Node *head;
        SinglyLinkedList(vector<int> numList) {
            this->head = numList.size() > 0 ? new Node(numList[0]) : NULL;
            Node *currentNode = this->head;
            for(int i=1; i<numList.size(); i++) {
                currentNode->next = new Node(numList[i]);
                currentNode = currentNode->next;
            }
        }
        Node *at(int index) {
            Node *iterator = this->head;
            for(int i=0; i<index; i++) {
                iterator = iterator->next;
                if(iterator == NULL) return NULL;
            }
            return iterator;
        }
        void preappend(Node *newNode) {
            newNode->next = this->head;
            this->head = newNode;
        }
        void append(Node *newNode) {
            Node *iterator = this->head;
            while(iterator->next != NULL) {
                iterator = iterator->next;
            }
            iterator->next = newNode;
        }
        // 先頭の要素を削除する
        void popFront() {
            this->head = this->head->next;
        }
        // 途中の要素を削除する
        void deleteNode(int index) {
            if(index == 0) return this->popFront();
            Node *iterator = this->head;
            // 削除するインデックスの手前まで繰り返し
            for(int i=0; i<index-1; i++) {
                iterator = iterator->next;
                if(iterator == NULL) return;
            }
            // for文を抜けたとき、iteratorの次の要素が削除したい要素になっている
            iterator->next = iterator->next->next;
        }
        void printList() {
            Node *iterator = this->head;
            string str = "";
            while(iterator != NULL) {
                str += to_string(iterator->data) + " ";
                iterator = iterator->next;
            }
            cout << str << endl;
        }
};

int main() {
    SinglyLinkedList *numList = new SinglyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});

    numList->printList();

    numList->popFront();
    numList->popFront();
    numList->printList();

    numList->deleteNode(4);
    numList->printList();

    numList->deleteNode(9);
    numList->printList();
}