#include <climits>
#include <cstddef>
#include <iostream>
#include <regex>
#include <vector>
using namespace std;

// MIN. NO. OF COINS :
// you have array of coins available infinitely for making a desired amount so,
// find the min. no. of coins to make that desired amount with these coins only.

// simple recursion / dp :
int minCoins_app1(vector<int> &num, int x) {
  int ans = minCoins_rec_01(num, x);
  if (ans == INT_MAX) {
    return -1;
  }
  return ans;
}

int minCoins_rec(vector<int> &num, int x) {

  // base case :
  if (x == 0)
    return 0;
  if (x < 0) // non valid ans.
    return INT_MAX;

  int mini = INT_MAX;

  for (int i = 0; i < num.size(); i++) {
    int ans = minCoins_rec(num, x - num[i]);
    // ek ek coins ko reduce kr rhe h, main amount me se
    // taaki saare paths ko explore kr paye

    if (ans != INT_MAX) {
      // agr abhi tk invalid ans. nhi aya h toh mini ko update krte rhenge
      mini = min(mini, 1 + ans);
    }
  }
  return mini;
}

// dp + memoization :
int minCoins_app2(vector<int> &num, int x) {
  vector<int> dp(x + 1, -1);

  int ans = minCoins_rec_02(num, x, dp);
  if (ans == INT_MAX) {
    return -1;
  }
  return ans;
}

int minCoins_rec_02(vector<int> &num, int x, vector<int> &dp) {
  //  base case :
  if (x == 0) {
    return 0;
  }

  if (x < 0) {
    return INT_MAX;
  }

  if (dp[x] != -1) {
    return dp[x];
  }

  int mini = INT_MAX;

  for (int i = 0; i < num.size(); i++) {
    int ans = minCoins_rec_02(num, x - num[i], dp);

    if (ans != INT_MAX) {
      mini = min(mini, 1 + ans);
    }
  }
  dp[x] = mini;
  return mini;
}

// dp + tabulation :

int minCoins_app3(vector<int> &num, int x) { return minCoins_rec_03(num, x); }

int minCoins_rec_03(vector<int> &num, int x) {

  vector<int> dp(x + 1, INT_MAX);
  // yha pr bottom up approach use kr rhe h, isliye leaf nodes se
  // root tk jayenge, isliye abhi sare values INT_MAX h
  // and ese hi amount ko break kr krke hm 0 and -ve tk aaye the, ab hm whi use
  // krke upar jayenge
  dp[0] = 0;
  for (int i = 1; i <= x; i++) {
    // ab ese hi 1 amount ko solve krne ke 'k' jo coins array ki size h, utne
    // tarike honge isliye 'k' coins ko bhi 1-1 krke select krna pdega :
    for (int j = 0; j < num.size(); j++) {
      if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
        dp[i] = min(dp[i], 1 + dp[i - num[j]]);
      }
    }
  }

  if (dp[x] == INT_MAX) {
    return -1;
  }

  return dp[x];
}

// dp + space optimized :
// it doesn't make any sense as dp[i] = min(dp[i],dp[i-num[j]])
// if num[j] == 0 => dp[i] depends on dp[i]
// if num[j] == 1 => dp[i] depends on dp[i-1]
// if num[j] == 2 => dp[i] depends on dp[i-2]
// if num[j] == 3 => dp[i] depends on dp[i-3]
// & so on...
// so here again we have to store num.size() variables for controlling over it
// & that has same S.C : O(num.size()) as memoization/ tabulation
// so doesn't make any sense
