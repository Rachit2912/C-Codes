#include <cstddef>
#include<iostream>
#include <vector>
#include "044 Linked List Basics.cpp"
using namespace std;

//PALINDROME LL :
// AAPROACH 1 : make new array and copy LL's content into it and check for array's palindrome
// S.C : O(n) ; T.C : O(n)

bool arrPalindrome(vector<int> arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;

    while (s<=e) {
    if (arr[s] != arr[e]) {
    return 0;
    }
    s++; e--;
    }
return 1;

}

bool isPalindrome(Node* head){
    vector<int> arr;
    Node* temp = head;
    while (temp != NULL) {
    arr.push_back(temp->data);  
    temp = temp->next;
    }
    return arrPalindrome(arr);
}

// APPROACH 2 : find middle and compare reverse the sub-ll after the middle and compare both before middle part and after middle part
// S.C : O(1) ; T.C : O(n)

Node* getmid(Node* head){
    Node *slow=head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
    }
    return slow;
}

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


bool ll_palindrome(Node* head){

    // empty list:
    if (head->next == NULL) return true;

    // finding middle :
    Node* mid = getmid(head);
    
    // reverse sub-ll part after middle :
    Node* temp = mid->next;
    mid->next = reverse(temp);

    // comparing both half parts :
    Node* head1 = head;
    Node* head2 = mid->next;

    while(head2 != NULL){
        if (head1->data != head2->data) {
        return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // reverting the ll back to its original position :
    temp = mid->next;
    mid->next = reverse(temp);

    return 1;

}


int main(){

//  singly linked list :
Node* node1 = new Node(1);
Node* head = node1;
Node* tail = node1;
insert_at_tail(tail,2 );
insert_at_tail(tail, 3);
insert_at_tail(tail, 2);
insert_at_tail(tail, 1);
print(head); 
cout<<endl;
cout<<isPalindrome(head)<<endl;



return 0;
}