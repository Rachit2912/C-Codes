#include <climits>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

// DIJKSTRA'S ALGO FOR SHORTEST PATH :
/*
- to find shortest path b/w vertex 'srcnode' and all the other vertices
- d.s : distance array, set for storing pair<min. distance,node>
- bs fir distance[srcnode] = 0 krdenge & set me insert krdenge {0,srcnode}
- fir set me se min. wala element uthate rhenge or uska distance agr INT_Max nhi
to min(vo distance, us node tk ka distance + weight of next node) ko dal denge
or same set me insert kr denge
- T.C : O(E.logV)
- S.C : O(n+e)
*/

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source) {

  // create adjList :
  unordered_map<int, list<pair<int, int>>> adj;
  // bcz it's a weighted graph
  for (int i = 0; i < vertices; i++) {
    adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
    adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
  }

  // distance array :
  vector<int> distance(vertices, INT_MAX);
  distance[source] = 0;
  // set for storing the pair<min. distance,node>
  set<pair<int, int>> s;
  s.insert({0, source});

  while (!s.empty()) {
    // get the min. distance node aka top & pop it from the set :
    auto top = *(s.begin());
    int topNode = top.second;
    int nodeDistance = top.first;
    s.erase(s.begin());

    // check the distance from that node and get the min distance for all the
    // nieghbours :
    for (auto n : adj[topNode]) {

      if (nodeDistance + n.second < distance[n.first]) {

        // finding the record :
        auto record = s.find({distance[n.first], n.first});

        // if record found, erase it :
        if (record != s.end()) {
          s.erase(record);
        }

        // distance update :
        distance[n.first] = nodeDistance + n.second;
        // push in set also :
        s.insert({distance[n.first], n.first});
      }
    }
  }
  return distance;
}

// we can also use priority queue (min. heap) instead of using set :
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source) {
  // Write your code here.
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < edges; i++) {
    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  vector<int> dist(vertices, INT_MAX);
  dist[source] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, source});

  while (!pq.empty()) {
    int topNode = pq.top().second;
    int nodeDist = pq.top().first;

    pq.pop();

    for (auto neighbour : adj[topNode]) {
      int v = neighbour.first;
      int weight = neighbour.second;

      if (dist[topNode] + weight < dist[v]) {
        dist[v] = dist[topNode] + weight;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}