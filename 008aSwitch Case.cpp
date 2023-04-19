#include<iostream>
#include<math.h>
using namespace std;
int main() {

// num is 1 then it'll go to the case(num)=>case(1)
int num=1;
switch(num){
    case 1: cout<<"First"<<endl;
        break;
    case 2: cout<<"Second"<<endl;
        break;
    default: cout<<"Default"<<endl;
}


// no is '2' then it'll go to the case(no)=>case('2')
char no='2';
switch(no){
    case 1: cout<<"First"<<endl;
        break;
    case '2': cout<<"Second"<<endl;
        break;
    default: cout<<"Default"<<endl;
}

// n is 3 then it'll go to the case(n)=>case(3)
// but case(3) doesn't exist so it'll refer the default case 
int n=3;
switch(no){
    case 1: cout<<"First"<<endl;
        break;
    case 2: cout<<"Second"<<endl;
        break;
    default: cout<<"Default"<<endl;
}

// n is 3 then it'll go to the case(n)=>case(3)
// but case(3) doesn't exist so it'll refer the default case 
// if default isn't there then it'll just go through it 
// and nothing will print
n=3;
switch(no){
    case 1: cout<<"First"<<endl;
        break;
    case 2: cout<<"Second"<<endl;
        break;
    //default: cout<<"Default"<<endl;
}

// break is used to break at that instant and as a seperation of cases 
// if break isn't used then it'll consider all the things in that case
//only until the next break; is found
n=1;
switch(n){
    case 1: cout<<"First"<<endl;
        // break;
    case 2: cout<<"Second"<<endl;
        //break;
    case 3: cout<<"Third"<<endl;
        break;
    case 4: cout<<"Fourth"<<endl;        
    default: cout<<"Default"<<endl;
// it'll go upto the next break;
// it'll print "First","Second" and "Third" and it'll stop 
}


//nested switch
n=2;
switch(n){
    case 1: cout<<"First"<<endl;
        break;
    case 2: cout<<"Second"<<endl;
            switch(n){
                case 1: cout<<"1st"<<endl;
                        break;
                case 2: cout<<"2nd"<<endl;
                        break;
            }
}
return 0;
}