//Triplet Sum 
// 2 pointer approach


#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

	vector<vector<int>> a;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-2;i++){
		int l=i+1,r=n-1;

		while(l<r){
			int s=arr[i]+arr[l]+arr[r];

			if(s==K){
				a.push_back({arr[i],arr[l],arr[r]});
				l++;r--;

				while((l<r) && (arr[l]=arr[l-1])){l++;}
				while((l<r) && (arr[r]=arr[r+1])){r--;}
			}

			else if(s<K){
				l++;
			}

			else{
				r--;
			}
		}
		while((i+1<n) && (arr[i]==arr[i+1])) {i++;}
	}
	return a;
}