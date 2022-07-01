#include <bits/stdc++.h> 
/* 2ND APPROACH - USING FAST AND SLOW POINTERS 
   Fast pointer increments by 2 and reaches the end of list while the slow increments with 1 and reaches 
   the middle of list 
*/
Node* getLength(Node* &head)
{
    if( head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast !=NULL)
    {
        fast = fast->next;
        // In case of even length of list if NULL already reached the last then, only slow pointer will be updated
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
    /* 1st APPROACH FUNCTION - ITERATVE*/ 
// int getlength(Node* head)
// {
//     int count = 0;
//     while(head!=NULL)
//     {
//         count++;
//         head = head->next;
//     }
//     return count;
// }
Node *findMiddle(Node *head) {

    /*  2nd APPROACH - ITERATIVE WITH FAST & SLOW POINTERS  */ 
        getLength(head);

    /*  1st APPROACH - ITERATIVE   */
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