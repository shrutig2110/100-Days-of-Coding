/*
PROBLEM: Lowest ancestor of binary tree
*/ 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//      Recursion method
        // if(root==NULL)
        // {
        //     return NULL;
        // }
        // if(root->val>p->val && root->val>q->val)
        // {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // else if(root->val<p->val && root->val<q->val)
        // {
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // else{
        //     return root;
        // }
        while(root!=NULL)
        {
            if(root->val>p->val && root->val>q->val)
            {
                root = root->left;
            }
            else if(root->val<p->val && root->val<q->val)
            {
                root = root->right;
            }
            else{
                break;
            }
        }
        return root;
        
    }
};