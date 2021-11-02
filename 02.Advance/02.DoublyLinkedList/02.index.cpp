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
        DoublyLinkedList(vector<int> numList) {
            if(numList.size() <= 0) {
                this->head = NULL;
                this->tail = this->head;
                return;
            }
            this->head = new Node(numList[0]);
            Node *currentNode = this->head;
            for(int i=1; i<numList.size(); i++) {
                currentNode->next = new Node(numList[i]);
                currentNode->next->prev = currentNode;
                currentNode = currentNode->next;
            }
            this->tail = currentNode;
        }
        Node *at(int index) {
            Node *iterator = this->head;
            for(int i=0; i<index; i++) {
                iterator = iterator->next;
                if(iterator == NULL) return NULL;
            }
            return iterator;
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

int main() {
    DoublyLinkedList *numList = new DoublyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});

    numList->printList();
    cout << numList->at(0)->data << endl; // 35
    cout << numList->at(2)->data << endl; // 546
    cout << numList->at(12)->data << endl; // 555
}