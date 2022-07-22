/*
PROBLEM : Partition a linked list around a value x, such that all nodes less than x come before all nodes greater 
than or equal to x.
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
//      Two dummy lists
        ListNode* left_list = new ListNode(0);
        ListNode* right_list = new ListNode(0);
//      Pointers to dummy lists
        ListNode* left_ptr = left_list;
        ListNode* right_ptr = right_list;
        ListNode* curr = head;
        
        while(curr)
        {
            if(curr->val <x)
            {
                left_ptr->next = curr;
                left_ptr = left_ptr->next;
            }
            else
            {
                right_ptr->next = curr;
                right_ptr = right_ptr->next;
            }
            curr = curr->next;
        }
        left_ptr->next = right_list->next;
        right_ptr->next = NULL;
        return left_list->next;
        
    }
};