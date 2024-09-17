#include <cstddef>
#include<iostream>
#include "044 Linked List Basics.cpp"
using namespace std;

// SORT 0,1,2 IN ll :
// Approach 1 : count krlo kitne 0,1 and 2 hai and utna chipka do

Node* sort012_app1(Node* head){
    int z = 0,o = 0, t = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) {
        z++;
        }

        else if (temp->data == 1) {
        o++;
        }

        else if (temp->data == 2) {
        t++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
    if (z != 0) {
    temp->data = 0;
    z--;
    }

    else if (o != 0) {
    temp->data = 1;
    o--;
    }

    else if (t != 0) {
    temp->data = 2;
    t--;
    }
    temp = temp->next;
    }

    return head;

}


// Approach 2 : data we can't change, so we'll change the links
/* 3 seperate ll bnayenge for 0,1 and 2 and then will merge 'em all */
Node* sort012_app2(Node* head){
    
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;

    while (curr != NULL) {
    int value = curr -> data;

    if (value == 0) {
    insert_at_tail(zeroTail, value);
    }

    if (value == 1) {
    insert_at_tail(oneTail, value);
    }

    if (value == 2) {
    insert_at_tail(twoTail, value);
    }

    curr = curr->next;
    }


// merge 3 sub-ll :
if (oneHead->next != NULL) {
zeroTail->next = oneHead->next; // 1's list isn't empty
}

else {
zeroTail->next = twoHead->next;
}

oneTail->next = twoHead->next;
twoTail->next = NULL;
head = zeroHead->next;
delete zeroHead;
delete oneHead;
delete twoHead;

return head;
}

// MERGE 2 SORTED LL :
/*
2nd list se 'temp' me 1-1 krke uthayenge or uske 1st list me 'prev' and 'curr' k beech me check krke dekhnge ki agr usko unn dono ke beech me rkh skte h ya nhi , agr rkh skte h to wha fit kr denge and temp ko aage bdhayenge nhi to prev and curr ko aage badhayenge
*/

Node* merge_sorted(Node* first,  Node* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if(first->next==NULL){
            first->next = second;
            return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL) {
    
    if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {

    curr1->next = curr2;
    next2 = curr2->next;
    curr2->next = next1;
    curr1 = curr2;
    curr2 = next2;
    }

    else {
    curr1 = next1;
    next1 = next1->next;
    if(next1 == NULL) {curr1->next = curr2; return first;}
    }
    }

return first;
}

Node* merge_2_sorted_ll(Node* first, Node* second){
    Node* ans = NULL;
    if (first->data <= second->data) {
    ans = merge_sorted(first,second);
    return ans;
    }

    else {
        ans = merge_sorted(second,first);
        return ans;
    }
}

int main(){

// sorted singly linked list :
Node* node1 = new Node(1);
Node* head = node1;
Node* tail = node1;
insert_at_tail(tail, 0);
insert_at_tail(tail, 1);
insert_at_tail(tail, 0);
insert_at_tail(tail, 2);
insert_at_tail(tail, 2);
insert_at_tail(tail, 1);
insert_at_tail(tail, 1);
insert_at_tail(tail, 0);
print(head); 
cout<<endl;
Node* head2 = sort012_app2(head);
print(head2);


// sorted singly linked list :
Node* first = new Node(1);
Node* headf = first;
Node* tailf = first;
insert_at_tail(tailf, 2);
insert_at_tail(tailf, 3);
insert_at_tail(tailf, 4);
insert_at_tail(tailf, 5);
print(headf); 
cout<<endl;


// sorted singly linked list :
Node* second = new Node(6);
Node* heads = second;
Node* tails = second;
insert_at_tail(tails, 7);
insert_at_tail(tails, 8);
insert_at_tail(tails, 9);
insert_at_tail(tails, 10);
print(heads);
cout<<endl;

Node* mergedHead = merge_2_sorted_ll(headf,heads);
cout<<endl;
print(mergedHead);
return 0;
}