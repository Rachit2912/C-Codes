#include<iostream>
#include <stack>
using namespace std;

// stacks : 
/*
data structure 
follows LIFO 
push(), pop(), peek(), isEmpty(),
*/

// stack implementation via arrays : 
class stack_with_array{
    public:
    int top = -1; // tracks top elemenet
    int* arr;
    int size;

    // constructor : 
    stack_with_array(int size){
        this->size = size ;
        arr = new int[size];
    }

    void push(int element){
        if (size - top > 1) {
            top++ ;
            arr[top] = element ;
        }
        else{
            cout << "Stack Overflow"<<endl;
        }
    }

    void pop(){
        if (top >= 0) {
        top-- ;
        }

        else {
        cout << "Stack Underflow"<<endl;
        }
    }

    int peek(){
        if (top >= 0) {
        return arr[top];
        }

        else {
        cout << "Stack is Empty"<<endl;
        return -1;
        }
    }


    bool isEmpty(){
        if (top == -1) return true;
        else return false;
    }
};

//  2 STACKS USING 1 ARRAY : 
class TwoStack {
    
    int* arr;
    int top1,top2;
    int size;


public:

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size = s;
        arr = new int[s];
        this->top1 = -1;
        this->top2 = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top2 - top1 > 1){
            top1++ ;
            arr[top1] = num;
        }

    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
         if(top2 - top1 > 1){
            top2-- ;
            arr[top2] = num;
        }

    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1 >= 0){
            int ans = arr[top1];
            top1-- ;
            return ans;
        }

        else{return -1;}
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2 < size){
            int ans = arr[top2];
            top2++ ;
            return ans;
        }

        else{return -1;}
    }
};


int main(){

stack<int> s;
s.push(10); // push element to the top of the stack
s.push(20);
cout << "Size of the Stack: "<<s.size()<<endl;
s.pop();
cout<<s.empty()<<endl;
cout<<s.top()<<endl;

// our defined stack : 
stack_with_array st(5);
st.push(10) ;
st.push(-2535);
st.push(132);
st.push(23543);
st.push(-123);
st.push(123455);
cout<<st.peek()<<endl;
cout<<st.isEmpty()<<endl;
st.pop();
st.pop();
st.pop();
st.pop();
st.pop();
st.pop();
st.pop();
cout<<"isemtpy : "<<st.isEmpty()<<endl;




}