/*
PROBLEM: Check if a binary tree is a subtree of another binary tree
*/ 
class Solution {
public:
bool isIdentical(TreeNode* root1, TreeNode* root2)
{
  if(!root1 || !root2)
    return root1==root2;
        
return(root1->val==root2->val && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
}
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if(!t) return true;
        if(isIdentical(s,t)) return true;
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};