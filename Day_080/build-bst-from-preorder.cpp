/*
PROBLEM: Build a binary search tree from a preorder traversal
*/
*/ 
class Solution {
public:
    TreeNode* buildtree(vector<int>& preorder, int &i, int maxv, int n)
    {
        if(i==n || preorder[i]>maxv) return NULL;
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = buildtree(preorder, i, node->val,n);
        node->right = buildtree(preorder, i, maxv,n);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int max_val = INT_MAX;
        int i =0;
        TreeNode* root = buildtree(preorder, i, max_val,preorder.size());
        return root;
    }
};