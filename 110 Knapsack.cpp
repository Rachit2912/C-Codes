// 2D DP : 
// knapsack problem : 

// ek chor h uske paas knapsack h jo max. 'W' weight carry kr skta h 
// and 'n' items h : 1 to n jinpe sbka 1 weight h 'Wi' and sabki 1 vlaue h 'Vi'
// we have to choose the items such that their weight should be <= W and their value should be max. 

// ** Normal recursion : 
#include <bits/stdc++.h> 


int knapsack1(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve1(weight,value,n-1,maxWeight);
}

int solve1(vector<int> weight, vector<int> value, int index, int maxWeight){

	// base case : 
	if(index == 0){
		if(weight[index] <= maxWeight){
			return value[index];
		}
		return 0;
	}


	// include : 
	int include =0;
	include = value[index] + solve1(weight,value,index-1,maxWeight-weight[index]);

	// exclude : 
	int exclude  = 0 + solve1(weight,value, index-1,maxWeight);

	int ans = max(include,exclude);
	return ans;
}


// ** recursion + memoization : 

int knapsack2(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

    // 2d dp vector  :
    // we used 2d dp vector, because here two variables are changing their states : index &  maxWeight
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solve2(weight,value,n-1,maxWeight,dp);
}


int solve2(vector<int> weight, vector<int> value, int index, int maxWeight, vector<vector<int>> &dp){

	// base case : 
	if(index == 0){
		if(weight[index] <= maxWeight){
			return value[index];
		}
        else{
		return 0;
        }
	}

    if(dp[index][maxWeight] != -1) return dp[index][maxWeight];


	// include : 
	int include =0;
    if(weight[index] <= maxWeight){
	include = value[index] + solve2(weight,value,index-1,maxWeight-weight[index],dp);
    }

	// exclude :
	int exclude  = 0 + solve2(weight,value, index-1,maxWeight,dp);

	dp[index][maxWeight] = max(include,exclude);
	return dp[index][maxWeight];
}




// ** recursion + space optimization  :
// current state depends on the previous vector only so, now use 2 vectors only  

int knapsack3(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve3(weight,value,n-1,maxWeight);
}


int solve3(vector<int> weight, vector<int> value, int index, int maxWeight){


    vector<int> prev(maxWeight+1,0);
    vector<int> curr(maxWeight+1,0);


	// base case : 
	for(int w = weight[0]; w<= maxWeight; w++){
        if(weight[0] <= maxWeight) prev[w] = value[0];
        else{
            prev[w] = 0;
        }
    }


    for(int index = 1;index < n; i++){
        for(int w = 0; w <= maxWeight; w++){

            int include = 0;
            if(weight[index] <= w){
                include = value[index] + prev[w-weight[index]];
            }

            int exclude = 0 + prev[w];

            curr[w] = max(exclude,include);
        }
        prev = curr;
    }
    return prev[maxWeight];
}


// ** recursion + used only 1 vector  :
// current state depends on the previous vector only so, now use 2 vectors only 
// but, now, we can do it with array only  

int knapsack4(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve4(weight,value,n-1,maxWeight);
}


int solve4(vector<int> weight, vector<int> value, int index, int maxWeight){

// curr[w] -> depends on prev[w] and prev[w-weight[index]] :
// it means, an element in the array depends on that element only and on the left part of the array 
// but, if we'll go from left to right, then we'll overwrite that value which will be later used by an another element on the right part of the array so, it'll be wrong 
// but, right part  has no role here
// so, we can start from right to left and we'll be filling the values from right to left so that no value will be the overwritten and we'll get the right 
// so replace prev with curr and for inner loop start from right to left


    vector<int> prev(maxWeight+1,0); 
    vector<int> curr(maxWeight+1,0);


	// base case : 
	for(int w = weight[0]; w<= maxWeight; w++){
        if(weight[0] <= maxWeight) curr[w] = value[0];
        else{
            curr[w] = 0;
        }
    }


    for(int index = 1;index < n; i++){
        for(int w = maxWeight; w >= 0; w--){    // right to left flow, only change

            int include = 0;
            if(weight[index] <= w){
                include = value[index] + curr[w-weight[index]];
            }

            int exclude = 0 + curr[w];

            curr[w] = max(exclude,include);
        }
        prev = curr;
    }
    return curr[maxWeight];
}

