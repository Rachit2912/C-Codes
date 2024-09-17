#include<iostream>
using namespace std;
int main() {


// complement of base 10 integer
//insert 1 in the mask unless the n=0 by doing right shift
//then take & of mask and ~n
int n;
cout<<"enter n:"<<endl;
cin>>n;
int m=n;
if(n==0){
    return 1;
}
int mask=0;
while(m!=0) {
mask= (mask<<1) | 1 ;
m=m>>1;
}
int ans = (~n) & mask ;
cout<<ans;
  }



//reverse the integer
int reverse(int x) {
        int a=0;
        while(x!=0){
            int d=x%10;
            if((a>(INT_MAX/10)) || (a<(INT_MIN/10))) {return 0;}
            a=a*10+d;
            x=x/10;
        }
        return a;
    }


//power of 2
// n&n-1 approach
// n&n-1 will always give the result 0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        return (n&(n-1))==0;
    }
};



// xor digit approach
// perform xor with every bit of no. and 0
//only 2^n nos. will give the ans. 1
//we can do only XOR of all the digits of no.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        else{
        int m=n;int xd=0;int ld;
while(m!=0){
        ld=m&1;
if((xd < INT_MAX) && (xd > INT_MIN)){
    xd=xd+(ld ^ 0);
    m=m>>1;
}}
if(xd==1){
    return true;
}
else{
        return false;
    }
}
}
};