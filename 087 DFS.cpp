#include<iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

/*
- DEPTH FIRST SEARCH (DFS) : 
- DFS is a traversal approach in which we start from a node and explore as far as possible
along each branch before backtracking.
- DFS is often used in tree or graph traversal.
- DFS can be implemented using recursion or iteration.
*/

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare adjList : 
    unordered_map<int, list<int>> adj;
    for (int i = 0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i<V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

void dfs(int node,unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component){
    component.push_back(node);
    visited[node] = true;

    // hr connected node k lye recursive call : 
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

// T.C & S.C. : O(n)