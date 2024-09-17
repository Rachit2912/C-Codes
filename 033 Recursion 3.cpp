#include <iostream>
using namespace std;

//  checking if an array is sorted using recursion
bool isSorted(int *arr, int n){

    // base case: if zero or only an element is present in the array then it's alreay sorted
    if (n == 0 || n == 1) {
    return true;
    }

    //checking first 2 elements if they are sorted or not 
    if (arr[0] > arr[1]) {
    return false;
    }

    // remaining part will be handled by recursion 
    else {
    return isSorted(arr+1 ,n-1);
    }
}


// getting sum of the elements of the array using recursion
int getSum(int *arr, int n) {
  // base cases : 
  // if zero elements are present in an array then sum 'll be zero 
  if (n == 0) return 0;

  //if it contains an element then sum is also the same element
  if (n == 1) return arr[0];

  // remaining part of the array will be done by the recursion
  int remainingPart = getSum(arr+1, n-1);
  return (arr[0] + remainingPart);
}


// linear search in an array using recursion
bool linearSearch(int *arr, int n, int key){

  // base case : we traversed the all array but we didn't find that key 
  if (n == 0) {
  return false;
  }

  // if the first element is our desired key 
  if (arr[0] == key) {
  return true;
  }

  // else we'll cut down the array and will move forward
  return linearSearch(arr+1, n - 1,key);
}


// Binary Search using recursion
bool binarySearch(int *arr,int s, int e, int k){

// finding mid 
int mid = s + (e-s)/2;

  // base case :
  // array ko crossover ho gye but 'k' nhi mila 
  if (s>e) {
  return false;
  }

  //ya mil gya 'k' hame 
  if (arr[mid] == k) {
  return true;
  }

  // proccesing condition
  if (arr[mid] > k) {
  return binarySearch(arr,s, mid-1,k);
  }

  else {
  return binarySearch(arr, mid+1 ,e, k );
  }
}


int main() {

int arr[6] = {1,2,3,4,8,6};


//  checking if an array is sorted using recursion
isSorted(arr, 6) ? (cout<<"array is sorted " <<endl) : (cout<< "array isn't sorted " <<endl) ; 


// getting sum of the elements of the array using recursion
cout<< "the sum of the elements is : " << getSum(arr,6) <<endl;


// linear search in an array using recursion
cout<< "Linear search" << endl;
linearSearch(arr,6,12) ? (cout <<"element found" << endl) : (cout<<"not found"<<endl) ;


// Binary Search using recursion
cout<< "Binary search" << endl;
binarySearch(arr,0,6,12) ? (cout <<"element found" << endl) : (cout<<"not found"<<endl) ;


  return 0;
}