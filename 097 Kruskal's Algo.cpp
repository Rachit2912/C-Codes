#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

// DISJOINT SET :
/*
- type of d.s. used to find if the two nodes of a graph are of the same
components of the graph or different components
- will be using for implementation of Kruskal' Algo of MST
- 2 imp. fn. : findParent() or findSet() && union() or unionSet()
- starting me sbhi distinct components honge and sbhi apne aap ke hi parents
honge
-  union by rank & path compression : dono diff. components k parents nikalo &
compare their ranks jiska rank smaller hoga usko parent[chota rank wala node] =
badi rank wala node
- & agr both ranks same h to kisiko kisi k saath bhi jod do
- agr 3 node h a <--- b <--- c to hm path compare krte waqt c ka parent b nhi a
ko lenge and path compression yhi ki direct c ko hm a se directly attach kr skte
h
- if 2 nodes k parents same h : same component else diff. components
*/

void initialize_disjointSet(int n) {
  vector<int> parent(n);
  iota(parent.begin(), parent.end(), 0); // starting me sb apne ap ke hi parents
                                         // h go and check it interesting !!!
  vector<int> rank(n, 0);
}

int findParent(vector<int> &parent, int node) {
  if (parent[node] == node) {
    return node;
  }
  return findParent(parent, parent[node]);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
  a = findParent(parent, a);
  b = findParent(parent, b);

  // compare ranks :
  if (rank[a] < rank[b]) {
    parent[a] = b;
  }

  else if (rank[a] > rank[b]) {
    parent[b] = a;
  }

  else {
    parent[b] = a;
    rank[a]++;
  }
}

// KRUSKAL'S ALGO :
/*
- for a given weighted graph : make a linear d.s and store wt,edge a, edge b and
sort it on the order of the wt
- starting me whi, sb apne aap ke hi parent honge
- ab 1-1 krke iteration krenge & agr 2 nodes diff. components se h to :
unionSet(a,b); else : ignore it
-
*/

int minimumSpanningTree(vector<vector<int>> &edges, int n) {

  vector<int> parent(n);
  iota(parent.begin(), parent.end(), 0); // starting me sb apne ap ke hi parents
                                         // h go and check it interesting !!!
  vector<int> rank(n, 0);

  sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
  }
  ); // using lambda fn.

  int mst_weight = 0;

  for (int i = 0; i < edges.size(); i++) {
    int a = findParent(parent, edges[i][0]);
    int b = findParent(parent, edges[i][1]);
    int wt = edges[i][2];

    if (a != b) {
      mst_weight += wt;
      unionSet(a, b, parent, rank);
    }
  }

  return mst_weight;
}

// T.C : O(e.log(e))
// S.C : O(e)