#include "062 Tree Basics.cpp"
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;


// MERGE 2 BST :
// approach 1 : 
// get the 2 inorders for 2 bst and merge them using merge 2 sorted arrays 
// get a new bst from that new sorted array 
//T.C & S.C : O(m+n)

// inorder save : 
void inorderSave(node* root, vector<int> &v){
    if (root == NULL ) {
        return;
    }

    inorderSave(root->left, v);
    v.push_back(root->data);
    inorderSave(root->right, v);
}

// merge 2 sorted arrays : 
vector<int> merge2SortedArrays(vector<int> a, vector<int> b){
    int i = 0 , j = 0, k = 0;
    vector<int> ans;
    while(i < a.size() && j <b.size()){
        if (a[i] < b[j]) {
            ans[k++] = a[i++];
        }

        else {
        ans[k++] = b[j++];
        }
    }

    while (i < a.size()) {
        ans[k++] = a[i++];
    }

    while (j < b.size()) {
        ans[k++] = b[j++];
    }

    return ans;
}

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
node* merge2BSTs(node* root1, node* root2){
    vector<int> inorder1, inorder2;
    inorderSave(root1, inorder1);
    inorderSave(root2, inorder2);

    vector<int> mergedArray = merge2SortedArrays(inorder1, inorder2);
    
    int s = 0, e = mergedArray.size() -1 ;
    return inorderToBST(s, e, mergedArray);
}

// approach 2 : more space wise optimized 
// we'll use LL to gain more optimized space time complexity of O(height)
// steps : 
// 1) convert a bst into a sorted DLL
// 2) merge 2 sorted LL 
// 3) make a bst out of sorted LL 
// T.C : O(m+n) and S.C : O(height1 + heght2)

// step 1 :
void flattenBST(node* root, node* head){
    if (root == NULL) {
        return;     
    }

    flattenBST(root->right, head);
    root->right = head;

    if (head != NULL) {
        head->left = root;
    }

    head = root;
    flattenBST(root->left, head);
}

// step 2 : 
node* mergeLinkedhead(node* head1, node* head2) {
    node* head = NULL;
    node* tail = NULL;

    cout << "\nBEFORE FIRST WHILE\n";
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if(head == NULL) {
                head = tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    cout << "\nAFTER FIRST WHILE\n";
    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// step 3 : 
// counting the total nodes : 
int countNodes(node* head) {
    int cnt = 0;
    node* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

// making a bst out of the sorted LL :
node* LL_2_BST(node* head, int n) {
    if(n <= 0 || head == NULL) {
        return NULL;
    }

    int temp = n/2;
    node* root = head;
    while(temp--) {
        root = root->right;
    }

    root->left = LL_2_BST(head, n/2);
    root->right = LL_2_BST(root->right, n-n/2-1);
    return root;

}

// driver code : 
node* merge2BSTs_LL(node* root1, node* root2){
    
    // step 1 : 
    node* head1 = NULL;
    node* head2 = NULL;
    flattenBST(root1, head1);
    flattenBST(root2, head2);
    head1->left = NULL;
    head2->left = NULL;

    // step 2 :
    node* mergedLL = mergeLinkedhead(head1, head2);

    // step 3 : 
    node* root_ans = LL_2_BST(mergedLL, countNodes(mergedLL));

    return root_ans;

}

int main(){

return 0;
}