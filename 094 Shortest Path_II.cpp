#include <climits>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <utility>
using namespace std;
#include "085 Graph Basics.cpp"

// SHORTEST PATH IN DAG :
/*
- we have to find shortest path from vertex0 to all vertices & if not possible
then assign -1 as distance
--> using topological sort :
- find topological sort of dag
- find the ans. using linear ordering
- iske baad 1 distance array bnao jisme sbki distance ki infinite rakhdo pr
srcnode ki distance ko 0 krdo
- ab linear order me se 1-1 element nikalo or uski distance dekho=> agr infinite
nhi h to, uski adjList check kro or usme agr unn nodes ki min. distance h jo
distance already distance array me pdi h to usko update krdo nhi to skip
*/

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges) {

  // create adj List :
  unordered_map<int, list<pair<int, int>>> adj;
  // pair for node and the weight of the edge
  for (int i = 0; i < m; i++) {
    adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    // inserting node -> node,weight of edge
  }

  // doing topological sort using dfs :
  int srcNode = 0;
  unordered_map<int, bool> visited;
  stack<int> s;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, adj, visited, s);
    }
  }

  // getting min. distance :
  vector<int> distance(n, INT_MAX);
  distance[srcNode] = 0;
  while (!s.empty()) {
    int top = s.top();
    s.pop();
    // checking if the distance is infinite or not :
    if (distance[top] != INT_MAX) {
      for (auto n : adj[top]) {
        distance[n.first] = min(distance[n.first], distance[top] + n.second);
      }
    }
  }

  for (int i = 0; i < distance.size(); i++) {
    if (distance[i] == INT_MAX) {
      distance[i] = -1;
    }
  }
  return distance;
}

void dfs(int node, unordered_map<int, list<pair<int, int>>> &adj,
         unordered_map<int, bool> &visited, stack<int> &s) {

  visited[node] = true;
  for (auto n : adj[node]) {
    if (!visited[n.first]) {
      dfs(n.first, adj, visited, s);
    }
  }
  s.push(node);
}