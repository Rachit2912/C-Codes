#include <iostream>
#include <queue>
using namespace std;
#include "085 Graph Basics.cpp"

// CYCLE DETECTION IN DIRECTED GRAPHS :
/*
-->USING Kahn's Algo (bfs) :
- it it applied only for DAG
- so converse is also true
- code will be same just
- T.C & S.C : O(n+e)
*/

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  // Write your code here.

  // Kahn's Algo :
  // create adj list :
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    adj[edges[i].first - 1].push_back(edges[i].second - 1);
    // bcz yha nodes 1 se start ho rhi h
  }

  // find all indegrees :
  vector<int> indegree(n);
  for (auto i : adj) {
    for (auto j : i.second) {
      indegree[j]++;
    }
  }

  // 0 indegree walo ko queue me daalo :
  queue<int> q;
  for (int i = 0; i < v; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  // do bfs for queue.front() :
  int cnt = 0;

  while (!q.empty()) {
    int front = q.front();
    q.pop();

    cnt++;

    // neighbours indegree update :
    for (auto n : adj[front]) {
      indegree[n]--;
      if (indegree[n] == 0) {
        q.push(n);
      }
    }
  }
  // agr cnt == n hogya : it means topological sort hogya : acyclic graph h
  return cnt != n;
}