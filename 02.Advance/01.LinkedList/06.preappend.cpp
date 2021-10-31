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
            for(int i=0; i<numList.size(); i++) {
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
        // 先頭に受け取ったノードを追加する
        void preappend(Node *newNode) {
            newNode->next = this->head;
            this->head = newNode;
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

    numList->preappend(new Node(45));
    numList->preappend(new Node(236));
    numList->printList();
}