//Finding the minimun and maximum value in BST
/*For finding the Min Value --> will go left of ->left of ->left of ..... untill the next left is NULL;
  For finding the Right Value --> will go right of ->right of ->right of ..... untill the next right is NULL;

  LETS CODE AND ROCK : Chalo recursion recursion khelte h // JAI MATA DI
*/

#include<bits/stdc++.h>
using namespace std;

// Defining a class for BST
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

//Fuction to build a BST from the values that were entered by user step by step
Node* buildtheBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d>root->data){
        root->right = buildtheBST(root->right,d); // Agar d bada h root->data se to right ka part build kardo
    }
    else{
        root->left = buildtheBST(root->left,d);  // Aur agar nhi h to left ka part build kardo
    }
    return root;
}

//Creating the fuction where user can Enter the value that is going to form the BST
void valuestoInsert(Node* &root){
    int d;
    cin>>d;
    while(d!=-1){                    //Condition that once it get -1 bulid has to terminate
        root = buildtheBST(root,d); //Taking the values from the user 'd' and pushing it to the funtion to create a BST
        cin>>d;
    }
}

// Funtion for level order traversal
void LevelTraversal(Node *root){
    if(root==NULL){
        return ;
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

//FINDING THE MINIMUM VALUE
void min_value(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    cout<<temp->data<<" --> is the minimum value of BST"<<endl;
}

//FINDING THE MAXIMUM VALUE
void max_value(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    cout<<temp->data<<" --> is the maximum value of BST"<<endl;
}

int main(){
    Node* root = NULL;

    //getting the value to be inserted in the BST from the user
    cout<<"Enter the value to be inserted: "<<endl;
    valuestoInsert(root);

    //Doing the Level Order Traversal for displaying our tree level wise
    LevelTraversal(root);

    //Finding the min Value
    min_value(root);

    //Finding the max Value
    max_value(root);

    return 0;
}