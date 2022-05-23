// Finding the minimun and maximum value in BST
/*For finding the Min Value --> will go left of ->left of ->left of ..... untill the next left is NULL;
  For finding the Right Value --> will go right of ->right of ->right of ..... untill the next right is NULL;

  LETS CODE AND ROCK : Chalo recursion recursion khelte h // JAI MATA DI
*/

#include <bits/stdc++.h>
using namespace std;

// Defining a class for BST
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Fuction to build a BST from the values that were entered by user step by step
Node *buildtheBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = buildtheBST(root->right, d); // Agar d bada h root->data se to right ka part build kardo
    }
    else
    {
        root->left = buildtheBST(root->left, d); // Aur agar nhi h to left ka part build kardo
    }
    return root;
}

// Creating the fuction where user can Enter the value that is going to form the BST
void valuestoInsert(Node *&root)
{
    int d;
    cin >> d;
    while (d != -1)
    {                                // Condition that once it get -1 bulid has to terminate
        root = buildtheBST(root, d); // Taking the values from the user 'd' and pushing it to the funtion to create a BST
        cin >> d;
    }
}

// Funtion for level order traversal
void LevelTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// FINDING THE MINIMUM VALUE
void min_value(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    cout << temp->data << " --> is the minimum value of BST" << endl;
}

Node* mini_value(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
    // cout<<temp->data<<" --> is the minimum value of BST"<<endl;
}

// FINDING THE MAXIMUM VALUE
void max_value(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    cout << temp->data << " --> is the maximum value of BST" << endl;
}

// Function for deleting a Node from BST -->> IMPORTANT OPERATION IN BST
Node* DeleteNode(Node* root, int key)
{
    // base Case
    if (root = NULL)
    {
        return root;
    }

    if(root->data == key)
    {
        // 0 child case
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child case -->i) case - if only left child exists, ii) if only Right child exists
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child case
        if (root->left != NULL && root->right != NULL)
        {
            // findout the minimum value node to right subtree
            //  Node* temp = root->right;
            //  while(temp->left!=NULL){
            //      temp=temp->left;
            //  }
            //  root->data == temp->data;
            //  root->right = DeleteNode(root->right,key);
            //  return root;

            int mini = mini_value(root->right)->data;
            root->data = mini;
            root->right = DeleteNode(root->right, key);
            return root;
        }
    }
    else if (root->data > key)
    {
        root->left = DeleteNode(root->left, key);
        return root;
    }
    else
    {
        root->right = DeleteNode(root->right, key);
        return root;
    }
} 
///50 20 70 10 30 90 110 -1
int main()
{
    Node *root = NULL;

    // getting the value to be inserted in the BST from the user
    cout << "Enter the value to be inserted: " << endl;
    valuestoInsert(root);

    // Doing the Level Order Traversal for displaying our tree level wise
    LevelTraversal(root);

    // Finding the min Value
    min_value(root);

    // Finding the max Value
    max_value(root);

    // Deleting the node of the given value from BST
    int key = 30;
    root = DeleteNode(root, 30);

    LevelTraversal(root);

    return 0;
}