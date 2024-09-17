#include "062 Tree Basics.cpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
using namespace std;

// LARGEST BST IN A BINARY TREE : 
// return the size of largest bst present in a binary tree
// approach 1 : 
// har node pr jao & check for validateBST() fn. and return the size if it is a validate bst 
// T.C: O(n^2)

// approach 2:
// pehle ham validateBST() fn. har node k liye call kr rhe the 
// pr hm 1 node pr validatebst() pta laga skte h if :
// left subtree is valid bst 
// right subtree is valid bst
// and max(left_subtree) < root->data < min(right_subtree)
// so to store this information, we'll make a class named 'info' having 4 params. int maxi,int mini,bool isvalidBST() & int size
// return this values recursively starting from leaf node and return this pile of params. to root node and check recursively for each node

class info{
    public:
    int maxi;
    int mini;
    int size;
    bool isBST;
};

info largestBST_rcrsn(node* root, int &ans){
    // base case : 
    if (root == NULL) {
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = largestBST_rcrsn(root->left, ans);
    info right = largestBST_rcrsn(root->right, ans);

    info currNode;
    currNode.maxi = max(right.maxi,root->data);
    currNode.mini = min(left.mini,root->data);
    currNode.size = left.size + right.size + 1;

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // answer update : 
    if (currNode.isBST) {
        ans = max(ans,currNode.size);
    }

    return currNode;
}

int largestBST(node* root){
    int maxSize = 0;
    info temp = largestBST_rcrsn(root, maxSize);
    return maxSize;
}
// T.C : O(n)
// S.C : O(h)


int main(){

return 0;
}
