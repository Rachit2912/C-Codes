#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
#include "085 Graph Basics.cpp"

/*
--> TOPOLOGICAL SORT USING KAHN'S ALGO or using bfs : 
- algo :
i) find indegree of all nodes 
ii) make a queue and push all nodes with 0 indegree 
iii) do bfs : frontnode nikalo, pop kro, ans me daalo, fir uske neighbour nikalo 
- ab since, vo node          to uske neighbours ki indegree 1 kam ho jayegi, or jiski 0 ho jayegi usko fir queue me daal do 
- do it until queue becomes empty
- T.C : O(n+e)
- S.C : O(n+e)
*/

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    // create adj list :
    unordered_map<int, list<int>> adj;
    for (int i =0; i<e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    // find all indegrees : 
    vector<int> indegree(v);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++ ;
        }
    }

    // 0 indegree walo ko queue me daalo :
    queue<int> q;
    for (int i =0; i<v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // do bfs for queue.front() :
    vector<int> ans;

    while (!q.empty()) {
       int front = q.front();
       q.pop();

       ans.push_back(front);

       // neighbours indegree update :
       for (auto n : adj[front]){
            indegree[n]-- ;
            if (indegree[n] == 0) {
                q.push(n);
            } 
       }
    }
    return ans;
}