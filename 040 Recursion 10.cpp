#include <iostream>
using namespace std;

// rat in a mzae problem
/*
1 grid h jiske hr element me 0 or 1 h,jha 0 h wha nhi ja skte h only 1 pe hi jaa
skte h, to hme origin se end corner tk ke saare ways collect krne h or hmare pe
4 movements h : up,down,left,right

so it's like a 2-d matrix
approach :
to whi src se start krenge or recursively l,r,u,d check krenge or aage bdhte
jayenge or x and y coord. change hote jayenge as movement and usko path me add
krte rhenge or 1 visited matrix bhi bnayenge jo pura track rkhega ki hm kis
element pr pehle aa chuke h uska takki ans. repeat na ho

*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited,
            vector<vector<int>> &m) {
  if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) &&
      (m[x][y] == 1)) {
    return true;
  }

  else {
    return false;
  }
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y,
           vector<vector<int>> visited, string path) {

  // base case :
  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }

  visited[x][y] = 1;

  // 4 choices d,l,r,u
  // down
  int newx, newy;
  newx = x + 1;
  newy = y;
  if (isSafe(newx, newy, n, visited, m)) {
    path.push_back('D');
    solve(m, n, ans, newx, newy, visited, path);
    path.pop_back();
  }

  // left
  newx = x, newy = y - 1;
  if (isSafe(newx, newy, n, visited, m)) {
    path.push_back('L');
    solve(m, n, ans, newx, newy, visited, path);
    path.pop_back();
  }

  // right
  newx = x, newy = y + 1;
  if (isSafe(newx, newy, n, visited, m)) {
    path.push_back('R');
    solve(m, n, ans, newx, newy, visited, path);
    path.pop_back();
  }

  // up
  newx = x - 1, newy = y;
  if (isSafe(newx, newy, n, visited, m)) {
    path.push_back('U');
    solve(m, n, ans, newx, newy, visited, path);
    path.pop_back();
  }

  visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
  // Your code goes here
  vector<string> ans;

  if (m[0][0] == 0)
    return ans;

  int srcx = 0;
  int srcy = 0;

  // initialized with 0
  vector<vector<int>> visited(n, vector<int>(n, 0));

  string path = "";
  solve(m, n, ans, srcx, srcy, visited, path);
  sort(ans.begin(), ans.end());
}

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> m[i][j];
      }
    }
    Solution obj;
    vector<string> result = obj.findPath(m, n);
    sort(result.begin(), result.end());
    if (result.size() == 0)
      cout << -1;
    else
      for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
