class Solution{
private:
pair<bool,int> balance(Node* root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
// Check if left root is balanced or not
    pair<bool,int> left = balance(root->left);
// Check if right root is balanced or not
    pair<bool,int> right = balance(root->right);

    int leftans = left.first;
    int rightans = right.first;
    bool diff = abs(left.second - right.second) <=1 ; 
    pair<bool,int> ans;
// For a tree to be balanced it's left and right subtree must be balanced(true) 
// and difference of height of left and right subtree must be <= 1
    if(leftans && rightans && diff)
    {
        ans.first = true;
    }
    else{
        ans.first = false;
    }
// Calculate the height of current node to be able to find difference later 
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