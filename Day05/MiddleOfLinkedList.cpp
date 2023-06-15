Node *findMiddle(Node *head) {

    if(head==NULL || head->next==NULL){return head;}

    Node* temp1 = head;

    Node* temp2 = head;

    while(temp1!=NULL && temp1->next!=NULL)

    {

        temp1 = temp1->next->next;

        temp2 = temp2->next;

    }

    return temp2;

}