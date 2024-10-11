#include <bits/stdc++.h>
using namespace std;

// HOUSE ROBBERY PROBLEM :
// boht saare houses circcular queue me arrange h ab inme se max. money rob krni
// h pr shrt h ki 2 adj. houses rob kr liye to police ajayegi and first and last
// houses are also neighbours so it's like last ques. only, max. sum of non adj.
// elts. but 1st and last sath me na ho itna make sure 2 case bna lo : first
// skip, last skip & return the max. of both

// same code from 106:
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
int houseRobber(vector<int> &valueInHouse) {
  int n = valueInHouse.size();
  if (n == 1)
    return valueInHouse[0];

  vector<int> first, last;
  for (int i = 0; i < n; i++) {
    if (i != n - 1) {
      first.push_back(valueInHouse[i]);
    }
    if (i != 0) {
      last.push_back(valueInHouse[i]);
    }
  }
  return max(solve(first), solve(last));
}

We can do it in O(1) space complexity by just passing starting and ending index
    of the array.-- -> as given,
    array is circular->robber can rob from 1st house to(n - 1) th house OR->from
    2nd houst to nth house to avoid police

    c++ code as follows :

    long long solve(vector<int> &nums, int stInd, int n) {
  long long prev2 = 0;
  long long prev1 = nums[stInd];
  for (int i = stInd + 1; i <= n; i++) {
    long long ans = max(nums[i] + prev2, prev1);
    prev2 = prev1;
    prev1 = ans;
  }
  return prev1;
}

long long int houseRobber(vector<int> &valueInHouse) {
  int n = valueInHouse.size();
  if (n == 1) {
    return valueInHouse[0];
  }

  // case 1 he robbs 1st house and excludes last
  // 0-based indexing
  long long sum1 = solve(valueInHouse, 0, n - 2);

  // case2 he excludes 1st and robbs last
  // 0-based indexing
  long long sum2 = solve(valueInHouse, 1, n - 1);
  return max(sum1, sum2);
}
