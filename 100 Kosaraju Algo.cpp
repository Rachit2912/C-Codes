#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;
#include "085 Graph Basics.cpp"

// KOSARAJU'S ALGO : 
/*
- used to find 2 strongly connected components
- strongly connected components vo h jiske andar har node har node reach ho jaye 
- steps : 
i) find topological sort 
ii) reverse or transpose the graph 
iii) dfs on topological sort and count strongly connected components
- 
*/

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){

    // create adj list : 
    unordered_map<int, list<int>> adj;
    for (int i =0; i<edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }	

    // topological sort : 
    stack<int> s;
    unordered_map<int, bool> vis;
    for (int i =0; i<v; i++) {
        if (!vis[i]) {
            dfs(i,vis,s,adj);
        }
    }

    // transpose the graph : 
    unordered_map<int, list<int>> transpose ;
    for (int i =0; i<v; i++) {
        for (auto n : adj[i]) {
            transpose[n].push_back(i);
        }
    }


    // dfs call on topological ordering : 
    int count = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!vis[top]) {
            count++;
            reverse_dfs(top,transpose,vis);
        }
    }
    return count ;
    	
}

// topo sort : 
void dfs(int node,unordered_map<int, bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adj){

    vis[node] = true;
    for (auto n: adj[node]) {
        if (!vis[n]) {
            dfs(n, vis, s, adj);
        }
    }

    s.push(node);
}

// reverse dfs for last step : 
void reverse_dfs(int node, unordered_map<int, list<int>> &transpose, unordered_map<int, bool> &vis){
    vis[node] = true;
    for (auto n : transpose[node]) {
        if (!vis[n]) {
            reverse_dfs(n, transpose, vis);
        }
    }
}