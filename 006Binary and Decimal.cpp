#include<iostream>
#include<math.h>
using namespace std;

//decimal to binary (Normal Approach)
int d2b(int n){
int r;double i=0,a=0;
while(n>0) {
    r=n%2;
    a += (r*pow(10,i));
    n=n/2 ;
    i++;
}
cout<<"binary form via normal approach: "<<a<<endl;
return 0;
}


//decimal to binary (Binary Approach)
int d2b2(int n){
int last_bit;double a=0,i=0;
/*  in binary form, all even nos. are of form 1-----0  & all odd nos. are of 1-----1
    so when we'll use '&' operator on any odd no. and 1 we'll always get 1
    and for even no. we'll always get 0

    so we'll get the last bit of the no. by doing:  number&1
    now we got last bit then for getting the next bit
    we'll right shift it once and
    now, second last bit will come at the  position of last bit
    at the end, due to right shifting number will become 0         */

while(n!=0){
    last_bit=n&1;   //getting the last bit
    n=n>>1;               // right shifting
    a+= (last_bit*pow(10,i));      //bits are in reversed order so we have to again reverse it
    i++;        //incrementing the power of 10
}
    cout<<"binary form via binary approach: "<<a<<endl;      //output
}





//binary to decimal
int b2d(int n) {
int r,b,fa=0,i=0;
while (n>0) {
r=n%10;
b=pow(2,i);
fa+=r*b;
i+=1;
n=n/10;
}
cout<<"decimal form: "<<fa<<endl;
}

//using both simultaneously
int main(){
int n;
cout<<"enter decimal no: "<<endl;
cin>>n;
d2b(n);
d2b2(n);
cout<<"enter binary no. "<<endl;
cin>>n;
b2d(n);
return 0;
}
