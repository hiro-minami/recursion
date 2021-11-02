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
                // 今作成したnextの前のノードをcurrentNodeに割り当てる
                currentNode->next->prev = currentNode;
                currentNode = currentNode->next;
            }
            this->tail = currentNode;
        }
        void printList() {
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
    cout << numList->head->data << endl;
    cout << numList->head->next->data << endl;

    cout << numList->tail->data << endl;
    cout << numList->tail->prev->data << endl;
}