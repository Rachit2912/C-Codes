#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

//  BELLMAN FORD ALGO :
/*
- used to find shortest path b/w src & dest vertex in a directed weighted graph
- graph may contain -vely weighted graphs
- dijskra's algo doesn't work on -vely weighted graph
- we'll use this algo on -ve weighted cycle but it shouldn't contain -ve cycles
: which gives variation in shortest distance everytime as we complete a loop of
the same path
- only applicable to directed graphs
- we can also find that does a graph contain -ve cycle or not
- algo :
i) we have to apply this formula (n-1) times on every edge :
dist[v] = min(dist[v], dist[u] + w(u,v))
ii) at last, we'll perform this formula one more time; if any value got updated
: -ve cycle present else : return shortest distance & at starting in distance
array : src node will be zero and all the other nodes will be at INT_MAX
- T.C : O(n*m) ; S.C : O(n)
*/

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

  vector<int> dist(n + 1, INT_MAX);
  dist[src] = 0;

  // bcz nodes # starts from 1
  for (int i = 1; i < n; i++) {
    // traverse on edge list :
    for (int j = 0; j < m; j++) {

      int u = edges[j][0];
      int v = edges[j][1];
      int w = edges[j][2];

      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  // -ve cycle checkpoint :
  bool updated = false;
  for (int j = 0; j < m; j++) {
    int u = edges[j][0];
    int v = edges[j][1];
    int w = edges[j][2];

    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      updated = true;
    }
  }

  if (!updated)
    return dist;
  return -1;
}