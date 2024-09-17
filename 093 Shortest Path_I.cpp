#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

// SHORTEST PATH IN UNDIRECTED GRAPHS :
/*
--> using bfs :
- hme mainly bss hr node  ka parent pta hona chahiye to find min. distance b/w
any 2 nodes
- islye hm bfs fn. ko run krenge using visited, parent, queue & adjList
- or fir destination node se parent array me backtrack krte krte shortest
distance nikal lenge
- T.C & S.C : O(n+e)
*/

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s,
                         int t) {

  // create adjList :
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    adj[edges[i].first].push_back(edges[i].second);
    adj[edges[i].second].push_back(edges[i].first);
  }

  // bfs for each node :
  unordered_map<int, bool> visited;
  unordered_map<int, int> parent;
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while (!q.empty()) {
    int frontNode = q.front();
    q.pop();

    for (auto n : adj[frontNode]) {
      if (!visited[n]) {
        visited[n] = true;
        parent[n] = frontNode;
        q.push(n);
      }
    }
  }

  // prepare shortest path :
  vector<int> ans;
  int curr = t;
  ans.push_back(t);
  while (curr != s) {
    curr = parent[curr];
    ans.push_back(curr);
  }

  // reversing the final ans :
  reverse(ans.begin(), ans.end());
  return ans;
}
