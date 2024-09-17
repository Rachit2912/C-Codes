#include "062 Tree Basics.cpp"
#include <iostream>
#include <map>
#include <queue>
using namespace std;

// MIN. TIME TO BURN A TREE : 
// from target node it's spread out to all its nodes and during each node time++ is performed ,then find the total time 
/*
algo : 
i) pehle 1 mapping bnayenge node to its parents, jisme saare nodes or unke parents honge 
ii) find target node 
iii) ab yha se traversal start krenge or 1 node k parent,left child & right child ko visit krenge 
iv) during this, we'll 1 map for checking if a node is visited or not and along with this we'll add new members if unvisited in the queue
v) if enqueue is performed we'll increase the time else not
vi) return the time 
*/

// i) mapping of nodes to their parents & finding the target node : 
//  we are doing l.o.t and by this we'll also find the target node and will also map the child to their parents in the given map 
node* childToParentsJODO(node* root,int target,map<node*, node*> &nodeToParents){
    node* result = NULL;
    nodeToParents[root] = NULL;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
    node* frontNode = q.front();
    q.pop();

    if(frontNode->data == target){ result = frontNode;
    }

    if(frontNode->left){
        nodeToParents[frontNode->left] = frontNode;
        q.push(frontNode->left);
    }

    if (frontNode->right) {
        nodeToParents[frontNode->right] = frontNode;
        q.push(frontNode->right);
    }
    }
    return result;
}

// burning tree fn. : 
void startBurning(node* root,map<node*, node*> &nodeToParents, int &time){
    map<node*, bool> visited; // map for tracking if a node is visited or not 
    queue<node*> q;

    q.push(root);
    visited[root] = true;
    
    while (!q.empty()) {
    int size = q.size();
    bool enqueue = false;
    
    // infecting the left child, right child and parent child also of the given node : 
    for(int i =0; i<size; i++){
        node* frontNode = q.front();
        q.pop();

        if(frontNode->left && !visited[frontNode->left]){
            q.push(frontNode->left);
            visited[frontNode->left] = true;
            enqueue=true;
        }

        if(frontNode->right && !visited[frontNode->right]){
            q.push(frontNode->right);
            visited[frontNode->right] = true;
            enqueue=true;
        }

        if(nodeToParents[frontNode] && !visited[nodeToParents[frontNode]]){
            q.push(nodeToParents[frontNode]);
            visited[nodeToParents[frontNode]] = true;
            enqueue = true;
        }

    }

    // agar enqueuing hui h to : 
    if (enqueue) {
        time++ ;
    }

}
}


// driver code : 
int burningTree(node* root,int target){
    int time = 0;
    map<node*, node*> nodeToParents;
    node* targetNode = childToParentsJODO(root, target, nodeToParents);
    startBurning(targetNode,nodeToParents,time);
    return time;
}



int main(){
return 0;
}
