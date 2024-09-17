#include "062 Tree Basics.cpp"
#include <climits>
#include <cstddef>
#include <iostream>
using namespace std;

/*
VALIDATE BST : 
approach 1 : inorder gives sorted array 
approach 2 : left part contains lesser values and right part contains greater values compared to root value
*/

bool isValidBST2_rcrsn(node* root, int min, int max){
    // base case : 
    if(root == NULL) return true;

    if (root->data <= max && root->data >= min) {
        bool leftPart = isValidBST2_rcrsn(root->left,min,root->data);
        bool rightPart = isValidBST2_rcrsn(root->right,root->data,max);
        return leftPart && rightPart;
    }

    else return false;
}

bool isValidBST2(node *root){
    return isValidBST2_rcrsn(root, INT_MIN, INT_MAX);
}


// FIND K-TH SMALLEST ELEMENT IN BST : 
// we'll use inorder sequence and count the k-th term of it and that's our answer
int k_th_smallest_rcrsn(node* root,int& i, int k){
    // base case : 
    if(root == NULL) return -1;

    // L : 
    int left = k_th_smallest_rcrsn(root->left, i, k);

    if(left != -1) return left;

    // N : 
    i++ ; 
    if(i == k) return root->data;

    // R : 
    return k_th_smallest_rcrsn(root->right, i, k);    
}

int k_th_smallest(node* root, int k){
    int i = 0;
    int ans = k_th_smallest_rcrsn(root,i,k);
    return ans;
}

// T.C : O(n) ; S.C : O(height)  
// we can make it more optimized by using Morris traversal 
// same que. : k-th largest element in bst : (n-k+1) th smallest element in inorder sequence


// PREDECESSOR & SUCCESSOR IN BST : 
// these are the pre & post values of an element in inorder sequence
// approach 1 : store inorder seperately and return pre & post values 
// approach 2 : 
// reach to the key node
// predecessor : left subtree me max. value(rightmost) and successor : right subtree me min. value (leftmost)
// T.C : O(n) ; S.C : O(1)


pair<int, int> predecessorSuccessor(node *root, int key)
{
   int pred = -1; // Initializing predecessor to -1
   int succ = -1; // Initializing successor to -1
   node* temp = root; // Initializing a temporary pointer to root
   
   // Traversing the tree until either reaching the end or finding the key
   while(temp && temp->data != key) {  
       if(temp->data > key) {
           // If current node's data is greater than key, update successor and move to the left subtree
           succ = temp->data;
           temp = temp->left;
       }
       else {
           // If current node's data is less than or equal to key, update predecessor and move to the right subtree
           pred = temp->data;
           temp = temp->right;
       }
   }  
   
   // If key is found in the tree
   if(temp) {
       // Finding predecessor
       node* leftTree = temp->left;
       while(leftTree) {
           pred = leftTree->data;
           leftTree = leftTree->right;
       }
       // Finding successor
       node* rightTree = temp->right;
       while(rightTree) {
           succ = rightTree->data;
           rightTree = rightTree->left;
       }
   }
   
   // Return the pair containing predecessor and successor
   return {pred, succ};
}


// LCA IN BST : 

node* LCAinaBST(node *root, node *P, node *Q)
{
    // base case : 
    while(root != NULL){
        
        // right side : 
        if(root->data < P->data && root->data < Q->data) root = root->right;

        // left side : 
        else if(root->data > P->data && root->data > Q->data) root = root->left;

        else{
            return root;
        }
    }
}





int main(){
return 0;
}