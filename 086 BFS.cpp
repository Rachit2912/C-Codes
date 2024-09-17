#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

/*
- BFS : breadth first search :
- ek node se start kro or use node se jitne bhi node connected h usko ans. me
likhte rho and ese hi aage bdthe rho

- for that, we'll need : ek adjacency list us graph ki, ek visited map jo store
krega ki node visit hua h ya nhi, 1 queue jisme hm us node k sbhi pdosi ko
daalenge

step 1: if(!visited(node)) : then only do bfs()
step 2 : frontnode = srcnode
step 3 : frontnode ko queue se nikalo
step 4 : frontnode ko visited map me T krdo
step 5 : frontnode k sbhi padosiyon ko queue me daalo
step 6 : ese hi aage 1-1 krke frontnode nikalte rho queue se and do it until
queue isn't empty

- agr 1 graph me 2 ya zyada components h means ki disconnected graphs h to usme
for loop lgake sbhi nodes ko cover kr lenge
*/

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {

  // adjacecncy list :
  unordered_map<int, list<int>> adjList;
  vector<int> breadth_first_search;

  // visited map :
  unordered_map<int, bool> visited;

  // preparing adjacency list :
  prepareAdjList(adjList, edges);

  // traverse all components of a graph :
  for (int i = 0; i < vertex; i++) {
    if (!visited[i]) {
      bfs(adjList, visited, breadth_first_search, i);
    }
  }
}

// preparing adjacency list fn. :
void prepareAdjList(unordered_map<int, list<int>> &adjList,
                    vector<pair<int, int>> &edges) {
  // going through all edges & adding the entries to adjList :
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}

// bfs fn. :
void bfs(unordered_map<int, list<int>> &adjList,
         unordered_map<int, bool> visited, vector<int> &breadth_first_search,
         int node) {

  // queue initiation :
  queue<int> q;
  q.push(node);
  visited[node] = true;
  while (!q.empty()) {
    int frontNode = q.front();
    q.pop();
    breadth_first_search.push_back(frontNode);
    for (auto i : adjList[frontNode]) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
}

// T.C & S.C : O(node + edges)
