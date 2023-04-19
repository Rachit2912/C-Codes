#include<iostream>
using namespace std;

//Functions

//power function
pow(int a,int b){
    int ans=1;
    for(int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

//even odd function
bool isEven(int a){
if(a&1){
    return 0;
}
else{
    return 1;
}
}

//factorial function
int fact(int n){
    int a=1;
    for(int i=1;i<=n;i++){
        a*=i;
    }
    return a;
}

//nCr function
int nCr(int n,int r){
    int nu=fact(n);
    int de=fact(r)*fact(n-r);
    return nu/de;
}

//counting function
//we'll use void if function isn't returning anything
void counting(int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

//prime no. program
bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

//pass by value example function
dummy(int n){
    n++;
    cout<<"in dummy function n is: "<<n<<endl;
}


int main(){
    
    //power function call
    int a,b;
    cout<<"enter a to the power b: "<<endl;
    cin>>a>>b;
    cout<<pow(a,b)<<endl;   

    //odd or even function call
    int a;
    cin>>a;
    if(isEven(a)){
    cout<<"It is even no. "<<endl;
    }
    else{
        cout<<"It's odd no. "<<endl;
    }

    //factorial function call
    int a;
    cin>>a;
    cout<<fact(a)<<endl;

    //nCr function call
    int c,b;
    cin>>c>>b;
    cout<<nCr(c,b)<<endl;

    //counting function call
    int n;
    cin>>n;
    counting(n);

    //prime no.function call
    int n;
    cin>>n;
    if(isPrime(n)){
        cout<<"Not a prime no. "<<endl;
    }
    else{
        cout<<"Prime no. "<<endl;
    }



//pass by value
int n;
cin>>n;
dummy(n);
cout<<"in main function n is: "<<n<<endl;
//in main() function value of n will be same
// bcoz when it'll pass in dummy(), it'll create 
//other copy of same variable
//so main() has the original variable 'n' with the same value

    return 0; 
}