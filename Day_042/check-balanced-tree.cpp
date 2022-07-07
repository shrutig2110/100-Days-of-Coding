class Solution{
private:
pair<bool,int> balance(Node* root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    
    pair<bool,int> left = balance(root->left);
    pair<bool,int> right = balance(root->right);
    
    int leftans = left.first;
    int rightans = right.first;
    bool diff = abs(left.second - right.second) <=1 ; 
    pair<bool,int> ans;
    if(leftans && rightans && diff)
    {
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    ans.second = max(left.second, right.second) +1;
    return ans;
}
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return balance(root).first;
    }
};