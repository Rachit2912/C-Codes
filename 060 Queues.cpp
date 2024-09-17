#include <deque>
#include<iostream>
#include <queue>
using namespace std;

// queue implementation using array : 
class Queue {
    int arr[100000];
    int qfront;
    int rear;

public:
Queue() {
    qfront =0;
    rear=0;
}

bool isEmpty() {
    if(qfront==rear){
        return true;
    }

    else{
        return false;
    }
}

void enqueue(int data) {
    if(rear==100000){
        return;
    }

    else{
        arr[rear++]=data;
    }
}

int dequeue() {
    if(isEmpty()){
        return -1;
    }

    else{
        int ans=arr[qfront];
        arr[qfront++]=-1;
        if(isEmpty()){
            qfront=0;
            rear=0;
        }

        return ans;
    }
}

int front() {
    if(isEmpty()){
        return -1;
    }

    else{
        return arr[qfront];
    }
}
};
// all operations like enqueue, dequeue and isEmpty() all have T.C : O(1) and S.C : O(1)


// circular queue implementation using array :
class CircularQueue{
    int* arr;
    int front;
    int rear;
    int size;
public:
CircularQueue(int n){

    size=n;

    arr=new int[size];

    front=rear=-1;

}

// Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.

bool enqueue(int value){
    if( (front==0 && rear==size-1) || (rear==(front-1)%(size-1) ) ){
        return false;
    }

    else if(front==-1){
        front=rear=0;
    }

    else if(rear==(size-1) && front!=0){
        rear=0;
    }

    else{
        rear++;
    }

    arr[rear]=value;
    return true;
}

// Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.

int dequeue(){
    if(front==-1){
        return -1;
    }

    int ans=arr[front];
    arr[front]=-1;

    if(front==rear){
        front=-1;
    }

    else if(front==size-1){
        front=0;
    }

    else{
        front++;
    }

    return ans;
}
};


// input restricted queue : push_back, pop_front & pop_back
//output restriced queue : push_front, push_back & pop_front

/* 
DOUBLY ENDED QUEUE :
- all 4 operations available
- push_back, push_front, pop_back & pop_front
- we can implement both stack and queue using doubly ended queue

--> push_front :
if queue full check
first element insert : front = rear = 0
cyclic nature maintain : front == 0 then front = n-1
else normal case :front-- and then insert 

--> push_back :
normal circular queue push case 

--> pop_front :
normal circular queue pop case 

--> pop_back :
if queue empty check
single element pop :front = rear = -1
cyclic nature maintain : rear == 0 then  rear = n-1
normal all cases : rear-- 

*/
//deque implementation using array :
class Deque{
public:
    int *arr;
    int rear, front, size;

Deque(int n){
    arr = new int[n];
    rear = front = -1;
    size = n;
}

~Deque() {
    delete[] arr;
}

// Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
bool pushFront(int x){
    // Case 1: If the queue is full
    if(isFull()){
        return false;
    }

    // Case 2: If it is the first element to push
    if(isEmpty()){
        front = 0;
        rear = 0;
    }

    // Case 3: If front is at 0
    else if(front == 0){
        front = size - 1;
    }

    // Case 4: normal case 
    else{
        front--;
    }

    // push the element at front
    arr[front] = x;
    return true;
}

// Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
bool pushRear(int x){
    // Case 1: If the queue is full
    if(isFull()){
        return false;
    }

    // Case 2: If it is first element to push
    if(isEmpty()){
        front = rear = 0;
    }

    // Case 3: If rear is at size - 1
    else if(rear == size - 1){
        rear = 0;
    }

    // Case 4: simple case
    else{
        rear++;
    }

    // push the element at rear
    arr[rear] = x;
    return true;
}

// Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
int popFront(){
    // Case 1: If the queue is empty
    if(isEmpty()){
        return -1;
    }
    int f = arr[front];
    // Case 2: If only one element is in the queue
    if(front == rear){
        front = rear = -1;
    }
    // Case 3: If front is equal to size - 1
    else if(front == size - 1){
        front = 0;
    }

    // Case 4: simple case
    else{
        front++;
    }

    return f;
}

// Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
int popRear(){
    // Case 1: If the queue is empty
    if(isEmpty()){
        return -1;
    }
    int r = arr[rear];
    // Case 2: If only one element is there
    if(front == rear){
        front = rear = -1;
    }

    // Case 3: If rear = 0
    else if(rear == 0){
        rear = size - 1;
    }

    // Case 4: Simple case
    else{
        rear--;
    }
    return r;
}

// Returns the first element of the deque. If the deque is empty, it returns -1.
int getFront(){
    // if queue is empty
    return isEmpty() ? -1 : arr[front];
}

// Returns the last element of the deque. If the deque is empty, it returns -1.
int getRear(){
    return isEmpty() ? -1 : arr[rear];
}

// Returns true if the deque is empty. Otherwise returns false.
bool isEmpty(){
    return front == -1;
}

// Returns true if the deque is full. Otherwise returns false.
bool isFull(){
return ((front == 0 && rear == size - 1) || (front == (rear + 1) % size));
}
};

int main(){

// queue implementation using STL :
queue<int> q;
q.push(11);
cout<<"front"<<q.front()<<endl;
q.push(15);
cout<<"front"<<q.front()<<endl;
q.push(17);
cout<< "size of queue is : " << q.size()<<endl;
q.pop();
cout<< "size of queue is : " << q.size()<<endl;

if (q.empty()) {cout<<"q is empty "<<endl;
}
else {
cout<<"q is not empty "<<endl;
}


// doubly ended queue implementation using STL:
deque<int> d;
d.push_front(12);
d.push_back(21);
cout<<d.front()<<endl;
cout<<d.back()<<endl;
d.pop_back();
cout<<d.front()<<endl;
cout<<d.back()<<endl;
d.pop_front();
cout<<d.front()<<endl;
cout<<d.back()<<endl;

if(d.empty())  cout<<"Deque is Empty"<<endl;

return 0;
}