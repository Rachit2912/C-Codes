#include "062 Tree Basics.cpp"
#include <cstddef>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// zig zag traversal :
// 1 level from left to right and then next level from right to left and so
// on... we'll use level order iterative approach only with the modification
// that we'll use a flag here for direction control we'll use queue with
// iterative approach we'll use a flag for the direction control either left to
// right or right to left
vector<int> zigZagBT(node *root) {
  vector<int> result;

  if (root == NULL)
    return result;

  queue<node *> q;
  q.push(root);

  // flag for the direction control :
  bool leftToRight = true;

  while (!q.empty()) {

    int size = q.size();
    vector<int> ans(size);

    // har level ko process krna h
    for (int i = 0; i < size; i++) {
      node *frontNode = q.front();
      q.pop();

      int index = leftToRight ? i : size - 1 - i;
      ans[index] = frontNode->data;

      if (frontNode->left) {
        q.push(frontNode->left);
      }

      if (frontNode->right) {
        q.push(frontNode->right);
      }
    }

    // direction change :
    leftToRight = !leftToRight;

    for (auto i : ans) {
      result.push_back(i);
    }
  }

  return result;
}

// BOUNDARY TRAVERSAL :
// traversing all the boundary nodes in cw or acw manner :
// divide it in 3 parts :
// left part (without leaf nodes), all leaf nodes, right part (in reverse order
// and without leaf nodes)

// left part fn. (wihtout leaf nodes) :
void left_part(node *root, vector<int> &ans) {

  // base case :
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
    return;

  // sabse pehle store krenge bcz we want in same order as rcrsn tree :
  ans.push_back(root->data);

  if (root->left) {
    left_part(root->left, ans);
  }

  else {
    left_part(root->right, ans);
  }
}

// all leaf nodes fn. :
void leaf_nodes(node *root, vector<int> &ans) {

  // base case :
  if (root == NULL)
    return;

  // leaf node :
  if (root->left == NULL && root->right == NULL) {
    ans.push_back(root->data);
    return;
  }

  leaf_nodes(root->left, ans);
  leaf_nodes(root->right, ans);
}

// right part (in reverse order and without leaf nodes) :
void right_part(node *root, vector<int> &ans) {

  // base case :
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
    return;

  if (root->right) {
    right_part(root->right, ans);
  } else {
    right_part(root->left, ans);
  }

  // sabse baad me store krenge bcz we want to store data in opposite order as
  // of rcrsn tree :
  ans.push_back(root->data);
}

// main driver fn. :
vector<int> boundaryBT(node *root) {
  vector<int> ans;

  if (root == NULL)
    return {};

  ans.push_back(root->data);

  // left part ko store :
  left_part(root->left, ans);
  // leaf nodes in left subtree :
  leaf_nodes(root->left, ans);
  // leaf nodes in right subtree:
  leaf_nodes(root->right, ans);
  // right part ko store in reverse order :
  right_part(root->right, ans);

  return ans;
}

// VERTICAL ORDER TRAVERSAL OF BT :
// we'll use a mapping from horizontal distance to level wise nodes
// level wise nodes will be a mapping from level  number to list of nodes at
// that level now, we'll obviously use queue for the level wise ordering of
// nodes but this time we'll use different type of queue we'll use :
// queue<pair<node*, pair<int,int>>>; here,1st is node, 2nd is pair consisting
// of 2 integers in which first is our horizontal distance & other one is level
// no. bcz we'll need atleast horizontal distance and level no for inserting
// data into our mapping .

