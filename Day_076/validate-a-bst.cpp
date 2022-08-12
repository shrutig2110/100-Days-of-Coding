/*
PROBLEM: Validate a Binary search tree
*/ 
class Solution {
public:
    bool bst(TreeNode* root, int *lower, int * upper)
    {
        if(!root) return true;
        if(lower && root->val<=*lower || upper && root->val>=*upper) return false;
        return bst(root->left, lower, &(root->val)) && bst(root->right,&(root->val), upper);
    }
    bool isValidBST(TreeNode* root) 
    {
      return bst(root, NULL, NULL);
    }
    
};