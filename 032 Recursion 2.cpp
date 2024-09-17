#include<iostream>
using namespace std;

// n-th  Fibonacci No.
int fib(int n){
// f(n) = f(n-1) + f(n-2) 

if(n == 0 | n == 1) return n;

else{
    return (fib(n-1) + fib(n-2)) ;
}
}


// Climbing Stairs 
int countDistinctWays(int n){
 if(n < 0) return 0;
 if(n == 0){return 1;}
//  if(n == 2) return 3 ;
else{    
        return (countDistinctWays(n-1)+countDistinctWays(n-2)) ;
    }
}


// Say It Digit
void sayItDigit(int n){
string arr[]= {"zero", "one", "two", "three","four", "five", "six", "seven", "eight", "nine"};

if(n == 0) return;
int d = n % 10;
n /= 10 ;
sayItDigit(n) ;
cout<< arr[d] <<" ";
}


int main() {
int n;
cin>> n;
cout<< countDistinctWays(n) <<endl;

cin>> n;
sayItDigit(n);


return 0;
}