vector<int> verticalOrderBT(node *root) {

  map<int, map<int, vector<int>>> nodes;
  //  horizontal_distance, level_no, list_of_nodes
  queue<pair<node *, pair<int, int>>> q;
  vector<int> ans;

  if (root == NULL)
    return {};

  q.push(make_pair(root, make_pair(0, 0)));

  while (!q.empty()) {
    pair<node *, pair<int, int>> temp = q.front();
    q.pop();
    node *frontNode = temp.first;
    int horizontal_distance = temp.second.first;
    int level_no = temp.second.second;

    (nodes[horizontal_distance])[level_no].push_back(frontNode->data);
    // map syntax

    if (frontNode->left) {
      q.push(make_pair(frontNode->left,
                       make_pair(horizontal_distance - 1, level_no + 1)));
    }

    if (frontNode->right) {
      q.push(make_pair(frontNode->right,
                       make_pair(horizontal_distance + 1, level_no + 1)));
    }

    for (auto i : nodes) {
      for (auto j : i.second) {
        for (auto k : j.second) {
          ans.push_back(k);
        }
      }
    }
  }
  return ans;
}

// TOP VIEW :
// level order traversal krenge just like as vertical view me kia tha but yha
// itna difference hoga ki jb mappping krenge horizontal distance ki to vo keval
// 1 int se krenge naaki pure vector se jese vertical view wale question me kia
// tha bcz yha hme sirf 1st wala element chahiye us fix horizontal distance pr
vector<int> topView(node *root) {

  vector<int> ans;
  // base case :
  if (root == NULL)
    return ans;

  map<int, int> topNode;
  // horizontal distance | node ki mapping
  queue<pair<node *, int>> q;
  // node | horizontal distance

  q.push(make_pair(root, 0));

  while (!q.empty()) {
    pair<node *, int> temp = q.front();
    q.pop();

    node *frontNode = temp.first;
    int hd = temp.second;

    // if one value is present for a horizontal_distance, then discard all the
    // other entries
    if (topNode.find(hd) == topNode.end()) {
      topNode[hd] = frontNode->data;
    }

    if (frontNode->left) {
      q.push(make_pair(frontNode->left, hd - 1));
    }

    if (frontNode->right) {
      q.push(make_pair(frontNode->right, hd + 1));
    }
  }

  for (auto i : topNode) {
  ans.push_back(i.second);
  }
  return ans;
}

// BOTTOM VIEW :
// isme approach same hi h same as like topview 
// yha pr hm map me uss node ko baar baar update krte rhenge taaki end tk vo har node bottom ka node hoga map me 
// just copy past the above code and remove the condition for inserting the node data in the map  that's it 
vector<int> bottomView(node* root){
    vector<int> ans;
  // base case :
  if (root == NULL)
    return ans;

  map<int, int> topNode;
  // horizontal distance | node ki mapping
  queue<pair<node *, int>> q;
  // node | horizontal distance

  q.push(make_pair(root, 0));

  while (!q.empty()) {
    pair<node *, int> temp = q.front();
    q.pop();

    node *frontNode = temp.first;
    int hd = temp.second;

    // if one value is present for a horizontal_distance, then discard all the
    // other entries
    // if (topNode.find(hd) == topNode.end()) {
      topNode[hd] = frontNode->data;
    // }
    /* BAS ISS CONDITION KO COMMENT KRDO AND IT'S DONE */

    if (frontNode->left) {
      q.push(make_pair(frontNode->left, hd - 1));
    }

    if (frontNode->right) {
      q.push(make_pair(frontNode->right, hd + 1));
    }
  }

  for (auto i : topNode) {
  ans.push_back(i.second);
  }
  return ans;    
}

// LEFT VIEW OF A BT : 
// har level ki left ya first node print krni h bsss
// now, this can be solved using l.o.t and recursion 
//l.o.t is quite obvious so we'll try here rcrsive :

// rcrsn fn. for left view :
void leftView_rcrsn(node* root,vector<int> &ans, int level){

    // base case :
    if(root == NULL) return;

    // condition for checking if we have entered the new lvl or not 
    if(level == ans.size()) ans.push_back(root->data);

    leftView_rcrsn(root->left, ans, level+1);
    leftView_rcrsn(root->right, ans,level+1);

}

// driver code for left view :
vector<int> leftView(node* root){
    vector<int> ans;
    leftView_rcrsn(root,ans,0);
    return ans;
}



