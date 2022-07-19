
    Node* tail = NULL;
    while(temp!=NULL){
        if(temp->data != temp->next->data){
            insertAttail(head,tail,temp->data);
        }
        temp = temp->next;
    }
    return head;   
}
