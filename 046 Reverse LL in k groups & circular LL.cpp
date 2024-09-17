#include <cstddef>
#include <iostream>
#include "044 Linked List Basics.cpp"
using namespace std;


// REVERSE LL IN "K GROUPS"
/*
we have to make pairs of k nodes and then we have to reverse them . 
So, we can do this by using recursion . we'll first start with head and select k nodes and reverse them iteratively.
Then, we will join the reversed ll with the remaining ll and by recursion it'll reverse all the nodes .
and last me prev wala node ko return kr denge so that we'll get our head pointer.
*/
Node* kReverse(Node *head, int k) { 
    
    // base case : 
    if (head == NULL) {
        return NULL;
    }
    
    // reversing the first "k" nodes iteratively :
    Node* remaining_ll_head = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;

    while (curr != NULL && count < k) {
        remaining_ll_head = curr->next;
        curr->next = prev;
        prev = curr;
        curr = remaining_ll_head;
        count++;
    }

    // recursion step for remaining ll :
    // checking if there are enough remaining nodes for applying the recursion : 
    int count_remain = 0;
    Node* temp = remaining_ll_head;
    while (temp != NULL) {
    temp = temp->next;
    count_remain++;
    }

    // doing the recursion on the remaining ll if there are enough nodes left :
    if (count_remain >= k) {
    head->next = kReverse(remaining_ll_head, k);
    }

    else{
        head->next = remaining_ll_head;
    }

    // returning the head pointer of k-Reversed ll :
    return prev;

}   


// CIRCULAR LL OR NOT ?
// to find if a ll is circular or not?
/*
(i) empty list : return true;
(ii) only 1 node: if head->next != NULL  then false otherwise true.
(iii) more than one node : loop through the linked list and check if next == head then it's circular else non-circular.
*/

bool circularOrNot(Node* &head){
    // empty list :
    if (head == NULL) {
    return true;
    }

    // only 1 node and all the other cases :
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    if(temp == head){
        return true;
    }
    return false;

    // we can use hash-map also for this prblm.
}


int main(){

Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;
insert_at_tail(tail, 20);
insert_at_tail(tail, 30);
insert_at_tail(tail, 40);
insert_at_tail(tail, 50);
insert_at_tail(tail, 60);
insert_at_tail(tail, 70);
insert_at_tail(tail, 80);
print(head); 
cout<<endl;


Node* kreverse = kReverse(head,3);
print(kreverse);    
cout<<endl<<circularOrNot(head);








return 0;

}
