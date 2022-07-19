/*
PROBLEM: Morris Traversal
*/ 
class Solution {
public:
    Node* find_predecessor(Node* root)
    {
        Node* pre = root->left;
        while(pre->right != NULL && pre->right != root)
        {
            pre = pre->right;
        }
        return pre;
    }
    vector<int> inOrder(Node* root)
    {
        vector<int> ans;
        Node* pred;
        Node* curr = root;
        while(curr != NULL)
        {
            // If root left not exists
            if(curr->left==NULL)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{
                // Go left and keep moving right till we encounter null
                pred = find_predecessor(curr);
                // Temp link creation between curr and predecessor
                if(pred->right == NULL)
                {
                    pred->right = curr;
                    // ans.push_back(curr->data);
                    curr = curr->left;
                }
                else{
                    // Temp link removal
                    pred->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};