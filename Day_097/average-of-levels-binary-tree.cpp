class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        // ans.push_back(root->val);
        double sum = 0;
        double avg = 0;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++) {
                TreeNode* t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                sum+=t->val;
            }
            
            ans.push_back(sum/s);
            sum = 0; 
        }
        return ans;
        
        
    }
};