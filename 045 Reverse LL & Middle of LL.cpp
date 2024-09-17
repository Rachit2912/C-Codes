#include <cstddef>
#include <iostream>
#include <ostream>
#include "044 Linked List Basics.cpp" // comment the main fn. in the file before using
using namespace std;


// REVERSE A LINKED LIST :-
// 2 approachs : 
// 1st approach : iteratively 
/*  sabhi links ko reverse krdo means ke sabhi forward links ka direction reverse kar dete h 1-1 karke or usko reverse krde to linked list apne aap reverse ho jayegi
1 -1 node ko lenge using 'curr' and 1 node lenge 'prev' usko null se start krenge and fir baki bachi hui ll ko 'remain_ll_head' me save krdenge and uss node ki link ko reverse krdenge and fir 'curr' , 'prev' and 'forward' sbko update krdenge
*/
Node* reverse_sll_iteratively(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* remaining_ll_head = curr->next;
        curr->next = prev;
        prev = curr;
        curr = remaining_ll_head;
    }

    return prev;

}

//2nd approach : recursively 
/*hum kya krenge isme ki 1 node ko leke sochenge or fir usko sbpr imply kr denge
to 1 node pr sb se pehle uski link kaat denge, or usko piche kahi connect kr denge and baki bachi hui ll ko uss node se connect kr denge 
bs yhi recursively krna h hme 
*/

void recursion_fn(Node* &head, Node* curr, Node* prev){
    // base case :
    if(curr == NULL){
        head = prev;
        return;
    }

    // recursive step :
    Node* remaining_ll_head = curr->next;
    recursion_fn(head,remaining_ll_head, curr);
    curr->next = prev;

}

Node* reverse_sll_recursively(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    recursion_fn(head, curr, prev);
    return head;
}

// 3rd approach : 
/*
using recursion only : 
first we'll solve 1 case then it'll go on recursively and solve all the other cases
first we'll take 1 node and uski links reverse krte krte baaki bachi hui linked list tk pahuch jayenge and isse end me linked list me keval 1 hi element bachega or uske liye hm base case likh denge and wapa recursive fn. return krte time sb apne aap reverse kr dega 
*/

Node* reverse_sll_recursively_2(Node* &head){
    //base case : jb end me last element bacha hoga 
    if (head == NULL || head->next == NULL) {
    return head;
    }

    // recursive step : linked list ko todte todte jao and links reverse krte jao
    Node* remaining_ll_head = reverse_sll_recursively_2(head->next);
    head->next->next = head;
    head->next = NULL;
    return remaining_ll_head;
}


// FIND THE MIDDLE ELEMENT OF THE LINKED LIST :-
// give the middle element if n == odd and return the second element if n == even
/*  approach 1 : basic approach 
count the no. of elements in linked list and find (length/2)+1  th element
*/
Node* middle_ll(Node* &head){
    int len = 0;
    Node* temp = head ;
    while (temp != NULL) {
    temp = temp->next;
    len++;
    }
    len = len/2;
    temp = head;
    while (len--) {
    temp = temp->next;
    }
    return temp;
}

 /* approach 2 :  
we'll use 2 pointers one will start at head->next and move 2 steps per iteration while the other one will start at head itself and will move 1 step per iteration and when fast one will reach at the end then the other one will be at the middle of the ll.
 */

Node* middle_ll_2(Node* &head){
    if (head == NULL || head->next == NULL) {
    return head;
    }

    if (head->next->next == NULL) {
    return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL) {

    fast = fast->next;
    
    if (fast != NULL) {
    fast = fast->next;
    }

    slow = slow->next;

    }
    return slow;
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
print(head); 
cout<<endl;

cout<<"approach 1 : iteratively "<<endl;
Node* reversehead1 = reverse_sll_iteratively(head);
print(reversehead1);
cout<<endl;
head = reverse_sll_iteratively(reversehead1);


cout<<"approach 2 : recursively 1 "<<endl;
Node* reversehead2 = reverse_sll_recursively(head);
print(reversehead2);
cout<<endl;
head = reverse_sll_recursively(reversehead2);


cout<<"approach 3 : recursively 2 "<<endl;
Node* reversehead3 = reverse_sll_recursively_2(head);
print(reversehead3);
cout<<endl;
head = reverse_sll_recursively_2(reversehead3);

cout<<"list is : ";
print(head);
cout<<endl<<"middle of ll by approach 1 is : ";
Node* middle = middle_ll(head);
cout<<middle ->data;
cout<<endl<<"middle of ll by approach 2 is : ";
Node* middle_2 = middle_ll_2(head);
cout<<middle_2->data<<endl;

return 0;
}