// RIGHT VIEW OF A BT : 
// isme bhi same approach as left view but sirf 1 change krenge ki wha pr fn. call rcrsn me left to right jaa rhi thi bss yhi change krna h 
//yha pr vo fn. call right to left jaayegi bss yhhi change h 

// rcrsn fn. for left view :
void rightView_rcrsn(node* root,vector<int> &ans, int level){

    // base case :
    if(root == NULL) return;

    // condition for checking if we have entered the new lvl or not 
    if(level == ans.size()) ans.push_back(root->data);

    rightView_rcrsn(root->right, ans,level+1);
    rightView_rcrsn(root->left, ans, level+1);

}

// driver code for right view : 
vector<int> rightView(node* root){
    vector<int> ans;
    rightView_rcrsn(root,ans,0);
    return ans;
}

// now, we can also solve this problem using l.o.t. approach: 
// the main idea behind both the approaches is same 
// just their implementation methods and data structures used are the only difference
vector<int> rightView_lot(node* root){

    vector<int> ans;
    map<int,int> rightView;
    // horizontal distance | node ki value

    if(root == NULL) return{};

    queue<pair<node*,int>> q;
    // node | horizontal distance 
    q.push({root,0});

    while (!q.empty()) {
    node* frontNode = (q.front()).first;
    int hd = (q.front()).second;
    q.pop();

    if(rightView.find(hd) == rightView.end()){
        rightView[hd] = frontNode->data;
        }
    
    // right view ka que.h isliye hm right se left ki or call marenge bcz right se bharna start krna zyada better rhega
    // and bss yhi order change ho jayega in left view bcz wha left se bharna better rhega and rcrsn bhi left se right ki or call krna optimal rhega
    if(frontNode->right) q.push({frontNode->right,hd + 1});

    if(frontNode->left) q.push({frontNode->left,hd-1});

    }

    for(auto i : rightView){
    ans.push_back(i.second);
    }

    return ans;
}
// same approach can be modified and used for the left view also 
// sbki time complexity dekhni h and check the impact of map on time complexity 

// DIAGONAL VIEW OF A BINARY TREE : 
// iske 2 methods h : 
// 1st iterative and using the vertical order approach : 
/* 
isme hm same whi approach use krenge vertical order wali and bss itna change kr denge ki right jate time horizontal distance change nhi hogi and left jate time increase ho jayegi horizontal distance and usko queue ki help se implement kr denge 
*/
vector<int> diagonalBT_app1(node* root){
  vector<int> ans;
  if(root == NULL) return ans;

  map<int, vector<int>> diagonal;
  // hd | nodes ka vector 
  queue<pair<node*, int>> q;
  // nodes @ that hd | hd 
  q.push({root,0});
  diagonal[0].push_back(root->data);

  while (!q.empty()) {
    node* frontNode = (q.front()).first;
    int hd = (q.front()).second;
    q.pop();

    if(frontNode->left){
      q.push({frontNode->left,hd+1});
      diagonal[hd+1].push_back(frontNode->left->data);
    }

    if(frontNode->right){
      q.push({frontNode->right,hd});
      diagonal[hd].push_back(frontNode->right->data);
    }

  }

  for (auto i : diagonal) {
    for (auto j : i.second) {
        ans.push_back(j);
    }
  }

  return ans;
}

//Approach2 : 
/*
yeh bhi simple approach h ki root se start kro and left ko queue me store krte rho and current node k right ko ans me store krte rho until u get a null and usko traverse krte during jitne bhi left aayenge sbko queue me push krte rho 
bottom line : left ko store krte rho queue me and right ko ans me store krte rho 
*/
vector<int> diagonalBT_app2(node* root){
  vector<int> ans;
  if(root == NULL) return {};

  queue<node*>  q;
  q.push(root);

  while (!q.empty()) {
    node* frontNode=q.front();
    q.pop();

    while (frontNode != NULL) {
      if (frontNode->left) {
          q.push(frontNode->left);
      }

      ans.push_back(frontNode->data);
      frontNode = frontNode->right;
    }
  }
  return ans;
}

int main() {
return 0;
}