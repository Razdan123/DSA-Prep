//MorrisTraversal(A special kind of Traversal)
//We can find out inorder / postorder traversal without using recursion or stack

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

void LOT(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
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

void morrisTraversal(Node* root, vector<int> &inOrder){
    if(root==NULL){
        return;
    }
    Node* currNode = root;
    while(currNode!=NULL){
        if(currNode->left == NULL){
        inOrder.push_back(currNode->data);
        currNode = currNode->right;
    }
    else{
        Node* prev = currNode->left;
        while(prev->right !=NULL && prev->right!=currNode){
            prev = prev->right;
        }
        if(prev->right == NULL){
            prev->right = currNode;
            currNode = currNode->left;
        }
        else{
            prev->right = NULL;
            inOrder.push_back(currNode->data);
            currNode = currNode->right;
        }
    }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);   
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    //LOT(root);
    vector<int> inOrder;
    morrisTraversal(root,inOrder);
    for(int i=0; i<inOrder.size(); i++){
        cout<<inOrder[i]<<" ";
    }

    return 0;
}