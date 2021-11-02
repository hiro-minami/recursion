#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        // C++では、次のノードのメモリアドレスを参照するときはポインタを使用する
        Node *next;
        Node(int value) {
            this->data = value;
            this->next = NULL;
        }
};

class SinglyLinkedList {
    public:
        Node *head;
        SinglyLinkedList(Node *node) {
            this->head = node;
        }
}

int main() {
    // ノードを扱う際はオブジェクトが格納されているヒープのメモリアドレスを保持するポインタを使用する
    // newを使って呼び出すことで、オブジェクトの参照を返してくれる
    Node* node1 = new Node(4);
    Node* node2 = new Node(65);
    Node* node3 = new Node(24);

    SinglyLinkedList numList(node1);
    numList.head->next = node2;
    numList.hed->next->next = node3;

    Node* currentNode = numList.head;
    while(currentNode != NULL) {
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }

    currentNode = numList.head;
    while(currentNode != NULL) {
        cout << (*currentNode).data << endl;
        currentNode = currentNode->next;
    }
}