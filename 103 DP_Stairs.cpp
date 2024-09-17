#include <iostream>
#include <vector>
using namespace std;

// COUNT WAYS TO REACH N-TH STAIR :

// using only recursion :
int count_rcrsn(int n, int i) {

  // base case :
  if (i == n)
    return 1;

  // exceeding case :
  if (i > n)
    return 0;

  // recursion step :
  return count_rcrsn(n, i + 1) + count_rcrsn(n, i + 2);
}

int countN_th_stair(int n) { return count_rcrsn(n, 0); }

/*
--> but it'll give TlE as many cases are repeating means overlapping subproblems
are there
- so,now we can use DP to achieve a optimal soln.
- there are 2 approaches to solve this :
i) you are at 0th stair and going upwards
ii) you are at n-th stair and we are imagining that we either came from n-1 th
stair or n-2 th stair
*/

// adding memoization :
int climbStairs_memo_rcrsn(int n, vector<int> &dp) {

  if (n < 0)
    return 0;
  if (n == 0)
    return 1;

  if (dp[n] != -1)
    return dp[n];

  dp[n] = climbStairs_memo_rcrsn(n - 1, dp) + climbStairs_memo_rcrsn(n - 2, dp);
  return dp[n];
}

int climbStairs_memo(int n) {
  vector<int> dp(n + 1, -1);

  return climbStairs_memo_rcrsn(n, dp);
}

// adding tabulation :
int climbStairs_tab(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  vector<int> dp(n + 1, -1);
  dp[0] = dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

// space optimization :
int climbStairs_space_opt(int n) {

  int prev0 = 1, prev1 = 1;
  for (int i = 2; i <= n; i++) {
    int temp = prev1;
    prev1 = prev1 + prev0;
    prev0 = temp;
  }
  return prev1;
}
// ans can be huge so check for some modulo fn.

// MIN COST CLIMBING STAIRS :
//-- que. is same as above but just they have added the cost also with it that
// we have to pay and have to find the min. cost

// only recursion:
int minCostClimbing_rcrsn(vector<int> &cost, int n) {

  // base case :
  if (n == 0)
    return cost[0];
  if (n == 1)
    return cost[1];

  // recursion step :
  return min(minCostClimbing_rcrsn(cost, n - 1),
             minCostClimbing_rcrsn(cost, n - 2)) +
         cost[n];
}

int minCostClimbing(vector<int> &cost) {

  int n = cost.size();
  int ans = min(minCostClimbing_rcrsn(cost, n - 1),
                minCostClimbing_rcrsn(cost, n - 2));
  return ans;
}

//*****
// but it is also giving TLE
// now, we'll add memoization to this recursion

int minCost_memo_rcrsn(vector<int> &cost, int n, vector<int> &dp) {

  // base case :
  if (n == 0)
    return cost[0];
  if (n == 1)
    return cost[1];

  // checking if value is already there or not:
  if (dp[n] != -1)
    return dp[n];

  // adding memoization :
  dp[n] = min(minCost_memo_rcrsn(cost, n - 1, dp),
              minCost_memo_rcrsn(cost, n - 2, dp)) +
          cost[n];
  return dp[n];
}

int minCost_memo(vector<int> &cost) {

  int n = cost.size();
  vector<int> dp(n + 1, -1);
  int ans = min(minCost_memo_rcrsn(cost, n - 1, dp),
                minCost_memo_rcrsn(cost, n - 2, dp));
  return ans;
}

// this is accepted optimal soln. it indicates that it has successfully removed
// the overlapping subproblems from it

// now, we'll try tabulation /bottom-up approach:
int minCost_tab_rcrsn(vector<int> &cost, int n) {

  vector<int> dp(n + 1, -1);

  // base cases :
  dp[0] = cost[0];
  dp[1] = cost[1];

  // rest the values with for loop :
  for (int i = 2; i <= n; i++) {
    dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
  }

  return dp[n];
}

int minCost_tab(vector<int> cost) {

  int n = cost.size();
  return minCost_tab_rcrsn(cost, n);
}

// tabulation part 2 : if we can edit input values only :
int minCost_tab2(vector<int> &cost) {
  int n = cost.size();

  for (int i = 2; i < n; i++) {
    cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
  }
  return min(cost[n - 1], cost[n - 2]);
}

// --> space optimization :
int minCost_space_opt(vector<int> &cost) {

  int n = cost.size();
  int prev0 = cost[0];
  int prev1 = cost[1];

  for (int i = 2; i < n; i++) {
    // n is excluded in for loop bcz we don't have to pay for n-th stair
    int curr = cost[i] + min(prev0, prev1);
    prev0 = prev1;
    prev1 = curr;
  }

  return min(prev0, prev1);
}