#include <bits/stdc++.h>
using namespace std;

// CUT THE ROD INTO X,Y,Z :
// X+Y+Z = TOTAL LENGTH OF ROD
// now, maximize the length of the segments

//* normal recursion :
int cutSegments(int n, int x, int y, int z) {
  int ans = solve2(n, x, y, z, dp);
  return (ans < 0) ? 0 : ans;
}

int solve1(int n, int x, int y, int z) {
  // base case :
  if (n == 0)
    return 0;
  // -ve case :
  if (n < 0)
    return INT_MIN;

  int a = solve(n - x, x, y, z) + 1;
  int b = solve(n - y, x, y, z) + 1;
  int c = solve(n - z, x, y, z) + 1;

  return (max(a, max(b, c)));
}

//* memoization :
int solve2(int n, int x, int y, int z, vector<int> &dp) {
  // base case :
  if (n == 0)
    return 0;
  // -ve case :
  if (n < 0)
    return INT_MIN;

  if (dp[n] != -1)
    return dp[n];

  int a = solve2(n - x, x, y, z, dp) + 1;
  int b = solve2(n - y, x, y, z, dp) + 1;
  int c = solve2(n - z, x, y, z, dp) + 1;

  dp[n] = (max(a, max(b, c)));
  return dp[n];
}

int cutSegments2(int n, int x, int y, int z) {
  vector<int> dp(n + 1, -1);
  int ans = solve2(n, x, y, z, dp);
  return (ans < 0) ? 0 : ans;
}

//* tabulation :
int solve3(int n, int x, int y, int z) {
  vector<int> dp(n + 1, INT_MIN);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    if (i - x >= 0) {
      dp[i] = max(dp[i], dp[i - x] + 1);
    }
    if (i - y >= 0) {
      dp[i] = max(dp[i], dp[i - y] + 1);
    }
    if (i - z >= 0) {
      dp[i] = max(dp[i], dp[i - z] + 1);
    }
  }

  return (dp[n] < 0) ? 0 : dp[n];
}

int cutSegments3(int n, int x, int y, int z) {
  int ans = solve3(n, x, y, z);
  return (ans < 0) ? 0 : ans;
}

//* space optimization :
// not possible bcz dp[i] depends on dp[i-x],dp[i-y],dp[i-z] so we don't know
// the fixed values of x,y,z as it can be anything, so not possible here.