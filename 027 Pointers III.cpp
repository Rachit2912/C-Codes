#include<iostream>
using namespace std;

void update( int **dp){
    // dp++ ;
    //change : no change will take place 

    // (*dp)++ ;
    // change : value of p will change 

    // (**dp)++ ;
    // change : value of i will change 
}

int main() {

//double pointer
int i = 5 ; 
int* p = &i ;
int** dp = &p;

cout << " printin p " << p <<"--"<< *dp<< endl; 
cout << " address of p " <<  &p <<"--"<<"" << endl;
cout<<"value of i "<< i<< "--"<< *p <<"--"<< **dp<<endl;
// and many more relations and values you can get

// double pointer in functions 
cout<<endl<<"Before "<< i << endl;
cout<<"Before "<< p << endl;
cout<<"Before "<< dp << endl;
update(dp);
cout<<endl<<"After "<< i << endl;
cout<<"After "<< p << endl;
cout<<"After "<< dp << endl<<endl;


return 0;
}