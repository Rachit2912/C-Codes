#include<iostream> 
using namespace std;

int factorial(int n) {
    
    //base case
    if(n==0)
        return 1;

    int smallerProblem = factorial(n-1); 
    //recursive relation  
    int biggerProblem = n * smallerProblem;

    return biggerProblem;
}


int power(int n) {

    //base case 
    if(n == 0)
        return 1;

    //recursive relation
    return 2 * power(n-1);    
}


int main() {

    int n;

    cin >> n;

    int ans = factorial(n);

    cout << ans << endl;

    cin >> n;

    int ans = power(n);

    cout << ans << endl;

    return 0;
}