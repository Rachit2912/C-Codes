#include <iostream>
#include <list>
#include <type_traits>
#include <unordered_map>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

// ARTICULATION POINTS :
/*
- esa node jisko remove krne par graph 2 ya zyada components me bt jayega
- node remove krna means uski edges ko bhi remove kr dena
-> brute force :
- remove each node and check for no. of components
- O(V^2) time complexity
- O(V) space complexity


-> optimized complexity : 
- same 4 d.s as they were in bridge question i.e disc_time, low_time, parents, visited
- starting me sb -1 and false h 
- low[nbr] >= disc[node] && parent!= -1 : it means it's the articulation point 
-  
*/

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool>&vis,unordered_map<int, list<int>> & adj, vector<int> &art_pt,int timer){

    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto n : adj[node]){
        if (n == parent) {
            continue;
        }

        if (!vis[n]) {
            dfs(n,node,disc,low,vis,adj,art_pt,timer);

            // check node for art_pt:
            if (low[n] >= disc[node] && parent != -1) {
                art_pt[node] = true;
            }
            child++ ;
        }

        else {
        low[node] = min(low[node],disc[n]);
        }
    }

    if (parent == -1 && child > 1) {
        art_pt[node] = 1;
    }
}

int main(){

    int n,e;
    vector<pair<int,int>> edges;
    // creating adj list : 
    unordered_map<int, list<int>> adj;

    for (int i =0; i<edges.size(); i++) {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> art_pt(n,0);

    for (int i =0; i<n; i++) {
        disc[i] = -1;
        low[i] = -1;
        vis[i] = false;
    }

    // dfs : 
    for (int i= 0; i<n; i++) {
        if (!vis[i]) {
            dfs(i, -1, disc, low, vis,adj, art_pt,timer);
        }
    }

    // print art_pt:
    cout<< "articulation points are as follows : "<<endl;
    for (int i =0; i<n; i++) {
        if (art_pt[i] != 0) {
            cout<<i<<" ";
        }
        cout<<endl;
    }





return 0;
}