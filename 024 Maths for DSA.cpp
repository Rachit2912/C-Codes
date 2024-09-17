#include<iostream>
using namespace std;

int main(){
// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        
        for(int i=2; i<n; i++){
            if(prime[i]){
            cnt++ ;

            for(int j=2*i; j<n; j+=i){
                prime[j]=false;
            }
            }
        }
        return cnt; 
    }
};


// GCD finding brute force
int gcd(int a , int b)
{
    int ans = 1;
    for(int i=2;i<=min(a,b);i++){
        if(a%i == 0 && b%i == 0){
            ans=i;
        }
    }
}


//  GCD Euclidean Algo
int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}

// Modular Exponentiation Using Fast Exponentiation
int modularExponentiation(int a, int n, int m) {
	int r=1;
	while(n>0){

		if(n&1){
			r=(1LL*r*(a)%m)%m ;
		}

		n=n>>1 ;

		a=(1LL*(a)%m*(a)%m)%m;
	}
	return r;
}


return 0;
}