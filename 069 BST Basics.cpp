#include "062 Tree Basics.cpp"
#include <cstddef>
#include <iostream>
using namespace std;

// BINARY SEARCH TREE :
// binary tree with 2 more conditions :
// for every node :- left subpart will have all values with less than root and right subpart will have all values more than root


// insertion in BST :
// just similar to binary search tree :
// T.C : O(log(n)) @ base 2; worst : O(n)
node* insertInBST(node* root,int d){
    // base case : 
    if (root == NULL) {
        root = new node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertInBST(root->right,d);
    }
    else {
        root->left = insertInBST(root->left,d);
    }

    return root;
}

void takingInput(node* &root){
    int d;
    cin>>d;

    while (d != -1) {
        root = insertInBST(root, d);
        cin>>d;
    }
}

// searching a member in BST :
// T.C : O(height); worst : O(n) ; S.C : O(height)
bool searchInBST(node *root, int x) {
    // base case :
    if(root == NULL) return false;
    if(root->data == x) return true;

    if(root->data > x){
        return searchInBST(root->left, x);
    }

    else{
        return searchInBST(root->right, x);
    }
}


// *** inorder of bst will give sorted order ***
node* minValue(node* root){
    node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

node* maxValue(node* root){
    node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}



//* inorder me kisi key k pehle jo ayega vo uska predecessor and jo baad me ayega vo uska successor
/* code to find them : 
 if (root->key == key)
    {
        the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
*/

// deletion :
// case 1 : if it doesn't have any child : just directly delete the node 
// case 2 : if it has only  one child : replace that node with its child 
// case 3 : if it contains both childs : 
// then, there are 2 ways to do it :
// either, replace the nodeToDelete with its either predecessor or successor, based on which we get minimum or maximum value and later delete that predecessor or successor node.

node* deletionInBST(node* root, int val){
    // base case :
    if(root == NULL) return root;

    if(root->data == val){
        // 0 child:
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child:
        // left child:
        if (root->left != NULL && root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // right child:
        else if (root->left == NULL && root->right != NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child:
        if (root->left != NULL && root->right != NULL) {
            // successor approach :
            int succ = minValue(root->right)->data;
            root->data = succ;
            root->right = deletionInBST(root->right, succ);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deletionInBST(root->left, val);
        return root;
    }

    else{
        root->right = deletionInBST(root->right, val);
        return root;
    }
}
// T.C : O(height); worst : O(n) ; S.C : O(height)

int main(){
    node* root = NULL;

    /*
    10 8 21 7 27 5 4 3 -1
    */
    cout<<"enter data to create bst : "<<endl;
    takingInput(root);

    cout<<"printing the bst : "<<endl;levelOrderTraversal(root);

    cout<<"inorder"<<endl;
    inorder(root);

    cout<<"preorder"<<endl;
    preorder(root);

    cout<<"postorder"<<endl;
    postorder(root);






return 0;
}