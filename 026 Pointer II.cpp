#include<iostream>
using namespace std;

void print(int *p){
    cout<< *p << endl;
}

void update(int *p){
    p++ ;
}

void updateValue(int *p){
    (*p)++ ; 
}

int getSum(int arr[], int n) {

    cout << endl << "Size : " << sizeof(arr) << endl;

    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }
    return sum;
}


int main(){

/*
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
cout<<"array name is only the address "<< arr << endl;
cout<<"and address of the first element is  "<< &(arr[0]) << endl;
cout<<" both will be same"<<endl;

cout<<"the value of 1st element is "<< arr[0] <<"--" << *arr <<endl;
cout<<"different cases: "<< *arr<<" " << *arr+1<<" " << *(arr+1)<<" " << *(arr)+1 <<endl;

cout<< "arr[i] = *(arr+i) and i[arr] = *(i+arr) "<<endl;
cout<< arr[3] << "--"<< 3[arr] << endl; 


// total size which is allocated is array and a pointer is a element of that array to which it is pointed
// array contains the total size whereas pointer contains the size of fixed pointer
int *ptr = &arr[0] ; 
cout<<(sizeof(ptr))<<endl;
cout<<(sizeof(*ptr))<<endl;
cout<<(sizeof(&ptr))<<endl;


// Character Arrays
// different implementation from int arrays
char ch[6] = "abcde" ; 
cout << ch << endl;
// array name prints whole array and pointer starts printing from the pointer address till it finds '\0'
char *c = &ch[0] ;
cout << c << endl; 

// the pointer will print until it gets a '\0'
char temp = 'm' ; 
char *f = &temp ; 
cout << f << endl;
*/


// Pointer in Functions 
int value = 5; 
int *p =  &value ; 
print(p);
cout<<"Before Address: "<< p << endl;
update(p);
cout<<"After Address : "<< p << endl;
// it is same bcoz as you'll pass the pointer as an param. it'll create an another copy as the convention of pass by value method and changes will take place to that dummy pointer not the original pointer 


// but we can change the value to which it is referencing 
cout<<"Before Value : "<< *p << endl;
updateValue(p);
cout<<"After Value : "<< *p << endl;

int arr[6] = {1,2,3,4,5,8};
cout << "Sum is " << getSum(arr+3 ,3) << endl ;  
// size 4 print hoga jo ki pointer ki memory h iska matlab yeh h ki jab aap function me array as a param. pass krte hain toh vo ek pointer me convert hoke jaata hain function me ie. int arr[] = int *arr and isliye vo size of pointer de rha h 

return 0;
}