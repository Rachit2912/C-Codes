#include "062 Tree Basics.cpp"
#include <climits>
#include <cstddef>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// SUM OF LONGEST BLOODLINE : 
//we can directly use recursion and for all paths we can check sum and will select the maximum sum 
void maxSum_rcrsn(node* root,int len,int &maxlen, int sum, int& maxSum){

    // base case : 
    if (root == NULL) {
        
        // length zyada ho gyi ho :
        if (len > maxlen) {
            maxlen = len ;
            maxSum = sum;
        }

        // length me kuch changes nhi hue :
        else if (len == maxlen) {
            maxSum = max(sum,maxSum);
        }
        return;
    }

    sum += root->data;

    maxSum_rcrsn(root->left, len+1, maxlen, sum, maxSum);
    maxSum_rcrsn(root->right, len+1, maxlen, sum, maxSum);

}

int maxSum(node* root){
    int len = 0;
    int maxlen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    maxSum_rcrsn(root,len,maxlen,sum,maxSum);
    return  maxSum;
}


// lOWEST COMMON ANCESTOR (LCA) OF BT : 
// neeche se 2 nodes k liye sbse pehle milne wala ancestor hi LCA h. 
// iske 2 solns. h : 1st is quite obvious ki dono nodes ka root se path nika lo or reverse me jo first common node mile whi ans h 
// 2nd approach is : using recursion :
// hm root se start krenge or 2 seperate parts ko maintain krenge leftPart ka ans. and rightPart ka ans.
// root se start krenge or puchenge ki kya vo 2 nodes me se h kya ya nhi 
// nhi to left me kud jayenge aur yhi same krte rhenge 
// end me jb left subtree ka last node aa jayega to 2 side se null ho jayega ans. and aise me null return kr denge
// ab right branch me ajayenge and same whi krenge, agar vo node kahi mil gya to 1 side se to non null ayega and 2nd side se null ayega aise me hm non null return krenge
// or jaha pr 2 node non null return krte hue mil jayenge whi pr hi hamara ans. hoga 

node* lca_BT(node* root,int n1,int n2){
    // base case :
    if(root == NULL) return NULL;

    // if n1 or n2 found : 
    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* leftPart = lca_BT(root->left, n1, n2);
    node* rightPart = lca_BT(root->right, n1, n2);

    if (leftPart != NULL && rightPart != NULL) {
        return root;
    }

    else if (leftPart != NULL && rightPart == NULL) {
        return leftPart;
    }

    else if (leftPart == NULL && rightPart != NULL) {
        return rightPart;
    }

    return NULL; // else when both are NULL 
}


// K sum paths : 
// given a targetSum and we have to find no. of all paths along which sum of all nodes will == targetSum
// approach: find all paths for a given BT and find the sum of all those and compare 

void k_sum_rcrsn(node* root,int targetSum, int &count, vector<int> paths){
    // base case :
    if(root == NULL) return;

    paths.push_back(root->data);

    // left call:
    k_sum_rcrsn(root->left, targetSum, count, paths);
    // right call :
    k_sum_rcrsn(root->right, targetSum, count, paths);

    // check if targetSum is achieved or not :
    int size = paths.size();
    int sum = 0;
    for (int i = size-1; i>=0; i--){
        sum += paths[i];
        if(sum == targetSum) count++;
    }
    
    // remove last element from path:
    paths.pop_back();
}


int k_sum(node* root,int targetSum){
    vector<int>paths;
    int count = 0;
    k_sum_rcrsn(root,targetSum,count,paths);
    return count;
}

// K TH ANCESTOR OF A TREE NODE :
//2 approaches : 
//1st path from root to node save krlo and reverse krke nikal lao
// 2nd recursive : 
// pehle to vo node search krlo 
// fir 2 parts baatlo leftPart and rightPart agar 2 null h to return null, koi 1 non null h to usko return krdo and during this 'k' will be decrementing and when we'll get k==0 that's our ans.

node* ancestor_k_rcrsn(node* root,int &k,int n){

    // base case : 
    if(root == NULL) return NULL;

    if(root->data == n) return root;

    node* leftPart = ancestor_k_rcrsn(root->left, k, n);
    node* rightPart = ancestor_k_rcrsn(root->right, k, n);

    // values check krlo : 
    if(leftPart != NULL && rightPart == NULL){
        k--;
        if(k<=0){
            k = INT_MAX; // itna bdaa krdo isko taaki ye kbhi zero naa ho paye
            return root;
        }
        return leftPart;
    }

    else if(leftPart == NULL && rightPart != NULL){
        k--;
        if(k<=0){
            k = INT_MAX; // itna bdaa krdo isko taaki ye kbhi zero naa ho paye
            return root;
        }
        return rightPart;
    }

    return NULL; // else both parts are NULL 
}


int ancestor_k(node *root ,int n, int k ) {

node* ans = ancestor_k_rcrsn(root ,k, n);
if(ans == NULL || ans->data == n) return -1;
// ans->data == n : will occur when we are asking for a non existing node or ancestor which is not the part of the tree basically considering when n == root of the tree then k doesn't matter bcz for root no ancestor is existing
else return ans->data;

}


// MAX SUM OF NON -ADJACENT NODES IN BT : 
// isko recursion se easily kr denge agar hmare paas har node ke liye 2 values ho : maxSum by including nodes at current level | maxSum by excluding nodes at current level 
// bss yeh pair ko neeche se start krenge or end tk hmare paas ans. aajayega 

pair<int, int> maximumSumOfNodes_rcrsn(node* root){
// pair : including value | excluding value 

    // base case : 
    if(root == NULL) {
        return {0,0};
    }

    pair<int, int> leftPart = maximumSumOfNodes_rcrsn(root->left);
    pair<int, int> rightPart = maximumSumOfNodes_rcrsn(root->right);

    pair<int, int> result;
    result.first = root->data + leftPart.second + rightPart.second;
    result.second = max(leftPart.first,leftPart.second) + max(rightPart.first,rightPart.second) ;

    return result;

} 

int maximumSumOfNodes(node* root){

    pair<int, int> ans = maximumSumOfNodes_rcrsn(root);
    return max(ans.first,ans.second);
}

int main(){
return 0;
}