#include <cstddef>
#include <iostream>
using namespace std;

/* linked list : 
linear data structure made up of collectiono of nodes 
node me kuch data hota h and next node ka address hota h 
array ki size ko runtime me nhi change kr skte and vector bhi full hone pr size double krta h and usme firse content copy krta h isliye vo bhi optimal nhi h 
isliye linked list aayi 
iska 1st pointer head pointer hota h 
yeh 1 dynamic d.s. h which can grow or shrink @ runtime
& no shifting needed for  insertion or deletion operation 
types : 1) singly ll  2) doubly ll 3) circular ll 4) circular doubly ll
*/

// singly linked list 
class Node{
    public:
    int data;
    Node* next;  

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if (this->next != NULL) {
        this->next = NULL;
        }
        cout<< " memory is free " << endl;
    }

};

/*
insertion at the head:
make new node
point ref of new node to existing head
update head
*/

void insert_at_head(Node* &head, int data) { 
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

/*
insertion at the tail :
make new node
point ref of new node to existing tail
update tail
*/

void insert_at_tail(Node* &tail, int data){
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
}

/*
insert at any position : 
traverse till node at previous position 
connect new node to next node 
connect previous node to new node
*/

void insert_at_position(Node* &head, Node* &tail, int position, int data){
    
    //starting position case
    if (position == 1) {
    insert_at_head(head, data);
    return;
    }
    
    // middle positions cases
    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1) {
    temp = temp->next;
    cnt++;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    // last position case 
    if (temp->next == NULL) {
        insert_at_tail(tail, data);
        return;
    }
}

// deletion at any position :

void delete_at_position(Node* &head,int position){

    // first position case : 
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    else {
    // all other cases : 
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while (cnt < position) {
    prev = curr;
    curr = curr -> next;
    cnt++;
    }

    prev -> next = curr -> next ;
    curr -> next = NULL;
    delete curr;
    }

}

void print(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout<<endl;
}

// doubly linked list 
class DLinkedList{
    public:
    int data;
    DLinkedList* prev;
    DLinkedList* next;

    //constructor :
    DLinkedList(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }

    ~DLinkedList(){
        int val = this->data;
        if (next != NULL) {
        delete next;
        next = NULL;
        }
        cout<<"memory free for node with data "<<val<< endl;
    }
};

// traversing doubly ll
void print(DLinkedList* head){
    DLinkedList* temp = head;
    
    while (temp != NULL) {
    cout<<temp->data<<",";
    temp = temp->next;
    }
    cout<<endl;
}

// length of doubly ll
int getlength(DLinkedList* head){
    int len = 0;
    DLinkedList* temp = head;

    while (temp != NULL) {
    len++ ;
    temp = temp->next;
    }
    return len ;
}

/*
insertion at head doubly ll 
create new node
connect new node to head & then vice versa
update head
*/ 
void insert_at_dhead(DLinkedList* &head,int d){

    //empty list
    if (head == NULL) {
    head = new DLinkedList(d);
    }

    else {
    DLinkedList* temp = new DLinkedList(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}

/*
insertion at tail doubly ll
create new node
create tail to new node and then vice versa
update tail

*/
void insert_at_dtail(DLinkedList* &tail,int d){
    
    // empty list
    if (tail == NULL) {
    tail = new DLinkedList(d);
    }


    else {
    DLinkedList *temp = new DLinkedList(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}

/*
insertion at any position doubly ll
create new node
connect new node to next node and update previous of next node from temp to new node
update next of temp from next node to new node
*/
void insert_at_dposition(DLinkedList* &head,DLinkedList* &tail, int position, int d){
    
    //starting position case
    if (position == 1) {
    insert_at_dhead(head, d);
    return;
    }

    // middle positions cases
    DLinkedList* temp = head;
    int cnt = 1;
    while (cnt < position-1) {
    temp = temp->next;
    cnt++;
    }

    DLinkedList* nodeToInsert = new DLinkedList(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

    // last position case 
    if (temp->next == NULL) {
        insert_at_dtail(tail, d);
        return;
    }

}

// deletion at any position doubly ll :

void delete_at_dposition(DLinkedList* &head,int position){

    // first position case : 
    if (position == 1) {
        DLinkedList* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    else {
    // all other cases : 
    DLinkedList* curr = head;
    DLinkedList* prev = NULL;
    int cnt = 1;
    while (cnt < position) {
    prev = curr;
    curr = curr -> next;
    cnt++;
    }

    curr-> prev = NULL;
    prev -> next = curr -> next ;
    curr -> next = NULL;
    delete curr;
    }   

}


// circular linked list 
class cNode{
    public:
    int data; 
    cNode* next;

    // constructor
    cNode(int d){
        data=d;
        next=NULL;
    }

    //destructor
    ~cNode(){
        int value = data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

// insertion at head in cll 
void insert_at_cll(cNode* &tail, int element, int d){

    // empty list
    if (tail == NULL) {
    cNode* newNode = new cNode(d);
    tail = newNode;
    newNode ->next = newNode;
    return;
    }

    else {
    // non empty list 
    // assuming that the element is present in the list
    cNode *curr = tail ;

    while (curr->data != element) {
    curr = curr->next;
    }

    cNode* temp = new cNode(d);
    temp ->next = curr->next;
    curr->next = temp;
    }
}

//printing cll
void print(cNode* &ctail){
    cNode* temp = ctail;

    //empty list
    if(ctail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << ctail -> data << " ";
        ctail = ctail -> next;
    } while(ctail != temp);

    cout << endl;
}


// deletion in cll 
void deletion_cll(cNode* &ctail, int d){

    // empty list
    if(ctail == NULL) {
        cout << "The List is already Empty list"<<endl;
        return;
    }
    else {
    //non empty list
    //assuming 'd' value is present in the list 
    cNode* prev = ctail;
    cNode* curr = prev->next;

    while (curr->data != d ) {
    prev = curr;
    curr = curr->next;
    } 

    prev->next = curr->next;
    
     //1 Node Linked List
        if(curr == prev) {
            ctail = NULL;
        }

        //>=2 Node linked list
        else if(ctail == curr ) {
            ctail = prev;
        }

    curr->next = NULL;
    delete curr;

    }
}



/*int main(){

// singly linked list
Node* node1 = new Node(10);
// cout << node1->data << endl;
// cout << node1->next << endl; 

Node* head = node1;
Node* tail = node1;

insert_at_head(head, 20);
insert_at_head(head, 15);
insert_at_tail(tail, 555);
insert_at_position(head,tail, 3, 123456);
print(head);
delete_at_position(head, 2);
print(head);

cout<<endl;
cout<< "head : " << head->data << endl;
cout<< "tail : " << tail->data << endl;

//doubly linked list
DLinkedList* dnode1 = new  DLinkedList(10);
DLinkedList* dhead = dnode1;
DLinkedList* dtail = dnode1;
print(dhead);
cout<<getlength(dhead)<<endl;

insert_at_dhead(dhead,11);
insert_at_dhead(dhead,233);
print(dhead);
insert_at_dtail(dtail,32532);
insert_at_dtail(dtail,300);
print(dhead);
insert_at_dposition(dhead, dtail, 1, 100);
insert_at_dposition(dhead, dtail, 3, -789);
print(dhead);
delete_at_dposition(dhead, 1);
print(dhead);
delete_at_dposition(dhead, 3);
print(dhead);


//circular linked list
cNode* ctail = NULL;
cout<<endl;
print(ctail);
insert_at_cll(ctail, NULL, -78);
print(ctail);
insert_at_cll(ctail, -78, 123);
print(ctail);
insert_at_cll(ctail, -78, 1024);
print(ctail);
insert_at_cll(ctail, 123,456);
print(ctail);
insert_at_cll(ctail, -78, -45);
print(ctail);
deletion_cll(ctail, -45);
print(ctail);
deletion_cll(ctail, -78);
print(ctail);




return 0;
}*/