#include<iostream>
using namespace std;

//swap alternate function
void swapAlternate(int arr[], int size){
    for(int i=0;i<4;i++){
        if(i+1<size){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
        i++;
        //you can also use i+=2
        }
    }
}

//unique element in array function
int findUnique(int arr[], int size)
{
    //we'll use here the XOR property: a^a=0 and a^0=a
    //we'll take the XOR's among all the elements of array
    //same element will give 0 as output then that 
    // 0^unique=unique that's our ans.
    //but it'll work only when same element is present in even nos.
    //eg:if same element '9' is present 3 times then 9^9^9 will give 9 as ans.
            int x=0;
    for(int i=0;i<size;i++){
        x=x^arr[i];
    }
    cout<<x;
}


int main()
{
//swap alternative nos.
int odd[5]={1,2,3,4,5},
even[6]={1,2,3,4,5,6};

//swap alternate function call
swapAlternate(odd,5);
swapAlternate(even,6);

for(int i=0;i<5;i++){
    cout<<odd[i]<<" ";
}
cout<<endl;
for(int i=0;i<6;i++){
    cout<<even[i]<<" ";    
}
cout<<endl;

//all elements except 1 element are twice in no. in array 
int un[11]={1,2,3,4,5,6,5,4,3,2,1};
//unique element que. function call
findUnique(un,11);


return 0;
}