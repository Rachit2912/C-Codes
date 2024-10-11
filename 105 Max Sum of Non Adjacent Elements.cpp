#include <iostream>
#include <vector>
using namespace std;

// MAXIMUM SUM OF NON - ADJACENT ELEMENTS :

// ** i) normal recursion : (TLE) :
// inclusion exclusion principle :
// 1 baar include another time exclude
// if include : index +=2 else : index +=1
// index out of bound : base case : save the answer

int maximumNonAdjacentSum1(vector<int> &nums) {

  if (nums.size() == 1)
    return nums[0];

  int ans = solve(nums, 0, 0);
  return ans;
}

int solve_1(vector<int> &nums, int indx, int sum) {

  // base case :
  if (indx >= nums.size()) {
    return sum;
  }

  // include :
  int include = solve(nums, indx + 2, sum + nums[indx]);

  // exclude :
  int exclude = solve(nums, indx + 1, sum);

  return max(include, exclude);
}

// ** ii) normal recursion + memoization :

int maximumNonAdjacentSum2(vector<int> &nums) {

  if (nums.empty())
    return 0;
  if (nums.size() == 1)
    return nums[0];
  vector<int> dp(nums.size() + 1, -1);

  int ans = solve2(nums, 0, 0, dp);
  return ans;
}

int solve2(vector<int> &nums, int indx, int sum, vector<int> &dp) {

  // base case :
  if (indx == nums.size()) {
    return sum;
  }

  if (dp[indx] != -1)
    return dp[indx];

  // include :
  int include = solve2(nums, indx + 2, sum + nums[indx], dp);

  // exclude :
  int exclude = solve2(nums, indx + 1, sum, dp);

  int result = max(include, exclude);
  dp[indx] = result;
  return dp[indx];
}

// ** iii) normal recursion + tabulation:

int maximumNonAdjacentSum3(vector<int> &nums) {

  if (nums.empty())
    return 0;
  if (nums.size() == 1)
    return nums[0];

  return solve3(nums);
}

int solve3(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp(n, -1);
  // base case :
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  for (int i = 2; i < n; i++) {
    int include = dp[i - 2] + nums[i];
    int exclude = dp[i - 1];
    dp[i] = max(include, exclude);
  }
  return dp[n - 1];
}

// ** (iv) space optimization :
int solve4(vector<int> &nums) {
  int n = nums.size();
  int prev2 = 0, prev1 = nums[0];

  for (int i = 1; i < n; i++) {
    int incl = prev2 + nums[i];
    int excl = prev1 + 0;
    int ans = max(incl, excl);
    prev2 = prev1;
    prev1 = ans;
  }
  return prev1;
}
