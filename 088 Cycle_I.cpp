#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;
#include "085 Graph Basics.cpp"

/*
CYCLE DETECTION IN UNDIRECTED GRAPHS :
->> using bfs :
- we have to maintain 4 d.s. : adjList,queue,parent,visited
- queue for enqueuing the node's connected nodes
- parent: map to store kon kisa parent h
- visited: map to store kis node ko visit kr lia h
- 1-1 node ko travel krenge and uske neighbours ko queue me dalenge and visited
ko true krenge, and kon kiska parent ye store krenge and agr :
- node already visited h && vo us node ka parent h to thik h : neglect it
- pr agr node already visited h && vo uss node ka parent nhi h : cycle present
- T.C & S.C : O(n)
*/

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
  // create adjList :
  unordered_map<int, list<int>> adj;
  unordered_map<int, bool> visited;
  for (int i = 0; i < m; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // to handle disconnected graphs :
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      // --> for bfs :
      bool ans = isCyclicBFS(i, visited, adj);
      //--> for dfs :
      bool ans = isCyclicDFS(i, -1, visited, adj);
      if (ans) {
        return "Yes";
      }
    }
    return "No";
  }
}

bool isCyclicBFS(int srcnode, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj) {

  // parent d.s.:
  unordered_map<int, int> parent;
  parent[srcnode] = -1;
  visited[srcnode] = true;
  // queue d.s :
  queue<int> q;
  q.push(srcnode);

  while (!q.empty()) {
    int frontnode = q.front();
    q.pop();

    for (auto n : adj[frontnode]) {
      if (visited[n] && parent[frontnode] != n) {
        // then there must be cycle present in  it :
        return true;
      }

      else if (!visited[n]) {
        q.push(n);
        visited[n] = true;
        parent[n] = frontnode;
      }
    }
  }
  return false;
}

/*
--> using dfs :
- same condition : visited[neighbour] == true && parent[neighbour] != node ==>
cycle present
- visited[neighbour] ==> neglect it
- T.C & S.C : O(n)
*/

bool isCyclicDFS(int srcnode, int parent, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adj) {

  visited[srcnode] = true;
  for (auto n : adj[srcnode]) {
    if (!visited[n]) {
      bool cycleDetected = isCyclicDFS(n, srcnode, visited, adj);
      if (cycleDetected) {
        return true;
      }
    }

    else if (n != parent) {
      // cycle present :
      return true;
    }
  }
  return false;
}