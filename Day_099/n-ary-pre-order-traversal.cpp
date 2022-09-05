class Solution {
public:
    vector<int>ans;
    vector<int> preorder(Node* root) {
    if(root==NULL)return ans;
    
    ans.push_back(root->val);
    
    for(auto x:root->children)
        preorder(x);
    
    return ans;
    }
};