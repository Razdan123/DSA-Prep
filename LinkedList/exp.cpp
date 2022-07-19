//Including the header -->>>>>>>> for the C++ Program

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};


//Function to declatre a new node in linked list at Tail.
void insertAtTail(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp; 
    }
    else{
        //creating new node
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}


//Printing the linked list you created.
void printingLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


void insertAttail(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
} 
 
Node* deleteDuplicates(Node* A) {
    Node* temp = A;
    Node* head = NULL;
    Node* tail = NULL;
    while(temp!=NULL){
        if(temp->data != temp->next->data){
            insertAttail(head,tail,temp->data);
        }
        temp = temp->next;
    }
    return head;   
}

int main(){
    
   Node* A = new Node(1);
   A->next->data = 2;
   A->next->next->data = 3;
   A->next->next->next->data = 3;
   A->next->next->next->next->data = 4;
   deleteDuplicates(A);
   printingLL(A);

    return 0;
}