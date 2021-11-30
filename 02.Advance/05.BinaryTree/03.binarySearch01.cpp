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
    // start == endなら値を返す
    if(start == end) return new BinaryTree(arr[start], NULL, NULL);
    // 真ん中を求める
    int mid = floor((start+end)/2);
    // 左側を攻める
    BinaryTree *left = NULL;
    if(mid-1 >= start) left = sortedArrayToBSTHelper(arr, start, mid-1);
    // 右側を攻める
    BinaryTree *right = NULL;
    if(mid+1 <= end) right = sortedArrayToBSTHelper(arr, mid+1, end);
    // rootを作成し、左右をつなげる
    BinaryTree *root = new BinaryTree(arr[mid], left, right);
    return root;
}

BinaryTree *sortedArrayToBST(vector<int> arr) {
    if(arr.size() == 0) return NULL;
    return sortedArrayToBSTHelper(arr, 0, arr.size()-1);
}

bool keyExist(int key, BinaryTree *tree) {
    // 最後まで検索できている、見つからなかったらfalse
    if(tree == NULL) return false;
    if(key == tree->data) return true;

    // 左右のどちらを次の検索範囲とするかを決める
    if(tree->data > key) return keyExist(key, tree->left);
    else return keyExist(key, tree->right);
}

int main(){
    BinaryTree* balancedBST = sortedArrayToBST({1,2,3,4,5,6,7,8,9,10,11});
    cout << keyExist(6, balancedBST) << endl;
    cout << keyExist(10, balancedBST) << endl;
    cout << keyExist(45, balancedBST) << endl;
}