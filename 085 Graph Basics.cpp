#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// GRAPHS :
/*
- d.s. with comb. of nodes and edges
- types : (i) undirected : edges are not directed towards any node
(ii) directed : all edges are directed towards any node
- degree(node): uss node se kitni edges h
- indegree(node) : edges us node pr andar aa rhi h vo
- outdegree(node) : edges jo us node se bahar ki or jaa rhi h
- weighted edge : edge ka weight ho to vo weighted edge
- path : node A se node B ka tk jane ka rasta
cyclic graph :  esa path miljaye jisse ap 1 node ko 2 baar visit kr ske
- acyclic graph : jisme cyclic path na mile


- implement krne k 2 methods h :
(i) adjacency matrix : har node ko row or col pr dal do or jaha edge ho wha 1
nhi to 0 bhardo (ii) adjacency list : saare node likho or jisse connected h wo
sb list pori use node k samne likhdo and implement it using : map<int,list<int>>
or vector<vector<int>>

*/
template <typename T> class graph {

public:
  unordered_map<T, list<T>> adj;

  void addEdge(int u, int v, bool direction) {
    // direction = 0 -> Undirected graph
    // direction = 1 -> Directed Graph
    adj[u].push_back(v);
    if (direction == 0) {
      adj[v].push_back(u);
    }
  }

  void printAdjList() {
    for (auto i : adj) {
      cout << i.first << "-> ";
      for (auto j : i.second) {
        cout << j << ",";
      }
      cout << endl;
    }
  }
};

int main() {

  int n;
  cout << "enter no. of nodes " << endl;
  cin >> n;

  int m;
  cout << "enter no. of edges " << endl;
  cin >> m;

  graph<int> g;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v, 0);
  }

  g.printAdjList();

  return 0;
}

/*
- using adjacency list :
#include<bits/stdc++.h>
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> &
edges) { vector<int> padosi[n]; for(int i =0;i<m;i++){ int u = edges[i][0]; int
v = edges[i][1]; padosi[u].push_back(v); padosi[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
        for(int j = 0;j<padosi[i].size();j++){
            adj[i].push_back(padosi[i][j]);
        }
    }
    return adj;

}
*/