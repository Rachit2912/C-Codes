#include <climits>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

//  PRIM'S ALGO FOR MST :
/*
- 3 d.s : minDistance for storing the min distance to that node availble in the
whole graph,mst for checking if that node has been included or not in the mst
,parent for getting the parents a/c to min. distance rln.
- start with srcnode = 0 : mindistance[0] =0 & parent[0] = -1
then do the steps until each is marked under mst:
i) get the node with min. distance in mindistance array
ii) mst[node] = true
iii) find the adj[node] and find the distance from that node : if it's lesser
then update the distance in mindistance and update parent in parent array and
repeat
- T.C : O(n^2) --optimized--> O(n.logn) {using min heap}
- S.C : O(n+e)
*/

vector<pair<pair<int, int>, int>>
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {

  // create adjList:
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < n; i++) {
    adj[g[i].first.first].push_back({g[i].first.second, g[i].second});
    adj[g[i].first.second].push_back({g[i].first.first, g[i].second});
  }

  vector<int> minDistance(n + 1, INT_MAX); // bcz here node indexing starts from
                                           // 1 so we'll start from 1 directly
  vector<bool> mst(n + 1, false);
  vector<int> parent(n + 1, -1);

  // let's start from srcnode :
  int srcNode = 1;
  minDistance[srcNode] = 0;
  parent[srcNode] = -1;
  // now let's start the algo :
  for (int i = 0; i < n; i++) {
    // get the node with min. distance in mindistance array:
    int mini = INT_MAX;
    int u;
    for (int i = 1; i <= n; i++) {
      if (mst[i] == false && minDistance[i] < mini) {
        u = i;
        mini = minDistance[i];
      }
    }

    // mark min node as true :
    mst[u] = true;

    // check its adj nodes :
    for (auto n : adj[u]) {
      int v = n.first;
      int w = n.second;
      if (mst[v] == false && w < minDistance[v]) {
        parent[v] = u;
        minDistance[v] = w;
      }
    }
  }

  vector<pair<pair<int, int>, int>> ans;
  for (int i = 2; i <= n; i++) {
    ans.push_back({{parent[i], i}, minDistance[i]});
  }
  return ans;
}
