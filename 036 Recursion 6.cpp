#include <iostream>
using namespace std;

int partition(int *arr, int s, int e){

    // pivot element 
    int pivot = arr[s];

    // counting the elements which are lesser than pivot element
    int cnt = 0;
    for (int i = s+1; i <= e ; i++) {
    if (arr[i] < pivot) {
    cnt++ ;
    }
    }

    // shifting the pivot element to it's correct position
    int pivotIndex = s + cnt;
    swap(arr[s],arr[pivotIndex]);

    // now organizing the left and right subarrays such that left side contains smaller ones and right one contains bigger ones by 2 pointer method
    int i=s , j=e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) {
        i++ ;
        }

        while (arr[j] > pivot) {
        j-- ;
        }

        if (i < pivotIndex && j > pivotIndex) {
        swap(arr[i++],arr[j--]);
        }
        
    }

    return pivotIndex;
}


void quickSort(int *arr, int s, int e){

    // base case for recursion : 
    if (s >= e) {
    return;
    }
    
    // partition fn. call
    int p = partition(arr, s, e);

    // recursive call for left subarray 
    quickSort(arr, s, p - 1);

    // recursive call for right subarray 
    quickSort(arr, p+1, e);


}

int main() {

// Quick Sort 
/*
1 element ko pick karenge or usko aise place karenge ki uske 1 side saare usse chote elements honge or 1 side saare bade or isiko partition kehte hain or pick kare hue element ko pivot element kehte hain  
partition ke liye ek fn. banayenge jo ki hume jis index pe place kiya h vo index return karega 
ab quicksort ka fn. banega jisme foremost partition fn. ko call karenge 
ab dono or 2 subarrays hain unko bhi aise hi place karna hain toh uske liye hum recursion ka use karenge 
recursion se hum phir same cheez in 2 subarrays ke liye implement kar denge 
recursion ke liye hum phir same quicksort wale fn. ko call kar denge 2 subarrays ke liye 

Partition kese karenge :
Well, jis element ko pivot karne hain uske chote elements ko count kar lenge or usko usi index wale element ke saath swap kara denge 
generally, pivot elements ya toh first element ya last element ko lete hain
ab uske normally 2 pointer method se saare chote 1 taraf or bade 1 taraf 

T.C. and S.C. : 
Best Case: Ω (N log (N))
The best-case scenario for quicksort occur when the pivot chosen at the each step divides the array into roughly equal halves.
In this case, the algorithm will make balanced partitions, leading to efficient Sorting.
Average Case: θ ( N log (N))
Quicksort’s average-case performance is usually very good in practice, making it one of the fastest sorting Algorithm.
Worst Case: O(N2)
The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly unbalanced partitions. When the array is already sorted and the pivot is always chosen as the smallest or largest element. To mitigate the worst-case Scenario, various techniques are used such as choosing a good pivot (e.g., median of three) and using Randomized algorithm (Randomized Quicksort ) to shuffle the element before sorting.
Auxiliary Space: O(1), if we don’t consider the recursive stack space. If we consider the recursive stack space then, in the worst case quicksort could make O(N).
*/



int arr[] = {0,4,6,8,7,1,2,3,9,5};

cout<<endl << " Given array is : " ;
for (int i=0; i<10; i++) {
cout<< arr[i] << " ";
}

quickSort(arr, 0, 9);

cout<<endl<< " Sorted array is : " ;
for (int i=0; i<10; i++) {
cout<< arr[i] << " ";
}
cout << endl;


return 0;
}