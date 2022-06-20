#include <bits/stdc++.h> 
Node* getLength(Node* &head)
{
    if( head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* slow = head;
    // Mves 2*times faster than slow
    Node* fast = head->next;
    // When fast reaches null, slow reached mid by moving n/2 steps;
    while(fast !=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
int getlength(Node* head)
{
    int count = 0;
    while(head!=NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
Node *findMiddle(Node *head) {
/*Approach 2(Two pointer) - Time Complexity - O(n/2)*/
        getLength(head);
/* Approach 1(Calculating length and middle)- Time Complexity - O(n) */
/*
    int len = getlength(head);
    int mid = ( len/2 ) ;
    Node* temp = head;
    int count=0;
    while(count<mid)
    {
        temp = temp->next;
        count++;
    }
    return temp;
*/
}