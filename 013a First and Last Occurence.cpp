//Binary Search Question
// first occurence and last occurence 
// my approach
#include<iostream>
#include<vector>
using namespace std;

int main(){
int arr[1]={10};
int s=0,e=0;int k=10;
int m=s+(e-s)/2 ;int a,b;
int ans1=-1,ans2=-1;
vector<int> ans;

while(s<=e){

    if(arr[m]<k){
         s=m+1;
    }

    else if(arr[m]>k){
       e=m-1;
    }

    else if(arr[m]==k){
        a=1;b=1;
        for(int i=s;i<=e;i++){

            if(arr[i]==k){
                if(a==1){
                    ans1=i;
                    a=-1;
                }}
            
            if(b==1){
                if(arr[e]==k){
                       ans2=e;
                        b++;
                    }
                
                else{
                    if((arr[i]==k) && (arr[i+1]!=k)){
                        ans2=i;
                        b++;
                    }}
            }

        }

       

    break;
    }
m=s+(e-s)/2;
ans.push_back(ans1);
ans.push_back(ans2);
}

cout<<ans1<<endl;
cout<<ans2<<endl;

return 0;
}




//2 different functions approach
#include<vector>
using namespace std;
int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    
    return p;
}
