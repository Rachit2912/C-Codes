#include<bits/stdc++.h>
using namespace std;


//reversing the array after the 'm'th position
vector <int> reverse(vector<int> v,int m){
    int s = m+1 , e = v.size() - 1 ;

    while(s<=e){
        swap (v[s],v[e]);
        s++;
        e--;
    }
    return v ;
}

//printing the vector
void print(vector <int> v){
    for(auto i : v){
        cout << i <<" ";
    }
    cout<<endl;
}


int main(){

    vector<int> v;
    
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    vector <int> ans = reverse(v,1);
    cout << "Printing Reverse : " << endl;
    print(ans);
return 0;
}


//merge 2 sorted array 
//stored in a different 3rd array
merge2sort(int arr1[],int m, int arr2[], int n, int arr3[]){
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(arr1[i]<arr2[j]){
                arr3[k++]=arr[i];
                i++;
            }
            else {
                arr3[k++] = arr2[j++];
            }
        }

        while(i<m){
            arr3[k++]=arr1[i++];
        }    

        while(j<n){
            arr3[k++]=arr2[j++];
        }
}

//stored in the same array 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};


//shifting zeroes to the right
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

int n=nums.size();
int i=0,j=0;
while(i<n){
    if(nums[i]!=0){
swap(nums[i],nums[j]);
j++;
    }
    i++;
}

    }
};