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


//Function to declatre a new node in linked list at Head.
void insertAtHead(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp; 
    }
    else{
        //creating new node
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

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

//Insertion at any Position 
void insertAtany(Node *&head, Node*&tail, int position, int d){
    Node * temp  = head;
    if(position == 1){
        insertAtHead(head,tail,d);
        return;
    }
    int pos = position-2;
    while(pos--){
        temp = temp->next;
    }

    //Inserting at last position
    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node* nodetoInsert = new Node(d);
    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
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

void Deletenode(Node* &head, int key){
    
    Node* temp = head;
    Node* prev = NULL;

    if(temp->data == key){
        head = temp->next;
        delete temp;
        return;
    }

    while(temp!=NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    //For last element
    if(temp==NULL){
        cout<<"Element not present"<<endl;
    }
    
    prev->next = temp->next;
    delete temp;

}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    //Calling the insert at head function
   // printingLL(head);
    insertAtHead(head,tail,5);
    printingLL(head);
    insertAtHead(head,tail,9);
    printingLL(head);
    insertAtTail(head,tail,4);
    printingLL(head);
    insertAtTail(head,tail,89);
    printingLL(head);
    insertAtany(head,tail,5,19);
    printingLL(head);
    Deletenode(head,9);
    printingLL(head);

    return 0;
}