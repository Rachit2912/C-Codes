#include <algorithm>
#include <cstddef>
#include <functional>
#include<iostream>
#include <queue>
#include <vector>
#include"074 Heap Basics.cpp"
#include "044 Linked List Basics.cpp"
using namespace std;

// K-TH LARGEST SUM SUBARRAY : 
/*
for a given array, uske sbhi subarrays honge or unn sbka sum bhi hoga, usme k-th largest sum nikalna h 

-> approach #1 :
- 2 loops chalayenge, useme outer loop ek ek krke elements ko choose krega & inner loop baaki bachi hui subarray bnata rhega 
- or inke sum ko vector me store krdo & k-th largest nikal lo usme se  
- T.C : O(n^2.log(n)) bcz n^2 jitne subarrays bnenge & unko sort krne liye n^2.log(n)
-S.C : O(n^2)

-> approach #2 (using min. heap) :
-  this approach almost same hi h bss in inner loop hm 1 min. heap bna denge jo top k-th sums ko rkhega and usko hm update krte rhenge hr baar taaki hme end me k-th largest sum mil jaye 
- T.C : O(n^2.log(k))
- S.C : O(k) : optimized 
*/


int getKthLargestApp1(vector<int> &arr, int k){
    vector<int> sumStore;
    int n = arr.size();

    // preparing the subarrays :
    for (int i = 0; i<n; i++) {
        int sum = 0;
        for (int j = i; j<n; j++) {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    // sorting the sumStore:
    sort(sumStore.begin(),sumStore.end());

    // returning the k-th largest :
    return sumStore[sumStore.size()-k];

}

int getKthLargestApp2(vector<int> &arr, int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    int n = arr.size();

    // preparing the subarrays :
    for (int i = 0; i<n; i++) {
        int sum = 0;
        for (int j = i; j<n; j++) {
            sum += arr[j];
            if (pq.size() < k) {
                pq.push(sum);
            }

            else {
                if (sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    // returning the k-th largest :
    return pq.top();

}


// MERGE K - SORTED ARRAYS :
/*
approach #1: 
- create ans array 
- insert all elements (n*k elements) into an array 
- sort the array 
- T.C : O((n*k).log(n*k))

approach #2 : 
- 1 min heap bnao or usme sbhi arrays k first elements ko compare krke unka min. wala pop krdo jo ki top pr hoga usko ans. vector me daal do or fir usi same array k next element ko heap me daal ke compare krte rho or ese hi chlte rho jb tk ki heap ki size > 1 h tb tk 
- ab yha hm priority queue k type k lye hme hmara d.s. bnana pdega jisme ki rows me diff. arrays h & colmns me unhi arrays k elements h 
- T.C : (n*k).log(k)
- S.C : O(n*k)
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

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays,int k){
    priority_queue<nodeK*,vector<nodeK*>,compare> minHeap;

    // saare arrays k first elements insert krne h in minHeap : 
    for (int i = 0; i<k; i++) {
        nodeK* temp = new nodeK(arrays[i][0],i,0);
        minHeap.push(temp);
    }

    // now, jbtk heap ki size > 1 h : tbtk top element ko pop krke ans me daal lo & usi array ka next element ko heap me daal do 
    vector<int> ans;
    while (minHeap.size() > 1) {
        nodeK* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        // usi array ke next element ko daal do:
        int r = temp->row;
        int c = temp->col;
        //checking all the conditions : 
        if (c+1 < arrays.size()) {
            nodeK* next = new nodeK(arrays[r][c+1],r,c+1);
            minHeap.push(next);
        }
    }
    return ans;
}

// MERGE K - SORTED LL : 
/*
- approach 1: 
- make new vector ans
- sort it 
- join all ll 
- replace ll nodes data with ans data

approach 2 :
- make a min heap of first element of ll
- make a ans ll with head and tail 
- insert the min. of all the ll which is minheap.top to ans ll 
- and repeat like it
- T.C : (n*k).log(k)
- S.C : O(k)
*/


Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    int k = listArray.size();
    // first element in minHeap:
    for (int i =0; i<k; i++) {
        if (listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    //making ans ll : 
    Node* head = NULL; Node* tail = NULL;

    // insertion in ans ll  : 
    while (minHeap.size() > 0) {
        Node* top = minHeap.top();
        minHeap.pop();

        // empty ans ll :
        if (head == NULL) {
            head = top;
            tail = top;
        }

        // insert at ll : 
        else {
            tail->next = top;
            tail = top;
        }

        // checking if next element is there or not :
        if (top->next != NULL) {
            minHeap.push(top->next);
        }
    }
    return head;
}