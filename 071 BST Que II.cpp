#include "062 Tree Basics.cpp"
#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

// TWO SUM IN A BST : 
// find two nos. in binary tree which gives sum equal to target sum : 
// 1st approach : brute force : har node ko visit krenge or uske left and right part me targetSum - node->data ko find krlenge agar mil gya toh thik h nhi to aisa pair exist nhi krta 
// T.C : O(n^2) for left and right skewed BT
// S.C : O(height)
// 2nd approach : 
// we know that bst ka inorder gives sorted order and we'll store that & then we'll find pair of nos. using 2 pointer approach 
//T.C : O(n) : single traversal 
// S.C : O(height) : for saving the inorder 

// saving the inorder : 
void inorderSave(node* root, vector<int> &v){
    if(!root) return ;
    inorderSave(root->left , v);
    v.push_back(root->data);
    inorderSave(root->right , v);
}

// driver fn. : 
bool twoSum(node* root, int targetSum){
    vector<int> v;
    inorderSave(root, v);

    int i = 0, j = v.size() - 1;
    while (i < j) {
        int sum = v[i] + v[j];
        if (targetSum == sum) {
            return true;
        }

        else if (sum > targetSum) {
            j-- ; 
        }

        else{
            i++ ; 
        }
    }
    return false;
}


//FLATTEN BST TO LL : 
// store inorder in a vector<int> and new nodes bnate rho iteratively and put left link to NULL and right link to next node 

node* flatten(node* root)
{
    // Write your code here
    vector<int> v;
    inorderSave(root, v);

    node* newRoot = new node(v[0]);
    node* curr = newRoot;

    int n = v.size();
    for(int i=1; i<n; i++){
        node* temp = new node(v[i]);
        curr->left = NULL;
        curr->right = temp ;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;
    return newRoot; 

}

// NORMAL BST TO BALANCED BST : 
// balanced bst : for every node |h(left subtree) - h(right subtree) | <= 1 
// check kese krenge if balanced bst or not : 
// recursion se har node ko puchte rhenge uska height differenc b/w left and right subtrees and usko return krte rhenge height,bool isBalancedSubtree 
// or usko convert krna to or bhi boht easy h : 
// inorder save krlo or usko mid se todd kr left half part left subtree me daal do and right half part right subtree me daal lo and baaki sb recursion sambhal lega 

// converting inorder to bst : 
node* inorderToBST(int s, int e, vector<int> v){
    // base case : 
    if (s > e) {
        return NULL;
    }

    int mid = (s+e)/2 ;
    node* root = new node(v[mid]);
    root->left = inorderToBST(s, mid-1, v);
    root->right = inorderToBST(mid+1, e, v);
    return root;
}

// driver code :
node* balancedBST(node* root){
    vector<int> v;
    inorderSave(root, v);
    return inorderToBST(0, v.size()-1, v);
}


// BST FROM PREORDER : 
// approach 1: take input and make bst from them using insertInBST() fn. like brute force method but it's T.C will be O(n^2)
// approach 2 : 
// sort the preorder so we'll get inorder and we already know to make bst from preorder and inorder with T.C : O(n.log(n))
// approach 3 : 
// we'll use range approach for root node it's range is (-inf,inf) then for it's left node range is (-inf,root->data) & for right node range is (root->data,inf)
// so we'll use this concept of ranging on node level using recursion such that we'll check for a new node if it first in which section of range and will put it there

// using ranging for each node using recursion : 
node* ranging(vector<int> &preorder, int mini, int maxi, int &i){
    // preorder completed :
    if (i >= preorder.size()) {
        return NULL;
    }

    // if out of the current selected range :
    if (preorder[i] < mini || preorder[i] > maxi ) {
        return NULL;    
    }

    // making new nodes and put it in place :
    node* root = new node(preorder[i++]);
    root->left = ranging(preorder, mini, root->data, i);
    root->right = ranging(preorder, root->data, maxi, i);
    return root;
}

// driver code : 
node* BSTfromPreOrder(vector<int> &preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return ranging(preorder, mini, maxi, i);
}

// T.C : O(n)
// S.C : O(h) where h is height of tree

int main(){

}