/*
In Binary Search Tree -->
1. InOrder Traversal is always a sorted array;
2. Right Subtree is Strictly greater that the root node && Left Subtree is always smaller than the root node
*/


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildthetree(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(root->data < d){
        root->right = buildthetree(root->right,d);
    }
    else{
        root->left = buildthetree(root->left,d);
    }
    return root;
}

void createBST(Node* &root){
    int d;
    cin>>d;
    while(d!=-1){
    root = buildthetree(root,d);
    cin>>d;
    }
}

void LOR(Node* root){
    //base case
    if(root == NULL){
        return ;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

int main(){
    Node *root =NULL;
    cout<<"Enter the elements : "<<endl;
    createBST(root);
    LOR(root);
    return 0;
}