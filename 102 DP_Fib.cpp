#include <iostream>
#include <vector>
using namespace std;

// DYNAMIC PROGRAMMING :
/*
requirements : i)optimal soln. for bigger problem has its way through finding
the soln for its subproblems i.e recursion ii) overlapping subproblems
- 2 approaches :
i) top-down : recursion + memoization
- isme recursion tree jb bnega tb usme jo jo bhi fn. ki return value ati jayegi
to usko store krte rhenge taki firse zrurt pdne pr hme vo value calc. nhi krni
pde isliye
- memoization : store the value of its subproblems in map/table
ii) bottom-up : tabulation
*/

// n-th fibonacci no. :
int n_fib(int n, vector<int> &dp) {

  // base case :
  if (n <= 1) {
    return n;
  }

  // checking if value is already there in dp array then no need to recalculate
  // it
  if (dp[n] != -1) {
    return dp[n];
  }

  // storing the returning values then returning the value
  dp[n] = n_fib(n - 1, dp) + n_fib(n - 2, dp);
  return dp[n];
}

int main() {
  int n;
  cin >> n;

  vector<int> dp(n + 1); // to store the returned values of fns.
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }

  cout << n_fib(n, dp) << endl;

  return 0;
}
// T.C & S.C : O(n) + O(n)

// bottom down approach :
/*
- i) dp array initialize kro
ii) base case check kro and vo values dp me daal do
iii) aage ki values ko bhi dp array ki help se access kr krke calculate krke
return krdo
- T.C & S.C : O(n)
*/

int fib_app2(int n) {

  // step 1 :
  vector<int> dp(n + 1);
  // step2 :
  dp[1] = 1;
  dp[0] = 0;

  // step3 :
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];

}

// space optimization :
/*
- puri array save krne ki need hi nhi h
- sirf 2 variables se start krke, usme store krte krte saara game ho jayega
-T.C : O(n)
- S.C : O(1)
*/

int fib_space_opt(int n) {
  int prev1 = 1;
  int prev2 = 0;

  if (n == 0) {
    return prev2;
  }

  for (int i = 2; i <= n; i++) {
    int curr = prev1 + prev2;
    prev2 = prev1;
    prev1 = curr;
  }

  return prev1;
}
