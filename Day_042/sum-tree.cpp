class Solution
{
    private:
    pair<bool,int> sum(Node* root)
    {
        if(root == NULL)
        {
            pair<int,int> p = make_pair(true,0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            pair<int,int> p = make_pair(true,root->data);
            return p;
        }
    // Calculate and see if all left subtrees add up to their root data
        pair<bool,int> left = sum(root->left);
     // Calculate and see if all right subtrees add up to their root data
        pair<bool,int> right = sum(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool totalsum = left.second + right.second == root->data;
        
        pair<bool,int> ans;
// For a tree to be a sum tree it's left and right subtree must be sum tree(true) 
// A sum tree is where a the 2 child nodes data sum == root data
        if(leftAns &&rightAns && totalsum)
        {
            ans.first = true;
        }
        else{
            ans.first= false;
        }
        // root's children->data add up to root->data hence we can directly write it as
        ans.second = 2*root->data;
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         return sum(root).first;
    }
};
