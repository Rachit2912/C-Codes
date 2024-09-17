#include<iostream>
using namespace std;

int main(){

double num  = 5 ;
double *ptr = &num ;

cout<<"address of num is "<< ptr <<endl;
cout<<"and value is "<< *ptr <<endl;

// size of a pointer is dependent on cpu architecture and it's constant for any type of pointer 
cout<<"size of num is " << sizeof(num) << endl;
cout<<"size of ptr is " << sizeof(ptr) << endl;

// it's better and adviced to initialize a pointer like this if you have to do it without any address
int *p = 0 ; 
//      OR
int *r = NULL ;


//change in value by pointer
int n = 5 ;
p = &n ;
(*p)++ ;
cout<< n << endl;

// copying a pointer to a pointer
int *q = p ; 
cout<< q << "--" << p << endl;
cout<< *q << "--" << *p << endl;

// pointer arithmetic
// it'll add the bytes to the address according the data type 
int i = 1 ;
int *t = &i ; 
cout<<"now the address is "<< t << endl;
t++ ;
cout<<"after adding the address is "<< t << endl;



return 0;
}