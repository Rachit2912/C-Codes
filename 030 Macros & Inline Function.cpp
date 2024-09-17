#include<iostream>
using namespace std;

int main() {

// Macros define/create : #define at global level
//we can also use variables but it'll take storage which'll affect your performace

#define PI 3.14

//Types of Macros: 
//(i) object like / simple : 
#define FI 18
//(ii) chain :
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 10
//(iii) multi-line :
#define ELE 1,\
            2,\
            3
//(iv) function line:
#define min(a,b) (((a)<(b)) ? (a) : (b))


/*
we have reference variable to share the variable data amongst the different functions
but we have another tool to perform this task of sharing which is Global Variable
Global Variables are declared outside any function and they're accessible from anywhere in our program
but still it's a bad practice or an outlaw because it's value can be altered anywhere by anyone in any function so it's risky 
prioritize reference variable method over this 


Inline Functions
are used to reduce the functions calls overhead 
if a function having a body of 1-2 lines then we can use inline function so that @ pre-compilation time function call will directly get altered by the body of function itself 
no function calls and no extra memory for pass by value method
but it is also compiler dependant if the function is eligilbe to be an inline function then only it'll be converted to an inline function
we have to just add inline before the function declaration
example:
inline int max(int a , int b){
    return ((a > b)? a : b); //ternary operator
    }

Default Arguments of a function
if you want to give default values while calling the function then do so as follows:
void print_sum(float x =5, float y=6 ){
    cout<<x+y<<" ";
    }
    print_sum();   //prints sum of both default arguments
    print_sum(-7,-9);// prints difference between two numbers
    }
isme only right to left hi default args de sakte hai i.e, sabse rightmost ko sabse pehle default arg dena padega usko diye bina tum left wale ko default arg nhi de skte 
eg:  void sum(int x=1,int y){}  :  yeh wrong hai 
eg:  void sum(int y, int x=1){}  :  yeh right hai ab 


Constant Variables
variables which are constant ; hahahhahahaahaa most ironic thing ever :-)
they can't be changed once assigned with some initial value, that's why assign them only @ the time of declaration otherwise they'll contain some garbage value which can't be changed later 
const int a = 5;
*/


return 0;
}