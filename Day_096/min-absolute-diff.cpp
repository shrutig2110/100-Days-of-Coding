class Solution {
public:
    void dfs(TreeNode* root, vector<int> &tree)
    {
        if(root==NULL)
        {
            return;
        }
        tree.push_back(root->val);
        dfs(root->left,tree);
        dfs(root->right,tree);
    }
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        vector<int> tree;
        dfs(root, tree);
        sort(tree.begin(),tree.end());
        for(int i =1;i<tree.size();i++)
        {
            int diff = tree[i]-tree[i-1];
            min_diff = min(diff, min_diff);
        }
        return min_diff;
    }
};