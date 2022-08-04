/*
PROBLEM : Given a linked list, remove the n-th node from the end of list and return its head.
*/ 
class Solution {
public:
//    Can't use temp, prev method as we can't handle the condition if temp->next->next is null or not
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
//      Create a gap of n between fast and slow pointer
        for(int i=0;i<n;i++)
        {
            fast = fast->next;
        }
        if(!fast)
        {
           return head->next; 
        }
//      Now increment both pointers with a fix gap of n until fast reaches last node and slow will reach the nth           node from last
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
        
    }
};