#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

// BRIDGES IN A GRAPH :
/*
- esi edge jo 2 disconnected components ko jodne ka kaam krti h, it means jis
edge ko todne pr no(connected components) increase ho jaye

-> brute force : 1-1 edge ko remove kro and using dfs connected components ka
no. check krlo

->optimized :
- 4 d.s. : discovery_time, lowest_time, parent, visited
- timer = 0 se start hoga or vertex 0 se start krenge or 1 par jayenge
- ab 1 par pahuchne ka disc_time & lowest_time dono hi 1 hoga
- pr jese hi agr second koi edge hogi jo ki back-edge hogi tb hm lowest_time ko
update kr denge by low_time[node] = min(low_time[node],disc_time[by_neighbour])
- or yehi hm hr waqt krenge jb return kr rhe honge
- or hr edge pr bridge ko check krlenge : low_time[by_neighbour] >
disc_time[node]
- this works bcz us 1 node tk jane ka yhi rasta hoga or na koi back-edge hogi jo
uska low_time kam kr ske isliye uska low_time > disc_time hoga
- or ese hi timer age badtha rhega
- T.C & S.C : O(n+e)
*/

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

  // create adjlist :
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }

  int timer = 0;
  vector<int> disc(v, -1);
  vector<int> low(v, -1);
  int parent = -1;
  unordered_map<int, bool> vis;
  for (int i = 0; i < v; i++) {
    vis[i] = false;
  }
  vector<vector<int>> result;

  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      dfs(i, parent, timer, disc, low, result, adj, vis);
    }
  }
  return result;
}

void dfs(int node, int &parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis) {

  vis[node] = true;
  disc[node] = low[node] = timer++;

  for (auto n : adj[node]) {

    if (n == parent) {
      continue;
    }

    if (!vis[n]) {
      dfs(n, node, timer, disc, low, result, adj, vis);
      low[node] = min(low[node], low[n]);

      // checking if edge is bridge:
      if (low[n] > disc[node]) {
        vector<int> temp;
        temp.push_back(node);
        temp.push_back(n);
        result.push_back(temp);
      }
    }

    // back-edges
    else {
      low[node] = min(low[node], disc[n]);
    }
  }
}