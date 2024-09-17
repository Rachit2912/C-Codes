#include<iostream>

using namespace std;

int main() {
// 2-D Array
int arr[3][4];
int arr2[3][4];

//taking input in 2d array
//row wise input
cout<<"Inputs for arr : "<<endl;
for(int i=0; i<3; i++){
    for(int j=0; j<4; j++){
        cin>>arr[i][j];
    }
}

//column wise input
cout<<"Inputs for arr2 : "<<endl;
for(int i=0; i<4; i++){
    for(int j=0; j<3; j++){
        cin>>arr2[j][i];
    }
}

//printing the 2d array
//row wise output
cout<<"Printing arr :"<<endl;
for(int i=0; i<3; i++){
    for(int j=0; j<4; j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}

//column wise output
cout<<"Printing arr2 :"<<endl;
for(int i=0; i<3; i++){
    for(int j=0; j<4; j++){
        cout<<arr2[i][j]<<" ";
    }
    cout<<endl;
}

// 2d array as a parameter in a function
bool isPresent(int arr[][3], int target, int row, int col) {

  for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            
            if( arr[row][col] == target) {
                return 1;
            }
            
        }
    }
    return 0;
}

//print row wise sum function
void printSum(int arr[][3], int row, int col) {
    cout << "Printing Sum -> " << endl;
    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}


// print column wise sum function
void printColSum(int arr[][3], int row, int col) {
    cout << "Printing Sum -> " << endl;
    for(int col=0; col<3; col++) {
        int sum = 0;
        for(int row=0; row<3; row++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}

// largest row sum function
void largestRowSum(int arr[][3],int r, int c){
    int maxi = INT_MIN;
    int rindx = -1;

    for(r=0; r<3; r++){
        int s=0;
        for(c=0; c<3; c++){
            s+=arr[r][c];
        }

        if(s>maxi){
            maxi = s;
            rindx = r;
        }
    }

    cout<<"max. sum is : "<< maxi<<endl;
    cout <<"index of the maximum value in a row: "<< rindx+1 <<endl;
    return (rindx);
}

// printing a wave pattern in a 2D matrix
#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int r, int c)
{
    vector<int> a;
for(int i=0; i<c; i++){
    
    if((i%2) == 0){
    for(int j=0; j<r; j++){
        // cout<<arr[j][i]<<" ";
        a.push_back(arr[j][i]);
    }
    }

    else{
        for(int j=r-1; j>=0; j--){
        // cout<<arr[j][i]<<" ";
        a.push_back(arr[j][i]);
    } 
    }
}
return a;
}


//spiral print in a 2d matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> a;

        int sR=0,sC=0,eR=r-1,eC=c-1;

        while(a.size()<r*c){
            for(int i=sC; i<=eC && count<total; i++){
                a.push_back(matrix[sR][i]);
            }
            sR++ ; 

            for(int i=sR; i<=eR && count<total; i++){
                a.push_back(matrix[i][eC]);
            }
            eC-- ;

            for(int i=eC; i>=sC && count<total; i--){
                a.push_back(matrix[eR][i]);
            }
            eR-- ;

            for(int i=eR; i>=sR && count<total; i--){
                a.push_back(matrix[i][sC]);
            }
            sC++ ;

        }


return a;
    }
};


// searching a element in a sorted 2D matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n - 1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int e = matrix[mid/n][mid%n];
        if(target < e)
        {
            end = mid - 1;
        }
        else if(target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}  
};

// searching in a 2D matrix II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int r=matrix.size(),c=matrix[0].size();
        int rI=r-1,cI=0;
        while(rI>=0  && cI<c){
            int e=matrix[rI][cI];
            if(t == e) {return 1;}
            if(e > t){ rI-- ; }
            else { cI++ ; }
        }
        return 0;
    }
};

// Rotate Image or Matrix by 90 degrees
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row; i++){
            for(int j=0; j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


return 0;
}