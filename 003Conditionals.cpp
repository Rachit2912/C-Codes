#include<iostream>
using namespace std;
int main() {
   
    int n;

    cin>>n;
cout<<"Value of n is "<<n<<endl;

if(n>0){
    cout<<"n is +ve"<<endl;
}
else if(n==0) {
cout<<"n is zero"<<endl;
}
else {
cout<<"n is -ve"<<endl;
}

int a,b;
//1st it will take input for a then for b 
cin>>a>>b;
cout<<"value of a and b is"<<a<<endl<<b<<endl;
// enter key,tab key and space key: this all are considered as whitespace keys
//bcoz compiler will ignore all these keys while entering the input.
// we can enter input for a and after it either of whitespaces we can use
 int z;
 // cin.get() reads the 1st input you entered then it will store the value according to datatype of variable declared 
 z=cin.get();
 cout<<"value of z is "<<z<<endl;


}