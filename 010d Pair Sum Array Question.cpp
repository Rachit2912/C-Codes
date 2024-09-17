//Pair sum question

 #include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector <vector<int>> ans;
   sort(arr.begin(),arr.end()); //just method to sort
   for(int i=0;i<arr.size();i++){

      for(int j=i+1;j<arr.size();j++){
         if(arr[i]+arr[j]==s){
            vector<int> temp;
            temp.push_back(min(arr[i],arr[j])); //method to return
            temp.push_back(max(arr[i],arr[j])); 
            ans.push_back(temp);
         }
      }
   }
return ans;
}