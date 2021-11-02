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
        // キーを受け取り、そのキーに合致するデータを持つ最初のノードを返す
        int findNode(int key) {
            Node *iterator = this->head;
            int count = 0;
            while(iterator != NULL) {
                if(iterator->data == key) return count;
                iterator = iterator->next;
                count++;
            }
            // 最後まで回った場合は見つからなかったということ
            return -1;
        }
};

int main(){
    SinglyLinkedList *numList = new SinglyLinkedList({35,23,546,67,86,234,56,767,34,1,98,78,555});
    cout << numList->at(2)->data << endl; // 546
    cout << numList->at(5)->data << endl; // 234
    cout << numList->findNode(67) << endl; // 3
    cout << numList->findNode(767) << endl; // 7
    cout << numList->findNode(111111) << endl; // -1
}