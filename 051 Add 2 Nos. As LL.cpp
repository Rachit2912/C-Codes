#include <cstddef>
#include<iostream>
#include "044 Linked List Basics.cpp"
using namespace std;

// ADD 2 NOS. REPRESENTED BY LL :
// Approaoch : reverse both linked lists then add then reverse the ans.

// long code :
/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        ListNode* temp = head;
        int carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        
        ListNode* a = l1;
        ListNode* b = l2;
        
        while(a != nullptr && b != nullptr) {
            int sum = a->val + b->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
            a = a->next;
            b = b->next;
        }
        
        while(a != nullptr) {
            int sum = a->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
            a = a->next;
        }
        
        while(b != nullptr) {
            int sum = b->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
            b = b->next;
        }
        
        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        
        return reverseList(head);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

*/

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
}
return prev;
}

// short code : all loops transformed into single loop 

Node* add_ll(Node* head1,Node* head2){

    // reverse ll:
    Node* first = reverse(head1);
    Node* second = reverse(head2);

    Node* ans_head = NULL;
    Node* ans_tail = NULL;
    int carry = 0;
    int digit = 0;
    int sum = 0;
    while (first != NULL || second != NULL || carry != 0) {
        
        int val1 = 0;
        if (first != NULL) {
        val1 = first->data;
        }

        int val2 = 0;
        if (second != NULL) {
        val2 = second->data;
        }
        
        sum = carry + val1 + val2 ;
        digit = sum % 10;
        carry = sum / 10;
        insert_at_tail(ans_tail, digit);

        if (first != NULL) {
        first = first->next;
        }

        if (second != NULL) {
        second = second->next;
        }
    }
    
    Node* final_ans = reverse(ans_head);
    
    return final_ans;
}



int main(){





return 0;
}