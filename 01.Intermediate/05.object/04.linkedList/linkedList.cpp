#include <iostream>
using namespace std;

class StringNode {
    public:
        string value;
        // ポインタを参照するメンバ変数の型はポインタになる
        StringNode* next;

        StringNode(string stringValue) {
            this->value = stringValue;
            this->next = NULL;
        }
};


class TodoList {
    public:
        StringNode* head;

        TodoList() {
            this->head = NULL;
        }

        void printList() {
            cout << "Printing the Todo List..." << endl;
            // ポインタを参照するメンバ変数の型はポインタになる
            StringNode* currentNode = this->head;
            while(currentNode != NULL) {
                cout << currentNode->value << endl;
                currentNode = currentNode->next;
            }
        }

};

int main() {
    TodoList* toDoList = new TodoList();
    StringNode* firstItem = new StringNode("Fix the alarm clock.");
    toDoList->head = firstItem;

    StringNode* secondItem = new StringNode("Pickup grandmother from the dentist.");
    firstItem->next = secondItem;

    StringNode* thirdItem = new StringNode("Call the handyman to fix the home appliance.");
    secondItem->next = thirdItem;

    StringNode* fourthItem = new StringNode("Go to the park to jog.");
    thirdItem->next = fourthItem;

    toDoList->printList();
    return 0;
}