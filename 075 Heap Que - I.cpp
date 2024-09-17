#include <cstddef>
#include <functional>
#include<iostream>
#include <queue>
#include <vector>
#include"074 Heap Basics.cpp"
#include "062 Tree Basics.cpp"
using namespace std;

// k-th smallest element : 
/*
given a array and find the k-th smallest element 
approach 1 : sort krdo and find krlo 
T.C : O(n.log(n))

approach 2 : using heap
- first, make a max heap of first k elements of array 
- then for left elements, if element < heap.top() : heap.pop() and then heap.push(element)
- so, it'll ultimately create a heap for the first k smallest element 
- & our heap.top() will be the ans. 
- T.C : O(n.log(n)) bcz we are doing push and pop operations for all n elements of array 
*/

int kthSmallest(int n, int k, vector<int> arr){
    priority_queue<int> pq;

    for (int i = 0; i<k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i<n; i++) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

// IS BINARY TREE A HEAP ?
/*
2 conditions : cbt & max heap property 
if both 2 conditions are satisfied then true else false 
T.C : O(n)
*/
// counting total nodes fn. : 
int countNodes(node* root){
    if (root == NULL) {
        return 0;
    }
    int n = 1 + countNodes(root->left) + countNodes(root->right);
    return n;
}

// complete binary tree checker fn. : 
bool isCBT(node* root, int i, int totalNodes){
    // leaf nodes always cbt
    if (root == NULL) {
        return true;
    }

    // index out of the totalNodes 
    if (i >= totalNodes) {
        return false;
    }

    //checking the left subpart and right subpart 
    else {
    bool left = isCBT(root->left, 2*i +1, totalNodes);
    bool right = isCBT(root->right,2*i +2, totalNodes);
    return left && right;
    }

}

// checking the max heap property : 
bool isMaxHeapOrder(node* root){
    // leaf nodes :
    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    // node with only left child :
    if (root->right == NULL) {
        return (root->data > root->left->data);
    }

    // Handle edge case :
    if (root->right && !root->left) return false;  

    // nodes with 2 children :
    else{

        // checking the left & right subparts also for the current selected node :
        bool leftPart = isMaxHeapOrder(root->left);
        bool rightPart = isMaxHeapOrder(root->right);

        // checking the conditions on current node also with left & right subparts : 
        return (leftPart && rightPart && root->data > root->left->data && root->data > root->right->data);
    }


}

bool isHeap(node* root){
    int i = 0;
    int totalNodes = countNodes(root);
    if(isCBT(root,i,totalNodes) && isMaxHeapOrder(root)) return true;
    return false;
}

// MERGE 2 BINARY MAX HEAPS : 
// approach : merge 2 vectors & heapify the merged ans vector 

// heapify fn. : 
// T.C : O(log(n))
void heapifyfn(vector<int> arr, int n, int i){
    // 1 based indexing 
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if (largest != i) {
        swap(arr[i],arr[largest]);
        heapifyfn(arr,n,largest);
    }
}

// main fn. : 
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m){
    // step 1 : merge both arrays in a final vector 
    vector<int> ans;
    for (auto i  : a) {
        ans.push_back(i);
    }
    for (auto i : b) {
        ans.push_back(i);
    }

    // step 2 : build heap using merged vector
    int size = ans.size();
    for (int i = n/2; i>0; i--) {
        heapifyfn(ans, size, i);
    }

    return ans;
}

//MINIMUM COST OF ROPES : 
/*
'n' ropes of different lengths & to connect 2 ropes the cost is their sum length then find the min. cost to connect all the 'n' ropes 

 approach :build a min heap of this given ropes using priority queue & find the top 2 min elements & add the again push in the heap & do the same until heap's size != 1 
*/

int minCost(int arr[], int n){

    // priority queue for min heap :
    priority_queue<int,vector<int>, greater<int>> pq;

    for (int i = 0; i<n; i++) {
        pq.push(arr[i]);
    }

    int cost = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int sum = a+b ; 
        cost += sum ; 
        pq.push(sum);
    }
    return cost;
}
// T.C : O(n.log(n))
// S.C : O(n)


// CONVERT BST TO MIN HEAP :
// given a bst which is a cbt, it means we have to just check the min order property & one condition is also there : that all left subtree elements should be lesser than right subtree elements
/*
approach : 
- ye cbt h already islye heap me iska structure same hi rhega ab bs hme min heap prop. ka dhyan rkhna h & left-right subtree wali values ka dhyan rkhna h 
- to first hm inorder nikalenge of given bst, which will give us the sorted order 
- ab hme Node<left<right is order me bharna h which is the preorder of the bst 
- bs to for given inorder, preorder se bst bana lo 
*/

void getinorder(node* root,vector<int> &v){

    if(!root){
        return;
    }

    getinorder(root->left,v);
    v.push_back(root->data);
    getinorder(root->right,v);

}

 

void fillpreorder(node* &root,vector<int> inorder,int &i){

    if(!root){
        return;
    }

    root->data = inorder[i++];
    fillpreorder(root->left,inorder,i);
    fillpreorder(root->right,inorder,i);

}

 

node* convertBST(node* root)

{
    //step1: get inorder of bst which is in sorted order

    vector<int> inorder;
    getinorder(root,inorder);

   //step 2: min order && for all  L data < for all  R  data => N<L<R which is a preorder

    int i=0;
    fillpreorder(root,inorder,i);
    return root;

}