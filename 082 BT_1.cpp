#include <iostream>
#include <string>
#include <vector>
using namespace std;

// BACKTRACKING DAY - 1 :
/*
- (0,0) SE  (n-1,n-1) tk pahuchna h hmko
- and wha tk saare paths ko return krna h
- u,l,r,d movement kr skte h
- sbhi paths ko lexicographic order me dena
*/

bool isSafe(int newx, int newy, vector<vector<bool>> &vis,
            vector<vector<int>> &arr, int n) {

  if (newx >= 0 && newx < n && newy >= 0 && newy < n && vis[newx][newy] != 1 &&
      arr[newx][newy] == 1) {
    return true;
  }
  return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
           vector<vector<bool>> &vis, string path) {

  // base case : reached the destination
  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }

  // lexicographic order :
  vis[x][y] = 1;

  // down:
  if (isSafe(x + 1, y, vis, arr, n)) {
    solve(x + 1, y, arr, n, ans, vis, path + 'D');
  }

  // left:
  if (isSafe(x, y - 1, vis, arr, n)) {
    solve(x, y - 1, arr, n, ans, vis, path + 'L');
  }

  // right:
  if (isSafe(x, y + 1, vis, arr, n)) {
    solve(x, y + 1, arr, n, ans, vis, path + 'R');
  }

  // up:
  if (isSafe(x - 1, y, vis, arr, n)) {
    solve(x - 1, y, arr, n, ans, vis, path + 'U');
  }

  vis[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
  vector<string> ans;
  vector<vector<bool>> visited(n, vector<bool>(n, 0));
  string path = "";
  // edge case : if src only is 0:
  if (arr[0][0] == 0) {
    return ans;
  }

  solve(0, 0, arr, n, ans, visited, path);
  return ans;
}