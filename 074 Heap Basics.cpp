/*
- heap : a complete binary tree (cbt) that comes with a heap order property 
- cbt : every level is completely filled except the last level 
- nodes always added from the left or lean towards the left (always the first child note in left) in cbt
- always follow left to right direction for filling the cbt and heap 


- heap order property : max heap or min heap 
- max heap : child note always less then root note 
- min heap : child note always greater then root note

- implementation : using array of size = height + 1
- filling will start from 1st index, 0th index will be vacant : known as 1 - indexing 
- if node is on i-th index :
then: left child : 2*i th index
right child : (2*i + 1) th index
parent : (i/2) th index
-> sometimes in questions, 0th indexing is also used then values will alter a little bit 
left child : 2*i + 1 
right child : 2*i + 2

- insertion in heap : 
S-1 : insert at end of array
S-2 : take it to its correct position
S-3 : compare with parent and swap if required
S-4 : repeat S-2 and S-3 until heap order property is satisfied

- deletion in heap : basically we are talking here about deleting root node
S-1 : swap first (root) node and last node (in array)
S-2 : delete last node (in array)
S-3 : take root node to its correct position
S-4 : compare with parent and swap if required
S-5 : repeat S-3 and S-4 until heap order property is satisfied

-> time complexity : O(log n) for insertion and deletion


-> heapify : 
- we are given a random array, which we have to transform it in heap 
- so, in cbt : (n/2 + 1)-th index to n-th index contains leaf nodes which heap in themselves as they are alone 
- so remaining, 1 to n/2-th index nodes are the main nodes which we have to consider and run heapify() fn. for them only 
- heapify() is nothing but a fn. which puts the remaining nodes to their correct places in order to make the full array to a heap
- heapify fn. for a node will put that node to the correct place in its whole left and right subtree
- it has T.C : O(log(n))
- iterating heapify fn. over remaining nodes except leaf nodes is known as build heap() which has time complexity of O(n)

HEAP SORT : 
first make a max heap out of the given array
so, given a max heap with a given size :
1) swap first (root) node and last node (of array)
2) now, first node which is the highest is at last position which is correct position for sorted array , so now size-- means  root node is deleted
3) first node ko correct position pr leke jao using heapify fn.
4) now repeat these steps until size > 1

- heap sort : 
1) build heap
2) heap sort
T.C : O(n.log(n))

-> STL used for heap : Priority queue

*/


#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    // constructor : 
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size++ ;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent],arr[index]);
                index = parent;
            }

            else {
                return;
            }
        }
    // T.C : O(log(n)) as it compares its parents iteratively
    }

    void deleteRoot(){
        if(size == 0){
            cout << " nothing to delete" <<endl;
            return;
        }

        arr[1] = arr[size];
        size-- ;

        int i = 1;
        while (i < size) {
            int leftIndex = 2*i ; 
            int rightIndex = 2*i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }

            else{
                return;
            }
        }
    }

    void printHeap(){
        for (int i = 1; i<=size; i++) {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

// heapify fn. : 
// T.C : O(log(n))
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if (largest != i) {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

// build min heap : 
// heapify fn. for min heap with a little bit changes only :
void heapifyMin(vector<int> &arr, int n, int i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i +1+ 1;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }

    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i],arr[smallest]);
        heapifyMin(arr,n,smallest);
    }
}

// driver code : 
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
     for(int i=(n/2)-1; i>=0; i--){
        heapifyMin(arr, n, i);
    }
    return arr;
}

// HEAP SORT : 
void heapSort(int arr[], int n){
    int size = n;
    while (size > 1) {
        // step 1 : swap
        swap(arr[size],arr[1]);
        // step 2 : 
        size-- ;

        // step 3 : first node ko correct position pr leke jao using heapify fn.
        heapify(arr, size, 1);

    }
}



int main(){
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.printHeap();
    h1.deleteRoot();
    h1.printHeap();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    // heapify all the remaining nodes except the leaf nodes : basically known as build the heap or heap creation 
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout<<"printing the array now : "<<endl;
    for (int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // heap sort : 
    heapSort(arr, n);
    
    cout<<"printing the sorted array now : "<<endl;
    for (int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //stl for heap :
    // max heap :
    priority_queue<int>pq;
    pq.push(50);
    pq.push(55);
    pq.push(53);
    pq.push(52);
    pq.push(54);
    cout<<pq.top();
    cout<<pq.size();
    cout<<pq.empty();
    pq.pop();

    // min heap : 
    priority_queue<int,vector<int>,greater<int>> pq2;
    pq2.push(50);
    pq2.push(55);
    pq2.push(53);
    pq2.push(52);
    pq2.push(54);

    cout<<pq2.top();
    cout<<pq2.size();
    cout<<pq2.empty();
    
return 0;
}