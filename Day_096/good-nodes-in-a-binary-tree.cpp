class Solution {
public:
    void dfs(TreeNode* root, int max_num, int &count)
    {
        if(root==NULL)
        {
            return;
        }
        if(max_num<=root->val)
        {
            count++;
            max_num = root->val;
        }
     
        dfs(root->left,max_num,count);
        dfs(root->right,max_num,count);
        
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        int max_num = root->val;
        dfs(root, max_num, count);
        return count;
    }
};