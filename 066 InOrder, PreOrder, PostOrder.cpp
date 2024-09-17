#include "062 Tree Basics.cpp"
#include <iostream>
#include <map>
using namespace std;

// BT FROM INORDER AND PREORDER : 
// LNR && NLR : these both have first left calls and then right calls and in preorder we'll start from N then L part is coming so we'll call left sub part first and then right part will be called 
// Preorder me 1st node root hota h, fir root ko inorder me find krenge or uske left and right sub parts dekhenge or usko bhi aise hi age solve krte rhenge 
/* 
Algo : 
i) take pre_index ( 1st element of preorder) as root element
ii) find root element's position in inorder
iii) ab to recursion sambhal lega baaki sare cases for left subpart : 0 to position and position + 1 to end tk right sub part k liye 
iv) for better time complexity : we can create  a map for connecting the nodes to their positions in inorder sequence
*/

// creating a map from node to their index in inorder sequence : 
void createMap(int in[],map<int, int> &nodeToIndex_inorder, int n){
    for (int i=0; i<n; i++) {
        nodeToIndex_inorder[in[i]] = i;
    }
}

// recursion main fn. : 
node* BT_Pre_In_rcrsn(int pre[],int in[], int pre_index, int inorderStart, int inorderEnd, int n, map<int, int> nodeToIndex_inorder){

    // base case : 
    if(pre_index >= n || inorderStart > inorderEnd) return NULL;

    int element = pre[pre_index++];
    node* root = new node(element);
    int position = nodeToIndex_inorder[element];
    // or can use brute force method to find:
    // for(int i=0; i<n; i++){
    //     if(in[i] == element) {position = i;}
    //     else {position = -1;}
    // }

    // recursive calls for left and right sub parts : 
    root->left = BT_Pre_In_rcrsn(pre, in, pre_index, inorderStart, position-1, n,nodeToIndex_inorder);
    root->right = BT_Pre_In_rcrsn(pre, in, pre_index, position+1, inorderEnd, n,nodeToIndex_inorder);

    return root;
}


// driver fn. :
node* BT_Pre_In(int pre[],int in[], int n){
    int pre_index = 0;
    map<int, int> nodeToIndex_inorder;
    // creating a map to connect the nodes to their indices in inorder sequence
    createMap(in,nodeToIndex_inorder,n);
    node* ans = BT_Pre_In_rcrsn(pre,in,pre_index,0,n-1,n,nodeToIndex_inorder);
    return ans;
}


// BT FROM INORDER AND POSTORDER : 
//bss kuch changes ho jayenge baaki sab same hi rhega
// Main difference : 
// LNR && LRN : these both have first left calls and then right calls 
// here, we'll be starting from N and going in reverse direction as we can see in Postorder after N, R is coming so we have to call right sub part first then we'll give a call for left sub part  

// creating a map from node to their index in inorder sequence : 
void createMap2(int in[],map<int, int> &nodeToIndex_inorder, int n){
    for (int i=0; i<n; i++) {
        nodeToIndex_inorder[in[i]] = i;
    }
}

// recursion main fn. : 
node* BT_Post_In_rcrsn(int post[],int in[], int post_index, int inorderStart, int inorderEnd, int n, map<int, int> nodeToIndex_inorder){

    // base case : 
    // post_index 0 se piche chala gya 
    if(post_index < 0 || inorderStart > inorderEnd) return NULL;

    int element = post[post_index--];
    node* root = new node(element);
    int position = nodeToIndex_inorder[element];
    // or can use brute force method to find:
    // for(int i=0; i<n; i++){
    //     if(in[i] == element) {position = i;}
    //     else {position = -1;}
    // }

    // recursive calls for left and right sub parts :
    // orders will be opposite from preorder problem :  
    root->right = BT_Pre_In_rcrsn(post, in, post_index, position+1, inorderEnd, n,nodeToIndex_inorder);
    root->left = BT_Pre_In_rcrsn(post, in, post_index, inorderStart, position-1, n,nodeToIndex_inorder);

    return root;
}


// driver fn. :
node* BT_Post_In(int post[],int in[], int n){
    
    // post_index hmesha last index hoga 
    int post_index = n-1;
    map<int, int> nodeToIndex_inorder;
    // creating a map to connect the nodes to their indices in inorder sequence
    createMap2(in,nodeToIndex_inorder,n);
    node* ans = BT_Pre_In_rcrsn(post,in,post_index,0,n-1,n,nodeToIndex_inorder);
    return ans;
}

// for both : 
// T.C : O(n.log(n)) bcoz of using hashing map 
// S.C : 


int main(){
return 0;
}