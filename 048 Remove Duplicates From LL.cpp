#include <cstddef>
#include<iostream>
#include <unordered_map>
#include <vector>
#include "044 Linked List Basics.cpp"
using namespace std;

//REMOVE DUPLICATES FROM A SORTED ll :
// 'curr' ko start kro direct head se and go until end and if next element  is same as curr, then link the curr to next node and delete the duplicate node
Node* rm_dplicate_sort(Node* head){
    
    // empty list:
    if (head == NULL) return NULL;

    Node* curr = head;
    while (curr->next != nullptr) {
    if (curr->data == curr->next->data) {

        Node* nextNext = curr->next;
        curr->next = curr->next->next;
        delete nextNext;
    }

    else{
        curr = curr->next;
    }

    }

    return head;
}

//REMOVE DUPLICATES FROM A UNSORTED ll :
/*
Approach 1 : using nested for loops :
1-1 'curr' node ko lenge and uski jo remaining sub-ll hogi usme check krlenge, agr vo element hoga to delete kr denge
T.C : O(n^2)  ; S.C : O(1)

Approach 2 : pehle sort krdo, fir rm_dplicate_sort use krlo
T.C : O(nlogn)  ; S.C : O(1)

Approach 3 : 1 visited ka map bnado, and har element pr check krlo if visited : fine; else : delete that node
T.C : O(n)  ; S.C : O(n)
*/

Node* rm_dp_unsort_app1(Node* head){
    if(head == NULL) return NULL;

    Node* curr = head;

    while(curr != NULL)
    {
        Node* temp = curr;
        while(temp->next != NULL)
        {
            if(curr->data == temp->next->data)
            {
                Node* next_next = temp->next->next;
                delete (temp->next);
                temp->next = next_next;
            }

            else
            {
                temp = temp->next;
            }
        }

        curr = curr->next;
    }

    return head;
}


Node* rm_dp_unsort_app3(Node* head){

    if (head == NULL) return NULL;

    unordered_map<int, bool> visit;
    Node* prev = head;
    Node* curr = head->next;
    visit[head->data] = true;
    while (curr != NULL) {
        if (visit[curr->data] == true) {
            prev->next = curr->next;
            delete curr;
        }

        else {
            visit[curr->data] = true;
            prev = prev->next;
        }

        curr = prev->next;
    }

    return head;
}

// DIVIDE THE CIRCULAR LL INTO 2 HALVES OF 2 CLL : 
/*
make 2 pointers and stop at the middle and then split it into 2 parts 
*/
vector<cNode*> splitCircularList(cNode *head)
{
    if(head == NULL) return vector<cNode*>(0);

    cNode* slow = head;
    cNode* fast = head;
    vector<cNode*> ans;
    bool f=1;
    while(f==1){
        cout<<"slow"<<slow->data<<endl;
        cout<<"fast"<<fast->data<<endl;
        slow = slow->next;
        fast = fast->next->next;
        if(fast->next == head) f=0;
    }
cout<<"endslow"<<slow->data<<endl;
        cout<<"endfast"<<fast->data<<endl;
    // cout<<"slow1"<<fast->next->data<<endl;
    fast->next = slow->next;
    ans.push_back(head);
    ans.push_back(slow->next);
    // cout<<"slow"<<fast->next->data<<endl;
    slow->next = head;
    // cout<<"fast"<<head->data<<endl;
    return ans;
}


int main(){

// sorted singly linked list :
Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;
insert_at_tail(tail, 20);
insert_at_tail(tail, 20);
insert_at_tail(tail, 30);
insert_at_tail(tail, 30);
insert_at_tail(tail, 60);
insert_at_tail(tail, 60);
insert_at_tail(tail, 70);
insert_at_tail(tail, 70);
insert_at_tail(tail, 70);
insert_at_tail(tail, 70);
insert_at_tail(tail, 70);
insert_at_tail(tail, 70);
insert_at_tail(tail, 70);
insert_at_tail(tail, 80);
print(head); 
rm_dplicate_sort(head);
print(head);



// unsorted singly linked list :
Node* node2 = new Node(10);
Node* head2 = node2;
Node* tail2 = node2;
insert_at_tail(tail2, 20);
insert_at_tail(tail2, 20);
insert_at_tail(tail2, 10);
insert_at_tail(tail2, 10);
insert_at_tail(tail2, 7);
insert_at_tail(tail2, 7);
insert_at_tail(tail2, 7);
insert_at_tail(tail2, 7);
insert_at_tail(tail2, 7);
insert_at_tail(tail2, 7);
insert_at_tail(tail2, 7);
print(head2); 
// rm_dp_unsort_app1(head2);
rm_dp_unsort_app3(head2);
print(head2);


//circular linked list
cNode* ctail = NULL;
cout<<endl;
insert_at_cll(ctail, 0, -78);
insert_at_cll(ctail, -78, 123);
insert_at_cll(ctail, -78, 1024);
insert_at_cll(ctail, 123,456);
insert_at_cll(ctail, -78, -45);
print(ctail);
vector<cNode*> a = splitCircularList(ctail);

for (auto i : a) {
    cout<<i->data<<endl;
}



return 0;
}