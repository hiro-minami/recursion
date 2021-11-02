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
        // 新しいノードを受け取って、次のノードに設定する
        void addNode(Node *newNode) {
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
        // ノードのデータを出力する
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
    cout << numList->at(2)->data << endl;
    cout << numList->at(3)->data << endl;
    cout << numList->at(4)->data << endl;
    numList->printList();

    // データの挿入(mainで書いた場合)
    Node *thirdNode = numList->at(2);
    Node *tempNode = thirdNode->next;
    Node *newNode = new Node(40);
    thirdNode->next = newNode;
    newNode->next = tempNode;

    cout << numList->at(2)->data << endl;
    cout << numList->at(3)->data << endl;
    cout << numList->at(4)->data << endl;
    numList->printList();

    // リストのインデックスが偶数番目の要素を 2 倍にし、それぞれの要素の後ろに追加する
    Node *iterator = numList->head;
    int i=0;
    while(iterator != NULL) {
        Node *currentNode = iterator;
        iterator = iterator->next;
        if(i%2 == 0) currentNode->addNode(new Node(currentNode->data*2));
        i++;
    }
    numList->printList();
}