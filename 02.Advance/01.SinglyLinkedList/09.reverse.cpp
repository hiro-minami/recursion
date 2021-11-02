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
        void popFront() {
            this->head = this->head->next;
        }
        void deleteNode(int index) {
            Node *iterator = this->head;
            for(int i=0; i<index-1; i++) {
                iterator = iterator->next;
                if(iterator == NULL) return;
            }
            iterator->next = iterator->next->next;
        }
        void reverse() {
            /*
            * ①先頭のアドレスをreverseHeadに追加
            * ②先頭を変更
            * ③reverseHeadに入っているアドレスのnextをnullにする
            * (②と③が逆になるとwhileがループしないので注意。this->headとreverseHeadのアドレスが同じなので影響が出る)
            */
            Node *reverseHead = this->head;
            this->head = this->head->next;
            reverseHead->next = NULL;
            while(this->head != NULL) {
                // 先頭をtemp
                Node *tempNode = this->head;
                this->head = this->head->next;
                // tempをeverseの先頭に
                tempNode->next = reverseHead;
                reverseHead = tempNode;
            }
            this->head = reverseHead;
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

    SinglyLinkedList *numList = new SinglyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});

    numList->printList();
    numList->reverse();
    numList->printList();

}