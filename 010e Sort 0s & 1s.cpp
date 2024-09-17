//Sort 0s and 1s

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOne(int arr[], int n) {

    int i = 0, j = n-1;

    while(i<j) {

        while(arr[i] == 0  )  {
            i++;
        }

        while(arr[j]==1 ){
            j--;
        }

        //agar yha pohoch gye ho, iska matlab
        //arr[left]==1 and arr[right]==0
        if(i<j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

}

int main() {

    int arr[]={1,1,0,0,1,1,0,1,0,1,0,1,0,0,1,1,1,0,0,0};

    sortOne(arr,20);
    printArray(arr,20);


    return 0;
}