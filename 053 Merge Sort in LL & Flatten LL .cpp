#include <cstddef>
#include<iostream>
#include "044 Linked List Basics.cpp"
using namespace std;

// for finding middle of ll :
Node* middle_ll_2(Node* &head){
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    }

    return slow;
}


// for merging 2 sorted ll :
Node* merge_2_sorted_ll(Node* left, Node* right){
    if (left == NULL) {
    return right;
    }

    if (right == NULL) {
    return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while (left != NULL && right != NULL) {

    if (left->data < right->data) {
    temp->next = left;
    temp = left;
    left = left->next;
    }

    else {
    temp->next = right;
    temp = right;
    right = right->next;
    }
    }

    while (left != NULL) {
    temp->next = left;
    temp = left;
    left = left->next; 
    }

    while (right != NULL) {
    temp->next = right;
    temp = right;
    right = right->next;
    }

    ans = ans->next;
    return ans;

}


// MERGE SORT IN LL : 
Node* mergesort_ll(Node* head){

    // base case : 
    if (head == NULL || head->next == NULL) return head;

    // dividing ll into 2 parts and making a partition  around the middle element:
    Node* mid = middle_ll_2(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL; // for making a wall or partition to divide the ll into 2 parts 


    // recursive calls to sort both halves :
    left = mergesort_ll(left);
    right = mergesort_ll(right);

    Node* result = merge_2_sorted_ll(left, right);

    // returning the ans.
    return result;
}

// FLATTEN A LL : 
/*  har 1 node k 2 pointers h next & child or iss multilevel ll ko hmko 1 single flatten ll bnake deni h jo ki sorted order me honi chahiye 

// Approach :
kuch nhi ll ko 2 parts me break kr denge 1) down wali and 2) next remaining ll 
remaining ll ko recursive me daal denge vo recursion se solve ho jayega with base case if : head->next == NULL: return head;
fir wha se jo return hoke node ayega usko add krte rhenge via merge 2 sorted ll and isse last tk return hote hote puri sorted ll ready ho jayegi
bss dhyaan rkhna ki merge_2_sortedd_ll wale fn. me jb merge kr rhe honge to next ptr. ki jagah child ptr. ko consider krenge everytime bcz yha pr sb child ptr. pr hi dependent h 
*/
Node* flattenLinkedList(Node* head) 
{
	// base case :
	if(head->next == NULL) return head;

	Node* down = head;
	Node* remaining_ll = flattenLinkedList(head->next);
	down->next = NULL;
	
	Node* ans = merge_2_sorted_ll(down, remaining_ll);
	return ans;

}

int main(){

// singly linked list :
Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;
insert_at_tail(tail, 100);
insert_at_tail(tail, 30);
insert_at_tail(tail, 4);
insert_at_tail(tail, 15);
insert_at_tail(tail, 62);
insert_at_tail(tail, -7);
insert_at_tail(tail, -8);
print(head); 
Node* sort = mergesort_ll(head);
print(sort);

return 0;
}


// IMP. QUESTION : 
/*
Q: WHY DO YOU PREFER MERGE SORT IN LL AND QUICK SORT IN ARRAY ?
*/