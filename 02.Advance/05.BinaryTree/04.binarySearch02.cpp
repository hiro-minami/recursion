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

BinaryTree *sortedArrayToBSTHelper(vector<int> arr, int start, int end) {
    if(start == end) return new BinaryTree(arr[start], NULL, NULL);
    int mid = floor((start+end)/2);
    BinaryTree *left = NULL;
    if(mid-1 >= start) left = sortedArrayToBSTHelper(arr, start, mid-1);
    BinaryTree *right = NULL;
    if(mid+1 <= end) right = sortedArrayToBSTHelper(arr, mid+1, end);
    BinaryTree *root = new BinaryTree(arr[mid], left, right);
    return root;
}

BinaryTree *sortedArrayToBST(vector<int> nums) {
    if(nums.size() == 0) return NULL;
    return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
}

bool keyExist(int key, BinaryTree *bst) {
    BinaryTree *iterator = bst;
    while(iterator != NULL) {
        if(iterator->data == key) return true;

        if(iterator->data > key) iterator = iterator->left;
        else iterator = iterator->right;
    }
    return false;
}

int main(){
    BinaryTree* balancedBST = sortedArrayToBST({1,2,3,4,5,6,7,8,9,10,11});
    cout << keyExist(6, balancedBST) << endl;
    cout << keyExist(10, balancedBST) << endl;
    cout << keyExist(45, balancedBST) << endl;
}