#include<iostream>
using namespace std;

// integer part of square root of a no.
long long int Bs(int n){
    int s=0,e=n;
    long long int m=s+(e-s)/2,ans=0;

    while(s<=e){
        long long int sq=m*m;
        if(sq==n) {return m;}
        if(sq>n){ e=m-1;}
        else {ans=m;
        s=m+1;}
        m=s+(e-s)/2;
    }
    return ans;
    }

//for extra precision using bruteforce method 
double precise(int n,int d,double intSol){
    double ans=intSol;
    double factor=1;

    for(int i=0;i<d;i++){
        factor/=10;

        for(double j=ans;j*j<n;j+=factor){
            ans=j;
        }
        return ans;
    }
}

int main(){
int n;
cout<<"Enter your no."<<endl;
cin>>n;
cout<<"Your Ans. is : "<<Bs(n) << " and " << precise(n) <<endl;
return 0;
}