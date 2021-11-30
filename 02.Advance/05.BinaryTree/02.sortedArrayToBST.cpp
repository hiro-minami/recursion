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

// ソート済みリストを木構造に変換する
// 真ん中を求める
// 問題を分割する
BinaryTree *sortedArrayToBSTHelper(vector<int> arr, int start, int end) {
    if(start == end) return new BinaryTree(arr[start], NULL, NULL);

    // 真ん中を求める
    int mid = floor((start+end)/2);

    // 左を攻める
    BinaryTree *left = NULL;
    if(mid-1 >= start) left = sortedArrayToBSTHelper(arr, start, mid-1);

    // 右を攻める
    BinaryTree *right = NULL;
    if(mid+1 <= end) right = sortedArrayToBSTHelper(arr, mid+1, end);

    // 真ん中と左右をつなげる
    BinaryTree *root = new BinaryTree(arr[mid], left, right);
    return root;
}

BinaryTree *sortedArrayToBST(vector<int> nums) {
    if(nums.size() == 0) return NULL;
    return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
}



int main(){
    BinaryTree* balancedBST = sortedArrayToBST({1,2,3,4,5,6,7,8,9,10,11});
    cout << keyExist(6, balancedBST) << endl;
    cout << keyExist(10, balancedBST) << endl;
    cout << keyExist(45, balancedBST) << endl;
}