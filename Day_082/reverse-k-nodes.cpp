/*
PROBLEM: Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a 
multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed 
*/ 
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Base case
        if(head==NULL)
        {
            return NULL;
        }
        struct node* curr = head;
        struct node* prev = NULL;
        struct node* next = NULL;
        int count = 0;
        // reverse k nodes
        while(curr!=NULL && count<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        // Recursion call for next k nodes
        // Join it to curr head of reversed node 
        // (head)1->2->.... After recursion becomes 2->1 (head)->.....
        if(next!=NULL) head ->next = reverse(next, k);
        return prev;
        
    }
};