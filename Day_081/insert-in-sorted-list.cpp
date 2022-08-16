/*
PROBLEM: Insert in sorted list
*/ 
class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node* new_node = new Node(data);
        Node* temp = head;
        if(head->data > data)
        {
            new_node->next = temp;
            temp = new_node;
            return temp;
            // head = new_node;
        }
        while(temp->next)
        {
            if(data>=temp->data && data<=temp->next->data)
            {
                new_node->next = temp->next;
                temp->next = new_node;
                return head;
            }
            temp = temp->next;
        }
        if(temp->next==NULL)
        {
            temp->next = new_node;
            new_node->next=NULL;
        }
        return head;
    }
};