#include <iostream>
using namespace std;

class BinaryTree {
    public:
        int data;
        BinaryTree *left;
        BinaryTree *right;
        BinaryTree(int value) {
            this->data = value;
            this->left = NULL;
            this->right = NULL;
        }
};

int main() {
    BinaryTree *binaryTree = new BinaryTree(1);
    BinaryTree *leftNode = new BinaryTree(2);
    BinaryTree *rightNode = new BinaryTree(3);

    binaryTree->left = leftNode;
    binaryTree->right = rightNode;

    cout << "Root: " << binaryTree->data << endl;
    cout << "Left: " << leftNode->data << endl;
    cout << "Right: " << rightNode->data << endl;

    cout << "Root: " << binaryTree->data << endl;
    cout << "Left: " << binaryTree->left->data << endl;
    cout << "Right: " << binaryTree->right->data << endl;

    delete binaryTree;
    delete leftNode;
    delete rightNode;

    cout << "Root: " << binaryTree->data << endl;
    cout << "Left: " << leftNode->data << endl;
    cout << "Right: " << rightNode->data << endl;

    return 0;
}