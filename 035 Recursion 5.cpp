#include <iostream>
using namespace std;

//defining no. of inversions as global because i don't want to write anew routine for printing no. of inversions but i do know very well it's a severe bad practice 
int n_O_i = 0;

void merge(int *arr, int s, int e){

    //using copy - paste method into a new array 

    int mid = s + (e-s)/2 ;

    // number of inversions
    

    int l1 = mid-s+1;   // length of the left subarray
    int l2 = e-mid;     // length of the right subarray 

    //making two subarrays of their respective length
    int* left = new int[l1];
    int* right = new int[l2];
    
    // copying left part of array  into left subarray 
    int k = s;
    for (int i=0; i<l1; i++) {
        left[i] = arr[k++] ; 
    }

    // copying right part of array into right subarray 
    k = mid+1;
    for (int i=0; i<l2; i++) {
    right[i] = arr[k++] ; 
    }

    // merging left and right sorted subarrays 
    // applying logic from merge 2 sorted arrays 
    int i1 = 0, i2 = 0;k = s;

    while (i1 < l1 && i2 < l2) {
        if (left[i1] < right[i2]) {
        arr[k++] = left[i1++];
        }

        else {
        arr[k++] = right[i2++];
        n_O_i += l1-i1 ;
        }
    }

    while (i1 < l1) {
    arr[k++] = left[i1++];
    }

    while (i2 < l2) {
    arr[k++] = right[i2++];
    }

    //freeing up the memory bcoz it's mandatory 
    delete [] left;
    delete [] right;

}


void mergeSort(int *arr, int s, int e){

    int mid = s + (e-s)/2 ;
    int inv = 0;

    // base case :
    if (s >= e) {
    return;
    }

    // sorting the left part 
   mergeSort(arr, s, mid);

    // sorting the right part
    mergeSort(arr, mid+1, e);

    // merging both the parts 
    merge(arr,s,e);
    
}


int main(){

//Merge Sort
/*
pehle array ko 2 parts me divide kar denge
uske baad aise hie same tute hue parts ko bhi tod denge 
or tab tak todenge jab tak ek-ek part me single element na ho  
phir unko 2-2 ke pair me baandhke or sort karke merge karte jaayenge 
or aise hi merge karte jayenge 
Steps:
1. divide the array into 2 parts 
2. sort both of them by using recursion 
3. merge this 2 sorted arrays into a single array 
and now, to divide the array we have 2 methods :
(a) using copy - paste values into a new array 
(b) using indexes for everything 

All Case SC : O(n)
All Cases TC : O(nlogn)


Or isme jab inversions count karne honge tab bhi hum jab last me merge karne jayenge tab wahi compare kar lenge 
or agar usme 1 element ke sath inversion h uska matlab uske baad ke saare elements ke saath inversion h as both the arrays are sorted 
*/

int arr[10] = {0,1,8,7,5,4,3,9,2,6};
// int arr[3] = {3,2,1};
cout<< "Original array is : ";
for (int i=0; i<10; i++) {
cout<< arr[i] << " ";
}
cout<<endl;

mergeSort(arr,0,9);

cout<< "Sorted array is : ";
for (int i=0; i<10; i++) {
cout<< arr[i] << " ";
}
cout<<endl;

//printing the no. of inversion 
cout<< "no. of inversions : " << n_O_i <<endl;


return 0;
}