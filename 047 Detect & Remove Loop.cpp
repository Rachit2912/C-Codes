#include <cstddef>
#include <iostream>
#include <map>
#include "044 Linked List Basics.cpp"
using namespace std;

// detect cycle in LL / Remove cycle from LL / return starting node of loop in LL :

// code approach #1: detect cycle using hash maps: 
// T.C : O(n) ; S.C : O(n)
// for circular ll :
bool detectloop_1(cNode* head){
    
    if (head == NULL) {
        return false;
    }

    map<cNode*, bool> visited;
    cNode* temp = head;

    while (temp != NULL) {

        if (visited[temp] == true) {
        cout<<"Loop present on element"<< temp->data<<endl;
        return 1; // we reached at the visited node 
        }

    visited[temp] = true; // mark the current node as visited
    temp = temp->next;
    }

    return 0; // ll is not circular bcz we got null at the end
}

// for singly ll :
bool detectloop_1(Node* head){
    
    if (head == NULL) {
        return false;
    }

    map<Node*, bool> visited;
    Node* temp = head;

    while (temp != NULL) {

        if (visited[temp] == true) {
        return 1; // we reached at the visited node 
        }

    visited[temp] = true; // mark the current node as visited
    temp = temp->next;
    }

    return 0; // ll is not circular bcz we got null at the end
}

// code approach #2: Floyd's cycle detection algo :
/*
make 2 pointers slow and fast started at head, slow will move 1 step and fast will move 2 steps and if they'll meet it means loop is definitely present there.
*/
// T.C : O(n) ; S.C : O(1)
bool floydDetection(cNode* head){

    if(head == NULL || head->next == NULL){
        return 0;
    }

    cNode* slow = head;
    cNode* fast = head;

    while (slow != NULL && fast != NULL) {
        slow = slow->next;

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        if (slow == fast) {
        cout<<"loop present at "<< slow->data<<endl;
        return 1;
        }
    }

    return 0;
}

// code approach #3: getting the Floyd's pointer :
// now to get at which  point loop starts, we will first use the above function to get the point of intersection and then again we'll start "slow" pointer from head and "fast" pointer from the same position at where they both meet in the floydDetectionAlgo & from there we'll move 1 step both the pointers and the point of interesection will be the starting point of loop.

cNode* floydPointer(cNode* head){
    cNode* slow = head;
    cNode* fast = head;
    cNode* pointOfIntersection = NULL;

    while (slow != NULL && fast != NULL) {
        slow = slow->next;

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }

        if (slow == fast) {
        cout<<"loop present at "<< slow->data<<endl;
        pointOfIntersection = slow;
        break;
        }
    }

    slow = head;
    while (slow != pointOfIntersection) {
        slow = slow->next;
        pointOfIntersection = pointOfIntersection->next;
    }

    return slow;
}

// code approach #4: remove the loop if it's present : 
void removeLoop(cNode* &head){

    if (head == NULL) {
    return;
    }

    cNode* startofLoop = floydPointer(head);
    cNode* temp = startofLoop;

    while (temp->next != startofLoop) {
    temp = temp->next;
    }
    temp->next = NULL;
    cout<<"Yeahhh !!! loop removed successfully "<<endl;
}


int main(){

// singly linked list :
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
cout<<endl<<detectloop_1(head)<<endl;

//circular linked list
cNode* ctail = NULL;
cout<<endl;
insert_at_cll(ctail, 0, -78);
insert_at_cll(ctail, -78, 123);
insert_at_cll(ctail, -78, 1024);
insert_at_cll(ctail, 123,456);
insert_at_cll(ctail, -78, -45);
print(ctail);

cout<<detectloop_1(ctail)<<endl;
cout<<floydDetection(ctail)<<endl;
cNode* fp = floydPointer(ctail);
cout<<fp->data<<endl;
removeLoop(ctail);
cout<<detectloop_1(ctail)<<endl;
cout<<floydDetection(ctail)<<endl;


return 0;
}