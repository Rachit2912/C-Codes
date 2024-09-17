#include<iostream>
#include<limits.h>
using namespace std;

//array parameter in function
int arrayfn(int arr[],int n){
    cout<<"this is a array"<<endl;
    cout<<"it's members are: "<<endl;
   for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
}

//array function to check how scope works in case of array
void update(int arr[],int size){
    cout<<"inside the update function: "<<endl;

    arr[0]=120; //updating a element in array to see the change

    //printing the array after changing the value
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//function for searching the key
bool search(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main() {

//array declaration & initialization
int arr[5]={};//this will fill the values with zeroes
int arr1[5]={0};//this will also fill the array with zeroes
int arr2[5]; //filled with garbage values
cout<<arr2[4]; //garbage value
cout<<endl;
int arr3[15]={1,2,3};
//we only gave 3 elements to it
// all other will be filled with 0
//printing arr3
for(int i=0;i<15;i++){
    cout<<arr3[i]<<endl;
}


int c[5]={1,2,3,4,5};
arrayfn(c,5); 
//it'll print all members of array
//to find how many elements are in array
cout<<"it has: ";
cout<<sizeof(c)/sizeof(int);
cout<<" members. "<<endl;

//character array
char cd[5]={'a','b','c','d','e'};
for(int i=0;i<5;i++){
    cout<<cd[i]<<endl;
}

//other arrays
double d[15];
float f[15];
bool b[15];

//maximum and minimum no. in array
int size;
cin>>size;  //input size of array

//never put array size as variable
// int num(size);
//it'll waste the memory
//instead of this put any random no.
int num[1000];
//this is better than above one

//extreme values of int data type
int min=INT_MAX; int max=INT_MIN;

//this will calculate max. & min. no. in array
//while taking the inputs for members of array itself   
for(int i=0;i<size;i++){
    cout<<"enter the"<<i+1<<"element: "<<endl;
    cin>>num[i];    //reading members 
    if(num[i]>max){
        max=num[i];     //calculating max.
    }
    if(num[i]<min){
        min=num[i];     //calculating min.
    }

}
cout<<"Max. is"<<max<<endl;
cout<<"Min. is"<<min<<endl;

//scopes in array
int arr4[3]={1,2,3};

update(arr4,3);  //calling he function

//printing the array to see the change
cout<<"inside the main function after passing it to update function: "<<endl;
for(int i=0;i<3;i++){
    cout<<arr4[i]<<" ";
}
cout<<endl;

//it changed the original value also
// it is opposite to the case of variables
//it's bcoz when we declare variables 
//it has only the name associated with it
//but in case of array, it's 1st element's address is also
//associated with its name
//that's why when a function changes something in an array
//it'll do with the help of address & that's why 
//it'll change the original values also.


//Linear Search
int arr5[10]={5,7,-2,10,22,-2,0,5,22,1};
//we have to find whether 1 is present or not in this array 
cout<<"enter the element that you want to check: "<<endl;
int key;
cin>>key;

bool found=search(arr5,10,key);

if(found){
    cout<<"key is present"<<endl;
}
else{
    cout<<"key is absent"<<endl;
}

//so method we applied here is linear search
// we are checking conditions on 1 by 1 element of array
//so we are travelling in 1-D direction
//that is linear search

//reversing the array
int arr[6]={1,2,3,4,5,6};
int arr2[7]={1,2,3,4,5,6,7};

for(int i=0;i<3;i++){
//both odd and ever no. arrays
//reversing using same loop
int temp1=arr[i];
arr[i]=arr[5-i];
arr[5-i]=temp1;
int temp2=arr2[i];
arr2[i]=arr2[6-i];
arr2[6-i]=temp2;    
}
//you can also use swap() function 
//instead of using temporary variable


for(int i=0;i<6;i++){
cout<<arr[i]<<" ";    
}

cout<<endl;
for(int i=0;i<7;i++){
cout<<arr2[i]<<" ";    
}


return 0;
}