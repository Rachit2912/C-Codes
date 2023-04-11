#include<iostream>
using namespace std;
 int main()
 {
   int n,r=1;
   cin>>n;
    while(r<n+1) {int c=1;
       while(c<=n-r+1) {
        cout<<c;
        c+=1;
       }
    while((c>n-r+1) && (c<=n-r+1+2*(r-1))) {
    cout<<"*";
    c+=1;
    }
    while((c<2*n+1) && (c>n-r+1+2*(r-1))) {
        cout<<2*n-c+1;
        c+=1;
    }
    cout<<endl;
    r+=1;
    }    
return 0;
 }