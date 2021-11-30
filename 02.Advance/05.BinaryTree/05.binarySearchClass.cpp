#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class BinaryTree {
    public:
        int data;
        BinaryTree *left;
        BinaryTree *right;
        BinaryTree(int value) {
            this->data = value;
        }
        BinaryTree(int value, BinaryTree *left, BinaryTree *right) {
            this->data = value;
            this->left = left;
            this->right = right;
        }
};

class BinarySearchTree {
    public:
        BinaryTree *root;
        BinarySearchTree(vector<int> arr) {
            this->root = (arr.size() == 0) ? NULL : this->sortedArrayToBST(arr, 0, arr.size());
        }
        BinaryTree *sortedArrayToBST(vector<int> arr, int start, int end) {
            if(start == end) return new BinaryTree(arr[start], NULL, NULL);
            int mid = floor((start+end)/2);
            BinaryTree *left = NULL;
            if(mid-1 >= start) left = this->sortedArrayToBST(arr, start, mid-1);
            BinaryTree *right = NULL;
            if(mid+1 <= end) right = this->sortedArrayToBST(arr, mid+1, end);
            BinaryTree *root = new BinaryTree(arr[mid], left, right);
            return root;
        }
        BinaryTree *search(int key) {
            BinaryTree *iterator = this->root;
            while(iterator != NULL) {
                if(key == iterator->data) return iterator;
                if(key < iterator->data) iterator = iterator->left;
                else iterator = iterator->right;
            }
            return NULL;
        }
        bool keyExist(int key) {
            BinaryTree *iterator = this->root;
            while(iterator != NULL) {
                if(key == iterator->data) return true;
                if(key < iterator->data) iterator = iterator->left;
                else iterator = iterator->right;
            }
            return false;
        }
};

int main(){
    BinarySearchTree* balancedBST = new BinarySearchTree({1,2,3,4,5,6,7,8,9,10,11});
    cout << balancedBST->keyExist(6) << endl;
    cout << balancedBST->search(6)->data << endl;
    cout << balancedBST->keyExist(2) << endl;
    cout << balancedBST->search(2)->data << endl;
    cout << balancedBST->search(34) << endl;
}