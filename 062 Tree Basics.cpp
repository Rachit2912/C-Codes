#include <cstddef>
#include<iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// building the tree using recursion :
node* buildTree(node* root){
    cout<<"enter the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    // -1 referred as NULL everywhere : 
    if (data == -1) {
          return NULL;
    }

    cout<<"enter data for inserting in left of "<<data<<" : "<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for inserting in right of "<<data<<" : "<<endl;
    root->right = buildTree(root->right);
    return root;
}

// printing level order traversal : 
void levelOrderTraversal(node* root){
    // base case : 
    if(root == NULL) return;
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
    node* temp = q.front();
    q.pop();

    if (temp == NULL) { // purana level complete traverse ho chuka hai
    cout<<endl;
    if (!q.empty()) {   //queue still has some child notes 
    q.push(NULL);
    }
    }


    else {
        cout<< temp->data <<" ";

        if (temp->left) {
        q.push(temp->left);
        }

        if (temp->right) {
        q.push(temp->right);
        }
    }

    }
}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}

// building the tree from the given level order traversal : 
node* buidlFromLevelOrder(node* root){
    queue<node*> q;
    cout<<"enter data for root : "<<endl;
    int data;
    cin>>data ; 
    root = new node(data);
    q.push(root);

    while (!q.empty()) {
    node* temp = q.front();
    q.pop();

    cout<<"enter left node for : "<< temp->data<<endl;
    int leftData;
    cin >> leftData;

    if (leftData != -1) {
        temp->left = new node(leftData);
        q.push(temp->left); 
    }


    cout<<"enter right node for :" << temp->data<<endl;
    int rightData;
    cin>>rightData;

    if (rightData != -1) {
    temp->right = new node(rightData);
    q.push(temp->right);
    }
}
return root;
}

// counting the leaf nodes for a given tree : 
void inOrderLeafNodes(node* root, int &count){
    // base case : 
    if(root == NULL){
        return;
    }

    inOrderLeafNodes(root->left,count);
    // left nodes : 
    if(root->left == NULL && root->right == NULL) count++ ;
    inOrderLeafNodes(root->right,count);
}


int noOfLeafNodes(node* root){
    int cnt = 0;
    inOrderLeafNodes(root, cnt);
    return cnt;
}

/*
int main(){

node* root = nullptr;
root = buildTree(root);

1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


cout<<"printing the level order traversal :"<<endl;
levelOrderTraversal(root);

cout << "inorder traversal is:  "<<endl;
inorder(root); 

cout << endl << "preorder traversal is:  "<<endl;
preorder(root); 

cout << endl << "postorder traversal is:  "<<endl;
postorder(root); 

return 0;
}


*/
