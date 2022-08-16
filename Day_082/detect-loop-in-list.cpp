/*
PROBLEM: Detect loop in linked list
*/ 
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        unordered_map<Node*,bool> isVisited;
        Node* temp = head;
        while(temp!=NULL)
        {
            if(isVisited[temp])
            {
                return 1;
            }
            isVisited[temp]= true;
            temp = temp->next;
        }
        return false;
        
    }
};