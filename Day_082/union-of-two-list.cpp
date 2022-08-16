struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int> s;
    Node* temp1 = head1;
    while(temp1!=NULL)
    {
        s.insert(temp1->data);
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while(temp2!=NULL)
    {
        s.insert(temp2->data);
        temp2 = temp2->next;
    }
    Node *head=NULL,*t;
    for(auto i : s)
    {
        Node *temp=new Node(i);
        if(head==NULL)
        {
            head=temp;
            t=temp;
        }
        else
        {
            t->next=temp;
            t=temp;
        }
    }
    
    return head;
}
