#include <iostream>
using namespace std;

//search in rotated sorted array

//finding pivot element in rotated sorted array
int indexPivot(int arr[], int n){

    int s=0;
    int e=n-1;
    int m=s+(e-s)/2;

    while(s<e){

        if(arr[m]>=arr[0]){
            s=m+1;
        }

        else{
            e=m;
        }

        m=s+(e-s)/2;
    }
    return m;
}


//binary search function 
int binarySearch(int a[], int start,int end, int key){

    int s=start,e=end;
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


int main(){

int arr[6]={7,9,11,1,2,3};
int k=11,n=6;
int p=indexPivot(arr,n);

if((k>=arr[p]) && (k<=arr[n-1])){
    cout<<binarySearch(arr,p,n-1,k)<<endl;
}

else{
    cout<<binarySearch(arr,0,p-1,k)<<endl;
}

return 0;
}