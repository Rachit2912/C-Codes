#include <climits>
#include <functional>
#include<iostream>
#include <queue>
#include <vector>
#include"074 Heap Basics.cpp"
#include "044 Linked List Basics.cpp"
using namespace std;

// SMALLEST RANGE IN K - SORTED LIST : 
/*
hmko k - sorted list di hui h, to hmko smallest range nikalni jimse har list ka atleast 1 element to aa hi jaye 


- approach 1 : brute force :
- sbse pehle saari range nikal lo with all p&c 
- sbka difference nikal lo & min. is the ans. & check also ki uss min. par sbhi list ka atleast 1 elmnt to aa rha ho 
- T.C : O(n^2.k^2)

- approach 2 : 
- k-list k liye k-pointers allot kr denge & unme se min & max nikal lenge and usse range bna lenge 
- ab range ko lessen krne ka 1 hi tarika h vo min. ko increase krdo bcz max. ko decrease kr nhi skte bcz list already sorted h and hmne sb list k first elements lye h 
- to min. wale pointer ko next pr laa do and firse sb me min and max nikal lo & agr range small h to update krlo
-  jb min. wala pointer list ko paar krde wha pr iss poore ko end krdo 
- T.C : O(n*k*k)  = O(n.k^2)  bcz n*k element k liye k-elements me se min. max. nikalna pdega 
- S.C : O(k)

- approach 3 : using heaps :  
- min heap bnake sb list k first element dal do 
- max ko bhi track kr rhe h saath me using var maxi
- ab bs range ko update krna h and maxi ko update krna h 
- to jb tk heap empty na hojaye : tb tk mini jo ki top element h or maxi se current range nikalo or usko ans. se compare krte rho and update krte rho 
- saath me maxi ko bhi update krna pdega in minheap, basically jo top pr tha uske age wale element ko push kr denge in minHeap 

*/

class nodeK{
    public:
    int data;
    int row;
    int col;
    nodeK(int d, int r, int c){
        this->data = d;
        this->row = r;
        this->col = c;
    }
};

class compare{
    public:
    bool operator()(nodeK* a, nodeK* b){
        return a->data > b->data ;
    }
};


int kSorted(vector<vector<int>> &a,int k, int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<nodeK*,vector<nodeK*>,compare> minHeap;

    // first elements ko daalo minHeap me :
    for (int i = 0; i<k; i++) {
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minHeap.push(new nodeK(element,i,0));

    }

    //processing of ranges :
    int start = mini; int end = maxi;
    while (!minHeap.empty()) {
        mini = minHeap.top()->data;
        nodeK* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;
        
        // range and answer updation :
        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // next element exists : 
        if (temp->col+1 < n) {
            maxi = max(maxi,a[temp->row][temp->col+1]);  
            minHeap.push(new nodeK(a[temp->row][temp->col +1], temp->row, temp->col +1));
        }

        else {
            break; // ending of a list 
        }

    }
    return (end-start+1);
}

// MEDIAN IN A STREAM : 
/*
- insertion sort : O(n^2)

- approach 2 :
- 2 part me baat do : maxHeap and minHeap jiski sizes me 3 case bn skte h
(i) n,n (ii) n,n-1 (iii) n-1,n
median : (i) avg of both the top elements (ii) top of maxheap (iii) top of minHeap 

- ab jb isme elements insert krna pdega to hm signum fn. ka use krenge jo size k basis pr 0,-1,1 value return krta h & usme jo case aayega uske basis pr hm median nikalenge 
- T.C : O(n.log(n)) bcz n elements ko insert kr rhe h heap me 

*/

int signum(int a, int b){
    if (a == b) {
        return 0;
    }

    else if (a > b) {
        return 1;
    }

    else {
        return -1;
    }
}

void callMedian(int element, priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini, int &median){

    switch (signum(maxi.size(),mini.size())) {

        case 0: 
        if (element > median) {
            mini.push(element);
            median = mini.top();
        }

        else{
            maxi.push(element);
            median = maxi.top();
        }
        break;

        case 1:
        if (element > median) {
            mini.push(element);
            median = (mini.top() + maxi.top())/2;
        }

        else {
        mini.push(maxi.top());
        maxi.pop();
        maxi.push(element);
        median = (mini.top() + maxi.top())/2;
        }
        break;

        case -1:
        if (element > median) {
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median = (mini.top() + maxi.top())/2;
        }

        else {
        maxi.push(element);
        median = (mini.top() + maxi.top()) /2 ;
        }
        break;
    }
}

vector<int> findMedian(vector<int> &arr,int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int median = 0 ;

    for (int i = 0; i<n; i++) {
        callMedian(arr[i],maxHeap,minHeap,median);
        ans.push_back(median);
    }
    return ans;
}