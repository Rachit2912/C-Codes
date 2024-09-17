//Intersection of 2 sorted arrays

//1st replacement method:
//but this code has so much time complexity 
// that's why it's not optimised soln.
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

	// Write your code here.
	vector<int> ans;
	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++){
                  if (arr1[i] < arr2[j]) {
                    break;
                  }
                          if (arr1[i] == arr2[j]) {
                            ans.push_back(arr1[i]);
                            arr2[j] = INT_MIN;
                            break;
                          }
                }
	}
	return ans;
}

//2nd method: 2 pointer approach
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	 vector<int> ans;int i=0,j=0;
	 
	 while(i<n && j<m){
		 if(arr1[i]==arr2[j]){
			 ans.push_back(arr1[i]);
			 i++;j++;
		 }
		 
		 else if(arr1[i]<arr2[j]){
			 i++;
		 }

		 else{
			 j++;
		 }
	 }
	 return ans;
}

