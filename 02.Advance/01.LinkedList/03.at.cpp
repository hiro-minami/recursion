#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        // メモリのアドレスを受け取るため、変数名の前にポインタが入る
        Node *next;
        Node(int value) {
            this->data = value;
            this->next = NULL;
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

        // 関数名にポインタが入るのは、返すデータのメモリを渡すから
        Node *at(int index) {
            Node *iterator = this->head;
            for(int i=0; i<index; i++) {
                iterator = iterator->next;
                if(iterator == NULL) return NULL;
            }
            return iterator;
        }
};

int main() {
    SinglyLinkedList *numList = new SinglyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});

    // 連結リストを反復します。
    cout << numList->at(2)->data << endl;
    cout << numList->at(12)->data << endl;
}