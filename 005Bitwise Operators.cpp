#include<iostream>
using namespace std;
int main() {

// 6 bitwise operators: &(and) |(or) ~(not) ^(xor) >>(right shift) <<(left shift)
//this operator compares two values in their binary form only bit by bit

int a=4,b=6;
signed int w=a&b,x=a|b,y=a^b,z=~a,m=~b;
bool p=a&b,q=a|b,r=a^b,s=~a,t=~b;

//int will give the answer in integer form
// but bool will answer only in 0 or 1
cout<<w<<endl<<x<<endl<<y<<endl<<z<<endl<<m<<endl;
cout<<p<<endl<<q<<endl<<endl<<r<<endl<<s<<endl<<t<<endl;

//default is signed int so it'll give answer in both +ve & -ve values
// but if we shift it to unsigned then ans. will only be in +ve number
unsigned int d=a&b,e=a|b,f=a^b,g=~a,h=~b;
cout<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl;

//right shift: no>>how many times we have to shift
//left shift: no<<how many times we have to shift
//it'll pad the older bits with 0 for +ve no. but not fix for -ve nos.

cout<<(17<<1)<<endl;
cout<<(17<<2)<<endl;
cout<<(17>>1)<<endl;
cout<<(17>>2)<<endl;

//pre(++i) & post(i++) - increment & decrement
// for pre first it is increased or decreased then it'll be stored
// for post first it is stored then it will be increased or decreased 
// same value is stored in pre but changed value will be stored in post
int l=10;
cout<<"For l=10 in every case"<<endl;
cout<<"l++ value is "<<l++<<endl;
cout<<"now l becomes"<<l<<endl;
l=10;
cout<<"++l value is "<<++l<<endl;
cout<<"now l becomes"<<l<<endl;
l=10;
cout<<"l-- value is "<<l--<<endl;
cout<<"now l becomes"<<l<<endl;
l=10;
cout<<"--l value is "<<--l<<endl;
cout<<"now l becomes"<<l<<endl;

//for loop:
//for(initialization;condition;updation) {statements}

int n;
cout<<"enter n: "<<endl;
cin>>n;
for(int i=1;i<=n;i++){
    cout<<i<<endl;
}


//intialization,condition and updation: these we can also do inside the statements
int i=1,n=5;
for(;;){
    if(i<=n){
        cout<<i<<endl;
        }

    else {
        break;
        }

    i++;
}

//this is the same representation of above example with using all the parameters inside the statement

// we can also use iterate multiple variables & their condition in a single loop


for(int a=10,b=1;a>0 && b<11;a--,b++){
    cout<<"a:"<<a<<"b: "<<b<<endl;
}

}

