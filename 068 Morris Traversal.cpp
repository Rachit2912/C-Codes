#include "062 Tree Basics.cpp"
#include <cstddef>
#include <iostream>
using namespace std;

// MORRIS TRAVERSAL :
// this gives a traversal among these 3 traversals : inorder, preorder & postorder
/*
algo : 
-> current = root 
-> while(root != NULL)
    if left not exists : 
        visit (current)
        current = current->right
    else :
        find predecessor of current 
        (one left and then go upto the last right )
        # this is for creating the temporary links
        if (pred->right == NULL)
            pred=>right = current
            current = current->left
        
        # this is for removing those temporary links 
        else :
            pred->right = NULL
            visit(current)
            current = current->right
here, predecessor will be connected to root again and then we'll go to right sub part
so order is : left,root,right
& that's why this'll give the inorder traversal order
*/
void morrisTraversal(node* root){
    // base case : 
    if(root == NULL) return;

    node* current = root;
    while (current != NULL) {
    
    if (current->left == NULL) {
        cout<<current->data<<" ";
        current = current->right;
    }

    else {
        node* pred = current->left;
        while(pred->right != NULL && pred->right != current){
            pred = pred->right;
        }

        if (pred->right == NULL) {
            pred->right = current;
            current = current->left;
        }

        else {
            pred->right = NULL;
            cout<<current->data<<" ";
            current = current->right;
        }
    }
    }
}
// T.C : O(n) bcz every edge and node is traversed 3 times 
// S.C : O(1) since we are using only constant variables AND ** ONLY TRAVERSAL WITH THIS O(1)



// FLATTEN A BT TO ll IN PREORDER :
// S.C : O(n) and T.C : O(1)
// after flattening, right should give next node of the preorder and left should be NULL
// approaches are : 
// i) do the traversal and keep creating and  adding to a linked list in preorder but we have to do it in-place
// ii) using recursion : but problem is O(n) and O(n)
// iii) only appropriate way is Morris traversal
// but, we have to do some changes in morris traversal ordering to get the preorder instead of inorder
// preorder is : node,left,right
// so, first we have to connect predecessor to the right part & then we have to connect the root node to the left sub part of the tree
/*
exact algo : 
-> current = root 
-> while(curr != NULL){
        if curr->left exists : 
            {
                pred = curr->left
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right
                }

                pred->right = curr->right
                curr-right = curr->left
            }
            curr =curr->right
    }
*/

void flattenBTtoLL(node* root){
    //Morris traversal for preorder : 
    node* curr = root;
    while (curr != NULL) {
        if (curr->left) {
            node *pred = curr->left;
            while (pred->right) {
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            // left part saath me NULL karte chalo
        }
     
        curr = curr->right;
    }

}






int main(){
return 0;
}