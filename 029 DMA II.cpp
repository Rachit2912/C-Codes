#include<iostream>
using namespace std;

int main() {
int r,c;
cout <<"enter r and c: " << endl;
cin >>r>>c ;  //input the value of row and column respectively.


// 2d arrays implementation by DMA
//making a 1d type of array as an object 
int** arr = new int*[r];
for(int i=0; i<r; i++){
    arr[i] = new int[c]; // allocating memory for each row in the matrix i.e, making columns in each row 
}

//taking input for a 2d array
for(int i=0; i<r; i++){
for(int j=0; j<c; j++){
    cout<< "enter "<< i << j << "element: "<<endl;
    cin >>arr[i][j];   // taking inputs from user
}
}

//printing elements of a 2d array
cout<< endl << "o/p : "<< endl;
for(int i=0; i<r; i++){
for(int j=0; j<c; j++){
    cout <<arr[i][j]<< " ";   // taking inputs from user
}
cout<< endl;
}


//releasing memory after using it 
for(int i=0; i<r; i++){
    delete[] arr[i];
    cout<<"Freeing "<<i<<endl;
}
delete[] arr;

/*
JAGGED ARRAY - jagged array is a 2-D array with different size of rows 
ex - 1 2
       1 2 3 4
       1 2
       3 4 5 6 6 7 
**/


//taking input size of rows
int n;
cout<<"Enter the no of rows ";
cin>>n;
//creating pointer array for row size
int** arr = new int*[n];
//creating array  of no of elements in each row 
int* size = new int[n];
//taking elements input
for(int i = 0; i<n; i++){
    //input size of elements
    cout<<"Enter "<<i+1<<" row size ";
    cin>>size[i];
    //creating column array of that size 
    arr[i] = new int[size[i]];
    //input values of elements
    cout<<"Enter "<<size[i]<<" elements for "<<i+1<<" row ";
    for(int j = 0 ; j < size[i]; j++){
        cin>>arr[i][j];
    }
}


//printing output
cout<<endl<<"output"<<endl;
for(int i = 0; i < n; i++){
    for(int j = 0 ; j < size[i]; j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}

//releasing memory after using it 
for(int i=0; i<n; i++){
    delete[] arr[i];
    cout<<"Freeing "<<i<<endl;
}
delete[] arr;


return 0;
}