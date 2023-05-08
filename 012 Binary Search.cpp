//Binary Search
/* Notes:
-> linear Search me ek ek karke linearly search karte h 
-> jese ki array me ek ek karke element search karenge
-> time complexity: O(n) for linear search
-> it's appplicable on only monotonic functions
-> it's started from the middle member of the array
-> now, if a[middle]==key then return the index
-> else if a[middle]>key => left side of a[middle]
-> else right side of a[middle]
-> after getting the sub-array we'll aagain find the middle element 
of that sub-array by using formula: (start+end)/2
-> then return the index when it satisfies the condition
-> but there is a problem with the formula of m
-> suppose if s=2^31-1 and e=2^31-1 
-> then s+e will go out of range of integer
-> to avoid this we can rather use m=s+(e-s)/2
-> due to this, 'm' will always lie within the range of integer.
*/


//finding an element in an array with binary search
#include<iostream>
using namespace std;

int binarySearch(int a[], int n, int key){

    int s=0,e=n-1;
    int m=s+(e-s)/2 ;

    while(s<=e){

        if(a[m]==key){
            return m;
        }

        else if(a[m]>key){
            e=m-1;
        }

        else{s=m+1;}

        m=s+(e-s)/2 ;
    }
    return -1;
}

int main() {

int even[10]={0,2,4,6,8,10};
int odd[9]={1,3,5,7,9,11,13,15,17};

int r=binarySearch(even,10,8);
cout<<"index of element '8' in even array is: "<<r<<endl;

r=binarySearch(odd,9,16);
cout<<"index of element '16' in even array is: "<<r<<endl;

return 0;
}