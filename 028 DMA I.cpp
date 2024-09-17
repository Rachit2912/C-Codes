#include<iostream>
using namespace std;

void update1(int n){
    n++ ;
}

void update2(int& n){
    n++ ;
}

int main(){

//reference variable
int i = 5 ; 
int& j = i ; 
i++ ;
cout<<i<<" "<<j<<endl;
j++ ;
cout<<i<<" "<<j<<endl;

int n = 5;

cout<<"without reference variable"<<endl;
cout<<"before "<<n<<endl;
update1(n);
cout<<"after "<<n<<endl;

cout<<"with reference variable"<<endl;
cout<<"before "<<n<<endl;
update2(n);
cout<<"after "<<n<<endl;
// the only change is the type of parameter now it's a refernce variable
// it is also known as pass by reference

// dynamic allocation on heaps
char ch = 'q' ;
cout<< sizeof(ch) <<endl;
char* c = &ch; 
cout<< sizeof(c) <<endl;
cout<< "total size of heap allocation will be add of both these " <<endl;
// array 
int* arr = new int[5] ;

//unlike stack or static allocation in DMA, we have to manually clear the memory for which we have asked on the heap by using 'delete' keyword
delete c ;      // delete for a single variable
delete[] arr;   // delete for an array 




return 0;

}