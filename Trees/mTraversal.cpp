#include<bits/stdc++.h>
using namespace std;

//Class for the treeNode
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left  = NULL;
        this->right = NULL;
    }
};

void LevelOrderTraversal(Node *root){
    //base case
    if(root == NULL){
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

void morrisTraversal(Node* root){
    if(root==NULL){
        return;
    }
    Node* current = root;
    while(current!=NULL){
        if(current->left == NULL){
            cout<<current->data<<" ";
            current = current -> right;
        }
        else{
            Node* prev = current->left;
            while(prev->right && prev->right != current){
                prev=prev->right;
            }
            if(prev->right == NULL){
                prev->right = current;
                current = current->left;
            }else{
                prev->right=NULL;
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right  = new Node(8);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    LevelOrderTraversal(root);
    morrisTraversal(root);

    return 0;
}