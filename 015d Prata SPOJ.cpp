#include <bits/stdc++.h> 
bool possible(vector<int> &rank, int m,int mid){
    int p=0;
    for(int i=0;i<rank.size();i++){
        int t=rank[i];
        int j=1;
        
        while(t<=mid){
            p++ ;
            t+=(rank[i])*(++j);
            
            if (p >= m) {
                return true;
            }

        }
        


    }
    return false;

}


int minCookTime(vector<int> &rank, int m)
{
    // Write your code here
    sort(rank.begin(),rank.end());
    int s=0,e=(rank[rank.size()-1]*m*(m+1)/2);
    int ans=-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(possible(rank,m,mid)){
            ans=mid;
            e=mid-1;
        }

        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }

    return ans;
}
