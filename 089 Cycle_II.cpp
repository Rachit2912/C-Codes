#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
#include "085 Graph Basics.cpp"

// CYCLE DETECTION IN DIRECTED GRAPHS : 
/*
--> using dfs :
- ye undirected jese same hi h, bss 1 or array maintain krni pdegi jo hogi dfsvisited jo ye btayegi ki vo wala node k lye dfs ka fn. call active h ya nhi bcz undirected me 1 bar visit hua to kaam hogya but yha direction specific h isliye ye sb maintain krna pdega 
- condition :vis[node] = true, dfs[node] = true : it means cycle present h 
*/

int detectCycleInDirectedGraphDFS(int n, vector < pair < int, int >> & edges) {
    // create adj list : 
    unordered_map<int, list<int>> adjList;
    for (int i =0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        // for directed graph :
        adjList[u].push_back(v);
        }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    // call dfs() for all components of graph :
    for (int i =1; i<=n; i++) {
        if (!visited[i]) {
            bool cycleFound = checkCycleDFS(i,visited,dfsVisited,adjList);
            if (cycleFound) {
                return true;
            }
        }
    }
    return false;
}


bool checkCycleDFS(int node, unordered_map<int, bool>&visited,unordered_map<int, bool>&dfsVisited,unordered_map<int, list<int>>adjList){

    visited[node] = true;
    dfsVisited[node] = true;

    for (auto n : adjList[node]) {
        if (!visited[n]) {
            bool cycleDetected = checkCycleDFS(n, visited, dfsVisited, adjList);
            if (cycleDetected) {
                return true;
            }
        }

        else {
            // already visited cases : 
            if (dfsVisited[n]) {
                return true;
            }
        } 
    }
    dfsVisited[node] = false;
    return false;
}
 
//  T.C : O(n+e) S.C : O(n)