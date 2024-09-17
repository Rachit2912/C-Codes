#include <float.h>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

/*
--> TOPOLOGICAL SORT : 
--> using dfs : 
- can be applied only on DAG : directed acyclic graph 
- linear ordering of vertices s.t. for every edge u-v : u always appears before v in that ordering
--> using dfs  : 
- same code hoga bs 1 stack extra use krenge jo recursion se return krte waqt uss node ko us stack me daal dega or wha se hme hmara topological sort mil jayega 
- T.C : O(n+e)
- S.C: O(n)
*/

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    //create adj list : 
    unordered_map<int, list<int>> adjList; 
    for (int i =0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }

    // call dfs topological sort fn. for all components : 
    vector<bool> visited;
    stack<int> s;
    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            topoSort(i,visited,s,adjList);
        }
    }
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

void topoSort(int node,vector<bool> &visited,stack<int> &s, unordered_map<int, list<int>> &adjList){
    visited[node] = true;

    for (auto n : adjList[node]) {
        if (!visited[n]) {
            topoSort(n,visited,s,adjList);
        }
    }

    // pushing the element in stack:
    s.push(node);
}


